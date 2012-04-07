#ifndef UTILS_H___JZ_12345
#define UTILS_H___JZ_12345
#include "ASTree.h"

void init_util();
void debugInfo(char* fmt, ...);
void debugInfoExt(char* fmt, ...);
void logInfo(char* fmt, ...);

void showASTandST(struct Node* node, const char * head);
#endif
