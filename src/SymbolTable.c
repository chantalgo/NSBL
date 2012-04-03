#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"

/************************************************
 * global variables (see SymbolTable.h)         *
 * - s_table                                    *
 * - s_stack                                    *
 ************************************************/
/** Global Variables */
SymbolTable*            s_table;
SymbolTableStack*       s_stack;



void s_table_init () {
    s_table = g_hash_table_new (g_str_hash, g_str_equal);
    return;
}

void s_table_destroy () {
    g_hash_table_destroy ( s_table );
}

void s_table_insert (SymbolTable* table, SymbolTableEntry* entry) {
    g_hash_table_insert(table, (gpointer) (entry->key), (gpointer) entry);
    return;
}

bool s_table_remove (SymbolTable* table, SymbolTableEntry* entry) {
    return g_hash_table_remove(table, (gpointer) (entry->key));
}

SymbolTableEntry* s_table_lookup (SymbolTable* table, SymbolTableKey key) {
    return (SymbolTableEntry*) g_hash_table_lookup(table, (gpointer) key);
}

char* s_table_type_name (int type) {
    switch (type) {
        case VOID_T: return "void";
        case BOOL_T: return "bool";
        case INT_T: return "int";
        case FLOAT_T: return "float";
        case STRING_T: return "str";
        case LIST_T: return "list";
        case VERTEX_T: return "vertex";
        case EDGE_T: return "edge";
        case GRAPH_T: return "graph";
        default: return NULL;
    }
}

int s_table_new_bindid () {
    static int tid = 0;
    return tid++;
}

int s_table_new_scopeid () {
    static int sid = 0;
    return sid++;
}

int s_stack_init () {
    s_stack = (SymbolTableStack*) malloc ( sizeof(SymbolTableStack) );
    s_stack->stack = g_array_new (1,1,sizeof(ScopeId));
    s_stack->top = -1;
    s_stack->present = -1;
    return 0;
}

int s_stack_destroy () {
    g_array_free ( s_stack->stack, 1 );
    free(s_stack);
    return 0;
}

int s_stack_push (SymbolTableStack* stack, ScopeId sid) {
    stack->stack = g_array_append_vals ( stack->stack, (gconstpointer) (&sid), 1 );
    stack->top ++;
    return 0;
}

ScopeId s_stack_pop (SymbolTableStack* stack) {
    ScopeId val = g_array_index ( stack->stack, ScopeId, stack->top );
    stack->stack = g_array_remove_index ( stack->stack, stack->top );
    stack->top --;
    return val;
}

ScopeId s_stack_down (SymbolTableStack* stack) {
    if(stack->present == -1) return -1; //stack bottom
    return g_array_index ( stack->stack, ScopeId, (stack->present)-- );
}

int s_stack_reset (SymbolTableStack* stack) {
    stack->present = stack->top;
    return 0;
}

SymbolTableEntry* s_entry_new (Lexeme lex, int type, ScopeId scope) {
    SymbolTableEntry* entry = (SymbolTableEntry*) malloc ( sizeof (SymbolTableEntry) );
    strcpy ((char *) entry->lex, (const char *) lex);
    entry->type = type;
    entry->scope = scope;
    s_new_key ( entry->lex, entry->scope, entry->key );
    s_new_bind ( entry, entry->bind );
    return entry;
}

int s_new_key ( Lexeme lex, ScopeId scope, SymbolTableKey key) {
    sprintf( key, "%s%d\0", lex, scope );
    return 0;
}

int s_new_bind ( SymbolTableEntry* entry, Binding bind) {
    char * typename = s_table_type_name( entry->type );
    int tmpid = s_table_new_bindid();
    sprintf( bind, "_%s%d\0", typename, tmpid );
    return 0;
}
