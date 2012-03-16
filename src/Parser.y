%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin; /* Input for yacc parser. */
extern void yyerror(char *str); /* Our version. */
extern int yywrap(void); /* Our version. */
extern int yylex(void); /* Lexical analyzer function. */
extern int yyparse(void); /* Parser function. */

%}

/**************************
 *      TOKEN LIST        *
 **************************/
/* TYPE RELATED */
%token BOOLEAN NUMBER STRING LIST VERTEX EDGE GRAPH
%token IDENTIFIER NUMBER_CONSTANT STRING_LITERAL
%token TRUE FALSE
/* FUNCTIONS RELATED */
%token DEF
/* GRAPH RELATED */
%token OUTCOMING_EDGES INCOMING_EDGES STARTING_VERTICES ENDING_VERTICES
%token ALL_VERTICES ALL_EDGES
/* OPERATOR */
%token OR AND
%token EQ NE
%token GT LT GE LE ELLIPSIS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token EAT ARROW PIPE AT
/* CONTROL */
%token IF ELSE
%token FOR WHILE
%token BREAK CONTINUE
%token RETURN

/**************************
 *  PRECEDENCE & ASSOC    *
 **************************/
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/**************************
 *     START SYMBOL       *
 **************************/
%start translation_unit

%%

/**************************
 *   BASIC CONCEPTS       *
 **************************/
translation_unit
    : external_statement
    | translation_unit external_statement
    ;

/**************************
 *   STATEMENTS           *
 **************************/
external_statement
    : function_definition
    | statement
    ;

statement
    : expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | declaration_statement
    ;

expression_statement
    : expression ';'
    | ';'
    ;

statement_list
    : statement
    | statement_list statement
    ;

compound_statement
    : '{' '}'
    | '{' statement_list '}'
    ;

selection_statement
    : IF '(' expression ')' statement %prec LOWER_THAN_ELSE ;
    | IF '(' expression ')' statement ELSE statement
    ;

iteration_statement
    : WHILE '(' expression ')' statement
    | FOR '(' expression ';' expression ';' expression ')' statement
    ;

jump_statement
    : BREAK ';'
    | CONTINUE ';'
    | RETURN expression ';'
    | RETURN ';'
    ;

declaration_statement
    : declaration
    ;

/**************************
 *   EXPRESSIONS          *
 **************************/

expression
    : assignment_expression
    | expression ',' assignment_expression
    ;

assignment_expression
    : conditional_expression
    | unary_expression assignment_operator assignment_expression
    ;

assignment_operator
    : '='
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | EAT
    ;

conditional_expression
    : logical_OR_expression
    ;

logical_OR_expression
    : logical_AND_expression
    | logical_OR_expression OR logical_AND_expression
    ;

logical_AND_expression
    : equality_expression
    | logical_AND_expression AND equality_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NE relational_expression
    ;

relational_expression
    : additive_expression
    | relational_expression LT additive_expression
    | relational_expression GT additive_expression
    | relational_expression LE additive_expression
    | relational_expression GE additive_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression '*' unary_expression
    | multiplicative_expression '/' unary_expression
    ;

unary_expression
    : postfix_expression
    | unary_operator unary_expression
    ;

unary_operator
    : '+'
    | '-'
    | '!'
    ;

postfix_expression
    : primary_expression
    | primary_expression ':' primary_expression ARROW primary_expression
    | postfix_expression PIPE pipe_property
    | postfix_expression '[' conditional_expression ']'
    | postfix_expression '.' IDENTIFIER
    | postfix_expression '.' graph_property
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '(' ')'
    ;

primary_expression
    : attribute
    | IDENTIFIER
    | constant
    | STRING_LITERAL
    | '(' expression ')'
    ;

graph_property
    : ALL_VERTICES
    | ALL_EDGES
    ;

pipe_property
    : OUTCOMING_EDGES
    | INCOMING_EDGES
    | STARTING_VERTICES
    | ENDING_VERTICES
    ;

argument_expression_list
    : assignment_expression
    | argument_expression_list ',' assignment_expression
    ;

attribute
    : AT IDENTIFIER
    ;

constant
    : NUMBER_CONSTANT
    | TRUE
    | FALSE
    ;

/**************************
 *   DECLARATION          *
 **************************/

/*
function_definition
    : DEF declarator ':' declaration_specifiers  compound_statement
    ;
*/
function_definition
    : declaration_specifiers declarator compound_statement
    ;

type_specifier
    : BOOLEAN
    | NUMBER
    | STRING
    | LIST
    | VERTEX
    | EDGE
    | GRAPH
    ;

declaration_specifiers
    : type_specifier
    ;

declaration
    : declaration_specifiers init_declarator_list ';'
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator
    : declarator
    | declarator '=' initializer
    ;

declarator
    : direct_declarator
    ;

direct_declarator
    : IDENTIFIER
    | '(' declarator ')'
    | direct_declarator '(' parameter_type_list ')'
    | direct_declarator '(' ')'
    | direct_declarator '(' identifier_list ')'
    ;

identifier_list
    : IDENTIFIER
    | identifier_list ',' IDENTIFIER
    ;

parameter_type_list
    : parameter_list
    | parameter_list ',' ELLIPSIS
    ;

parameter_list
    : parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration
    : declaration_specifiers declarator
    ;

initializer
    : assignment_expression
    | '{' initializer_list '}'
    | '{' initializer_list ',' '}'
    ;

initializer_list
    : initializer
    | initializer_list ',' initializer
    ;

%%

void yyerror(char *s) {
    printf("%s\n", s);
}

int main(int argc, char * const * argv) {
    if (argc<=1) { // missing file
        fprintf(stdout, "missing input file\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    fclose(yyin);
    return 0;
}
