#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "SymbolTable.h"
#include "ASTree.h"
#include "Error.h"

int sTableDeclare(struct Node* node) {
    if(node->token == AST_DECLARATION ||
            node->token == AST_PARA_DECLARATION) {    // declaration
        int ttype = node->child[0]->lexval.ival;
        struct Node* nlist = node->child[1];
        // insert all IDENTIFIER as TYPE ttype in tree nlist
        sTableInsertTree(nlist, ttype);     
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
    SymbolTableEntry* entry = sNewEntry ( node->lexval.sval, ttype, node->line );
    if ( sTableInsert( entry ) == ErrorSymbolTableKeyAlreadyExsit ) {
        SymbolTableEntry * te = sTableLookup(entry->key);
        errorInfo("`%s' is already declared.\n note: `%s' is first declared at line %d\n", 
           node->lexval.sval, node->lexval.sval, te->line);
        return ERRNO = ErrorIdentifierAlreadyDeclared;
        // should tell where first declared
    }
    node->symbol = entry;
    node->type   = ttype;
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
        errorInfo("`%s' is not declared before.\n", node->lexval.sval);
        return ERRNO = ErrorIdentifierUsedBeforeDeclaration;
    }
    node->symbol = entry;
    node->type = entry->type;
    return 0;
}
