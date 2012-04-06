#ifndef SYMBOLTABLEUTIL_H___NSBL_
#define SYMBOLTABLEUTIL_H___NSBL_
#include "ASTree.h"
int sTableDeclare(struct Node* node);
int sTableLookupId(struct Node* node);

void FuncHead(char* funcId, GArray* typeCon, FILE* out);

#endif
