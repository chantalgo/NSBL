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
#define VOID_T          0
#define BOOL_T          1
#define INT_T           2
#define FLOAT_T         3
#define STRING_T        4
#define LIST_T          5
#define VERTEX_T        6
#define EDGE_T          7
#define GRAPH_T         8
#define FUNC_T          10
#define FUNC_LITERAL_T  11

#define DYN_BOOL_T      -1
#define DYN_INT_T       -2
#define DYN_FLOAT_T     -3
#define DYN_STRING_T    -4
#define DYN_LIST_T      -5
#define DYN_VERTEX_T    -6
#define DYN_EDGE_T      -7
#define DYN_GRAPH_T     -8
#define DYNAMIC_T       -9

#define UNKNOWN_T       -99
#define NOT_AVAIL       -55

typedef int ScopeId;
typedef GHashTable SymbolTable;
typedef char SymbolTableKey[KEY_LENGTH];
typedef char Lexeme[LEXEME_LENGTH];
typedef char Binding[BIND_LENGTH];

/** Entry of Symbol Table */
typedef struct {
    Lexeme              lex;
    int                 type;           // basic var type, FUNC, FUNC_LITERAL
    int                 rtype;          // return type
    GArray*             typeCon;        // var : NULL
                                        // fun : ( returnType, paraType1, ...)
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
bool                    s_table_remove      (SymbolTable* s_table,   SymbolTableEntry* the_entry, bool keepEntry);
SymbolTableEntry*       s_table_lookup      (SymbolTable* s_table,   SymbolTableKey key);
int                     s_table_check_key_exsit (SymbolTable* table, SymbolTableKey key);
void                    s_table_show        (SymbolTable* table, FILE* out);

char*                   s_table_type_name   (int type);
char*                   s_table_short_type_name   (int type);
ScopeId                 s_table_new_scopeid ();

int                     s_stack_init        (SymbolTableStack** s_stack);
int                     s_stack_destroy     (SymbolTableStack* s_stack);
int                     s_stack_push        (SymbolTableStack* s_stack, ScopeId scopeid);
ScopeId                 s_stack_pop         (SymbolTableStack* s_stack);
ScopeId                 s_stack_top_id      (SymbolTableStack* s_stack);
ScopeId                 s_stack_down        (SymbolTableStack* s_stack);
int                     s_stack_reset       (SymbolTableStack* s_stack);

SymbolTableEntry*       s_new_var_entry     (Lexeme lex, int type, long long line);
SymbolTableEntry*       s_new_fun_entry     (Lexeme lex, int type, int rtype, GArray* typeCon, ScopeId sLevel, ScopeId sId, long long line);
void                    s_destroy_entry     (gpointer dummy1, gpointer entry, gpointer dummy2);
void                    s_show_entry        (gpointer key, gpointer entry, gpointer out);
void                    s_show_typeCon      (GArray* tc, FILE* out);
int                     s_new_key           (Lexeme lex, ScopeId scope2, SymbolTableKey key);
int                     s_new_bind          (SymbolTableEntry* entry, Binding bind);

/****************
 * Call Wrapper *
 ****************/

#define sTableInit()        s_table_init( &s_table )
#define sTableDestroy()     s_table_destroy( s_table )
#define sTableInsert(e)     s_table_insert( s_table, e )
#define sTableRemove(e)     s_table_remove( s_table, e, false )
#define sTableRemoveKeep(e) s_table_remove( s_table, e, true )    
#define sTableLookup(k)     s_table_lookup( s_table, k )
#define sTableShow(o)       s_table_show( s_table, o )

#define sTypeName(t)        s_table_type_name(t)
#define sShortTypeName(t)   s_table_short_type_name(t)
#define sNewScopeId()       s_table_new_scopeid()

#define sStackInit()        s_stack_init( &s_stack )
#define sStackDestroy()     s_stack_destroy( s_stack )
#define sStackPush(a)       s_stack_push( s_stack, a )
#define sStackPop()         s_stack_pop( s_stack )
#define sStackDown()        s_stack_down( s_stack )
#define sStackReset()       s_stack_reset( s_stack )
#define sStackLevel         s_stack->top
#define sStackTopId         s_stack_top_id( s_stack )

#define sNewVarEty(l,t,ll)  s_new_var_entry(l,t,ll)
#define sNewFunEty(l,t,rt,tc,sl,sd,ll) s_new_fun_entry(l,t,rt,tc,sl,sd,ll)
#define sDestroyEntry(e)    s_destroy_entry(NULL,e,NULL)
#define sNewKey(l,s2,k)     s_new_key(l,s2,k)
#define sNewBind(e,b)       s_new_bind(e,b)

#endif
