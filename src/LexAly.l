%{
#include <stdio.h>
#include "Parser.tab.h"


#ifdef _MYECHO
#define MYECHO myecho() 
#else
#define MYECHO 
#endif
void  myecho();
void countLine(const char* ptr);
#include "util.h"
#include "global.h"
%}

letter_         [A-Za-z_]
digit           [0-9]
floatconst      ({digit}*\.{digit}+|{digit}+\.{digit}*)([eE][+-]?{digit}+)?
intconst        {digit}+
identifier      {letter_}({letter_}|{digit})*
strliteral      \"([^\"\\]|\\.)*\"
comment         (\/\*([^\*]|(\*+([^\*\/])))*\*+\/)|(\/\/.*)

%%
"void"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return VOID; }
"boolean"       { MYECHO; yylval.LString.l = LEXLINECOUNTER; return BOOLEAN; }
"int"           { MYECHO; yylval.LString.l = LEXLINECOUNTER; return INTEGER; }
"float"         { MYECHO; yylval.LString.l = LEXLINECOUNTER; return FLOAT; }
"string"        { MYECHO; yylval.LString.l = LEXLINECOUNTER; return STRING; }
"list"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return LIST; }
"vertex"        { MYECHO; yylval.LString.l = LEXLINECOUNTER; return VERTEX; }
"edge"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return EDGE; }
"graph"         { MYECHO; yylval.LString.l = LEXLINECOUNTER; return GRAPH; }

"func"			{ MYECHO; yylval.LString.l = LEXLINECOUNTER; return FUNC_LITERAL; }
"if"            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return IF; }
"else"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ELSE; }
"for"           { MYECHO; yylval.LString.l = LEXLINECOUNTER; return FOR; }
"foreach"       { MYECHO; yylval.LString.l = LEXLINECOUNTER; return FOREACH; }
"while"         { MYECHO; yylval.LString.l = LEXLINECOUNTER; return WHILE; }
"break"         { MYECHO; yylval.LString.l = LEXLINECOUNTER; return BREAK; }
"continue"      { MYECHO; yylval.LString.l = LEXLINECOUNTER; return CONTINUE; }
"return"        { MYECHO; yylval.LString.l = LEXLINECOUNTER; return RETURN; }
"mark"			{ MYECHO; yylval.LString.l = LEXLINECOUNTER; return MARK; }

"outE"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return OUTCOMING_EDGES; }
"inE"           { MYECHO; yylval.LString.l = LEXLINECOUNTER; return INCOMING_EDGES; }
"strtV"         { MYECHO; yylval.LString.l = LEXLINECOUNTER; return STARTING_VERTICES; }
"endV"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ENDING_VERTICES; }
"allV"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ALL_VERTICES; }
"allE"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ALL_EDGES; }

"=="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return EQ; }
"!="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return NE; }
"<="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return LE; }
">="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return GE; }
"+="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ADD_ASSIGN; }
"-="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return SUB_ASSIGN; }
"*="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return MUL_ASSIGN; }
"/="            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return DIV_ASSIGN; }
"||"            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return OR; }
"&&"            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return AND; }
"::"			{ MYECHO; yylval.LString.l = LEXLINECOUNTER; return BELONG; }

"<:"            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return APPEND; }
"->"            { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ARROW; }
"|"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return PIPE; }
"@"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return AT; }

"{"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '{'; }
"}"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '}'; }
"("             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '('; }
")"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ')'; }
"["             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '['; }
"]"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ']'; }
";"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ';'; }
","             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ','; }
":"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ':'; }
"."             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '.'; }
"!"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '!'; }
"+"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return ADD; }
"-"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return SUB; }
"*"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return MUL; }
"/"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return DIV; }
"="             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return '='; }
">"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return GT; }
"<"             { MYECHO; yylval.LString.l = LEXLINECOUNTER; return LT; }

"true"          { MYECHO; yylval.LString.l = LEXLINECOUNTER; return BOOL_TRUE; }
"false"         { MYECHO; yylval.LString.l = LEXLINECOUNTER; return BOOL_FALSE; }
{intconst}      { MYECHO; 
                  yylval.LString.s = (char *) malloc ( strlen(yytext) ); 
                  yylval.LString.l = LEXLINECOUNTER;
                  strcpy( yylval.LString.s, yytext ); 
                  return INTEGER_CONSTANT;
                }
{floatconst}    { MYECHO; 
                  yylval.LString.s = (char *) malloc ( strlen(yytext) ); 
                  yylval.LString.l = LEXLINECOUNTER;
                  strcpy( yylval.LString.s, yytext ); 
                  return FLOAT_CONSTANT;
                }
{identifier}    { MYECHO; 
                  yylval.LString.s = (char *) malloc ( strlen(yytext) ); 
                  yylval.LString.l = LEXLINECOUNTER;
                  strcpy( yylval.LString.s, yytext ); 
                  return IDENTIFIER; 
                }
{strliteral}    { MYECHO; 
                  yylval.LString.s = (char *) malloc ( strlen(yytext) ); 
                  yylval.LString.l = LEXLINECOUNTER;
                  strncpy( yylval.LString.s, yytext, strlen(yytext)  ); 
                  yylval.LString.s[strlen(yytext)]='\0';
                  return STRING_LITERAL; 
                }
{comment}       { MYECHO; countLine(yytext); }

[ \t]           { }
[\n]            { LEXLINECOUNTER++; }
.               { errorInfo(ErrorUnrecognizedLexeme, LEXLINECOUNTER, "error :%d: unrecognized lexeme `%s'\n", LEXLINECOUNTER, yytext);
                }

%%

void countLine(const char* ptr) {
    int i;
    for (i=0; i<strlen(ptr); ++i) {
        if (ptr[i]=='\n') LEXLINECOUNTER++;
    }
}

void myecho() {
    fprintf(yyout, "LEX:");
    fprintf(yyout, "YYLENG=%d:",yyleng);
    fprintf(yyout, "YYTEXT=\"");
    ECHO; 
    fprintf(yyout, "\"\n");
}

