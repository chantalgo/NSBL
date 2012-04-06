#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "SymbolTable.h"
#include "SymbolTableUtil.h"
#include "Error.h"

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
    return 0;
}

int sTableInsertTree(struct Node* node, int ttype) {
    if(node == NULL) return;
    if(node->token != IDENTIFIER) {
        int i; for(i=0; i<node->nch; ++i) {
            sTableInsertTree( node->child[i], ttype );
        }
    }
    else {
        sTableInsertId(node, ttype);
    }
    return 0;
}

int sTableInsertId(struct Node* node, int ttype) {
    SymbolTableEntry* entry = sNewVarEty ( node->lexval.sval, ttype, node->line );
    if ( sTableInsert( entry ) == ErrorSymbolTableKeyAlreadyExsit ) {
        SymbolTableEntry * te = sTableLookup(entry->key);
        ERRNO = ErrorIdentifierAlreadyDeclared;
        errorInfo("`%s' is already declared.\n", node->lexval.sval);
        errorInfoNote("`%s' is first declared at line %d\n", 
           node->lexval.sval, te->line);
        return ERRNO;
        // should tell where first declared
    }
    node->symbol = entry;
    node->type   = ttype;
    return 0;
}

int sTableInsertFunc(struct Node* node) {
    // declaration_specifiers   : node->child[0]
    // func_declarator          : node->child[1]
    // func_id                  : node->child[1]->child[0]
    struct Node* declSpec = node->child[0];
    struct Node* funcId   = node->child[1]->child[0];
    SymbolTableEntry* entry = sNewFunEty ( funcId->lexval.sval, FUNC_T, declSpec->lexval.ival, node->typeCon, node->tmp[0], node->tmp[1], node->line );
    if ( sTableInsert( entry ) == ErrorSymbolTableKeyAlreadyExsit ) {
        SymbolTableEntry * te = sTableLookup(entry->key);
        ERRNO = ErrorIdentifierAlreadyDeclared;
        errorInfo("`%s' is already declared.\n", funcId->lexval.sval);
        errorInfoNote("`%s' is first declared at line %d\n",
           funcId->lexval.sval, te->line);
        return ERRNO;
    }
    node->symbol = entry;
    node->type = FUNC_T;
    return 0;
}

int sTableLookupId(struct Node* node) {
    if(node->token != IDENTIFIER) {
        fprintf(stderr,"error: sTableLookupId: argument must be IDENTIFIER\n");
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
    if(entry == NULL) {
        ERRNO = ErrorIdentifierUsedBeforeDeclaration;
        errorInfo("`%s' is not declared before.\n", node->lexval.sval);
        return ERRNO;
    }
    node->symbol = entry;
    node->type = entry->type;
    return 0;
}

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
        errorInfo("`");
        FuncHead(funcId->lexval.sval, node->typeCon, ERRORIO);
        errorInfoExt("' is not declared before.\n");
        return ERRNO;
    }
    if (entry->type != FUNC_T) {
        ERRNO = ErrorFunctionCalledBeforeDeclaration;
        errorInfo("`%s' is not declared as a function\n",funcId->lexval.sval );
        errorInfoNote("`%s' is first declared at line %d\n",funcId->lexval.sval,entry->line);
        return ERRNO;
    }
    // if found, check parameter types
    GArray* caller = node->typeCon;
    GArray* ref    = entry->typeCon;
    if(caller->len != ref->len) {
        ERRNO = ErrorFunctionCallNOTEqualNumberOfParameters;
        errorInfo("function Call `");
        FuncHead(funcId->lexval.sval, caller, ERRORIO);
        errorInfoExt("' has inconsistent number of arguments to its declaration.\n");
    }
    else {
        if ( checkTwoTypeCons(caller, ref) == 0 ) { // not equal
            ERRNO = ErrorFunctionCallIncompatibleParameterType;
            errorInfo("function Call `");
            FuncHead(funcId->lexval.sval, caller, ERRORIO);
            errorInfoExt("' has incompatible arguments to its declaration.\n");
        }
    }
    if (ERRNO == ErrorFunctionCallNOTEqualNumberOfParameters ||
            ERRNO == ErrorFunctionCallIncompatibleParameterType ) {
        errorInfoNote("function `");
        FuncHead(funcId->lexval.sval, ref, ERRORIO);
        errorInfoExt("' first declared at line %d\n",entry->line);    
        return ERRNO;
    }
    // found correct one
    node->symbol = entry;
    node->type = entry->rtype;
}

void FuncHead(char* funcId, GArray* typeCon, FILE* out) {
    fprintf(out, "%s(", funcId);
    int i, ll=typeCon->len;
    for (i=0; i<ll-1; ++i)
        fprintf(out, "%s,", sTypeName( g_array_index(typeCon, int, i) ) );
    fprintf(out,"%s)", sTypeName( g_array_index(typeCon, int, ll-1) ) );
}

int checkTwoTypeCons(GArray* t1, GArray* t2) {
    if (t1->len!=t2->len) return 0;
    int i;
    for (i=0; i<t1->len; ++i) {
        if (g_array_index(t1, int, i) != g_array_index(t2, int, i) )
            return 0;
    }
    return 1;
}
