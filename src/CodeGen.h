#ifndef CODEGEN_H_NSBL_
#define CODEGEN_H_NSBL_
#include "ASTree.h"

char * strCatAlloc(char* sep, int n, ...);
char * strRightCatAlloc(char * base, char* sep, int n, ...);
void   strFreeAll(int n, ...);

#define strCatAllocSpace(n,...)       strCatAlloc(' ',n,...)

int codeGen (struct Node * node);
int codeAllGen(struct Node* node, char ** mainCode, char ** funCode);

char * opMacro(int ma);
char * wapperMainCode(char * mainBodyCode);
void exportCode(char * code);
#endif
