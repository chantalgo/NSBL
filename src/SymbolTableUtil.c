#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "SymbolTable.h"
#include "SymbolTableUtil.h"
#include "Error.h"

/** declare the variables or parameters */
int sTableDeclare(struct Node* node) {
    if(node->token == AST_DECLARATION ||
            node->token == AST_PARA_DECLARATION) {    // var declaration
        int ttype = node->child[0]->lexval.ival;
        struct Node* nlist = node->child[1];
        // insert all IDENTIFIER as TYPE ttype in tree nlist
        sTableInsertTree(nlist, ttype);     
    }
    if(node->token == AST_FUNC ) { // func declaration
        sTableInsertFunc(node);
    }
    if(node->token == FUNC_LITERAL ) { // func_literal
        sTableInsertFuncLiteral(node);
    }
    return 0;
}

/** insert all IDENTIFIER or DYN_ATTRIBUTE in the subtree */
int sTableInsertTree(struct Node* node, int ttype) {
    if(node == NULL) return;
    switch (node->token) {
        case IDENTIFIER :
            sTableInsertId(node, ttype); break;
        case DYN_ATTRIBUTE :
            // Do NOT insert attribute to symbol table
            //sTableInsertId(node, -ttype); 
            break;
        case AST_COMMA :
            sTableInsertTree(node->child[0], ttype);
            sTableInsertTree(node->child[1], ttype); break;
        case AST_ASSIGN :
            sTableInsertTree(node->child[0], ttype); break;
		case BELONG:
            // Do NOT insert attribute to symbol table
			//sTableInsertTree(node->child[1], -ttype);
            break;
        default :
            fprintf(stderr, "sTableInsertTree : unknown token %d\n",node->token);
    }
    return 0;
}

/** insert one IDENTIFIER or DYN_ATTRIBUTE */
int sTableInsertId(struct Node* node, int ttype) {
    if ( ttype < DYN_STRING_T  && ttype!=DYNAMIC_T) { // take care of declare unsupported type for attribute
        ERRNO = ErrorAttributeTypeNotSupported;
        errorInfo(ERRNO, node->line, "Type `%s' is not supported for Attribute\n", sTypeName(ttype));
        return ERRNO;
    } 
    else if ( ttype == VOID_T ) {
        ERRNO = ErrorVoidTypeVariableNotSupported;
        errorInfo(ERRNO, node->line, " cannot declare `void' variable.\n");
        return ERRNO;
    }
   
    SymbolTableEntry* entry = sNewVarEty ( node->lexval.sval, ttype, node->line );
    if ( sTableInsert( entry ) == ErrorSymbolTableKeyAlreadyExsit ) {
        SymbolTableEntry * te = sTableLookup(entry->key);
        ERRNO = ErrorIdentifierAlreadyDeclared;
        errorInfo(ERRNO, node->line,"`%s%s' is already declared.\n",(ttype<0)?"@":"", node->lexval.sval);
        errorInfoNote("`%s%s' is first declared at line %d\n", 
           (ttype<0)?"@":"",node->lexval.sval, te->line);
        return ERRNO;
        // should tell where first declared
    }
    node->symbol = entry;
    node->type   = ttype;
    return 0;
}

/** insert a function */
int sTableInsertFunc(struct Node* node) {
    // declaration_specifiers   : node->child[0]
    // func_declarator          : node->child[1]
    // func_id                  : node->child[1]->child[0]
    struct Node* declSpec = node->child[0];
    struct Node* funcId   = node->child[1]->child[0];
    SymbolTableEntry* entry = sNewFunEty ( funcId->lexval.sval, FUNC_T, declSpec->lexval.ival, node->typeCon, node->scope[0], node->scope[1], node->line );
    if ( sTableInsert( entry ) == ErrorSymbolTableKeyAlreadyExsit ) {
        SymbolTableEntry * te = sTableLookup(entry->key);
        ERRNO = ErrorIdentifierAlreadyDeclared;
        errorInfo(ERRNO, node->line,"`%s' is already declared.\n", funcId->lexval.sval);
        errorInfoNote("`%s' is first declared at line %d\n",
           funcId->lexval.sval, te->line);
        return ERRNO;
    }
    node->symbol = entry;
    node->type = FUNC_T;
    return 0;
}

/** insert a func_literal */
int sTableInsertFuncLiteral(struct Node* node) {
    struct Node* declSpec = node->child[1];
    struct Node* funcId   = node->child[0]->child[0];
    SymbolTableEntry* entry = sNewFunEty ( funcId->lexval.sval, FUNC_LITERAL_T, declSpec->lexval.ival, node->typeCon, node->scope[0], node->scope[1], node->line );
    if ( sTableInsert( entry ) == ErrorSymbolTableKeyAlreadyExsit ) {
        SymbolTableEntry * te = sTableLookup(entry->key);
        ERRNO = ErrorIdentifierAlreadyDeclared;
        errorInfo(ERRNO, node->line,"`%s' is already declared.\n", funcId->lexval.sval);
        errorInfoNote("`%s' is first declared at line %d\n",
           funcId->lexval.sval, te->line);
        return ERRNO;
    }
    node->symbol = entry;
    node->type = FUNC_T;
    return 0;
}

/** lookup an Id from symtable, if not found report compiling error */
int sTableLookupId(struct Node* node) {
    SymbolTableEntry* entry = sTableTryLookupId(node);
    if(entry == NULL) {
        ERRNO = ErrorIdentifierUsedBeforeDeclaration;
        errorInfo(ERRNO, node->line,"`%s' is not declared before.\n", node->lexval.sval);
        return ERRNO;
    }
    node->symbol = entry;
    node->type = entry->type;
    return 0;
}

/** lookup an Id from symtable, return the entry */
SymbolTableEntry* sTableTryLookupId(struct Node* node) {
    if( node->token != IDENTIFIER &&
            node->token != DYN_ATTRIBUTE ) {
        fprintf(stderr,"error: sTableLookupId: argument must be IDENTIFIER or DYN_ATTRIBUTE\n");
        exit(EXIT_FAILURE);
    }
    SymbolTableKey key;
    SymbolTableEntry* entry;
    ScopeId id = sStackTopId;
    sStackReset();
    while (id>=0) {
        sNewKey(node->lexval.sval, id, key);
        if ( (entry = sTableLookup(key)) != NULL ) break;
        id = sStackDown();
    }
    return entry;
}

/** lookup a func or func_literal, if not found report compiling error */
int sTableLookupFunc(struct Node* node) {
    if(node->token != AST_FUNC_CALL) {
        fprintf(stderr,"error: sTableLookupFunc: argument must be AST_FUNC_CALL\n");
        exit(EXIT_FAILURE);
    }
    SymbolTableKey key;
    SymbolTableEntry* entry;
    struct Node* funcId = node->child[0];
    // create key
    sNewKey(funcId->lexval.sval, 0, key);       // function always in scope 0
    // try lookup in Symbol Table
    entry = sTableLookup(key);
    if(entry == NULL) {
        ERRNO = ErrorFunctionCalledBeforeDeclaration;
        errorInfo(ERRNO, node->line, "`");
        FuncHead(funcId->lexval.sval, node->typeCon, ERRORIO);
        errorInfoExt("' is not declared before.\n");
        return ERRNO;
    }
    // if found, check parameter types
    GArray* caller = node->typeCon;
    GArray* ref    = entry->typeCon;
    int flag = 0;
/*    if(entry->type == FUNC_T) {   // if function
        if(caller->len != ref->len) {
            flag = (ERRNO = ErrorFunctionCallNOTEqualNumberOfParameters); 
            errorInfo(ERRNO, node->line, "function Call `");
            FuncHead(funcId->lexval.sval, caller, ERRORIO);
            errorInfoExt("' has inconsistent number of arguments to its declaration.\n");
        }
        else {
            if ( checkTwoTypeCons(caller, ref) == 0 ) { // not equal
                flag = (ERRNO = ErrorFunctionCallIncompatibleParameterType);
                errorInfo(ERRNO, node->line, "function Call `");
                FuncHead(funcId->lexval.sval, caller, ERRORIO);
                errorInfoExt("' has incompatible arguments to its declaration.\n");
            }
        }
    }
    else if(entry->type == FUNC_LITERAL_T) { // func_literal
        if ( checkTwoTypeConsExceptDyn(caller, ref) == 0 ) { // not equal
            flag = (ERRNO = ErrorFuncLiteralCallIncompatibleParameterType);
            errorInfo(ERRNO, node->line, "function literal Call `");
            FuncHead(funcId->lexval.sval, caller, ERRORIO);
            errorInfoExt("' has incompatible arguments to its declaration.\n");
        }
    }
    else {
        flag = (ERRNO = ErrorFunctionCalledBeforeDeclaration);
        errorInfo(ERRNO, node->line,"`%s' is not declared as a function or function literal\n",funcId->lexval.sval );
        errorInfoNote("`%s' is first declared at line %d\n",funcId->lexval.sval,entry->line);
        return ERRNO;
    }*/
    if (flag == ErrorFunctionCallNOTEqualNumberOfParameters ||
            flag == ErrorFunctionCallIncompatibleParameterType ||
                flag == ErrorFuncLiteralCallIncompatibleParameterType ) {
        errorInfoNote("function `");
        FuncHead(funcId->lexval.sval, ref, ERRORIO);
        errorInfoExt("' first declared at line %d\n",entry->line);    
        return ERRNO;
    }
    // found correct one
    node->symbol = entry;
    node->type = entry->rtype;
    return 0;
}

/** output function heading */
void FuncHead(char* funcId, GArray* typeCon, FILE* out) {
    fprintf(out, "%s(", funcId);
    int i, ll=typeCon->len;
    for (i=0; i<ll-1; ++i)
        fprintf(out, "%s,", sTypeName( g_array_index(typeCon, int, i) ) );
    fprintf(out,"%s)", sTypeName( g_array_index(typeCon, int, ll-1) ) );
}

/** check equivalence of two type constructors */
int checkTwoTypeCons(GArray* t1, GArray* t2) {
    if (t1->len!=t2->len) return 0;
    int i;
    for (i=0; i<t1->len; ++i) {
        int it1 = g_array_index(t1, int, i);
        int it2 = g_array_index(t2, int, i);
        if ( it1 >= 0 && it2 >= 0 && it1 != it2 ) // ignore dynamic type
            return 0;
    }
    return 1;
}

/** remove dynamic type from type constructors */
GArray* rmDynFromTypeCon(GArray* t) {
    int i;
    GArray* tga = g_array_new ( 1, 1, sizeof(int) );
    for (i=0; i<t->len; ++i) {
        int type = g_array_index(t, int, i);
        if (type>=0) g_array_append_vals ( tga, (gconstpointer) & type, 1);
    }
    return tga;
}

/** check equivalence of two type constructors, ignore dynamic types */
int checkTwoTypeConsExceptDyn(GArray* t1, GArray* t2) {
    GArray *ft1,*ft2;
    ft1 = rmDynFromTypeCon(t1); 
    ft2 = rmDynFromTypeCon(t2);
    int rlt = checkTwoTypeCons(ft1,ft2);
    g_array_free(ft1,1);
    g_array_free(ft2,1);
    return rlt;
}
