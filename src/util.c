#include <stdio.h>
#include <stdarg.h>
#include "util.h"

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
    va_list args;
    va_start(args, fmt);
#ifdef _DEBUG
    vfprintf(DEBUGIO, fmt, args);
#endif
    va_end(args);
    return;
}

void logInfo(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
#ifndef _NO_LOG
    vfprintf(LOGIO, fmt, args);
#endif
    va_end(args);
    return;
}

void errorInfo(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(ERRORIO,"error: ");
    vfprintf(ERRORIO, fmt, args);
    va_end(args);
    return;
}

