#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "CodeGen.h"
#include "SymbolTable.h"
#include "Parser.tab.h"
#include "global.h"
#include "Error.h"

char ** INDENT;                 // space indent
char * OUTFILE; 
FILE * OUTFILESTREAM;           // Output file

int  inLoop, inFunc;            // flags to indicate inside of loop or func

char * strCatAllocBase(char* sep, int n, char ** ptr){
    if(n<=0) return NULL;
    int i;
    int l, ll=0, ls=strlen(sep);
    for(i=0; i<n; ++i) ll += strlen(ptr[i]);
    
    char * nstr = (char *) malloc (sizeof(char)*(ll+(n-1)*ls+1));
    char * pt = nstr;
    for(i=0; i<n; ++i) {
        l = strlen(ptr[i]);
        strncpy(pt, ptr[i], l); pt += l;
        if(i<n-1) {
            strncpy(pt, sep, ls); pt += ls;
        }
        else *(pt++) = '\0';
    }
    return nstr; 
}

char * strCatAlloc(char* sep, int n, ...) {
    if (n<=0) return NULL;
    int i, nsep=0;
    va_list args;
    va_start (args, n);
    char ** ptr = (char **) malloc (sizeof(char *)*n);
    for(i=0; i<n; ++i) {
        char *tp = va_arg(args, char *);
        if(tp!=NULL) ptr[nsep++] = tp;
    }
    char* nstr = strCatAllocBase(sep, nsep, ptr);
    free(ptr);
    va_end(args);
    return nstr;
}

char * strRightCatAlloc(char * base, char* sep, int n, ...) {
    if (n<=0) return base;
    int i, nsep=0;
    va_list args;
    va_start (args, n);
    char ** ptr = (char **) malloc (sizeof(char *)*(n+1));
    if(base!=NULL) ptr[nsep++] = base;
    for(i=0; i<n; ++i) {
        char *tp = va_arg(args, char *);
        if(tp!=NULL) ptr[nsep++] = tp;
    }
    char* nstr = strCatAllocBase(sep, nsep, ptr);
    if(base!=NULL) free(base);
    free(ptr);
    va_end(args);
    return nstr;
}

void  strFreeAll(int n, ...) {
    if (n<=0) return;
    int i;
    va_list args;
    va_start (args, n);
    char * tptr;
    for(i=0; i<n; ++i) {
        if ( (tptr = va_arg(args, char *)) != NULL)
            free(tptr);
    }
    return;
}

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
	switch(type){
		case INT_T:
			if(node->child[1]->type == FLOAT_T)
				node->code = strCatAlloc("", 20, INDENT[node->child[0]->child[0]->scope[0]], sTypeName(type), " ", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind, " = ", "(int)", node->child[1]->code, ";\n",INDENT[node->child[0]->child[0]->scope[0]], "vertex_assign_attribute(", node->child[0]->child[0]->symbol->bind, ", \"", node->child[0]->child[1]->lexval.sval, "\", &", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind,", INT);\n");
			else if(node->child[1]->type == INT_T)
				node->code = strCatAlloc("", 19, INDENT[node->child[0]->child[0]->scope[0]], sTypeName(type), " ", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind, " = ", node->child[1]->code, ";\n",INDENT[node->child[0]->child[0]->scope[0]], "vertex_assign_attribute(", node->child[0]->child[0]->symbol->bind, ", \"", node->child[0]->child[1]->lexval.sval, "\", &", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind,", INT);\n");
			else
				err = ErrorTypeMisMatch;		
			break;
		case FLOAT_T:
			if(node->child[1]->type == INT_T)
				node->code = strCatAlloc("", 20, INDENT[node->child[0]->child[0]->scope[0]], sTypeName(type), " ", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind, " = ", "(float)", node->child[1]->code, ";\n",INDENT[node->child[0]->child[0]->scope[0]], "vertex_assign_attribute(", node->child[0]->child[0]->symbol->bind, ", \"", node->child[0]->child[1]->lexval.sval, "\", &", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind ,", FLOAT);\n");
			else if(node->child[1]->type == FLOAT_T)
				node->code = strCatAlloc("", 19, INDENT[node->child[0]->child[0]->scope[0]], sTypeName(type), " ", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind, " = ", node->child[1]->code, ";\n",INDENT[node->child[0]->child[0]->scope[0]], "vertex_assign_attribute(", node->child[0]->child[0]->symbol->bind, ", \"", node->child[0]->child[1]->lexval.sval, "\", &", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind ,", FLOAT);\n");
			else
				err = ErrorTypeMisMatch;
			break;
		case STRING_T:
			if(node->child[1]->type == STRING_T)
				node->code = strCatAlloc("", 20, INDENT[node->child[0]->child[0]->scope[0]], sTypeName(type), " ", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind," = g_string_new(", node->child[1]->code, ");\n",INDENT[node->child[0]->child[0]->scope[0]], "vertex_assign_attribute(", node->child[0]->child[0]->symbol->bind, ", \"", node->child[0]->child[1]->lexval.sval, "\", ", node->child[0]->child[0]->symbol->bind, "_", node->child[0]->child[1]->symbol->bind, "->str ,", "STRING);\n");
			else
				err = ErrorTypeMisMatch;
			break;
		default:
			break;
	}
	return err;
}

/** recursively generate code piece on each node */
int codeGen (struct Node * node) {
    if( node == NULL ) return;
    int token = node->token, errflag = 0;
    char * op = opMacro(token);
    struct Node *lf, *rt, *sg;
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
                node->code = strCatAlloc("",1,node->symbol->bind);
                node->codetmp = strCatAlloc("",1,node->symbol->bind);
            }
            else
                ERRNO = ErrorNoBinderForId;
            break;
        case DYN_ATTRIBUTE :
            if (node->symbol->bind!=NULL)
                node->code = strCatAlloc("",1,node->symbol->bind);
            else
                ERRNO = ErrorNoBinderForAttribute;
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
        case AST_TYPE_SPECIFIER :
            node->code = strCatAlloc(" ",1,sTypeName(node->lexval.ival));
            break;
        case AST_DECLARATION :
            codeGen( node->child[0] );codeGen( node->child[1] );
            if(node->scope[0]==0) { // we need to treat them as external declaration in c
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
        case AST_ASSIGN :               // assignment_operator 
        case ADD_ASSIGN :   
        case SUB_ASSIGN :   
        case MUL_ASSIGN :  
        case DIV_ASSIGN : 
            lf =  node->child[0]; rt = node->child[1];
            if(existbelong(lf))
				break;
			codeGen(lf);codeGen(rt);
            // type check and implicit type conversion
            if(lf->type == rt->type) {
                // int float support : = += -= *= /=
                if(lf->type == INT_T || lf->type == FLOAT_T || token == AST_ASSIGN) {
                    node->code = strCatAlloc(" ",3,lf->code,op,rt->code);
                    node->type = lf->type;
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
            else {
                ERRNO = ErrorTypeMisMatch;
                errorInfo(ERRNO, node->line, "type mismatch for the operands of operator `%s'\n",op);
                return ERRNO;
            }
            //
            if(node->scope[0]==0){
                node->codetmp = strCatAlloc("",1,lf->codetmp);
            }
            break;

        case APPEND :       codeGen( node->child[0] );codeGen( node->child[2] );
            // TODO
            break;
/************************************************************************************/
        case OR  :          
        case AND :          
            lf =  node->child[0]; rt = node->child[1];
            codeGen(lf);codeGen(rt);
            node->type = BOOL_T;
            if(lf->type != rt->type){
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
            break;
/************************************************************************************/
        case EQ :           
        case NE :           
            lf =  node->child[0]; rt = node->child[1];
            codeGen(lf);codeGen(rt);
            if(lf->type != rt->type){
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
            if(castType == rt->type) {
                node->code = strCatAlloc(" ",4,"(",lf->code,")" , rt->code);
                node->type = castType;
            }
            else if ( (castType == INT_T && rt->type == FLOAT_T) ||
                        (castType == FLOAT_T && rt->type == INT_T) ) {
                node->code = strCatAlloc(" ",4,"(",lf->code,")" , rt->code);
                node->type = castType;
            }
            else {
                ERRNO = ErrorCastType;
                errorInfo(ERRNO, node->line, "cast from `%s' to `%s' is invalid\n", sTypeName(castType), sTypeName(rt->type) );
                return ERRNO;
            }
            break; 
/************************************************************************************/
        case AST_UNARY_PLUS :   
        case AST_UNARY_MINUS :  
        case AST_UNARY_NOT :    
            sg = node->child[0];
            codeGen(sg);
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
                if(node->nch == 1) node->code = strCatAlloc(" ",2,node->symbol->bind,"()");
                else node->code = strCatAlloc(" ",4,node->symbol->bind,"(", node->child[1]->code, ")");
            }
            break;
        case AST_ARG_EXPS :
            codeGen(node->child[0]);
            node->type = node->child[0]->type;
            node->code = strCatAlloc(" ", 3, "(", node->child[0]->code,")");
            break;
/************************************************************************************/
        case PIPE :
            break;
/************************************************************************************/
        case AST_MATCH :
            break;
/************************************************************************************/
        case AST_ATTIBUTE :
            break;
/************************************************************************************/
        case AST_GRAPH_PROP :
            break;
/************************************************************************************/
        case AST_COMP_STAT :            // compound_statement
        case AST_COMP_STAT_NO_SCOPE :
            if(node->nch == 0) { // empty
                node->code = strCatAlloc("",1,"{ }\n");
            }
            else {
                codeGen(node->child[0]);
                if(token == AST_COMP_STAT_NO_SCOPE)
                    node->code = strCatAlloc("",3,
                        "{\n", node->child[0]->code,"}\n");
                else 
                    node->code = strCatAlloc("",5,INDENT[node->scope[0]],
                        "{\n", node->child[0]->code,
                        INDENT[node->scope[0]],"}\n");
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
                node->code = strCatAlloc("",3,INDENT[node->scope[0]],node->child[0]->code, ";\n");
            }
            break;
/************************************************************************************/
        case AST_IF_STAT :              // selection_statement
            lf = node->child[0]; rt = node->child[1];
            codeGen(lf); codeGen(rt);
            node->code = strCatAlloc("",7, 
                    INDENT[node->scope[0]],"if ( ", lf->code, " ) \n", 
                    rt->code, 
                    INDENT[node->scope[0]],"\n");
            break;
        case AST_IFELSE_STAT :
            lf = node->child[0]; sg = node->child[1]; rt = node->child[2];
            codeGen(lf); codeGen(sg); codeGen(rt);
            node->code = strCatAlloc("",10,
                    INDENT[node->scope[0]],"if ( ", lf->code, " ) \n",
                    sg->code, 
                    INDENT[node->scope[0]],"else\n", rt->code, 
                    INDENT[node->scope[0]],"\n");
            break;
/************************************************************************************/
        case AST_WHILE :                // iteration_statement
            lf = node->child[0]; rt = node->child[1];
            codeGen(lf); 
            inLoop++; codeGen(rt); inLoop--;
            node->code = strCatAlloc("", 7, 
                    INDENT[node->scope[0]],"while ( ", lf->code, " ) {\n",
                    rt->code, INDENT[node->scope[0]], 
                    "} //END_OF_WHILE\n");
            break;
        case AST_FOR :
            { 
                struct Node *f1 = node->child[0],
                        *f2 = node->child[1],
                        *f3 = node->child[2],
                        *fs = node->child[3];
                codeGen(f1);codeGen(f2);codeGen(f3);
                inLoop++; codeGen(fs); inLoop--;
                node->code = strCatAlloc("",10, INDENT[node->scope[0]],
                    "for (", (f1!=NULL)? f1->code : "", ";", 
                             (f2!=NULL)? f2->code : "", ";", 
                             (f3!=NULL)? f3->code : "", ") {\n",
                             fs->code, "} //END_OF_FOR\n");
            }
            break;
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
            if(inFunc==0) {
                ERRNO = ErrorCallReturnOutsideOfFunc;
                errorInfo(ERRNO, node->line, "call `return' outside of function or function literal\n");
                return ERRNO;
            }
            else {
                if (node->nch == 0) {
                    node->code = strCatAlloc("", 2,INDENT[node->scope[0]], "return ;\n");
                } else {
                    codeGen(node->child[0]);
                    node->code = strCatAlloc("", 4,INDENT[node->scope[0]], "return ",node->child[0]->code,";\n");
                }
            }
            break;
        // TODO: we must check 
        // 1> break continue is in scope of loop
        // 2> return is in scope of func, and return type is correct

/************************************************************************************/
        case AST_FUNC :                 // function_definition
            lf = node->child[0];            // return type
            sg = node->child[1];            // parameter_list
            rt = node->child[2];            // compound_statement
            codeGen(sg); 
            inFunc++; codeGen(rt); inFunc--;
            node->code = strCatAlloc("",7,
                    sTypeName(lf->lexval.ival)," ",
                    node->symbol->bind,     // func_id
                    " ( ", sg->code," ) ",
                    rt->code);
            //showASTandST(node,"Function Definition");
            break;
        case FUNC_LITERAL :             // function_literal_declaration
            lf = node->child[1];            // return type
            sg = node->child[0];            // parameter_list
            rt = node->child[2];            // compound_statement
            codeGen(sg); 
            inFunc++; codeGen(rt); inFunc--;
            //    put code to node->codetmp, as we need put all func_literals in
            // the external in target code.
            node->code = NULL;
            node->codetmp = strCatAlloc("", 8, INDENT[node->scope[0]],
                    sTypeName(lf->lexval.ival)," ",
                    node->symbol->bind,
                    " ( ", sg->code, " ) ",
                    rt->code);
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
    if (node->token == FUNC_LITERAL) {
        *code = strRightCatAlloc( *code, "", 2, node->codetmp, "\n");
        return;
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
char * opMacro(int ma) {
    switch(ma) {
        case AST_ASSIGN :       return "=";
        case ADD_ASSIGN :       return "+=";
        case SUB_ASSIGN :       return "-=";
        case MUL_ASSIGN :       return "*=";
        case DIV_ASSIGN :       return "/=";
        case OR  :              return "||";
        case AND :              return "&&";
        case EQ :               return "==";
        case NE :               return "!=";
        case LT :               return "<";
        case GT :               return ">";
        case LE :               return "<=";
        case GE :               return ">=";
        case ADD :              return "+";
        case SUB :              return "-";
        case MUL :              return "*";
        case DIV :              return "/";
        case AST_UNARY_PLUS :   return "+";
        case AST_UNARY_MINUS :  return "-";
        case AST_UNARY_NOT :    return "!";
        default:                return "??????????";
    }
}

char * wapperMainCode(char * mainBodyCode){
    char * head = "int main() {\n\n";
    char * end = "\n} // END_OF_MAIN \n";
    return strCatAlloc("",3,head,mainBodyCode,end);
}

void exportCode(char * code){
    fprintf(OUTFILESTREAM,"%s",code);
}

void codeIndentInit(){
    int mlvl = maxLevel, i;
    //printf("Max LEVEL: %d\n", mlvl);
    INDENT = (char **) malloc( sizeof( char * ) * (mlvl+1) );
    INDENT[0] = strCatAlloc("",1,"");
    for (i=1; i<=mlvl; ++i) {
        INDENT[i] = strCatAlloc("",2,INDENT[i-1],"  ");
    }
}

void codeIndentFree() {
    int mlvl = maxLevel, i=0;
    sTableMaxLevel(&mlvl);
    for (i=0; i<=mlvl; ++i) {
        //printf("%d %d\n",i,strlen(INDENT[i]));
        free(INDENT[i]);
    }
    free(INDENT);
}
