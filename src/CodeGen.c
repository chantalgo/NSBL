/********************************************************************
 * CodeGen.c                                                        *
 * This is the source for code generation in NSBL. Code Gen is done *
 * on the ASTree, via post-order traversal.                         *
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "CodeGen.h"
#include "SymbolTable.h"
#include "Parser.tab.h"
#include "global.h"
#include "Error.h"
#include "operator.h"
#include "CodeGenUtil.h"
#include "NSBLio.h"
#include "Derivedtype.h"

char * OUTFILE;                 // Output file name 
FILE * OUTFILESTREAM;           // Output file stream

int     inLoop, 
        inFunc;                 // flags to indicate : inside of loop or func
int     inMATCH,                // flags to indicate : inside of match operator
        existMATCH,             //                   : exist match operator in subtree of AST
        existPIPE,              //                   : exist pipe operator in subtree of AST
        nMATCHsVab;             // count number of dynamic variables in Match
GList *returnList, *noReturn;
char * matchStaticVab, *matchStrDecl;

void derivedTypeInitCode(struct Node* node, int type, int isglobal){
	if(node->token == AST_COMMA){
		derivedTypeInitCode(node->child[0], type, isglobal);
		derivedTypeInitCode(node->child[1], type, isglobal);
    	node->code = strCatAlloc("",2, node->child[0]->code, node->child[1]->code);
	}else if (node->token == IDENTIFIER) {
		switch(type){
			case GRAPH_T:
				if(isglobal)
					node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = new_graph();\n"); 
				else
					node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), "* ", node->symbol->bind, " = new_graph();\n");
				break;
			case VERTEX_T:
				if(isglobal)
					node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = new_vertex();\n"); 
				else
					node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), "* ", node->symbol->bind, " = new_vertex();\n");
				break;
			case EDGE_T:
				if(isglobal)
					node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = new_edge();\n"); 
				else
					node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), "* ", node->symbol->bind, " = new_edge();\n");
				break;
			default:
				break;
		}
	}
    else if (node->token == AST_ASSIGN) {
        if (node->child[1]->type != type) {
            ERRNO= ErrorInitDerivedType;
            errorInfo(ERRNO, node->line, "type mismatch for the initialization of derived type.\n");
            node->code = NULL;
            return;
        }
        if(isglobal) 
            node->code = strCatAlloc("",5, INDENT[node->scope[0]], node->child[0]->symbol->bind, " = ", node->child[1]->code, ";\n");
        else
            node->code = strCatAlloc("",7, INDENT[node->scope[0]], sTypeName(type), "* ",node->child[0]->symbol->bind, " = ", node->child[1]->code, ";\n");
    }
    else {
        ERRNO = ErrorIllegalDerivedTypeDeclaration;
        errorInfo(ERRNO, node->line, "Illegal declaration of derived type  (vertex, edge, graph).\n");
    }
}

void stringInitCode(struct Node* node, int type, int isglobal){
	if(node->token == AST_COMMA){
		stringInitCode(node->child[0], type, isglobal);
		stringInitCode(node->child[1], type, isglobal);
		node->code = strCatAlloc("", 2, node->child[0]->code, node->child[1]->code);
	}else if(node->token == AST_ASSIGN){
		if(isglobal)
			node->code = strCatAlloc("",5,INDENT[node->scope[0]], 
                node->child[0]->symbol->bind, " = ", node->child[1]->code, ";\n"); 
		else
			node->code = strCatAlloc("",7,INDENT[node->scope[0]], 
                sTypeName(type), " ", node->child[0]->symbol->bind, " = ", node->child[1]->code, ";\n");	
	}else{
		if(isglobal)
			node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = g_string_new(\"\");\n"); 
		else
			node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), " ", node->symbol->bind, " = g_string_new(\"\");\n");
	}
}

void listInitCode(struct Node* node, int type, int isglobal){
    int mtype = (type == VLIST_T) ? VERTEX_T : EDGE_T;
    if(node->token == AST_COMMA){
        listInitCode(node->child[0], type, isglobal);
        listInitCode(node->child[1], type, isglobal);
        node->code = strCatAlloc("", 2, node->child[0]->code, node->child[1]->code);
    }
    else if (node->token == AST_ASSIGN){
        char num[32];
        int flag = listCountCheck(node->child[1], mtype);
        int nArgs = (flag > 0)? flag : 0;
        sprintf(num,"%d\0", nArgs);
        node->code = strCatAlloc("", 7, INDENT[node->scope[0]],
            (isglobal)? "" : "ListType * ", node->child[0]->symbol->bind, 
                " = list_declaration( ", typeMacro(mtype), " , ", num);
        if(nArgs>0) node->code = strRightCatAlloc( node->code, "",3, " , ", node->child[1]->code, ");\n");
        else node->code = strRightCatAlloc( node->code, "", 1, ");\n");        
        // if not init by [], 
        if (flag<0) {
            node->code = strRightCatAlloc( node->code, "", 5,
                "assign_operator_list ( & (", node->child[0]->symbol->bind, " ) , ( ",
                node->child[1]->code, " ) );\n");
        }
    }
    else {
        node->code = strCatAlloc("", 6, INDENT[node->scope[0]],
            (isglobal)? "" : "ListType * ", node->symbol->bind,
                " = list_declaration( ", typeMacro(mtype), " , 0 );\n");    
    }        
}

// count number of initializor in [ ...]
int listCountCheck(struct Node* node, int type){
	int count = 0, flag = 0;
	struct Node* tn = node;
	if(tn->token != AST_LIST_INIT) {
        return -1;
    }
    if(tn->nch > 0) {
		tn = tn->child[0];
    	while (tn->token == AST_COMMA ) {
        	if ( tn->child[1]->type != type ) flag = ErrorListMixedType;
        	tn = tn->child[0];
        	count++;
    	}
    	if (tn->token == IDENTIFIER) {
        	if ( tn->type != type ) flag = ErrorListMixedType;
        	count++;
    	}
		else if(tn->token == AST_ASSIGN){
        	if ( tn->type != type ) flag = ErrorListMixedType;
        	count++;
		}else{
			flag = ErrorAssignmentExpression;
		}
    	if (flag == ErrorListMixedType) {
        	ERRNO = flag;
        	errorInfo(ERRNO, node->line, "list Initialization with wrong type.\n");
    	}
		else if(flag == ErrorAssignmentExpression){
			ERRNO = flag;
			errorInfo(ERRNO, node->line, "list Initialization with wrong argument expression.\n");
		}
	}
    return count;
}

char * codeDel( struct Node * node ) {
    if (node == NULL) return NULL;
#ifdef _DEBUG
    debugInfo("codeDel: NODE = %d\n",node->token);
#endif
    if (node->token == AST_COMMA) {
        char * lfc = codeDel( node->child[0] );
        char * rtc = codeDel( node->child[1] );
        return strCatAlloc("", 2, lfc, rtc);
    }
    else if (node->token == AST_DEL_ATTRIBUTE) {
        codeGen(node);
        char * freeFunc = codeRemoveAttrFuncName(node->child[0]->type);
        return strCatAlloc("", 7, INDENT[node->scope[0]],freeFunc," ( ", node->child[0]->code, " , \"", node->child[1]->code, "\" );\n");
        return NULL;
    }
    else if (node->token == IDENTIFIER) {
        int type = node->symbol->type;
        if (type<=FLOAT_T || type>=FUNC_T) {
            ERRNO = ErrorDelVariableOfWrongType;
            errorInfo(ERRNO,node->line,"delete variable of type `%s'.\n",sTypeName(type));
            return NULL;
        } 
        char * freeFunc = codeFreeFuncName(type);
        return strCatAlloc("",5,INDENT[node->scope[0]],freeFunc," ( ", node->symbol->bind, " );\n");
    }
    else {
        fprintf(stderr, "codeDel: unknown node %d !!!!!!\n", node->token);
        return NULL;
    }
}

int codeAttr ( struct Node * node ) {
    // codeGen should already be called on this node, before codeAttr
    char * code = node->code;
    if(node->type<=0 || node->type>STRING_T) {
        ERRNO = ErrorBinaryOperationWithDynamicType;
        errorInfo(ERRNO, node->line, "Binary Operation with Dynamic Type.\n");
        return 1;
    }
    node->code = strCatAlloc("", 5, " new_attr_", typeMacro(node->type), "( ", code," )");
    free(code);
    node->tmp[0] = REMOVE_DYN;  // set remove flag
    return 0;
}

char * codeGetAttrVal( char * operand, int type, int lno ) {
    if(type != BOOL_T && type != INT_T && type != FLOAT_T && type != STRING_T) {
        ERRNO = ErrorGetAttrForWrongType;
        errorInfo(ERRNO, lno, "get attribute value for wrong type.\n");
        return NULL;
    }
    return strCatAlloc("",7,"get_attr_value_",typeMacro(type),
            " ( ",  operand, " , ", strLine(lno), " ) " );
}

char * codeFrontDecl(int lvl ) {
    char * decl = NULL;
    if(existMATCH == 1 || existPIPE == 1){ // for MATCH
       decl = strRightCatAlloc(decl, "", 2,INDENT[lvl],matchStrDecl);
       free(matchStrDecl); matchStrDecl= NULL;
       existMATCH = 0; existPIPE = 0;
    }
    return decl;
}

int codeAssignLeft( struct Node * node) {
    if (node->token == IDENTIFIER) {
        codeGen(node);
    }
    else if (node->token == AST_ATTRIBUTE) {
        // assume: NO assignment in MATCH
        node->child[0]->code = strCatAlloc("", 1, node->child[0]->symbol->bind);
        node->child[1]->code = strCatAlloc("", 1, node->child[1]->lexval.sval);
        // put "1" for xxx_get_attribute to auto allocate storage
        if(node->child[0]->type == VERTEX_T )
            node->code = strCatAlloc("", 7, "vertex_get_attribute( ",
                    node->child[0]->code, " ,  \"", node->child[1]->code, "\", 1, ", strLine(node->line)," )");
        else if(node->child[0]->type == EDGE_T )
                node->code = strCatAlloc("", 7, "edge_get_attribute( ",
                    node->child[0]->code, " ,  \"", node->child[1]->code, "\", 1, ", strLine(node->line)," )");
        else {
                ERRNO = ErrorGetAttrForWrongType;
                errorInfo(ERRNO, node->line, "Access attribute for type `%s'.\n",
                    sTypeName(node->child[0]->type) );
                node->code = NULL;
        }
        node->type = DYNAMIC_T;
    }
    else if (node->token == DYN_ATTRIBUTE) {
        node->code = strCatAlloc("",6,
                "object_get_attribute( _obj, _obj_type, ",
                "\"::",node->lexval.sval, "\", 1, ",strLine(node->line)," ) ");
        node->type = DYNAMIC_T;
    }
}

int codeFuncWrapDynArgs(struct Node* node, GArray* tcon, int* cnt){
    if(node->token == AST_COMMA) {
        codeFuncWrapDynArgs(node->child[0], tcon, cnt);
        codeFuncWrapDynArgs(node->child[1], tcon, cnt);
        node->code = strCatAlloc("", 3, node->child[0]->code, " , ", node->child[1]->code);
    }
    else if (node->token == AST_ARG_EXPS) {
        codeGen(node);
        if(tcon->len > *cnt) {
            int rtype = g_array_index(tcon, int, *cnt);
            if(node->type < 0) {
                char * ctmp = node->code;
                node->code = codeGetAttrVal(ctmp, rtype , node->line);
                free(ctmp);
            }
            else if (node->type >=0 && node->type != rtype ) {
                ERRNO = ErrorFunctionCallIncompatibleParameterType;
                errorInfo(ERRNO, node->line, "function arg has incompatible arguments to its declaration.\n");
            }
        }
        (*cnt)++;
    }
    return 0;
}

/** recursively generate code piece on each node */
int codeGen (struct Node * node) {
    if( node == NULL ) return;
    int token = node->token, errflag = 0;
    char * op = opMacro(token);
    struct Node *lf, *rt, *sg;
    char* printFunc;
    char* var;
    char* endBrace;
    char* printVattr;
    char* printCall;    	
    char* fileloc;
    char* comma;
    switch (token) {
/************************************************************************************/
        case INTEGER_CONSTANT :
        case FLOAT_CONSTANT :
        case BOOL_TRUE :
        case BOOL_FALSE :
        case STRING_LITERAL :
            // code and type already done in ASTree.c
            break;
        case IDENTIFIER :
            // type is done when insert into symtable
            if (node->symbol->bind!=NULL){ 
                if(inMATCH==0){
                    node->code = strCatAlloc("", 1, node->symbol->bind);
                    if (node->type == VERTEX_T || node->type == EDGE_T || 
                            node->type == VLIST_T || node->type == ELIST_T
                                || node->type == STRING_T || node->type == GRAPH_T) {
                        node->codetmp = strCatAlloc("",2,"* ",node->symbol->bind);
                    }
                    else {
                        node->codetmp = strCatAlloc("",1,node->symbol->bind);
                    }
                }
                else{
                    node->code = strCatAlloc("",3,"_str->",node->symbol->bind,"_match");
                    if (node->type == VERTEX_T || node->type == EDGE_T ||
                            node->type == VLIST_T || node->type == ELIST_T
                                || node->type == STRING_T || node->type == GRAPH_T) {
                        node->codetmp = strCatAlloc("",2,"* ",node->symbol->bind);
                    }
                    else {
                        node->codetmp = strCatAlloc("",1,node->symbol->bind);
                    }
                    matchStaticVab = strRightCatAlloc( matchStaticVab, "", 5, 
                        INDENT[1], sTypeName(node->type),
                        (node->type == VERTEX_T || node->type == EDGE_T ||
                            node->type == VLIST_T || node->type == ELIST_T
                                || node->type == STRING_T || node->type == GRAPH_T)
                                 ? " * " :" ",
                        node->symbol->bind,"_match;\n");
                    matchStrDecl = strRightCatAlloc( matchStrDecl, "", 2,
                        (nMATCHsVab++==0) ? "" : " , ",
                        node->symbol->bind);
                }
            }
            else
                ERRNO = ErrorNoBinderForId;
            break;
        case DYN_ATTRIBUTE :
            node->code = strCatAlloc("",6,
                "object_get_attribute( _obj, _obj_type, ", 
                "\"::",node->lexval.sval, "\", 0, ", strLine(node->line)," ) ");
            node->type = DYNAMIC_T;
            break;
        case AST_DEL_ATTRIBUTE :
            node->child[0]->code = strCatAlloc("", 1, node->child[0]->symbol->bind);
            node->child[1]->code = strCatAlloc("", 1, node->child[1]->lexval.sval);
            break;
        case AST_COMMA :
            lf = node->child[0]; rt = node->child[1];
            codeGen( lf );codeGen( rt );
            node->code = strCatAlloc(" ",3,lf->code,",",rt->code);
            if(node->scope[0]==0){ // for global declaration
                node->codetmp = strCatAlloc(" ",3,lf->codetmp,",",rt->codetmp);
            }
            node->type = node->child[1]->type;
            break;
		case AST_LIST_INIT:
			node->type = UNKNOWN_T;
			if(node->child==NULL)
				node->code = strCatAlloc("", 1, " ");
			else{
				sg = node->child[0];
				codeGen(sg);
				node->code = strCatAlloc("", 1, sg->code);
			}
			break;
        case AST_TYPE_SPECIFIER :
            node->code = strCatAlloc(" ",1,sTypeName(node->lexval.ival));
            break;
        case AST_DECLARATION :
            codeGen( node->child[0] );codeGen( node->child[1] );
            node->code = codeFrontDecl(node->scope[0] );
            // when the declaration is in scope 0, we need to generate two places of code for c
            // 1. external global declaration 
            // 2. assignment in main func, if possible
            if(node->scope[0]==0) {
                node->codetmp = strCatAlloc("",5,INDENT[node->scope[0]],node->child[0]->code," ",node->child[1]->codetmp,";\n");
				switch(node->child[0]->lexval.ival){
					case GRAPH_T: 
					case VERTEX_T:
					case EDGE_T:
						derivedTypeInitCode(node->child[1], node->child[0]->lexval.ival, 1);
						node->code = strRightCatAlloc(node->code,"", 1, node->child[1]->code);
						break;
					case STRING_T:
						stringInitCode(node->child[1], node->child[0]->lexval.ival, 1);
					    node->code = strRightCatAlloc(node->code,"", 1, node->child[1]->code);
						break;
					case VLIST_T:
                    case ELIST_T:
                        listInitCode(node->child[1], node->child[0]->lexval.ival, 1);
                        node->code = strRightCatAlloc(node->code,"", 1, node->child[1]->code);
                        break;
					default:
               		    node->code = strRightCatAlloc(node->code,"",3,INDENT[node->scope[0]],node->child[1]->code,";\n");
				}
            }
            // If scope > 0, no bother, just declaration everything in one c declaration
            else {
				switch(node->child[0]->lexval.ival){
					case GRAPH_T:
					case VERTEX_T:
					case EDGE_T:
						derivedTypeInitCode(node->child[1], node->child[0]->lexval.ival, 0);
						node->code = strRightCatAlloc(node->code,"", 1, node->child[1]->code);
						break;
					case STRING_T:
						stringInitCode(node->child[1], node->child[0]->lexval.ival, 0);
						node->code = strRightCatAlloc(node->code,"", 1, node->child[1]->code);
						break;
					case VLIST_T :
                    case ELIST_T :
                        listInitCode(node->child[1], node->child[0]->lexval.ival, 0);
                        node->code = strRightCatAlloc(node->code,"", 1, node->child[1]->code);
                        break;
					default:
                		node->code = strRightCatAlloc(node->code,"",5,INDENT[node->scope[0]],node->child[0]->code," ",node->child[1]->code,";\n");
				}
            }
            break;
/************************************************************************************/
        case DEL : {
            node->code = codeDel(node->child[0]);
            break;
        }
/************************************************************************************/
        case AST_ASSIGN :               // assignment_operator 
            if(inMATCH > 0) {
                ERRNO = ErrorAssignInMatch;
                errorInfo ( ERRNO, node->line, "assignment in Match operator.\n");
                return ERRNO;
            }
            lf =  node->child[0]; rt = node->child[1];
            if(lf->token != IDENTIFIER && lf->token != AST_ATTRIBUTE && lf->token != DYN_ATTRIBUTE) {
                ERRNO = ErrorAssignLeftOperand;
                errorInfo ( ERRNO, node->line, "the left operand of assign operator MUST be IDENTIFIER or ATTRIBUTE.\n");
                return ERRNO;
            }
            codeAssignLeft(lf);
            codeGen(rt);
            // type check and implicit type conversion
            if(lf->type == rt->type && lf->type>=0 ) {
                if ( lf->type == INT_T || lf->type == FLOAT_T || lf->type == BOOL_T ) {
                    node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
                    node->type = lf->type;
                }
                else if ( lf->type == STRING_T || lf->type == VLIST_T || lf->type == ELIST_T ||
                            lf->type == VERTEX_T || lf->type == EDGE_T || 
                                lf->type == GRAPH_T ){
                    char * func = assignFunc(lf->type);
					node->type = lf->type;
                    node->code = strCatAlloc("", 6,
                        func, " ( &(", lf->code, ") , (",
                        rt->code, ") ) " 
                    );
                }
                else {
                    ERRNO = ErrorOperatorNotSupportedByType;
                    errorInfo(ERRNO, node->line, "operator `%s' is not supported by type `%s'\n",op,sTypeName(lf->type));
                    return ERRNO;
                }
            }
            // float ==> int
            else if (lf->type == INT_T && rt->type == FLOAT_T)  {
                node->code = strCatAlloc(" ",4,lf->code,op,"(int)", rt->code);
                node->type = INT_T;
            }
            // int ==> float
            else if (lf->type == FLOAT_T && rt->type == INT_T) {
                node->code = strCatAlloc(" ",4,lf->code,op,"(float)", rt->code);
                node->type = FLOAT_T;
            }
            // DYNAMIC 
            else if (lf->type < 0 || rt->type < 0) {
                if (lf->type < 0 ) { // DYNAMIC = DYNAMIC or STATIC
                    int flag = 0;
                    if (rt->type >=0) flag = codeAttr(rt);
                    if (!flag){
                        node->code = strCatAlloc("", 9,
                            "assign_operator (", lf->code, " , ", rt->code, 
                            (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                            (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                            " , ", strLine(node->line), " ) "
                        );
                    }
                    node->type = DYNAMIC_T;
                    node->tmp[0] = REMOVE_DYN;
                }
                else  { // STATIC = DYNAMIC
                    //debugInfo("%s %d %s\n", rt->code, lf->type, lf->code);
                    node->code = strCatAlloc("", 12,
                        "( assign_operator_to_static (", rt->code, " , ", typeMacro(lf->type), 
                        " , (void *)&", lf->code,  
                        (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                        " , ", strLine(node->line), " ),  ", lf->code, " ) "
                    );
                    //debugInfo("%s\n",node->code);
                    node->type = lf->type;
                }
            }
            else { // ERROR
                node->code = NULL;
                ERRNO = ErrorTypeMisMatch;
                errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                return ERRNO;
            }
            // for global declaration in c
            if(node->scope[0]==0){
                node->codetmp = strCatAlloc("",1,lf->codetmp);
            }
            break;

        case APPEND :      
			lf = node->child[0]; rt = node->child[1];
			codeGen( lf );codeGen( rt );
            // TODO
			if(lf->type==GRAPH_T && rt->type==VERTEX_T){
				node->code = strCatAlloc("", 5, "g_insert_v(", lf->code, ", ", rt->code, ")");
			}
			else if(lf->type==GRAPH_T && rt->type==EDGE_T){
				node->code = strCatAlloc("", 5, "g_insert_e(", lf->code, ", ", rt->code, ")");	
			}
			else if(lf->type==GRAPH_T && (rt->type==VLIST_T || rt->type == ELIST_T) ){
				node->code = strCatAlloc("", 5, "g_append_list(", lf->code, ", ", rt->code, ")");
			}
			else if(lf->type==VLIST_T && rt->type==VERTEX_T){
				node->code = strCatAlloc("", 5, "list_append(", lf->code, ", VERTEX_T, ", rt->code, ")");
			}
			else if(lf->type==ELIST_T && rt->type==EDGE_T){
				node->code = strCatAlloc("", 5, "list_append(", lf->code, ", EDGE_T, ", rt->code, ")");
			}else{
				ERRNO = ErrorAssignmentExpression;
				errorInfo(ERRNO, node->line, "append expression error\n");
				return ERRNO;
			}
            break;
/************************************************************************************/
        case OR  :          
        case AND :          
            lf =  node->child[0]; rt = node->child[1];
            codeGen(lf);codeGen(rt);
            node->type = BOOL_T;
            if(lf->type >= 0 && rt->type >= 0) {
                if (lf->type != rt->type){
                    ERRNO = ErrorTypeMisMatch;
                    errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                    return ERRNO;
                }
                else if (lf->type == BOOL_T) {
                    node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
                }
                else {
                    ERRNO = ErrorOperatorNotSupportedByType;
                    errorInfo(ERRNO, node->line, "operator `%s' is only supported by type `bool'\n",op);
                    return ERRNO;
                }
            }
            else { // DYNAMIC
                int flag = 0;
                if (lf->type > 0 && lf->type == BOOL_T) flag = codeAttr(lf);
                if (rt->type > 0 && rt->type == BOOL_T) flag = codeAttr(rt);
                if (lf->type > 0 && lf->type != BOOL_T ||
                        rt->type > 0 && rt->type != BOOL_T) {
                    ERRNO = ErrorOperatorNotSupportedByType;
                    errorInfo(ERRNO, node->line, "operator `%s' is only supported by type `bool'\n",op);
                    return ERRNO;
                }
                if(!flag) {
                    node->code = strCatAlloc("",12 ,
                    " binary_operator ( ", lf->code, " , ", rt->code, " , ", DynOP(token),
                    ", FLAG_NO_REVERSE",
                    ( (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ),
                    ( (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ),
                    " , ", strLine(node->line), " )"
                    );
                }
                node->tmp[0] = REMOVE_DYN;
                node->type = DYN_BOOL_T;
            }    
            break;
/************************************************************************************/
        case EQ :           
        case NE :           
            lf =  node->child[0]; rt = node->child[1];
            codeGen(lf);codeGen(rt);
            if(lf->type >= 0 && rt->type >= 0){ // STATIC
                if (lf->type != rt->type) {
                    if(lf->type == INT_T && rt->type == FLOAT_T) {
                        node->code = strCatAlloc(" ",4,"(float)",lf->code,op,rt->code);
                        node->type = BOOL_T;
                    }
                    else if(lf->type == FLOAT_T && rt->type == INT_T) {
                        node->code = strCatAlloc(" ",4,lf->code,op,"(float)",rt->code);
                        node->type = BOOL_T;
                    }
                    else {
                        ERRNO = ErrorTypeMisMatch;
                        errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                        return ERRNO;
                    }
                }
                else {
                    node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
                    node->type = BOOL_T;
                }
            }
            else {  // DYNAMIC
                int flag = 0;
                if(lf->type >= 0) flag = codeAttr(lf);
                if(rt->type >= 0) flag = codeAttr(rt);
                if(!flag) {
                    node->code = strCatAlloc("",12 ,
                    " binary_operator ( ", lf->code, " , ", rt->code, " , ", DynOP(token),
                    ", FLAG_NO_REVERSE",
                    ( (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ),
                    ( (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ),
                    " , ", strLine(node->line), " )"
                    );
                }
                node->tmp[0] = REMOVE_DYN;
                node->type = DYN_BOOL_T; 
            }
            break;
/************************************************************************************/
        case LT :           
        case GT :           
        case LE :           
        case GE :           
            lf =  node->child[0]; rt = node->child[1];
            codeGen(lf);codeGen(rt);
            node->type = BOOL_T;
            if(lf->type == rt->type && (lf->type == INT_T) || (lf->type == FLOAT_T ) ) 
                node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
            else if (lf->type == INT_T && rt->type == FLOAT_T) 
                node->code = strCatAlloc(" ",4, "(float)",lf->code,op,rt->code);
            else if (rt->type == INT_T && lf->type == FLOAT_T) 
                node->code = strCatAlloc(" ",4, lf->code,op,"(float)",rt->code);
            else if (lf->type <= 0 || rt->type <= 0) {  // DYNAMIC
                if(lf->type >=0 && lf->type != INT_T && lf->type != FLOAT_T ||
                    lf->type >=0 && lf->type != INT_T && lf->type != FLOAT_T ){
                    ERRNO = ErrorTypeMisMatch;
                    errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                    return ERRNO;
                }
                int flag = 0;
                if(lf->type >= 0) flag = codeAttr(lf);
                if(rt->type >= 0) flag = codeAttr(rt);
                if(!flag) {
                    node->code = strCatAlloc("",12 ,
                    " binary_operator ( ", lf->code, " , ", rt->code, " , ", DynOP(token),
                    ", FLAG_NO_REVERSE",
                    ( (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ),
                    ( (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ),
                    " , ", strLine(node->line), " )"
                    );
                }
                node->tmp[0] = REMOVE_DYN;
                node->type = DYNAMIC_T; 
            }
            else {
                ERRNO = ErrorTypeMisMatch;
                errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                return ERRNO;
            }
            
            break;
/************************************************************************************/
        case ADD :          
        case SUB :          
        case MUL :          
        case DIV :          
            lf =  node->child[0]; rt = node->child[1];
            codeGen(lf);codeGen(rt);
            if(lf->type == rt->type && (lf->type == INT_T) || (lf->type == FLOAT_T ) ) {
                node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
                node->type = lf->type;
            }
            else if (lf->type == INT_T && rt->type == FLOAT_T) {
                node->code = strCatAlloc(" ",4, "(float)",lf->code,op,rt->code);
                node->type = FLOAT_T;
            }
            else if (rt->type == INT_T && lf->type == FLOAT_T) {
                node->code = strCatAlloc(" ",4, lf->code,op,"(float)",rt->code);
                node->type = FLOAT_T;
            }
            else if (lf->type < 0 || rt->type < 0) { // DYNAMIC
#ifdef _DEBUG
                debugInfo("DYNAMIC : %d : (%d, %d) \n",
                    node->token, lf->type, rt->type );
#endif
                int flag = 0;
                if(lf->type>=0) flag = codeAttr(lf);    // if STATIC, wapper to Attr
                if(rt->type>=0) flag = codeAttr(rt);
                if (!flag) {
                    node->code = strCatAlloc("", 12,
                        " binary_operator( ", lf->code, " , ", rt->code, " , ", DynOP(token), 
                        ", FLAG_NO_REVERSE",
                        (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ,
                        (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR" ,
                        " , ", strLine(node->line), " )"
                    );
                    node->tmp[0] = REMOVE_DYN;
                    node->type = DYNAMIC_T;
                }         
            }
            else {
                ERRNO = ErrorTypeMisMatch;
                errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                return ERRNO;
            }
            break;
/************************************************************************************/
        case AST_CAST :
            lf =  node->child[0]; rt = node->child[1];
            int castType = lf->lexval.ival;
            codeGen(rt);
            if(rt->type >= 0) {
                if(castType == rt->type) {
                    node->code = strCatAlloc(" ",4,"(",sTypeName(lf->lexval.ival),")" , rt->code);
                    node->type = castType;
                }
                else if ( (castType == INT_T && rt->type == FLOAT_T) ||
                        (castType == FLOAT_T && rt->type == INT_T) ) {
                    node->code = strCatAlloc(" ",4,"(",sTypeName(lf->lexval.ival),")" , rt->code);
                    node->type = castType;
                }
                else {
                    ERRNO = ErrorCastType;
                    errorInfo(ERRNO, node->line, "cast from `%s' to `%s' is invalid\n", sTypeName(castType), sTypeName(rt->type) );
                    return ERRNO;
                }
            }
            else {  // DYNAMIC
                node->code = strCatAlloc( "" , 8,
                    "cast_operator( ", rt->code, " , ", typeMacro(castType),
                    (rt->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                    " , ", strLine(node->line), " )"
                );
                node->tmp[0] = REMOVE_DYN;
                node->type = DYNAMIC_T;
            }
            break; 
/************************************************************************************/
        case AST_UNARY_PLUS :   
        case AST_UNARY_MINUS :  
        case AST_UNARY_NOT :    
            sg = node->child[0];
            codeGen(sg);
            if ( sg->type >= 0) {
                if ( (sg->type == INT_T || sg->type == FLOAT_T) &&
                    ( token == AST_UNARY_PLUS || token == AST_UNARY_MINUS) ) {
                    node->code = strCatAlloc(" ",4,op,"(",sg->code,")");
                    node->type = sg->type;
                }
                else if ( sg->type == BOOL_T && token == AST_UNARY_NOT ) {
                    node->code = strCatAlloc(" ",4,op,"(",sg->code,")");
                    node->type = sg->type;
                }
                else {
                    ERRNO = ErrorOperatorNotSupportedByType;
                    errorInfo(ERRNO, node->line, "unary operator `%s' is not supported by type `%s'.\n",op,sTypeName(sg->type));
					return ERRNO;
                }
            }
            else { // DYNAMIC
                node->code = strCatAlloc("", 8,
                    "unary_operator (", sg->code, " , ", DynOP(token),
                    (sg->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                    " , ", strLine(node->line), " )"
                );
                node->tmp[0] = REMOVE_DYN;
                if(token==AST_UNARY_NOT) node->type = DYN_BOOL_T;
                else node->type = DYNAMIC_T;
            }
            break;
/************************************************************************************/
        case ARROW :
			lf = node->child[0]; sg = node->child[1]; rt = node->child[2];
			if(lf->token!=IDENTIFIER || sg->token!=IDENTIFIER || rt->token!=IDENTIFIER){
				ERRNO = ErrorEdgeAssignExpression;
				errorInfo(ERRNO, node->line, "edge assign expression error\n");
			}
			if(lf->type!=EDGE_T||sg->type!=VERTEX_T||rt->type!=VERTEX_T){
				ERRNO = ErrorEdgeAssignExpression;
				errorInfo(ERRNO, node->line, "edge assign illegal var type error\n");
			}
			codeGen(lf); codeGen(sg); codeGen(rt);
			node->code = strCatAlloc("",7,"edge_assign_direction(", lf->code, ", ", sg->code, ", ", rt->code, ")");
			node->codetmp = NULL;
            break;
/************************************************************************************/
        case AST_FUNC_CALL :
            //  lookup symbol table, also set type
            errflag = sTableLookupFunc(node);
            //  code Gen
            if(!errflag) {
                if (node->nch > 1){         //    if have args
                    int cnt = 0;            //    count number of args
                    codeFuncWrapDynArgs(node->child[1], node->symbol->typeCon, &cnt);
                    if (node->symbol->typeCon->len != cnt) {
                        ERRNO = ErrorFunctionCallNOTEqualNumberOfParameters;
                        errorInfo(ERRNO, node->line, "function Call has inconsistent number of arguments to its declaration. %d, %d\n", node->symbol->typeCon->len, cnt);
                    }
                }
                if(node->symbol->type == FUNC_LITERAL_T && inMATCH > 0) {
                    if(node->nch == 1)
                        node->code = strCatAlloc("",2,node->symbol->bind, " ( _obj, _obj_type )" );
                    else
                        node->code = strCatAlloc("",4,node->symbol->bind, " ( _obj, _obj_type, ",
                            node->child[1]->code, " )");
                }
                else if (node->symbol->type == FUNC_T) {
                    if(node->nch == 1) node->code = strCatAlloc(" ",2,node->symbol->bind,"()");
                    else node->code = strCatAlloc(" ",4,node->symbol->bind,"(", node->child[1]->code, " )");
                }
                else {
                    ERRNO = ErrorWrongFuncCall;
                    errorInfo(ERRNO,node->line,"invalid func call.\n");
                }
            }
            break;
        case AST_ARG_EXPS :
            codeGen(node->child[0]);
            node->type = node->child[0]->type;
            node->code = strCatAlloc(" ", 1, node->child[0]->code );
            break;
/************************************************************************************/
        case PIPE :{
			lf = node->child[0];
			rt = node->child[1];
			codeGen(lf);codeGen(rt);
			if(lf->type!=ELIST_T && lf->type!=VLIST_T){
				ERRNO = ErrorPipeWrongType;
				errorInfo(ERRNO, node->line, "pipe can NOT be operated on type `%s'.\n", sTypeName(lf->type));
			}
			existPIPE = 1;
			char* nltype;
			if(lf->type == ELIST_T)
				nltype = strCatAlloc("",1, typeMacro(VERTEX_T));
			else
				nltype = strCatAlloc("", 1, typeMacro(EDGE_T));
			char* pop;
			switch(rt->token){
				case OUTCOMING_EDGES: pop = strCatAlloc("",1,"OP_OUTE");break;
				case INCOMING_EDGES: pop = strCatAlloc("", 1, "OP_INE");break;
				case STARTING_VERTICES: pop = strCatAlloc("", 1, "OP_SV");break;
				case ENDING_VERTICES: pop = strCatAlloc("", 1, "OP_EV"); break;
			}
			char* tnl = strCatAlloc("",1, tmpVab());
			char* tlen = strCatAlloc("", 1, tmpVab());
			char * ti = strCatAlloc("", 1, tmpVab());
			matchStrDecl = strRightCatAlloc( matchStrDecl,"", 87,
					"ListType * ", tnl, " = (ListType*) malloc(sizeof(ListType));\n",
					tnl, "->list = NULL;\n",
					tnl, "->type = ", nltype, ";\n",
					"int ", tlen, " = g_list_length(", lf->code, "->list);\n",
					"int ", ti, ";\n",
					"for(", ti, "=0; ", ti, "<", tlen, "; ", ti, "++){\n",
					"switch(",nltype, "){\n",
					"case EDGE_T:\n",
					"if(", pop, "==OP_OUTE)\n",
					tnl, " = list_append_gl(", tnl, ", ((VertexType*)g_list_nth_data(", lf->code, "->list, ", ti, "))->outEdges, EDGE_T);\n",
					"else if(", pop, "==OP_INE)\n",
					tnl, " = list_append_gl(", tnl, ", ((VertexType*)g_list_nth_data(", lf->code, "->list, ", ti, "))->inEdges, EDGE_T);\n",
					"else ", "die(", strLine(node->line),", \"illeage pipe op for vlist\\n\");\n",
					"break;\n",
					"case VERTEX_T:\n",
					"if(", pop, "==OP_SV)\n",
					tnl, " = list_append(", tnl, ", VERTEX_T, ((EdgeType*)g_list_nth_data(", lf->code, "->list, ", ti, "))->start);\n",
					"else if(", pop, "==OP_EV)\n",
					tnl, " = list_append(", tnl, ", VERTEX_T,  ((EdgeType*)g_list_nth_data(", lf->code, "->list, ", ti, "))->end);\n",
					"else ", "die(", strLine(node->line),", \"illeage pipe op for elist\\n\");\n",
					"break;\n",
					"}\n",
					"}\n"
					);
            if(lf->tmp[0]==REMOVE_DYN) {
                matchStrDecl = strRightCatAlloc(matchStrDecl,"",3,
                    "destroy_list ( ", lf->code, ");\n"
                );
            }
            free(pop);free(tlen);free(ti);free(nltype);
            node->code = tnl;  
			if(lf->type == ELIST_T)
            	node->type = VLIST_T;
			else
				node->type = ELIST_T;
            node->tmp[0] = REMOVE_DYN; 
			break;
	    }
/************************************************************************************/
        case AST_MATCH :
            lf = node->child[0];        // list
            rt = node->child[1];        // condition
            codeGen(lf); 
            // get the STR name, func name, 
            char * tmpfunc = tmpMatch();
            char * match_str = tmpMatchStr();
            char * match_str_val = tmpMatchStrVab();
            // declaration of STR
            matchStrDecl = strRightCatAlloc( matchStrDecl, "", 5,
                "struct ", match_str, " ", match_str_val, " = {"
            );
            nMATCHsVab = 0;
            inMATCH++; codeGen(rt); inMATCH--;
            matchStrDecl = strRightCatAlloc( matchStrDecl,"",1,"};\n" );
            if(lf->type != VLIST_T && lf->type != ELIST_T) {
                ERRNO = ErrorMactchWrongType;
                errorInfo(ERRNO,node->line," match can NOT be operated on type `%s'.\n",sTypeName(lf->type) );
                return ERRNO;
            }
            //  check return type == bool
            if(rt->type != BOOL_T && rt->type >=0 ){
                ERRNO = ErrorInvalidReturnType;
                errorInfo(ERRNO,node->line,"the body of Match operator must return bool result.\n");
                return ERRNO;
            } 
            // set FLAG for STR declaration
            // FLAG cleared in AST_EXP_STAT
            existMATCH = 1;
            // DYNAMIC : get attr val
            if(rt->type < 0) {
                char * ctmp = rt->code;
                rt->code = codeGetAttrVal( rt->code,  BOOL_T, node->line );
                free(ctmp);
            }
            // first generate struct and func for this match 
            node->codetmp = strCatAlloc("", 15,
                "struct ",match_str, " {\n",
                matchStaticVab,
                "};\n",
                "bool ", tmpfunc, 
                " ( void * _obj, int _obj_type, struct ", match_str, " * _str ) {\n",
                INDENT[1], "return ", rt->code, " ;\n",
                "} // END_MATCH_FUNC \n"
            );
            free(matchStaticVab); matchStaticVab =NULL;
            // 
            char * tlt = strCatAlloc("",1,tmpVab());
            char * tlen = strCatAlloc("",1,tmpVab());
            char * ti = strCatAlloc("",1,tmpVab());
            char * tb = strCatAlloc("",1,tmpVab());
            char * tobj = strCatAlloc("",1,tmpVab());
            matchStrDecl = strRightCatAlloc(matchStrDecl,"", 55,
                "ListType* ", tlt, " = new_list ();\n",
                tlt, "->type = (", lf->code, ")->type;\n",
                "int ", tlen, " = g_list_length( (", lf->code, ")->list );\n",
                "int ", ti, ";\n",
                "bool ", tb, ";\n",
                "void *", tobj, ";\n",
                "for (", ti, "=0; ", ti, "<", tlen, "; ", ti, "++) {\n",
                tobj, "= g_list_nth_data( (", lf->code, ")->list, ", ti, ");\n",
                "if ( ", tb, " = ", tmpfunc, "( ",tobj, ", ( ", lf->code, ")->type, &", match_str_val,") ) {\n",
                tlt, "->list = g_list_append ( ", tlt, "->list , ", tobj, ");\n",
                "}\n",
                "}\n"
            );
            if(lf->tmp[0]==REMOVE_DYN) {
                matchStrDecl = strRightCatAlloc(matchStrDecl,"",3,
                    "destroy_list ( ", lf->code, ");\n"
                );
            }
            free(tlen);free(ti);free(tb);free(tobj);
            // code for match body
            /*
            node->code = strCatAlloc("", 8,
                "list_match( ", lf->code, " , &" , tmpfunc, " , &", match_str_val, 
                (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                " )"
            );*/
            node->code = tlt;  
            node->type = lf->type;
            node->tmp[0] = REMOVE_DYN; 
            break;
/************************************************************************************/
        case AST_LIST_MEMBER:
            lf = node->child[0];
            rt = node->child[1];
            codeGen(lf); codeGen(rt);
            if(lf->type != VLIST_T && lf->type != ELIST_T) {
                ERRNO = ErrorGetMemberForNotListType;
                errorInfo( ERRNO, node->line, "get member for not list type.\n");
                return ERRNO;
            }
            if(rt->type == INT_T){
                node->code = strCatAlloc( "", 6 ,
                    (lf->type == VLIST_T) ? "(VertexType *) " : "(EdgeType *) ",
                    "list_getelement ( ", lf->code, " , " ,rt->code, " )" );
            }
            else if (rt->type < 0) {  // DYNAMIC
                node->code = strCatAlloc( "" , 8, 
                    (lf->type == VLIST_T) ? "(VertexType *) " : "(EdgeType *) ",
                    "list_getelement ( ", lf->code,
                    ", get_attr_value_INT_T ( ", rt->code, " , ", strLine(node->line), " ) )");
            }
            node->type = (lf->type == VLIST_T) ? VERTEX_T : EDGE_T;
            break;
        case AST_LENGTH:
            sg = node->child[0];
            codeGen(sg);
            if(sg->type != VLIST_T && sg->type != ELIST_T) {
                ERRNO = ErrorGetLengthForTypeNotList;
                errorInfo( ERRNO, node->line, "get length for type not list.\n");
                return ERRNO;
            }
            node->code = strCatAlloc( "", 3,
                "g_list_length( ",sg->code,"->list )" );
            node->type = INT_T; 
            break;
/************************************************************************************/
        case AST_ATTRIBUTE : 
            if(inMATCH==0){
                node->child[0]->code = strCatAlloc("", 1, node->child[0]->symbol->bind);
            }
            else {
                node->child[0]->code = strCatAlloc("", 3,"_str->", node->child[0]->symbol->bind,"_match");
                matchStaticVab = strRightCatAlloc( matchStaticVab,"", 5,
                    INDENT[1], sTypeName(node->child[0]->symbol->type), 
                        " * ", node->child[0]->symbol->bind,"_match;\n");
                matchStrDecl = strRightCatAlloc( matchStrDecl, "", 2,
                    (nMATCHsVab++==0) ? "" : " , ",
                    node->child[0]->symbol->bind);
            }
            node->child[1]->code = strCatAlloc("", 1, node->child[1]->lexval.sval); 
            if(node->child[0]->type == VERTEX_T ) 
                node->code = strCatAlloc("", 7, "vertex_get_attribute( ",
                    node->child[0]->code, " ,  \"", node->child[1]->code, "\", 0, ", strLine(node->line),")");
            else if(node->child[0]->type == EDGE_T )
                node->code = strCatAlloc("", 7, "edge_get_attribute( ",
                    node->child[0]->code, " ,  \"", node->child[1]->code, "\", 0, ", strLine(node->line), ")");
            else {
                ERRNO = ErrorGetAttrForWrongType;
                errorInfo(ERRNO, node->line, "Access attribute for type `%s'.\n",
                    sTypeName(node->child[0]->type) );
                node->code = NULL;
            }
            node->type = DYNAMIC_T;
            break;
/************************************************************************************/
        case AST_GRAPH_PROP :
			lf = node->child[0]; rt = node->child[1];
			codeGen(lf); codeGen(rt);
			if(lf->type != GRAPH_T){
				ERRNO = ErrorWrongArgmentType;
				errorInfo(ERRNO, node->line, "need a graph type for AllV and AllE operation, but type used is `%s'. \n",
						sTypeName(lf->type) );
				return;
			}
			switch(rt->token){
				case ALL_VERTICES:
					node->type = VLIST_T;
					node->code = strCatAlloc("", 3, "get_g_vlist(", lf->code, ")");
					break;
				case ALL_EDGES:
					node->type = ELIST_T;
					node->code = strCatAlloc("", 3, "get_g_elist(", lf->code, ")");
					break;
				default:
					ERRNO = ErrorOperatorNotSupportedByType;
					errorInfo(ERRNO, node->line, "Undifined Operation for graph \n");
					return;
			}
            break;
/************************************************************************************/
        case AST_COMP_STAT :            // compound_statement
        case AST_COMP_STAT_NO_SCOPE :
            if(node->nch == 0) { // empty
                node->code = strCatAlloc("",1,"");
            }
            else {
                codeGen(node->child[0]);
                node->code = strCatAlloc("",1,node->child[0]->code);
            }
            break;
        case AST_STAT_LIST :
            lf = node->child[0]; rt = node->child[1];
            codeGen(lf); codeGen(rt);
            node->code = strCatAlloc("",2,lf->code,rt->code);
            break;
/************************************************************************************/
        case AST_EXP_STAT :             // expression_statement
            if(node->nch == 0)  { // empty
                node->code = strCatAlloc("",1,";\n");
            }
            else {
                codeGen(node->child[0]);
                node->code = codeFrontDecl(node->scope[0]);
                node->code = strRightCatAlloc(node->code,"",3,INDENT[node->scope[0]],node->child[0]->code, ";\n");
            }
            break;
/************************************************************************************/
        case AST_IF_STAT :              // selection_statement
            lf = node->child[0]; rt = node->child[1];            
            codeGen(lf); 
            node->code = codeFrontDecl(node->scope[0]);
            codeGen(rt);
            if(lf->type == BOOL_T) {
                node->code = strRightCatAlloc(node->code, "",7, 
                    INDENT[node->scope[0]],"if ( ", lf->code, " ){ \n", 
                    rt->code, 
                    INDENT[node->scope[0]]," }// END_IF \n");
            }
            else if (lf->type < 0) { // DYNAMIC
                char * ctmp = tmpAttr();
                node->code = strRightCatAlloc(node->code, "", 17,
                    INDENT[node->scope[0]],"// START_IF\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"if ( ", codeGetAttrVal(ctmp, BOOL_T, node->line), " ) {\n",
                    rt->code,
                    INDENT[node->scope[0]],"} \ndestroy_attr( ", ctmp, " ); // END_IF\n");
            }
            else {
                ERRNO = ErrorIfConditionNotBOOL;
                errorInfo(ERRNO, node->line, "condition in IF statement is NOT of type `bool'.\n"); 
                return ERRNO;
            }
            break;
        case AST_IFELSE_STAT :
            lf = node->child[0]; sg = node->child[1]; rt = node->child[2];
            codeGen(lf); 
            node->code = codeFrontDecl(node->scope[0]);
            codeGen(sg); codeGen(rt);
            if(lf->type == BOOL_T) {
                node->code = strRightCatAlloc(node->code, "",10,
                    INDENT[node->scope[0]],"if ( ", lf->code, " ){ \n",
                    sg->code, 
                    INDENT[node->scope[0]],"else\n", rt->code, 
                    INDENT[node->scope[0]]," }// END_IF\n");
            }
            else if (lf->type < 0) { // DYNAMIC
                char * ctmp = tmpAttr();
                node->code = strRightCatAlloc(node->code, "", 20, 
                    INDENT[node->scope[0]],"// START_IF\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"if ( ", codeGetAttrVal(ctmp, BOOL_T, node->line), " ) {\n",
                    sg->code, 
                    INDENT[node->scope[0]],"} else {\n", rt->code,
                    INDENT[node->scope[0]],"}\ndestroy_attr( ", ctmp, " ); // END_IF\n");
            }
            else {
                ERRNO = ErrorIfConditionNotBOOL;
                errorInfo(ERRNO, node->line, "condition in IF statement is NOT of type `bool'.\n");
                return ERRNO;
            }
            break;
/************************************************************************************/
        case AST_WHILE :                // iteration_statement
            lf = node->child[0]; rt = node->child[1];
            codeGen(lf); 
            node->code = codeFrontDecl(node->scope[0] );
            inLoop++; codeGen(rt); inLoop--;
            if(lf->type>=0){
                node->code = strRightCatAlloc(node->code, "", 7, 
                    INDENT[node->scope[0]],"while ( ", lf->code, " ) {\n",
                    rt->code, INDENT[node->scope[0]], 
                    "} //END_OF_WHILE\n");
            }
            else { // DYNAMIC
                char * ctmp = tmpAttr();
                node->code = strRightCatAlloc(node->code, "", 24,
                    INDENT[node->scope[0]],"// START_OF_WHILE\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"while ( ", codeGetAttrVal(ctmp, BOOL_T,node->line),
                    " ) {\n", rt->code, 
                   // INDENT[node->scope[0]],"destroy_attr( ", ctmp, " );\n",
                    INDENT[node->scope[0]],ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"} \n",
                    INDENT[node->scope[0]],"destroy_attr( ", ctmp, " ); //END_OF_WHILE\n");
            }
            break;
        case AST_FOR : {
            struct Node *f1 = node->child[0],
                        *f2 = node->child[1],
                        *f3 = node->child[2],
                        *fs = node->child[3];
            codeGen(f1);codeGen(f2);codeGen(f3);
            node->code = codeFrontDecl(node->scope[0] );
            inLoop++; codeGen(fs); inLoop--;
            if (f1->type>=0 && f2->type>=0 && f3->type>=0){
                node->code = strRightCatAlloc(node->code, "",10, INDENT[node->scope[0]],
                    "for (", (f1!=NULL)? f1->code : "", ";", 
                             (f2!=NULL)? f2->code : "", ";", 
                             (f3!=NULL)? f3->code : "", ") {\n",
                             fs->code, "} //END_OF_FOR\n");
            }
            else {  // DYNAMIC :: translate for to while
                char * ctmp = tmpAttr();
                node->code = strRightCatAlloc(node->code,"", 33,
                    INDENT[node->scope[0]],"// START_OF_FOR\n",
                    INDENT[node->scope[0]],f1->code,";\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", f2->code, " ;\n", 
                    INDENT[node->scope[0]],"while (", codeGetAttrVal(ctmp, BOOL_T,node->line),
                    " ) {\n", fs->code,
                    INDENT[node->scope[0]],f3->code,";\n",
                    INDENT[node->scope[0]],"destroy_attr( ", ctmp, " );\n",
                    INDENT[node->scope[0]],ctmp, " = ", f2->code, " ;\n",
                    "} \n",
                    INDENT[node->scope[0]],"destroy_attr( ", ctmp, " ); // END_OF_FOR\n"
                );
            }
            break;
        }
        case AST_FOREACH :{
			lf = node->child[0]; sg = node->child[1]; rt = node->child[2];
			inLoop++; codeGen(lf); codeGen(sg); codeGen(rt); inLoop--;
			int ltype = lf->child[1]->type, rtype = sg->type;
			if( ltype==VERTEX_T&&rtype==VLIST_T || ltype==EDGE_T&&rtype==ELIST_T ){
				char* ti = lf->child[1]->symbol->bind;
				char* tlen = strCatAlloc("", 1, tmpVab());
				char* tc = strCatAlloc("", 1, tmpVab());
            	node->code = codeFrontDecl(node->scope[0] );
				node->code = strRightCatAlloc(node->code, "" , 35,
					INDENT[node->scope[0]], sTypeName(ltype), " * ", ti, ";\n",
					INDENT[node->scope[0]], "int ", tlen, " = g_list_length(", sg->code, "->list);\n",
					INDENT[node->scope[0]], "int ", tc, ";\n",
					INDENT[node->scope[0]], "for (", tc, "=0; ", tc, "<", tlen, "; ", tc, "++) {\n",
					INDENT[node->scope[0]], ti, " = g_list_nth_data ( ", sg->code, "->list, ", tc, " );\n",
					rt->code,
				    INDENT[node->scope[0]], "} //END_OF_FOREACH\n");
				free(tlen);free(tc);
				if(sg->tmp[0]==REMOVE_DYN) {
					node->code = strRightCatAlloc(node->code,"", 5,
						INDENT[node->scope[0]], codeFreeFuncName(VLIST_T), " ( ", sg->code, " );\n");
				}
			}
			else {
				ERRNO = ErrorForeachType;
				errorInfo(ERRNO, node->line, "foreach has wrong type\n");
				return ERRNO;
			}

			break;
		}
/************************************************************************************/
        case AST_JUMP_BREAK :           // jump_statement
            if(inLoop==0) {
                ERRNO = ErrorCallBreakOutsideOfLoop;
                errorInfo(ERRNO, node->line, "call `break' outside of loop\n");   
                return ERRNO;
            } else {
                node->code = strCatAlloc("", 2,INDENT[node->scope[0]], "break ;\n");
            }
            break;
        case AST_JUMP_CONTINUE :
            if(inLoop==0) {
                ERRNO = ErrorCallContinueOutsideOfLoop;
                errorInfo(ERRNO, node->line, "call `continue' outside of loop\n");
                return ERRNO;
            } else {
                node->code = strCatAlloc("", 2,INDENT[node->scope[0]], "continue ;\n");
            }
            break;
        case AST_JUMP_RETURN :
            if(inFunc<0) {
                ERRNO = ErrorCallReturnOutsideOfFunc;
                errorInfo(ERRNO, node->line, "call `return' outside of function or function literal\n");
                return ERRNO;
            }
            else {
                int rtype = * (int *) g_list_nth_data ( returnList, inFunc );
                (* (int *) g_list_nth_data ( noReturn, inFunc ) ) ++ ;
                if (node->nch == 0) {
                    if (rtype != VOID_T) {
                        ERRNO = ErrorInvalidReturnType;
                        errorInfo(ERRNO, node->line, "invalid return type.\n");
                        return ERRNO;
                    }
                    node->code = strCatAlloc("", 2,INDENT[node->scope[0]], "return ;\n");
                } 
                else {
                    codeGen(node->child[0]);
                    node->code = codeFrontDecl(node->scope[0] );
                    if (rtype != node->child[0]->type && node->child[0]->type >= 0) {
                        ERRNO = ErrorInvalidReturnType;
                        errorInfo(ERRNO, node->line, "invalid return type.\n");
                        return ERRNO;
                    }
                    else if (rtype == node->child[0]->type && node->child[0]->type >= 0) {
                        node->code = strRightCatAlloc(node->code, "", 4,INDENT[node->scope[0]], "return ",node->child[0]->code,";\n");
                    }
                    else {
                        node->code = strRightCatAlloc(node->code,"", 4, 
                            INDENT[node->scope[0]], "return ",
                            codeGetAttrVal( node->child[0]->code, rtype, node->line ),";\n" ); 
                    }
                }
            }
            break;
        // 1> break continue is in scope of loop    // DONE
        // 2> return is in scope of func, and return type is correct //DONE

/************************************************************************************/
        case AST_FUNC : {                // function_definition
            lf = node->child[0];            // return type
            sg = node->child[1];            // parameter_list
            rt = node->child[2];            // compound_statement
            codeGen(sg); 
            int zero = 0, nort;
            inFunc++; 
            returnList = g_list_append(returnList, (gpointer) & (lf->lexval.ival) ); 
            noReturn = g_list_append( noReturn, (gpointer) &zero);
            codeGen(rt); 
            returnList = g_list_remove(returnList, g_list_nth_data(returnList, inFunc) );
            gpointer gp = g_list_nth_data( noReturn, inFunc );
            nort = *(int *) gp;
            noReturn = g_list_remove( noReturn, gp );
            inFunc--;
            if ( nort <= 0 && lf->lexval.ival != VOID_T ) {
                ERRNO = ErrorNoReturnInFunc;
                errorInfo(ERRNO, node->line, "missing return in function declaration.\n");
                return ERRNO;
            } 
            int flag0 = 0;
            int type0 = lf->lexval.ival;
            if (type0 == VERTEX_T || type0 == EDGE_T || type0 == VLIST_T ||
                    type0 == ELIST_T ||type0 == STRING_T || type0 == GRAPH_T) flag0 = 1;
            node->code = strCatAlloc("",9,
                    sTypeName(lf->lexval.ival),(flag0)? " * ":" ",
                    node->symbol->bind,     // func_id
                    " ( ", sg->code," ) ", "{\n",
                    rt->code, "}\n");
            //showASTandST(node,"Function Definition");
            break;
        }
        case FUNC_LITERAL :             // function_literal_declaration
            lf = node->child[1];            // return type
            sg = node->child[0];            // parameter_list
            rt = node->child[2];            // compound_statement
            codeGen(sg); 
            int zero = 0, nort;
            inFunc++;
            returnList = g_list_append(returnList, (gpointer) & (lf->lexval.ival) );
            noReturn = g_list_append( noReturn, (gpointer) &zero); 
            codeGen(rt); 
            returnList = g_list_remove(returnList, g_list_nth_data(returnList, inFunc) );
            gpointer gp = g_list_nth_data( noReturn, inFunc );
            nort = *(int *) gp;
            noReturn = g_list_remove( noReturn, gp );
            inFunc--;
            if ( nort <= 0 && lf->lexval.ival != VOID_T ) {
                ERRNO = ErrorNoReturnInFunc;
                errorInfo(ERRNO, node->line, "missing return in function literal declaration.\n");
                return ERRNO;
            }
            //    put code to node->codetmp, as we need put all func_literals in
            // the external in target code.
            node->code = NULL;
            node->codetmp = strCatAlloc("", 10,
                    sTypeName(lf->lexval.ival)," ",
                    node->symbol->bind,
                    " ( void * _obj, int _obj_type",
                    (sg->nch==1) ? "" : " , ",
                     sg->code, " ) ", "{\n",
                    rt->code, "}  // END_OF_FUNC_LITERAL\n");
            break;
/************************************************************************************/
        case AST_FUNC_DECLARATOR :
            // here only create parameter list
            if(node->nch==1) // empty list
                node->code = strCatAlloc("",1,"");
            else {
                sg = node->child[1];
                codeGen(sg);
                node->code = strCatAlloc("",1,sg->code);
            }
            break;
        case AST_PARA_DECLARATION :
            lf = node->child[0];            // declaration_specifiers
            rt = node->child[1];            // IDENTIFIER or attribute
            codeGen(rt);
            node->type = node->child[0]->lexval.ival;
            if (node->type == STRING_T || node->type == VLIST_T || node->type == ELIST_T ||
                node->type == VERTEX_T || node->type == EDGE_T || node->type == GRAPH_T)
                    node->code = strCatAlloc("",3,sTypeName(lf->lexval.ival)," * ", node->child[1]->code);
            else if (node->type == BOOL_T || node->type == INT_T || node->type == FLOAT_T)
                node->code = strCatAlloc("", 3, sTypeName(lf->lexval.ival)," ", node->child[1]->code );
            else {
                ERRNO = ErrorWrongArgmentType;
                errorInfo(ERRNO, node->line, "invalid argument type.\n");
                return ERRNO;
            }    
            break;
/************************************************************************************/
	    case AST_PRINT_STAT :
            codeGen(node->child[0]);
            node->code = strCatAlloc("", 1, node->child[0]->code);
            break;
        case AST_PRINT_COMMA :
            codeGen(node->child[0]);
            codeGen(node->child[1]);
            node->code = strCatAlloc("", 2, node->child[0]->code, node->child[1]->code);
            break;
	    case AST_PRINT : {
            codeGen(node->child[0]);
            int tt = node->child[0]->type;
            if ( tt >= 0 ) {
                node->code = strCatAlloc("", 6,
                    INDENT[node->scope[0]], "print_", typeMacro(tt), " ( ",
                        node->child[0]->code, " );\n");
            }
            else if ( tt < 0 ) {
                node->code = strCatAlloc("", 4,
                    INDENT[node->scope[0]], "print_attr ( ", 
                        node->child[0]->code, " );\n");
            }
            break;
	    }
/************************************************************************************/
	    case AST_READ_GRAPH:        // FILE >> Graph
		    lf=node->child[0];
		    rt=node->child[1];
            codeGen(lf); codeGen(rt);
            if ( lf->type == STRING_T && rt->type == GRAPH_T ) {
                char * tg = tmpGraphVab();
                node->code = strCatAlloc("", 10,
                    INDENT[node->scope[0]], codeFreeFuncName(GRAPH_T), "( ", rt->code, " );\n",
                    INDENT[node->scope[0]], rt->code, " = readGraph( ", lf->code, "->str );\n"
                ); 
            }
            else {
                ERRNO = ErrorTypeMisMatch;
                errorInfo(ERRNO, node->line, "expected `FILE:STRING' to be fetched from `GRAPH' file location.\n" );	
            }
		    break;
	    case AST_WRITE_GRAPH:       // FILE << Graph
            lf=node->child[0];
            rt=node->child[1];
            codeGen(lf); codeGen(rt);
            if ( lf->type == STRING_T && rt->type == GRAPH_T ) {
                node->code = strCatAlloc("", 6,
                    INDENT[node->scope[0]], "saveGraph( ", rt->code, " , (", lf->code,")->str );\n"
                );
            }
            else {
                ERRNO = ErrorTypeMisMatch;
                errorInfo(ERRNO, node->line, "expected `FILE:STRING' to be written into `GRAPH' file location.\n");
                        
            }
            break;		
/************************************************************************************/
        default:
            if(node->code == NULL) {
#ifdef _DEBUG
                debugInfo("Warning: No code generated on ");
                astOutNode(node, DEBUGIO,"\n");
#endif
            }
    }
    return 0;
}

int codeAllGen(struct Node* node, char ** mainCode, char ** funCode) {
    if(node->token == AST_EXT_STAT_COMMA) {
        codeAllGen(node->child[0], mainCode, funCode);
        codeAllGen(node->child[1], mainCode, funCode);
    }
    else if(node->token == AST_FUNC) {  // merge in funCode
        codeGen(node);
        *funCode = strRightCatAlloc( *funCode, "", 2, node->code,"\n" );
    }
    else { // merge in mainCode
        codeGen(node);
        *mainCode = strRightCatAlloc( *mainCode, "", 1, node->code );
    }

    return 0;
}

void codeAllFuncLiteral(struct Node* node, char ** code) {
    // travel the entire tree, get all func_literals
    if (node==NULL) return;
    if (node->token == FUNC_LITERAL ||
            node->token == AST_MATCH ) {
        *code = strRightCatAlloc( *code, "", 2, node->codetmp, "\n");
        // DO NOT return, for nested Func_Literal
        //if (node->token == FUNC_LITERAL) return;
    }
    int i;
    for (i=0; i<node->nch; ++i) {
        codeAllFuncLiteral(node->child[i], code);
    }
    return;
}

void codeInclude(char ** code) {
    *code = strRightCatAlloc( *code, "" ,3 ,
        "#include \"Derivedtype.h\"\n",
        "#include \"NSBLio.h\"\n",
        "#include \"FileReadWrite.h\"\n");
}

void codeAllGlobal(struct Node* node, char ** code) {
    // travel the entire tree, get all declaration in scope level 0
    if (node==NULL) return;
    if (node->token == AST_DECLARATION) {
        if (node->scope[0] == 0)
            *code = strRightCatAlloc( *code, "", 1, node->codetmp);
        return;
    }
    int i;
    for (i=0; i<node->nch; ++i) {
        codeAllGlobal(node->child[i], code);
    }
    return;
}

char * wapperMainCode(char * mainBodyCode){
    char * head = "int main() {\n\n";
    //char * freecode = allFreeCodeInScope( 0, NULL, 0 );
#ifdef _DEBUG
    //debugInfo("MainFreeCode:\n");
    //debugInfoExt("%s",freecode);
#endif
    //char * freecode = NULL;
    char * end = "\n} // END_OF_MAIN \n";
    return strCatAlloc("",3,head,mainBodyCode, end);
}

void exportCode(char * code){
    fprintf(OUTFILESTREAM,"%s",code);
}


