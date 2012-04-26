#ifndef CODEGEN_H_NSBL_
#define CODEGEN_H_NSBL_
#include "ASTree.h"

#define REMOVE_DYN  0xF01

// node->tmp[]
#define GLOBAL_TMP  0
#define MATCH_TMP   1

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
char * tmpMatch();
char * assignFunc(int t);
char * wapperMainCode(char * mainBodyCode);
void exportCode(char * code);
#endif
