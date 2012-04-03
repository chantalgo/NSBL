#ifndef SYMBOLTABL_H_JZ__12345
#define SYMBOLTABL_H_JZ__12345

#include <glib/ghash.h>
#include <glib/garray.h>
#include <stddef.h>
#include <stdbool.h>

/** LENGTH */
#define LEXEME_LENGTH           128
#define BIND_LENGTH             128
#define KEY_LENGTH              256
#define S_STACK_INIT_LENGTH     128

/** ALL TYPES */
#define VOID_T      0
#define BOOL_T      1
#define INT_T       2
#define FLOAT_T     3
#define STRING_T    4
#define LIST_T      5
#define VERTEX_T    6
#define EDGE_T      7
#define GRAPH_T     8
#define UNKNOWN_T   -1

typedef int ScopeId;
typedef GHashTable SymbolTable;
typedef char SymbolTableKey[KEY_LENGTH];
typedef char Lexeme[LEXEME_LENGTH];
typedef char Binding[BIND_LENGTH];

/** Entry of Symbol Table */
typedef struct {
    Lexeme              lex;
    int                 type;
    ScopeId             scope;
    SymbolTableKey      key;
    Binding             bind;
}SymbolTableEntry;

typedef struct {
    GArray*             stack;
    int                 top;            // pointing to top of stack, initial value is -1.
    int                 present;        // a pointer, initial value is -1.
}SymbolTableStack;

/** Methods */
/****************************************************************
 * ATTENTION:                                                   *
 * - gpointer is type of entry for GHashTable, i.e. void *      *
 ****************************************************************/

void                    s_table_init        ();
void                    s_table_destroy     ();
void                    s_table_insert      (SymbolTable* s_table,   SymbolTableEntry* the_entry);
bool                    s_table_remove      (SymbolTable* s_table,   SymbolTableEntry* the_entry);
SymbolTableEntry*       s_table_lookup      (SymbolTable* s_table,   SymbolTableKey key);

char*                   s_table_type_name   (int type);
int                     s_table_new_scopeid ();

int                     s_stack_init        ();
int                     s_stack_destroy     ();
int                     s_stack_push        (SymbolTableStack* s_stack, ScopeId scopeid);
ScopeId                 s_stack_pop         (SymbolTableStack* s_stack);
ScopeId                 s_stack_down        (SymbolTableStack* s_stack);
int                     s_stack_reset       (SymbolTableStack* s_stack);

SymbolTableEntry*       s_entry_new         (Lexeme lex, int type, ScopeId scope);
int                     s_new_key           (Lexeme lex, ScopeId scope, SymbolTableKey key);
int                     s_new_bind          (SymbolTableEntry* entry, Binding bind);

#endif
