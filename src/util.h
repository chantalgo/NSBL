#ifndef UTILS_H_NSBL_
#define UTILS_H_NSBL_
#include "ASTree.h"

void init_util();
void debugInfo(char* fmt, ...);
void debugInfoExt(char* fmt, ...);
void logInfo(char* fmt, ...);

void showASTandST(struct Node* node, const char * head);
#endif
