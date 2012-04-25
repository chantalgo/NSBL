#ifndef SYMBOLTABLEUTIL_H_NSBL_
#define SYMBOLTABLEUTIL_H_NSBL_
#include "ASTree.h"
int sTableDeclare(struct Node* node);
int sTableLookupId(struct Node* node);
SymbolTableEntry* sTableTryLookupId(struct Node* node);
int sTableLookupFunc(struct Node* node);



int sTableInsertTree(struct Node* node, int ttype);
int sTableInsertId(struct Node* node, int ttype);
int sTableInsertFunc(struct Node* node);
int sTableInsertFuncLiteral(struct Node* node);
void FuncHead(char* funcId, GArray* typeCon, FILE* out);
GArray* rmDynFromTypeCon(GArray* t);
int checkTwoTypeConsExceptDyn(GArray* t1, GArray* t2);

#endif
