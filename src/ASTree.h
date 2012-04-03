#ifndef ASTREE_H__JZ_12345
#define ASTREE_H__JZ_12345
/***************************************
 * Abstract Syntax Tree                *
 ***************************************/
#include <stdio.h>
#include "Parser.tab.h"     // definition of tokens
#include "SymbolTable.h"

/**************************************
 * Additional Tokens (AST)            *
 **************************************/
#define AST_TYPE_SPECIFIER          9001
#define AST_DECLARATION             9002
#define AST_COMMA                   9003

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
};

struct Node* ast_new_leaf(int token, void * ptr);
struct Node* ast_new_node(int token, int nch, struct Node** child);
struct Node** ast_all_children(int n, ...);

#define ast_leaf_val(leaf,field) leaf.lexval.field

void ast_output_node(struct Node* node, FILE* out, const char * sep);
void ast_output_subtree(struct Node* node, FILE* out, int level);
#endif
