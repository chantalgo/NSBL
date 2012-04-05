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

// init Symbol Table
void s_table_init (SymbolTable** table) {
    *table = g_hash_table_new (g_str_hash, g_str_equal);
}

// destroy Symbol Table
void s_table_destroy (SymbolTable* table) {
    g_hash_table_destroy ( table );
}

// insert an entry into ST
int s_table_insert (SymbolTable* table, SymbolTableEntry* entry) {
    if ( s_table_check_key_exsit(table, entry->key) ) 
        return ErrorSymbolTableKeyAlreadyExsit;
    g_hash_table_insert(table, (gpointer) (entry->key), (gpointer) entry);
    return 0;
}

// remove an entry (with key) from ST
bool s_table_remove (SymbolTable* table, SymbolTableEntry* entry) {
    return g_hash_table_remove(table, (gpointer) (entry->key));
}

// find an entry with key
SymbolTableEntry* s_table_lookup (SymbolTable* table, SymbolTableKey key) {
    return (SymbolTableEntry*) g_hash_table_lookup(table, (gpointer) key);
}

// check if key exist
int s_table_check_key_exsit (SymbolTable* table, SymbolTableKey key) {
    if ( g_hash_table_lookup(table, (gpointer) key) != NULL ) return 1;
    return 0;
}

// Output an entry
void s_entry_show  (gpointer key, gpointer entry, gpointer out) {
    SymbolTableEntry * e = (SymbolTableEntry*) entry;
    fprintf( (FILE*) out, "%10s  %3d  %3d  %3d  %15s  %15s  %4d\n",
        e->lex, e->type, e->scope[0], e->scope[1], e->key, e->bind, e->line );
}

// show entire ST
void s_table_show (SymbolTable* table, FILE* out) {
    fprintf(out, "%10s  %3s  %3s  %3s  %15s  %15s  %4s\n",
        "Lexeme", "T", "L", "Sp", "Key", "Binding", "Line");
    g_hash_table_foreach(table, &s_entry_show, (gpointer) out);
}

char* s_table_type_name (int type) {
    switch (type) {
        case VOID_T:    return "void";
        case BOOL_T:    return "bool";
        case INT_T:     return "int";
        case FLOAT_T:   return "float";
        case STRING_T:  return "str";
        case LIST_T:    return "list";
        case VERTEX_T:  return "vertex";
        case EDGE_T:    return "edge";
        case GRAPH_T:   return "graph";
        default:        return NULL;
    }
}

int s_table_new_bindid () {
    static int tid = 0;
    return tid++;
}

ScopeId s_table_new_scopeid () {
    static ScopeId sid = 0;
    return sid++;
}

int s_stack_init (SymbolTableStack** stack) {
    SymbolTableStack* tstack = (SymbolTableStack*) malloc ( sizeof(SymbolTableStack) );
    tstack->stack = g_array_new (1,1,sizeof(ScopeId));
    tstack->top = -1;
    tstack->present = -1;
    s_stack_push( tstack, s_table_new_scopeid () );
    *stack = tstack;
    return 0;
}

int s_stack_destroy (SymbolTableStack* stack) {
    g_array_free ( stack->stack, 1 );
    free(stack);
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

ScopeId s_stack_top_id (SymbolTableStack* stack) {
    return g_array_index ( stack->stack, ScopeId, stack->top );
}

ScopeId s_stack_down (SymbolTableStack* stack) {
    if(stack->present == -1) return -1; //stack bottom
    return g_array_index ( stack->stack, ScopeId, (stack->present)-- );
}

int s_stack_reset (SymbolTableStack* stack) {
    stack->present = stack->top;
    return 0;
}

SymbolTableEntry* s_entry_new (Lexeme lex, int type, long long line) {
    SymbolTableEntry* entry = (SymbolTableEntry*) malloc ( sizeof (SymbolTableEntry) );
    strcpy ((char *) entry->lex, lex);
    entry->line = line;
    entry->type = type;
    entry->scope[0] = sStackLevel;
    entry->scope[1] = sStackTopId;
    s_new_key ( entry->lex, entry->scope[1], entry->key );
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

