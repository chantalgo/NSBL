#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "CodeGenUtil.h"
#include "Parser.tab.h"
#include "type.h"
#include "operator.h"
#include "global.h"

char ** INDENT;                 // space indent

char * strCatAllocBase(char* sep, int n, char ** ptr){
    if(n<=0) return NULL;
    int i;
    int l, ll=0, ls=strlen(sep);
    for(i=0; i<n; ++i) ll += strlen(ptr[i]);
    
    char * nstr = (char *) malloc (sizeof(char)*(ll+(n-1)*ls+1));
    char * pt = nstr;
    for(i=0; i<n; ++i) {
        l = strlen(ptr[i]);
        strncpy(pt, ptr[i], l); pt += l;
        if(i<n-1) {
            strncpy(pt, sep, ls); pt += ls;
        }
        else *(pt++) = '\0';
    }
    return nstr; 
}

char * strCatAlloc(char* sep, int n, ...) {
    if (n<=0) return NULL;
    int i, nsep=0;
    va_list args;
    va_start (args, n);
    char ** ptr = (char **) malloc (sizeof(char *)*n);
    for(i=0; i<n; ++i) {
        char *tp = va_arg(args, char *);
        if(tp!=NULL) ptr[nsep++] = tp;
    }
    char* nstr = strCatAllocBase(sep, nsep, ptr);
    free(ptr);
    va_end(args);
    return nstr;
}

char * strRightCatAlloc(char * base, char* sep, int n, ...) {
    if (n<=0) return base;
    int i, nsep=0;
    va_list args;
    va_start (args, n);
    char ** ptr = (char **) malloc (sizeof(char *)*(n+1));
    if(base!=NULL) ptr[nsep++] = base;
    for(i=0; i<n; ++i) {
        char *tp = va_arg(args, char *);
        if(tp!=NULL) ptr[nsep++] = tp;
    }
    char* nstr = strCatAllocBase(sep, nsep, ptr);
    if(base!=NULL) free(base);
    free(ptr);
    va_end(args);
    return nstr;
}

void  strFreeAll(int n, ...) {
    if (n<=0) return;
    int i;
    va_list args;
    va_start (args, n);
    char * tptr;
    for(i=0; i<n; ++i) {
        if ( (tptr = va_arg(args, char *)) != NULL)
            free(tptr);
    }
    return;
}

char * strLine(int l) {
    static char LineNO[64];
    sprintf(LineNO, "%d\0", l);
    return LineNO;
}

char * codeFreeFuncName( int type ) {
    switch (type) {
        case LIST_T :
            return "destroy_list" ;
        case VERTEX_T :
            return "destroy_vertex" ;
        case EDGE_T :
            return "destroy_edge" ;
        case GRAPH_T :
            return "destroy_graph" ;
        case STRING_T :
            return "destroy_string" ;
        default :
            return NULL;
    }
}

char * codeRemoveAttrFuncName( int type ) {
    switch ( type ) {
        case VERTEX_T :
            return "vertex_remove_attribute";
        case EDGE_T :
            return "edge_remove_attribute";
        case GRAPH_T :
            return "graph_remove_attribute";
        default :
            return NULL;
    }
}

char * opMacro(int ma) {
    switch(ma) {
        case AST_ASSIGN :       return "=";
        case ADD_ASSIGN :       return "+=";
        case SUB_ASSIGN :       return "-=";
        case MUL_ASSIGN :       return "*=";
        case DIV_ASSIGN :       return "/=";
        case OR  :              return "||";
        case AND :              return "&&";
        case EQ :               return "==";
        case NE :               return "!=";
        case LT :               return "<";
        case GT :               return ">";
        case LE :               return "<=";
        case GE :               return ">=";
        case ADD :              return "+";
        case SUB :              return "-";
        case MUL :              return "*";
        case DIV :              return "/";
        case AST_UNARY_PLUS :   return "+";
        case AST_UNARY_MINUS :  return "-";
        case AST_UNARY_NOT :    return "!";
        default:                return "??????????";
    }
}

char * DynOP(int ma) {
    switch(ma) {
        case AST_ASSIGN :       return "OP_ASSIGN";
        case ADD :              return "OP_ADD";
        case SUB :              return "OP_SUB";
        case MUL :              return "OP_MUL";
        case DIV :              return "OP_DIV";
        case OR :               return "OP_OR";
        case AND :              return "OP_AND";
        case EQ :               return "OP_EQ";
        case NE :               return "OP_NE";
        case LT :               return "OP_LT";
        case GT :               return "OP_GT";
        case LE :               return "OP_LE";
        case GE :               return "OP_GE";
        case AST_UNARY_PLUS :   return "OP_PLUS";
        case AST_UNARY_MINUS :  return "OP_MINUS";
        case AST_UNARY_NOT :    return "OP_NOT"; 
        default :               return "OP_UNKNOWN" ;
    }
}

char * typeMacro(int t) {
    switch(t) {
        case VOID_T :           return "VOID_T";
        case BOOL_T :           return "BOOL_T";
        case INT_T :            return "INT_T";
        case FLOAT_T :          return "FLOAT_T";
        case STRING_T :         return "STRING_T";
        case LIST_T :           return "LIST_T";
        case VERTEX_T :         return "VERTEX_T";
        case EDGE_T :           return "EDGE_T";
        case GRAPH_T :          return "GRAPH_T";
        default :               return "UNKNOWN_T";
    }
}

char * assignFunc(int t) {
    switch(t) {
        case STRING_T :         return "assign_operator_string";
        case LIST_T :           return "assign_operator_list";
        case VERTEX_T :         return "assign_operator_list";
        case EDGE_T :           return "assign_operator_edge";
        case GRAPH_T :          return "assign_operator_graph";
        default :               return "XXXXXXXXXXXXXX";
    }
}

char * tmpAttr() {
    static char tmp[128];
    static int i = 0;
    sprintf(tmp,"_tmp_attr_%d\0", i++);
    return tmp;
}

char * tmpMatch() {
    static char tmp[128];
    static int i = 0;
    sprintf(tmp,"_tmp_match_%d\0", i++);
    return tmp;
}

char * tmpMatchStr() {
    static char tmp[128];
    static int i = 0;
    sprintf(tmp,"_STR_tmp_match_%d\0", i++);
    return tmp;
}

char * tmpMatchStrVab() {
    static char tmp[128];
    static int i = 0;
    sprintf(tmp,"_STRV_%d\0", i++);
    return tmp;
}

void codeIndentInit(){
    int mlvl = maxLevel, i;
    //printf("Max LEVEL: %d\n", mlvl);
    INDENT = (char **) malloc( sizeof( char * ) * (mlvl+1) );
    INDENT[0] = strCatAlloc("",1,"");
    for (i=1; i<=mlvl; ++i) {
        INDENT[i] = strCatAlloc("",2,INDENT[i-1],"  ");
    }
}

void codeIndentFree() {
    int mlvl = maxLevel, i=0;
    sTableMaxLevel(&mlvl);
    for (i=0; i<=mlvl; ++i) {
        //printf("%d %d\n",i,strlen(INDENT[i]));
        free(INDENT[i]);
    }
    free(INDENT);
}
