#ifndef ASTREE_H_NSBL_
#define ASTREE_H_NSBL_
/***************************************
 * Abstract Syntax Tree                *
 ***************************************/
#include <stdio.h>
#include "Parser.tab.h"     // definition of tokens
#include "SymbolTable.h"

#ifdef _DEBUG
#ifdef _AST_DEBUG_ALL
#define _AST_DEBUG_BASE
#define _AST_DEBUG_EXTRA
#define _AST_DEBUG_MEMORY
#endif
#ifdef _AST_DEBUG
#define _AST_DEBUG_BASE
#endif
#endif

typedef union {
    bool                bval;
    int                 ival;
    float               fval;
    char*               sval;
}val_t;

struct Node {
    int                 token;          // can also be operator
    int                 type;           // see SymbolTable.h
    int                 nch;            // number of children
    struct Node**       child;          // if Leaf, NULL
    val_t               lexval;         // store lexeme value
    SymbolTableEntry*   symbol;         // default NULL
    long long           line;           // # line in source
};

/** create a Leaf of AST, ptr is the pointer to the lexemeval */
struct Node* ast_new_leaf(int token, void * ptr, long long l);
/** create a node of AST */
struct Node* ast_new_node(int token, int nch, struct Node** child);
/** pack all children in order */
struct Node** ast_all_children(int n, ...);
/** get the lexval.field */
#define ast_leaf_val(leaf,field) leaf.lexval.field
/** free subtree */
void ast_free_tree(struct Node* node);

/** output functions */
void ast_output_node(struct Node* node, FILE* out, const char * sep);
void ast_output_tree(struct Node* node, FILE* out, int level);

/****************
 * Call Wrapper *
 ****************/

#define astNewLeaf(t,p,l)       ast_new_leaf( t, (void*) p, l )
#define astNewNode(t,n,c)       ast_new_node( t, n, c )
#define astAllChildren          ast_all_children
#define astFreeTree             ast_free_tree
#define astOutNode              ast_output_node
#define astOutTree              ast_output_tree

#endif
