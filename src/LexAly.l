%{
#include <stdio.h>
#include "Parser.tab.h"


#ifdef _MYECHO
#define MYECHO myecho() 
#else
#define MYECHO 
#endif
%}

letter_         [A-Za-z_]
digit           [0-9]
numconst        ({digit}*\.?{digit}+|{digit}+\.?{digit}*)([eE][+-]?{digit}+)?
identifier      {letter_}({letter_}|{digit})*
strliteral      \"([^\"\\]|\\.)*\"
comment         (\/\*([^\*]|(\*+([^\*\/])))*\*+\/)|(\/\/.*)

%%
"boolean"       { MYECHO; return BOOLEAN; }
"number"        { MYECHO; return NUMBER; }
"string"        { MYECHO; return STRING; }
"list"          { MYECHO; return LIST; }
"vertex"        { MYECHO; return VERTEX; }
"edge"          { MYECHO; return EDGE; }
"graph"         { MYECHO; return GRAPH; }

"if"            { MYECHO; return IF; }
"else"          { MYECHO; return ELSE; }
"for"           { MYECHO; return FOR; }
"while"         { MYECHO; return WHILE; }
"break"         { MYECHO; return BREAK; }
"continue"      { MYECHO; return CONTINUE; }
"return"        { MYECHO; return RETURN; }

"outE"          { MYECHO; return OUTCOMING_EDGES; }
"inE"           { MYECHO; return INCOMING_EDGES; }
"strtV"         { MYECHO; return STARTING_VERTICES; }
"endV"          { MYECHO; return ENDING_VERTICES; }


"..."           { MYECHO; return ELLIPSIS; }
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

"<:"            { MYECHO; return EAT; }
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

{identifier}    { MYECHO; return IDENTIFIER; }
{numconst}      { MYECHO; return NUMBER_CONSTANT; }
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

