#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "util.h"
extern SymbolTable*            s_table;
extern SymbolTableStack*       s_stack;
extern int ERRNO;

#ifdef _DEBUG
FILE* DEBUGIO;
#endif
#ifndef _NO_LOG
FILE* LOGIO;
#endif
FILE* ERRORIO;

long long LEXLINECOUNTER;

void init_util() {
#ifdef _DEBUG
    DEBUGIO = stdout;
#endif
#ifndef _NO_LOG
    LOGIO   = stdout;
#endif
    ERRORIO = stdout;
    LEXLINECOUNTER = 1;
}

void debugInfo(char* fmt, ...){
#ifdef _DEBUG
    va_list args;
    va_start(args, fmt);
    fprintf(DEBUGIO,"DEBUG: ");
    vfprintf(DEBUGIO, fmt, args);
    va_end(args);
#endif
    return;
}

void debugInfoExt(char* fmt, ...){
#ifdef _DEBUG
    va_list args;
    va_start(args, fmt);
    vfprintf(DEBUGIO, fmt, args);
    va_end(args);
#endif
    return;
}


void logInfo(char* fmt, ...){
#ifndef _NO_LOG
    va_list args;
    va_start(args, fmt);
    vfprintf(LOGIO, fmt, args);
    va_end(args);
#endif
    return;
}

void showASTandST(struct Node* node, const char * head) {
#ifndef _NO_LOG
    logInfo("=======AST::%s=======\n", head);
    astOutTree(node, LOGIO, 0);
    logInfo("=======Symbol Table======\n");
    sTableShow(LOGIO);
#endif
}
