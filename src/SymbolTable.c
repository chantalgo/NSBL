#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"
#ifdef _DEBUG
extern FILE* DEBUGIO;
#endif

/************************************************
 * global variables (see SymbolTable.h)         *
 * - s_table                                    *
 * - s_stack                                    *
 ************************************************/
/** Global Variables */
SymbolTable*            s_table;
SymbolTableStack*       s_stack;
int                     isDynamicScope;
int                     isNoTypeCheck;
int                     maxLevel;

// init Symbol Table
void s_table_init (SymbolTable** table) {
    *table = g_hash_table_new (g_str_hash, g_str_equal);
    debugInfo("Symbol Table Initialized.\n");
}

// destroy Symbol Table
void s_table_destroy (SymbolTable* table) {
    debugInfo("Try to destroy Symbol Table\n");
    g_hash_table_foreach(table, &s_destroy_entry, NULL);
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
bool s_table_remove (SymbolTable* table, SymbolTableEntry* entry, bool keepEntry) {
    bool flag = g_hash_table_remove(table, (gpointer) (entry->key));
    if(!keepEntry) sDestroyEntry ( entry );
    return flag;
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
void s_show_entry  (gpointer key, gpointer entry, gpointer out) {
    SymbolTableEntry * e = (SymbolTableEntry*) entry;
    fprintf( (FILE*) out, "%10s  %3d  %3d  %3d  %3d  %15s  %15s  %4d  ||",
        e->lex, e->type, e->rtype, e->scope[0], e->scope[1], e->key, e->bind, e->line );
    s_show_typeCon(e->typeCon, out);
    fprintf( (FILE*) out, "\n" );
}

void s_show_typeCon (GArray* tc, FILE* out){
    if (tc==NULL) return;
    int ii, ll = tc->len;
    for (ii=0; ii<ll; ++ii)
        fprintf( (FILE*) out, "  %3d", g_array_index(tc, ScopeId, ii) );
}
// show entire ST
void s_table_show (SymbolTable* table, FILE* out) {
    fprintf(out, "%10s  %3s  %3s  %3s  %3s  %15s  %15s  %4s  || %15s\n",
        "Lexeme", "T", "RT", "L", "Sp", "Key", "Binding", "Line", "Func Parameters");
    g_hash_table_foreach(table, &s_show_entry, (gpointer) out);
}

void s_entry_compare_levle  (gpointer key, gpointer entry, gpointer mlevel){
    SymbolTableEntry* e = (SymbolTableEntry*) entry;
    if ( e->scope[0] > *(int *) mlevel ) *(int *) mlevel = e->scope[0];
}

void s_table_max_level (SymbolTable* table, int* mlevel) {
    g_hash_table_foreach(table, &s_entry_compare_levle, (gpointer) mlevel);
}

// convert type MACRO to char *
char* s_table_type_name (int type) {
    switch (type) {
        case VOID_T:            return "void";
        case BOOL_T:            return "bool";
        case INT_T:             return "int";
        case FLOAT_T:           return "float";
        case STRING_T:          return "GString*";
        case LIST_T:            return "ListType*";
        case VERTEX_T:          return "VertexType*";
        case EDGE_T:            return "EdgeType*";
        case GRAPH_T:           return "GraphType*";
        case DYNAMIC_T:         return "dyn";
        case FUNC_T:            return "func";
        case FUNC_LITERAL_T:    return "fl";
        case DYN_BOOL_T:        return "D_bool";
        case DYN_INT_T:         return "D_int";
        case DYN_FLOAT_T:       return "D_float";
        case DYN_STRING_T:      return "D_string";
        case DYN_LIST_T:        return "D_list";
        case DYN_VERTEX_T:      return "D_vertex";
        case DYN_EDGE_T:        return "D_edge";
        case DYN_GRAPH_T:       return "D_graph";
        default:                return NULL;
    }
}

char* s_table_short_type_name (int type) {
    switch (type) {
        case VOID_T:            return "v";
        case BOOL_T:            return "b";
        case INT_T:             return "i";
        case FLOAT_T:           return "f";
        case STRING_T:          return "s";
        case LIST_T:            return "l";
        case VERTEX_T:          return "v";
        case EDGE_T:            return "e";
        case GRAPH_T:           return "g";
        case DYNAMIC_T:         return "DD";
        case FUNC_T:            return "fc";
        case FUNC_LITERAL_T:    return "fl";
        case DYN_BOOL_T:        return "Db";
        case DYN_INT_T:         return "Di";
        case DYN_FLOAT_T:       return "Df";
        case DYN_STRING_T:      return "Ds";
        case DYN_LIST_T:        return "Dl";
        case DYN_VERTEX_T:      return "Dv";
        case DYN_EDGE_T:        return "De";
        case DYN_GRAPH_T:       return "Dg";
        default:                return NULL;
    }
}


// get new binder Id
int s_table_new_bindid () {
    static int tid = 0;
    return tid++;
}

// get new scope Id
ScopeId s_table_new_scopeid () {
    static ScopeId sid = 0;
    return sid++;
}

// init Scope Stack 
int s_stack_init (SymbolTableStack** stack) {
    SymbolTableStack* tstack = (SymbolTableStack*) malloc ( sizeof(SymbolTableStack) );
    tstack->stack = g_array_new (1,1,sizeof(ScopeId));
    tstack->top = -1;
    tstack->present = -1;
    s_stack_push( tstack, s_table_new_scopeid () );
    *stack = tstack;
    return 0;
}

// destroy Scope Stack
int s_stack_destroy (SymbolTableStack* stack) {
    g_array_free ( stack->stack, 1 );
    free(stack);
    return 0;
}

// push in one Scope Id
int s_stack_push (SymbolTableStack* stack, ScopeId sid) {
    stack->stack = g_array_append_vals ( stack->stack, (gconstpointer) (&sid), 1 );
    stack->top ++;
    return 0;
}

// pop out
ScopeId s_stack_pop (SymbolTableStack* stack) {
    ScopeId val = g_array_index ( stack->stack, ScopeId, stack->top );
    stack->stack = g_array_remove_index ( stack->stack, stack->top );
    stack->top --;
    return val;
}

// get the Scope Id on the top of stack
ScopeId s_stack_top_id (SymbolTableStack* stack) {
    return g_array_index ( stack->stack, ScopeId, stack->top );
}


// return scope id pointed by `present' and `present' move downward 
ScopeId s_stack_down (SymbolTableStack* stack) {
    if(stack->present == -1) return -1; //stack bottom
    return g_array_index ( stack->stack, ScopeId, (stack->present)-- );
}

// reset ptr `present' to the top
int s_stack_reset (SymbolTableStack* stack) {
    stack->present = stack->top;
    return 0;
}

// create variable Symbol Table entry
SymbolTableEntry* s_new_var_entry (Lexeme lex, int type, long long line) {
    if( type==FUNC_T || type==FUNC_LITERAL_T ) {
        fprintf(stderr, "Hey wrong call to s_new_var_entry!\n");
        return NULL;
    }
    SymbolTableEntry* entry = (SymbolTableEntry*) malloc ( sizeof (SymbolTableEntry) );
    strcpy ((char *) entry->lex, lex);
    entry->line = line;
    entry->type = type;
    entry->rtype = NOT_AVAIL;
    entry->typeCon = NULL;
    entry->scope[0] = sStackLevel;
    entry->scope[1] = sStackTopId;
    s_new_key ( entry->lex, entry->scope[1], entry->key );
    s_new_bind ( entry, entry->bind );
    return entry;
}

// create function Symbol Table entry
SymbolTableEntry* s_new_fun_entry (Lexeme lex, int type, int rtype, GArray* typeCon, ScopeId sLevel, ScopeId sId, long long line  ) {
    if( type!=FUNC_T && type!=FUNC_LITERAL_T ) {
        fprintf(stderr, "Hey wrong call to s_new_fun_entry!\n");
        return NULL;
    }
    SymbolTableEntry* entry = (SymbolTableEntry*) malloc ( sizeof (SymbolTableEntry) );
    strcpy ((char *) entry->lex, lex);
    entry->line = line;
    entry->type = type;
    entry->rtype = rtype;
    entry->typeCon = typeCon;
    entry->scope[0] = sLevel;
    entry->scope[1] = sId;
    s_new_key ( entry->lex, entry->scope[1], entry->key );
    s_new_bind ( entry, entry->bind );
    return entry;
}

// destroy Symbol Table entry
void s_destroy_entry ( gpointer dummy1, gpointer entry, gpointer dummy2 ) {
#ifdef _DEBUG
    debugInfo("Destroy Entry: ");
    s_show_entry(NULL, entry, DEBUGIO);
#endif
    SymbolTableEntry* e = ( SymbolTableEntry* ) entry ; 
    if (e->typeCon != NULL) {
        g_array_free( e->typeCon, 1 );
#ifdef _DEBUG
        debugInfoExt(" >> destroy typeCon... \n");
#endif
    }

    free( e );
}

// create new key 
int s_new_key ( Lexeme lex, ScopeId scope, SymbolTableKey key) {
    sprintf( key, "%s%d\0", lex, scope );
    return 0;
}

// create new binder
int s_new_bind ( SymbolTableEntry* entry, Binding bind) {
    if(entry->type >= 0) {
        char * typename = s_table_short_type_name( entry->type );
        int tmpid = s_table_new_bindid();
        sprintf( bind, "%s_%s%d_s%d\0", entry->lex,typename, tmpid, entry->scope[1] );
    }
    else {
        sprintf( bind, "D_%s\0", entry->lex);
    }
    return 0;
}

