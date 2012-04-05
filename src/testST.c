#include <stdio.h>
#include "SymbolTable.h"

extern SymbolTable* s_table;
extern SymbolTableStack*       s_stack;
int main() {
    sTableInit();
    sStackInit();
    // generate entries
    SymbolTableEntry* entry, *entry2, *result, *result2;
    Lexeme ll = "abc";
    int tt = 1;
    printf("%d\n", s_stack->top);fflush(stdout);
    entry = sNewEntry ( ll, tt, sStackLevel, sStackTopId );
    entry2 = sNewEntry ( "xyz", 2, 1, 1 );
    printf("key=%s\nbind=%s\nSlevel=%d\nScopeId=%d\n", entry->key, entry->bind,entry->scope[0],entry->scope[1]);
    printf("key=%s\nbind=%s\n", entry2->key, entry2->bind);
    // insert to s_table
    sTableInsert( entry);
    // lookup
    SymbolTableKey key;
    sNewKey(entry->lex, entry->scope[1], key);
    result = s_table_lookup(s_table, key);
    // check
    printf("key=%s\nbind=%s\n", result->key, result->bind);
    // remove
    bool istat = s_table_remove(s_table, entry);
    if (istat) printf("remove done\n");
    else printf("remove false\n");
    // lookup 2 , should fail
    result2 = s_table_lookup(s_table, key);
    printf("Should be NULL %p\n", result2);
    // cleanup
    sTableDestory();

    // test stack
    ScopeId ttt;
    s_stack_push(s_stack, 1);
    s_stack_push(s_stack, 2);
    s_stack_push(s_stack, 3);
    s_stack_push(s_stack, 4);
    printf("top=%d, present=%d\n", s_stack->top, s_stack->present);
    ttt = s_stack_pop(s_stack);
    printf("pop:%d\n",ttt);
    //
    printf("top=%d, present=%d\n", s_stack->top, s_stack->present);
    // 
    s_stack_reset(s_stack);
    while(s_stack->present>=0) {
        printf("down:%d\n",s_stack_down(s_stack));
    }
    s_stack_reset(s_stack);
    printf("top=%d, present=%d\n", s_stack->top, s_stack->present);
    //
    sStackDestroy();
}
