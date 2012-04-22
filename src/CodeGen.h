#ifndef CODEGEN_H_NSBL_
#define CODEGEN_H_NSBL_
#include "ASTree.h"

#define REMOVE_DYN 0xF01

char * strCatAlloc(char* sep, int n, ...);
char * strRightCatAlloc(char * base, char* sep, int n, ...);
void   strFreeAll(int n, ...);

#define strCatAllocSpace(n,...)       strCatAlloc(' ',n,...)

int codeGen (struct Node * node);
int codeAllGen(struct Node* node, char ** mainCode, char ** funCode);

char * opMacro(int ma);
char * DynOP(int ma);
char * typeMacro(int t);
char * tmpAttr();
char * wapperMainCode(char * mainBodyCode);
void exportCode(char * code);
#endif
