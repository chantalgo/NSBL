#include <stdio.h>
#include <stdarg.h>
int ERRNO;
FILE* ERRORIO;

void errorInfo(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(ERRORIO,"ERROR::%d: ",ERRNO);
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
