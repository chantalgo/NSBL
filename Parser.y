%{
#include <stdio.h>

%}

%token BOOLEAN NUMBER STRING LIST VERTEX EDGE GRAPH
%token TRUE FALSE
%token IDENTIFIER NUMBER_CONSTANT STRING_LITERAL
%token OUTCOMING_EDGES INCOMING_EDGES STARTING_VERTICES ENDING_VERTICES

%token OR AND
%token EQ NE
%token GT LT GE LE ELLIPSIS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token EAT ARROW PIPE AT 

%token IF ELSE
%token FOR WHILE
%token BREAK CONTINUE
%token RETURN

%%
start
    : start translation_unit
    | start
    |
    ;

translation_unit
    : external_declaration
    | translation_unit external_declaration
    ;

external_declaration
    : declaration
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
    | init_declarator_list ';'
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
    | postfix_expression PIPE graph_property
    | postfix_expression '[' conditional_expression ']'
    | postfix_expression '.' IDENTIFIER
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

%%
int yyerror(char *s) {
    printf("%s\n", s);
    return 1;
}

int main(void) {
    yyparse();
    return 0;
}


