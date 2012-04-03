%{
#include <stdio.h>
#include "Parser.tab.h"


#ifdef _MYECHO
#define MYECHO myecho() 
#else
#define MYECHO 
#endif
void  myecho();
%}

letter_         [A-Za-z_]
digit           [0-9]
floatconst      ({digit}*\.{digit}+|{digit}+\.{digit}*)([eE][+-]?{digit}+)?
intconst        {digit}+
identifier      {letter_}({letter_}|{digit})*
strliteral      \"([^\"\\]|\\.)*\"
comment         (\/\*([^\*]|(\*+([^\*\/])))*\*+\/)|(\/\/.*)

%%
"void"          { MYECHO; return VOID; }
"boolean"       { MYECHO; return BOOLEAN; }
"int"           { MYECHO; return INTEGER; }
"float"         { MYECHO; return FLOAT; }
"string"        { MYECHO; return STRING; }
"list"          { MYECHO; return LIST; }
"vertex"        { MYECHO; return VERTEX; }
"edge"          { MYECHO; return EDGE; }
"graph"         { MYECHO; return GRAPH; }

"func"			{ MYECHO; return FUNC_LITERAL; }
"if"            { MYECHO; return IF; }
"else"          { MYECHO; return ELSE; }
"for"           { MYECHO; return FOR; }
"foreach"       { MYECHO; return FOREACH; }
"while"         { MYECHO; return WHILE; }
"break"         { MYECHO; return BREAK; }
"continue"      { MYECHO; return CONTINUE; }
"return"        { MYECHO; return RETURN; }
"mark"			{ MYECHO; return MARK; }

"outE"          { MYECHO; return OUTCOMING_EDGES; }
"inE"           { MYECHO; return INCOMING_EDGES; }
"strtV"         { MYECHO; return STARTING_VERTICES; }
"endV"          { MYECHO; return ENDING_VERTICES; }
"allV"          { MYECHO; return ALL_VERTICES; }
"allE"          { MYECHO; return ALL_EDGES; }

"=="            { MYECHO; return EQ; }
"!="            { MYECHO; return NE; }
"<="            { MYECHO; return LE; }
">="            { MYECHO; return GE; }
"+="            { MYECHO; return ADD_ASSIGN; }
"-="            { MYECHO; return SUB_ASSIGN; }
"*="            { MYECHO; return MUL_ASSIGN; }
"/="            { MYECHO; return DIV_ASSIGN; }
"||"            { MYECHO; return OR; }
"&&"            { MYECHO; return AND; }
"::"			{ MYECHO; return BELONG; }

"<:"            { MYECHO; return APPEND; }
"->"            { MYECHO; return ARROW; }
"|"             { MYECHO; return PIPE; }
"@"             { MYECHO; return AT; }

"{"             { MYECHO; return '{'; }
"}"             { MYECHO; return '}'; }
"("             { MYECHO; return '('; }
")"             { MYECHO; return ')'; }
"["             { MYECHO; return '['; }
"]"             { MYECHO; return ']'; }
";"             { MYECHO; return ';'; }
","             { MYECHO; return ','; }
":"             { MYECHO; return ':'; }
"."             { MYECHO; return '.'; }
"!"             { MYECHO; return '!'; }
"+"             { MYECHO; return '+'; }
"-"             { MYECHO; return '-'; }
"*"             { MYECHO; return '*'; }
"/"             { MYECHO; return '/'; }
"="             { MYECHO; return '='; }
">"             { MYECHO; return GT; }
"<"             { MYECHO; return LT; }

"true"          { MYECHO; return TRUE; }
"false"         { MYECHO; return FALSE; }
{intconst}      { MYECHO; return INTEGER_CONSTANT;}
{floatconst}    { MYECHO; return FLOAT_CONSTANT;}
{identifier}    { MYECHO; yylval.str = (char *) malloc ( strlen(yytext) ); strcpy( yylval.str, yytext ); return IDENTIFIER; }
{strliteral}    { MYECHO; return STRING_LITERAL; }
{comment}       { MYECHO; }

[ \t\n]         { }
.               { ECHO; }

%%

void myecho() {
    fprintf(yyout, "LEX:");
    fprintf(yyout, "YYLENG=%d:",yyleng);
    fprintf(yyout, "YYTEXT=");
    ECHO; 
    fprintf(yyout, "\n");
}

