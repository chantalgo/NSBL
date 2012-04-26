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

char * OUTFILE; 
FILE * OUTFILESTREAM;           // Output file

int  inLoop, inFunc;            // flags to indicate inside of loop or func
int  inMATCH, exsitMATCH, nMATCHsVab;
GList *returnList, *noReturn;
char * matchStaticVab, *matchStrDecl;

void derivedTypeInitCode(struct Node* node, int type, int isglobal){
	if(node->token == AST_COMMA){
		derivedTypeInitCode(node->child[0], type, isglobal);
		derivedTypeInitCode(node->child[1], type, isglobal);
    	node->code = strCatAlloc("",2, node->child[0]->code, node->child[1]->code);
	}else{
		switch(type){
			case GRAPH_T:
				if(isglobal)
					node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = new_graph();\n"); 
				else
					node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), " ", node->symbol->bind, " = new_graph();\n");
				break;
			case VERTEX_T:
				if(isglobal)
					node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = new_vertex();\n"); 
				else
					node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), " ", node->symbol->bind, " = new_vertex();\n");
				break;
			case EDGE_T:
				if(isglobal)
					node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = new_edge();\n"); 
				else
					node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), " ", node->symbol->bind, " = new_edge();\n");
				break;
			default:
				break;
		}
	}
}

void stringInitCode(struct Node* node, int type, int isglobal){
	if(node->token == AST_COMMA){
		stringInitCode(node->child[0], type, isglobal);
		stringInitCode(node->child[1], type, isglobal);
		node->code = strCatAlloc("", 2, node->child[0]->code, node->child[1]->code);
	}else if(node->token == AST_ASSIGN){
		if(isglobal)
			node->code = strCatAlloc("",5,INDENT[node->scope[0]], node->child[0]->symbol->bind, " = g_string_new(", node->child[1]->code, ");\n"); 
		else
			node->code = strCatAlloc("",7,INDENT[node->scope[0]], sTypeName(type), " ", node->child[0]->symbol->bind, " = new_vertex(", node->child[1]->code, ");\n");	
	}else{
		if(isglobal)
			node->code = strCatAlloc("",3,INDENT[node->scope[0]], node->symbol->bind, " = g_string_new(\"\");\n"); 
		else
			node->code = strCatAlloc("",5,INDENT[node->scope[0]], sTypeName(type), " ", node->symbol->bind, " = g_string_new(\"\");\n");
	}
}

int listInitCode(struct Node* node, int type, int isglobal){
	int etype = UNKNOWN_T;
	char buffer[20];
	int count = 0;
	struct Node* tn = node->child[1];
	if(tn->token != AST_LIST_INIT)
		return ErrorAssignmentExpression;

	if(tn->child!=NULL){
		count++;
		tn = tn->child[0];
		if(tn->token == IDENTIFIER)
			etype = tn->type;
		else{
			etype = tn->child[1]->type;
			while(tn->token == AST_COMMA){
				count++;
				if(tn->child[1]->type != etype)
					return ErrorListMixedType;
				tn = tn->child[0];
			}
		}
	}
	sprintf(buffer, "%d", count);
	if(isglobal){
		switch(etype){
			case -1:
				node->code = strCatAlloc("", 5, INDENT[node->scope[0]], node->child[0]->symbol->bind, " = list_declaration(UNKNOWN_T, ", buffer, ");\n"); 
				break;
			case VERTEX_T:
				node->code = strCatAlloc("", 7, INDENT[node->scope[0]], node->child[0]->symbol->bind, " = list_declaration(VERTEX, ", buffer, ", ",node->child[1]->child[0]->code, ");\n");
				break;
			case EDGE_T:
				node->code = strCatAlloc("", 7, INDENT[node->scope[0]], node->child[0]->symbol->bind, " = list_declaration(EDGE, ", buffer, ", ",node->child[1]->child[0]->code, ");\n");
				break;
			default:
				break;
		}
	}else{
		switch(etype){
			case -1:
				node->code = strCatAlloc("", 7, INDENT[node->scope[0]], sTypeName(type), " ", node->child[0]->symbol->bind, " = list_declaration(-1, ", buffer, ");\n"); 
				break;
			case VERTEX_T:
				node->code = strCatAlloc("", 9, INDENT[node->scope[0]], sTypeName(type), " ", node->child[0]->symbol->bind, " = list_declaration(VERTEX, ", buffer, ", ",node->child[1]->code, ");\n");
				break;
			case EDGE_T:
				node->code = strCatAlloc("", 9, INDENT[node->scope[0]], sTypeName(type), " ", node->child[0]->symbol->bind, " = list_declaration(EDGE, ", buffer, ", ",node->child[1]->code, ");\n");
				break;
			default:
				break;
		}
	}
	return 0;
}

int existbelong(struct Node* node){
	if(node == NULL)
		return 0;
	if(node->token == BELONG)
		return 1;
	if(node->child == NULL)
		return 0;
	return (existbelong(node->child[0]) || existbelong(node->child[1]));
}

int attributeDeclareCode(struct Node* node, int type){
	int err = 0;
    // First generate code for BELONG
    codeGen(node->child[0]);
    // Then generate declaration
	switch(type){
		case INT_T:
			if(node->child[1]->type == FLOAT_T)
				node->code = strCatAlloc("", 16 , 
                    INDENT[node->child[0]->child[0]->scope[0]], 
                    "{ ",
                    sTypeName(type), 
                    " ", 
                    node->child[0]->child[1]->code, 
                    " = ", 
                    "(int)",            // type conversion : FLOAT ==> INT 
                    node->child[1]->code, 
                    "; ",
                    "vertex_assign_attribute(", 
                    node->child[0]->child[0]->symbol->bind, 
                    ", \"", 
                    node->child[0]->child[1]->code, 
                    "\", &", 
                    node->child[0]->child[1]->code, 
                    ", INT); }\n"
                );
			else if(node->child[1]->type == INT_T)
                node->code = strCatAlloc("",15 ,
                    INDENT[node->child[0]->child[0]->scope[0]], 
                    "{ ",
                    sTypeName(type), 
                    " ", 
                    node->child[0]->child[1]->code, 
                    " = ", 
                    node->child[1]->code, 
                    "; ",
                    "vertex_assign_attribute(", 
                    node->child[0]->child[0]->symbol->bind, 
                    ", \"", 
                    node->child[0]->child[1]->code, 
                    "\", &", 
                    node->child[0]->child[1]->code, 
                    ", INT); }\n"
                );

			else
				err = ErrorTypeMisMatch;		
			break;
		case FLOAT_T:
			if(node->child[1]->type == INT_T)
                node->code = strCatAlloc("", 16 ,
                    INDENT[node->child[0]->child[0]->scope[0]],
                    "{ ",
                    sTypeName(type),
                    " ",
                    node->child[0]->child[1]->code,
                    " = ",
                    "(float)",            // type conversion : INT ==> FLOAT
                    node->child[1]->code,
                    "; ",
                    "vertex_assign_attribute(",
                    node->child[0]->child[0]->symbol->bind,
                    ", \"",
                    node->child[0]->child[1]->code,
                    "\", &",
                    node->child[0]->child[1]->code, 
                    ", FLOAT); }\n"
                );
			else if(node->child[1]->type == FLOAT_T)
                node->code = strCatAlloc("", 15 ,
                    INDENT[node->child[0]->child[0]->scope[0]],
                    "{ ",
                    sTypeName(type),
                    " ",
                    node->child[0]->child[1]->code,
                    " = ", 
                    node->child[1]->code,
                    "; ",
                    "vertex_assign_attribute(",
                    node->child[0]->child[0]->symbol->bind,
                    ", \"",
                    node->child[0]->child[1]->code,
                    "\", &",
                    node->child[0]->child[1]->code,
                    ", FLOAT); }\n"
                );
			else
				err = ErrorTypeMisMatch;
			break;
		case STRING_T:
			if(node->child[1]->type == STRING_T)
                node->code = strCatAlloc("", 15 ,
                    INDENT[node->child[0]->child[0]->scope[0]],
                    "{ ",
                    sTypeName(type),
                    " ",
                    node->child[0]->child[1]->code,
                    " = g_string_new(", 
                    node->child[1]->code,
                    "); ",
                    "vertex_assign_attribute(",
                    node->child[0]->child[0]->symbol->bind,
                    ", \"",
                    node->child[0]->child[1]->code,
                    "\", ",
                    node->child[0]->child[1]->code,
                    "->str, STRING); }\n"
                );
			else
				err = ErrorTypeMisMatch;
			break;
		default:
			break;
	}
    if(err) {
        errorInfo(err, node->line, "Type Mismatch for the assignment\n");
    }
	return err;
}

// not used, JZ 
char * codeForFreeDerivedVabInScope(ScopeId sid, int type, GList * gl, ScopeId lvl){
    GList * vals = sTableAllVarScope( sid, type );
    char * code = NULL, * freefunc = codeFreeFuncName(type);
    int i, l = g_list_length( vals );
    SymbolTableEntry * e;
#ifdef _DEBUG
    int ll = g_list_length( gl );
    debugInfo("codeForFreeDerivedVabInScope: sid=%d, type=%d, l=%d, ll=%d\n", sid,type,l,ll);
    if(ll>0) {
        int i;
        for (i=0; i<ll; ++i) {
            e = (SymbolTableEntry *) g_list_nth_data( gl, i );
            debugInfoExt("      gl[%d] ==> %s\n", i, e->bind);
        }
    }
#endif
    for ( i=0; i<l; ++i ){
        e = (SymbolTableEntry *) g_list_nth_data( vals, i );
        if( g_list_find( gl, (gpointer) e ) == NULL )
            code = strRightCatAlloc( code, "", 5, INDENT[lvl], freefunc, "( ", e->bind, " );\n" );
    }
    g_list_free( vals );
    return code;
}

// not used, JZ
char * allFreeCodeInScope(ScopeId sid, GList * gl, ScopeId lvl) {
    char * sc = codeForFreeDerivedVabInScope( sid, STRING_T, gl, lvl );
    char * vc = codeForFreeDerivedVabInScope( sid, VERTEX_T, gl, lvl );
    char * ec = codeForFreeDerivedVabInScope( sid, EDGE_T, gl, lvl );
    char * gc = codeForFreeDerivedVabInScope( sid, GRAPH_T, gl, lvl );
    char * lc = codeForFreeDerivedVabInScope( sid, LIST_T, gl, lvl );

    return strCatAlloc("", 5, sc, vc, ec, gc, lc );
}

// not used, JZ
GList * getAllParaInFunc(struct Node * node, GList * gl) {
    if (node ==NULL) return gl;
    else if (node->token == AST_COMMA) {
        gl = getAllParaInFunc(node->child[0], gl);
        gl = getAllParaInFunc(node->child[1], gl);
    }
    else if (node->token == AST_PARA_DECLARATION) {
        gl = g_list_append( gl, node->child[1]->symbol );
    }
    else {
        fprintf(stderr, "getAllParaInFunc: unknow node %d !!!!!!!!!!\n", node->token);
    }
    return gl;
}

// not used, JZ
GList * getReturnVab( struct Node * node, GList * gl) {
    if (node == NULL) return gl;
    else if (node->token == AST_JUMP_RETURN) {
        if (node->nch!=0) {
            gl = g_list_append( gl, node->child[0]->symbol );
        }
        return gl;
    }
    
    int i;
    for (i=0; i<node->nch; ++i) {
        gl = getReturnVab( node->child[i], gl );
    }
    return gl;
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
    else if (node->token == BELONG) {
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

char * codeGetAttrVal( char * operand, int type ) {
    return strCatAlloc("",7 , " *(", sTypeName(type),
        " *) get_attr_value( ", operand, " , ", typeMacro(type), " ) " );
}

char * codeFrontDecl(int lvl ) {
    char * decl = NULL;
    if(exsitMATCH == 1){ // for MATCH
       decl = strRightCatAlloc(decl, "", 2,INDENT[lvl],matchStrDecl);
       free(matchStrDecl); matchStrDecl= NULL;
       exsitMATCH = 0;
    }
    return decl;
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
                    node->code = strCatAlloc("",1,node->symbol->bind);
                    node->codetmp = strCatAlloc("",1,node->symbol->bind);
                }
                else{
                    node->code = strCatAlloc("",3,"_str->",node->symbol->bind,"_match");
                    node->codetmp = strCatAlloc("",1,node->code);
                    matchStaticVab = strRightCatAlloc( matchStaticVab, "", 5, 
                        INDENT[1], sTypeName(node->type)," ",node->symbol->bind,"_match;\n");
                    matchStrDecl = strRightCatAlloc( matchStrDecl, "", 2,
                        (nMATCHsVab++==0) ? "" : " , ",
                        node->symbol->bind);
                }
            }
            else
                ERRNO = ErrorNoBinderForId;
            break;
        case DYN_ATTRIBUTE :
            node->code = strCatAlloc("",4,
                "object_get_attribute( _obj, _obj_type, ", 
                "\"::",node->lexval.sval, "\" ) ");
            break;
        case BELONG :
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

			node->type = LIST_T;
			if(node->child==NULL)
				node->code = strCatAlloc("", 1, " ");
			else{
				lf = node->child[0];
				codeGen(lf);
				node->code = strCatAlloc("", 1, lf->code);
			}
			break;
        case AST_TYPE_SPECIFIER :
            node->code = strCatAlloc(" ",1,sTypeName(node->lexval.ival));
            break;
        case AST_DECLARATION :
            codeGen( node->child[0] );codeGen( node->child[1] );
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
						node->code = strCatAlloc("", 1, node->child[1]->code);
						break;
					case STRING_T:
						if(node->child[1]->child!=NULL && node->child[1]->child[0]->token == BELONG){
							int rv = attributeDeclareCode(node->child[1], node->child[0]->lexval.ival);
							if(rv!=0){
								ERRNO = rv;
								return ERRNO;
							}
							node->code = strCatAlloc("", 1, node->child[1]->code);
							node->codetmp = NULL;
						}else if(existbelong(node->child[1])){
							ERRNO = ErrorAttributeDeclaration;
							return ERRNO;
						}else{
							stringInitCode(node->child[1], node->child[0]->lexval.ival, 1);
							node->code = strCatAlloc("", 1, node->child[1]->code);
						}
						break;
					case LIST_T:
						if(node->child[1]->token!=AST_ASSIGN){
							ERRNO = ErrorDerivedTypeDeclaration;
							return ERRNO;
						}else{
							int r = listInitCode(node->child[1], node->child[0]->lexval.ival, 1);
							if(r){
								ERRNO = r;

								return ERRNO;
							}
							node->code = strCatAlloc("", 1, node->child[1]->code);
						}
						break;

					default:
						if(node->child[1]->child!=NULL && node->child[1]->child[0]->token == BELONG){
							int rv = attributeDeclareCode(node->child[1], node->child[0]->lexval.ival);
							if(rv!=0){
								ERRNO = rv;
								return ERRNO;
							}
							node->code = strCatAlloc("", 1, node->child[1]->code);
							node->codetmp = NULL;
						}else if(existbelong(node->child[1])){

							ERRNO = ErrorAttributeDeclaration;
							return ERRNO;
						}else
               				node->code = strCatAlloc("",3,INDENT[node->scope[0]],node->child[1]->code,";\n");
						break;
				}
            }
            // If scope > 0, no bother, just declaration everything in one c declaration
            else {
				switch(node->child[0]->lexval.ival){
					case GRAPH_T:
					case VERTEX_T:
					case EDGE_T:
						derivedTypeInitCode(node->child[1], node->child[0]->lexval.ival, 0);
						node->code = strCatAlloc("", 1, node->child[1]->code);
						break;
					case STRING_T:
						if(node->child[1]->child!=NULL && node->child[1]->child[0]->token == BELONG){
							int rv = attributeDeclareCode(node->child[1], node->child[0]->lexval.ival);
							if(rv != 0){
								ERRNO = rv;
								return ERRNO;
							}
							node->code = strCatAlloc("", 1, node->child[1]->code);
							node->codetmp = NULL;
						}else if(existbelong(node->child[1])){
							ERRNO = ErrorAttributeDeclaration;
							return ERRNO;
						}else{
							stringInitCode(node->child[1], node->child[0]->lexval.ival, 0);
							node->code = strCatAlloc("", 1, node->child[1]->code);
						}
						break;
					case LIST_T:
						if(node->child[1]->token!=AST_ASSIGN){
							ERRNO = ErrorDerivedTypeDeclaration;
							return ERRNO;
						}else{
							int r = listInitCode(node->child[1], node->child[0]->lexval.ival, 0);
							if(r){
								ERRNO = r;
								return ERRNO;
							}
							node->code = strCatAlloc("", 1, node->child[1]->code);
						}
						break;
					default:
						if(node->child[1]->child!=NULL && node->child[1]->child[0]->token == BELONG){
							int rv = attributeDeclareCode(node->child[1], node->child[0]->lexval.ival);
							if(rv != 0){
								ERRNO = rv;
								return ERRNO;
							}
							node->code = strCatAlloc("", 1, node->child[1]->code);
							node->codetmp = NULL;
						}else if(existbelong(node->child[1])){
							ERRNO = ErrorAttributeDeclaration;
							return ERRNO;
						}else
                			node->code = strCatAlloc("",5,INDENT[node->scope[0]],node->child[0]->code," ",node->child[1]->code,";\n");
						break;
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
        //case ADD_ASSIGN :                 // not supported, JZ
        //case SUB_ASSIGN :   
        //case MUL_ASSIGN :  
        //case DIV_ASSIGN : 
            lf =  node->child[0]; rt = node->child[1];
            if(existbelong(lf)) {
                codeGen(rt);
				break;
            }
			codeGen(lf);codeGen(rt);
            // type check and implicit type conversion
            if(lf->type == rt->type && lf->type>=0 ) {
                // int float support : = += -= *= /=,  not supported, JZ
                if ( lf->type == INT_T || lf->type == FLOAT_T || lf->type == BOOL_T ) {
                    node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
                    node->type = lf->type;
                }
                else if ( lf->type == STRING_T || lf->type == LIST_T || 
                            lf->type == VERTEX_T || lf->type == EDGE_T || 
                                lf->type == GRAPH_T ){
                    char * func = assignFunc(lf->type);
                    node->code = strCatAlloc("", 6,
                        func, " ( ", lf->code, " , ",
                        rt->code, " ) " 
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
                        " , (void *) ", lf->code,  
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
			else if(lf->type==GRAPH_T && rt->type==LIST_T){
				node->code = strCatAlloc("", 5, "g_append_list(", lf->code, ", ", rt->code, ")");
			}
			else if(lf->type==LIST_T && rt->type==VERTEX_T){
				node->code = strCatAlloc("", 5, "list_append(", lf->code, ", VERTEX_T, ", rt->code, ")");
			}
			else if(lf->type==LIST_T && rt->type==EDGE_T){
				node->code = strCatAlloc("", 5, "list_append(", lf->code, ", EDGE_T, ", rt->code, ")");
			}else{
				ERRNO = ErrorAssignmentExpression;
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
            break;
/************************************************************************************/
        case AST_FUNC_CALL :
            // 1> create type constructor for input parameters
            if(node->nch == 1){ 
                node->typeCon = astTypeConArgList(NULL, NULL);
            }
            else {
                codeGen(node->child[1]);
                node->typeCon = astTypeConArgList(node->child[1], NULL);
            }
            // 2> lookup symbol table, also set type
            errflag = sTableLookupFunc(node);
            // 3> clear up
            astFreeTypeCon(node->typeCon);
            // 4> code Gen
            if(!errflag) {
                if(node->symbol->type == FUNC_LITERAL_T && inMATCH > 0) {
                    if(node->nch == 1)
                        node->code = strCatAlloc("",2,node->symbol->bind, " ( _obj, _objtype )" );
                    else
                        node->code = strCatAlloc("",4,node->symbol->bind, " ( _obj, _objtype, ",
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
        case PIPE :
            break;
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
            if(lf->type != LIST_T) {
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
            exsitMATCH = 1;
            // DYNAMIC : get attr val
            if(rt->type < 0) {
                char * ctmp = rt->code;
                rt->code = codeGetAttrVal( rt->code,  BOOL_T );
                free(ctmp);
            }
            // first generate struct and func for this match 
            node->codetmp = strCatAlloc("", 15,
                "struct {\n",
                matchStaticVab,
                "} ", match_str, ";\n",
                "bool ", tmpfunc, 
                " ( void * _obj, int _obj_type, struct ", match_str, " * _str ) {\n",
                INDENT[1], "return ", rt->code, " ;\n",
                "} // END_MATCH_FUNC \n"
            );
            free(matchStaticVab); matchStaticVab =NULL;
            // code for match body
            node->code = strCatAlloc("", 8,
                "list_match( ", lf->code, " , &" , tmpfunc, " , &", match_str_val, 
                (lf->tmp[0]==REMOVE_DYN) ? " , FLAG_DESTROY_ATTR" : " , FLAG_KEEP_ATTR",
                " )"
            );  
            node->type = LIST_T;
            node->tmp[0] = REMOVE_DYN; 
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
                        " ", node->child[0]->symbol->bind,"_match;\n");
                matchStrDecl = strRightCatAlloc( matchStrDecl, "", 2,
                    (nMATCHsVab++==0) ? "" : " , ",
                    node->child[0]->symbol->bind);
            }
            node->child[1]->code = strCatAlloc("", 1, node->child[1]->lexval.sval); 
            if(node->child[0]->type == VERTEX_T ) 
                node->code = strCatAlloc("", 5, "vertex_get_attribute( ",
                    node->child[0]->code, " ,  \"", node->child[1]->code, "\" )");
            else if(node->child[0]->type == EDGE_T )
                node->code = strCatAlloc("", 5, "edge_get_attribute( ",
                    node->child[0]->code, " ,  \"", node->child[1]->code, "\" )");
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
                    INDENT[node->scope[0]],"if ( ", lf->code, " ) \n", 
                    rt->code, 
                    INDENT[node->scope[0]]," // END_IF \n");
            }
            else if (lf->type < 0) { // DYNAMIC
                char * ctmp = tmpAttr();
                node->code = strRightCatAlloc(node->code, "", 17,
                    INDENT[node->scope[0]],"// START_IF\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"if ( ", codeGetAttrVal(ctmp, BOOL_T), " ) \n",
                    rt->code,
                    INDENT[node->scope[0]],"destory_attr( ", ctmp, " ); // END_IF\n");
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
                    INDENT[node->scope[0]],"if ( ", lf->code, " ) \n",
                    sg->code, 
                    INDENT[node->scope[0]],"else\n", rt->code, 
                    INDENT[node->scope[0]]," // END_IF\n");
            }
            else if (lf->type < 0) { // DYNAMIC
                char * ctmp = tmpAttr();
                node->code = strRightCatAlloc(node->code, "", 20, 
                    INDENT[node->scope[0]],"// START_IF\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"if ( ", codeGetAttrVal(ctmp, BOOL_T), " ) \n",
                    sg->code, 
                    INDENT[node->scope[0]],"else\n", rt->code,
                    INDENT[node->scope[0]],"destory_attr( ", ctmp, " ); // END_IF\n");
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
                node->code = strRightCatAlloc(node->code, "", 28,
                    INDENT[node->scope[0]],"// START_OF_WHILE\n",
                    INDENT[node->scope[0]],"Attribute* ", ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"while ( ", codeGetAttrVal(ctmp, BOOL_T),
                    " ) {\n", rt->code, 
                    INDENT[node->scope[0]],"destory_attr( ", ctmp, " );\n",
                    INDENT[node->scope[0]],ctmp, " = ", lf->code, " ;\n",
                    INDENT[node->scope[0]],"} \n",
                    INDENT[node->scope[0]],"destory_attr( ", ctmp, " ); //END_OF_WHILE\n");
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
                    INDENT[node->scope[0]],"while (", codeGetAttrVal(ctmp, BOOL_T),
                    " ) {\n", fs->code,
                    INDENT[node->scope[0]],f3->code,";\n",
                    INDENT[node->scope[0]],"destory_attr( ", ctmp, " );\n",
                    INDENT[node->scope[0]],ctmp, " = ", f2->code, " ;\n",
                    "} \n",
                    INDENT[node->scope[0]],"destory_attr( ", ctmp, " ); // END_OF_FOR\n"
                );
            }
            break;
        }
        case AST_FOREACH :
            break;
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
                            codeGetAttrVal( node->child[0]->code, rtype ),";\n" ); 
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
            // We need to find out all parameters and return type, which should NOT be free
            //GList* exVab = getAllParaInFunc(sg->child[1], NULL);
            //exVab = getReturnVab(rt, exVab);
            // generate freecode
            //char * freecode = allFreeCodeInScope(rt->scope[1], exVab, rt->scope[0] );
            //g_list_free(exVab);
            // generate all
            node->code = strCatAlloc("",9,
                    sTypeName(lf->lexval.ival)," ",
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
            node->code = strCatAlloc(" ",2,
                    sTypeName(lf->lexval.ival),
                    rt->code);
            break;
/************************************************************************************/
	case AST_PRINT_STAT :
            codeGen(node->child[0]);
            break;
	case AST_PRINT :
	    {switch(node->child[0]->type)
		{
	    	case INT_T:
			{printFunc=" printInteger("; 
			var=node->child[0]->symbol->bind;
			endBrace=");\n";
			printCall = malloc(strlen(printFunc) + strlen(var) + strlen(endBrace) + 3);
			strcpy(printCall, printFunc);
			strcat(printCall, var);
			strcat(printCall, endBrace);
			if(node->nch == 1){ 
	    			node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
            		}
            		else {
                		node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
				codeGen(node->child[1]);
		       	}
            		break;}
	    	case FLOAT_T:
                        {printFunc=" printFloat(";
                        var=node->child[0]->symbol->bind;
                        endBrace=");\n";
                        printCall = malloc(strlen(printFunc) + strlen(var) + strlen(endBrace) + 3);
			strcpy(printCall, printFunc);
			strcat(printCall, var);
			strcat(printCall, endBrace);
	    		if(node->nch == 1){ 
	    			node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
            		}
            		else {
                		node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);		
	    			codeGen(node->child[1]);
            		}
            		break;}
	    	case GRAPH_T:
                        {printFunc=" print_g(";
                        var=node->child[0]->symbol->bind;
                        endBrace=");\n";
                        printCall = malloc(strlen(printFunc) + strlen(var) + strlen(endBrace) + 3);
                        strcpy(printCall, printFunc);
                        strcat(printCall, var);
                        strcat(printCall, endBrace);
                         if(node->nch == 1){
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                        }
                        else {
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                                codeGen(node->child[1]);
                        }
                        break;}
		case VERTEX_T:
                        {printFunc=" print_v(";
                        var=node->child[0]->symbol->bind;
                        endBrace=");\n";
			printVattr=" print_v_attr(";
			printCall = malloc(strlen(printFunc) + 2*(strlen(var) + strlen(endBrace)) + strlen(printVattr) + 6);
                        strcpy(printCall, printFunc);
                        strcat(printCall, var);
                        strcat(printCall, endBrace);
			strcat(printCall, printVattr);
			strcat(printCall, var);
			strcat(printCall, endBrace);
                         if(node->nch == 1){
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                        }
                        else {
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                                codeGen(node->child[1]);
                        }
                        break;}

		case EDGE_T:
			{printFunc=" print_e(";
                        var=node->child[0]->symbol->bind;
                        endBrace=");\n";
                        printVattr=" print_e_attr(";
                        printCall = malloc(strlen(printFunc) + 2*(strlen(var) + strlen(endBrace)) + strlen(printVattr) + 6);
                        strcpy(printCall, printFunc);
                        strcat(printCall, var);
                        strcat(printCall, endBrace);
                        strcat(printCall, printVattr);
                        strcat(printCall, var);
                        strcat(printCall, endBrace);
                         if(node->nch == 1){
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                        }
                        else {
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                                codeGen(node->child[1]);
                        }
                        break;}
		case STRING_T:
                        {printFunc=" printString(";
                        var=node->child[0]->symbol->bind;
                        endBrace=");\n";
                        printCall = malloc(strlen(printFunc) + strlen(var) + strlen(endBrace) + 3);
                        strcpy(printCall, printFunc);
                        strcat(printCall, var);
                        strcat(printCall, endBrace);
                        if(node->nch == 1){
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                        }
                        else {
                                node->code = strCatAlloc(" ",3,INDENT[node->child[0]->scope[0]], " ",  printCall);
                                codeGen(node->child[1]);
                        }
                        break;}
		//default:
			//printf("This is default\n");
				//break;


	}
	break;}
/************************************************************************************/
	case AST_READ_GRAPH:
		lf=node->child[0];
		rt=node->child[1];
		if (lf->type==GRAPH_T && rt->type==STRING_T)
		{
			printFunc=" = readGraph(";
                        var=rt->symbol->bind;
                        endBrace=");\n";
                        printCall = malloc(strlen(printFunc) + strlen(var) + strlen(endBrace) + 3);
                        strcpy(printCall, printFunc);
			strcat(printCall, var);
			strcat(printCall, endBrace);
			node->code =  strCatAlloc(" ",2,lf->symbol->bind,printCall);
		}
            	else {
                	ERRNO = ErrorTypeMisMatch;
                	errorInfo(ERRNO, node->line, "expected `%s' to be fetched from `%s' file location\n", sTypeName(lf->type), sTypeName(rt->type) );
                	
            	}
		break;
	case AST_WRITE_GRAPH:
                lf=node->child[0];
                rt=node->child[1];
                if (lf->type==GRAPH_T && rt->type==STRING_T)
                {
                        printFunc=" = saveGraph(";
                        var=lf->symbol->bind;
                        endBrace=");\n";
			fileloc=rt->symbol->bind;
			comma=", ";
                        printCall = malloc(strlen(printFunc) + strlen(var) + strlen(endBrace) + strlen(comma) + strlen(fileloc) + 3);
                        strcpy(printCall, printFunc);
                        strcat(printCall, var);
                        strcat(printCall, comma);
			strcat(printCall, fileloc);
			strcat(printCall, endBrace);
                
                        node->code =  strCatAlloc(" ",1,printCall);
                }
                else {
                        ERRNO = ErrorTypeMisMatch;
                        errorInfo(ERRNO, node->line, "expected `%s' to be written into `%s' file location\n", sTypeName(lf->type), sTypeName(rt->type) );
                        
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


