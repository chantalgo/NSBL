#ifndef CODEGENUTIL_H_NSBL_
#define CODEGENUTIL_H_NSBL_

// string operation
char * strCatAllocBase(char* sep, int n, char ** ptr);
char * strCatAlloc(char* sep, int n, ...);
char * strRightCatAlloc(char * base, char* sep, int n, ...);
void  strFreeAll(int n, ...);

// convert line number to string
char * strLine(int l);

char * codeFreeFuncName( int type );
char * codeRemoveAttrFuncName( int type );
char * opMacro(int ma);
char * DynOP(int ma);
char * typeMacro(int t);
char * assignFunc(int t);
char * tmpAttr();
char * tmpMatch();
char * tmpMatchStr();
char * tmpMatchStrVab();
char * tmpGraphVab();
char * tmpVab();
void codeIndentInit();
void codeIndentFree();


#endif
