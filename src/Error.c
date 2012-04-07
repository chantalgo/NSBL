#include <stdio.h>
#include <stdarg.h>
FILE* ERRORIO;
int ERRNO;

void errorInfo(int eno, long long line, char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(ERRORIO,"ERROR:%d:%d: ",line, eno);
    vfprintf(ERRORIO, fmt, args);
    va_end(args);
    return;
}

void errorInfoExt(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    vfprintf(ERRORIO, fmt, args);
    va_end(args);
    return;
}

void errorInfoNote(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(ERRORIO,">>>NOTE>>>: ");
    vfprintf(ERRORIO, fmt, args);
    va_end(args);
    return;
}
