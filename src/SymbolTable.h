#ifndef SYMBOLTABL_H_NSBL_
#define SYMBOLTABL_H_NSBL_

#include <glib/ghash.h>
#include <glib/garray.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "Error.h"

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
    ScopeId             scope[2];       // level, Id
    SymbolTableKey      key;
    Binding             bind;
    long long           line;
}SymbolTableEntry;

typedef struct { 
    GArray*             stack;
    int                 top;            // pointing to top of stack, initial value is 0.
    int                 present;        // a pointer, initial value is 0.
}SymbolTableStack;

/** Methods */
/****************************************************************
 * ATTENTION:                                                   *
 * - gpointer is type of entry for GHashTable, i.e. void *      *
 ****************************************************************/

void                    s_table_init        (SymbolTable** s_table);
void                    s_table_destroy     (SymbolTable* s_table);
int                     s_table_insert      (SymbolTable* s_table,   SymbolTableEntry* the_entry);
bool                    s_table_remove      (SymbolTable* s_table,   SymbolTableEntry* the_entry);
SymbolTableEntry*       s_table_lookup      (SymbolTable* s_table,   SymbolTableKey key);
int                     s_table_check_key_exsit (SymbolTable* table, SymbolTableKey key);
void                    s_table_show        (SymbolTable* table, FILE* out);

char*                   s_table_type_name   (int type);
ScopeId                 s_table_new_scopeid ();

int                     s_stack_init        (SymbolTableStack** s_stack);
int                     s_stack_destroy     (SymbolTableStack* s_stack);
int                     s_stack_push        (SymbolTableStack* s_stack, ScopeId scopeid);
ScopeId                 s_stack_pop         (SymbolTableStack* s_stack);
ScopeId                 s_stack_top_id      (SymbolTableStack* s_stack);
ScopeId                 s_stack_down        (SymbolTableStack* s_stack);
int                     s_stack_reset       (SymbolTableStack* s_stack);

SymbolTableEntry*       s_entry_new         (Lexeme lex, int type, long long line);
void                    s_entry_show        (gpointer key, gpointer entry, gpointer out);
int                     s_new_key           (Lexeme lex, ScopeId scope2, SymbolTableKey key);
int                     s_new_bind          (SymbolTableEntry* entry, Binding bind);

/****************
 * Call Wrapper *
 ****************/

#define sTableInit()    s_table_init( &s_table )
#define sTableDestroy() s_table_destroy( s_table )
#define sTableInsert(e) s_table_insert( s_table, e )
#define sTableRemove(e) s_table_remove( s_table, e )
#define sTableLookup(k) s_table_lookup( s_table, k )
#define sTableShow(o)   s_table_show( s_table, o )

#define sTypeName(t)    s_table_type_name(t)
#define sNewScopeId()   s_table_new_scopeid()

#define sStackInit()    s_stack_init( &s_stack )
#define sStackDestroy() s_stack_destroy( s_stack )
#define sStackPush(a)   s_stack_push( s_stack, a )
#define sStackPop()     s_stack_pop( s_stack )
#define sStackDown()    s_stack_down( s_stack )
#define sStackReset()   s_stack_reset( s_stack )
#define sStackLevel     s_stack->top
#define sStackTopId     s_stack_top_id( s_stack )

#define sNewEntry(l,t,ll)  s_entry_new(l,t,ll)
#define sNewKey(l,s2,k) s_new_key(l,s2,k)
#define sNewBind(e,b)   s_new_bind(e,b)

#endif
