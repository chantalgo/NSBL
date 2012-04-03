%{
#include <stdio.h>
#include <stdlib.h>

#include <SymbolTable.h>

extern FILE *yyin; /* Input for yacc parser. */
extern void yyerror(char *str); /* Our version. */
extern int yywrap(void); /* Our version. */
extern int yylex(void); /* Lexical analyzer function. */
extern int yyparse(void); /* Parser function. */

#include "ASTree.h"
#include "SymbolTable.h"
%}

/**************************
 * Field names            *
 **************************/
%union{
    struct Node*    node;
    char *          str;
}
%type <str> IDENTIFIER
%type <node> declaration
%type <node> basic_type_specifier declaration_specifiers 
%type <node> init_declarator_list init_declarator declarator direct_declarator
/**************************
 *      TOKEN LIST        *
 **************************/
/* TYPE RELATED */
%token VOID BOOLEAN INTEGER FLOAT STRING LIST VERTEX EDGE GRAPH
%token IDENTIFIER INTEGER_CONSTANT FLOAT_CONSTANT STRING_LITERAL
%token TRUE FALSE
/* FUNCTIONS RELATED */
%token FUNC_LITERAL
/* GRAPH RELATED */
%token OUTCOMING_EDGES INCOMING_EDGES STARTING_VERTICES ENDING_VERTICES
%token ALL_VERTICES ALL_EDGES
/* OPERATOR */
%token OR AND
%token EQ NE
%token GT LT GE LE
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token APPEND ARROW PIPE AT MARK
%token BELONG
/* CONTROL */
%token IF ELSE
%token FOR FOREACH WHILE
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
    | FOR '(' expression ';' expression ';' ')' statement
    | FOR '(' expression ';' ';' expression ')' statement
    | FOR '(' expression ';' ';' ')' statement
    | FOR '(' ';' expression ';' expression ')' statement
    | FOR '(' ';' expression ';' ')' statement
    | FOR '(' ';' ';' expression ')' statement
    | FOR '(' ';' ';' ')' statement
    | FOREACH '(' IDENTIFIER ':' postfix_expression ')' statement
    ;

jump_statement
    : BREAK ';'
    | CONTINUE ';'
    | RETURN expression ';'
    | RETURN ';'
    ;

declaration_statement
    : declaration
    | function_literal_declaration
    ;

/**************************
 *   EXPRESSIONS          *
 **************************/

expression
    : assignment_expression
    | expression ',' assignment_expression
    ;

assignment_expression
    : logical_OR_expression
    | unary_expression assignment_operator assignment_expression
    ;

assignment_operator
    : '='
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | APPEND
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
    : cast_expression
    | multiplicative_expression '*' cast_expression
    | multiplicative_expression '/' cast_expression
    ;

cast_expression
    : unary_expression
    | '(' declaration_specifiers ')' cast_expression
    ;

unary_expression
    : postfix_expression
    | unary_operator cast_expression
    ;

unary_operator
    : '+'
    | '-'
    | '!'
    ;

postfix_expression
    : primary_expression
    | primary_expression ':' primary_expression ARROW primary_expression
    | primary_expression ':' primary_expression ARROW primary_expression MARK primary_expression 
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '(' ')'
    | postfix_expression PIPE pipe_property
    | postfix_expression '[' logical_OR_expression ']'
    | postfix_expression '.' IDENTIFIER
    | postfix_expression '.' graph_property
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
    : INTEGER_CONSTANT
    | FLOAT_CONSTANT
    | TRUE
    | FALSE
    ;

/**************************
 *   DECLARATION          *
 **************************/

function_literal_declaration
    : function_literal_type_sepcifier declarator '=' compound_statement ';'
    | function_literal_type_sepcifier declarator ':' declaration_specifiers '=' compound_statement ';'
    ;

function_definition
    : declaration_specifiers declarator compound_statement
    ;

function_literal_type_sepcifier
    : FUNC_LITERAL
    ;

basic_type_specifier
    : VOID      { int ttype = VOID_T;   $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | BOOLEAN   { int ttype = BOOL_T;   $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | INTEGER   { int ttype = INT_T;    $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | FLOAT     { int ttype = FLOAT_T;  $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | STRING    { int ttype = STRING_T; $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | LIST      { int ttype = LIST_T;   $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | VERTEX    { int ttype = VERTEX_T; $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | EDGE      { int ttype = EDGE_T;   $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    | GRAPH     { int ttype = GRAPH_T;  $$= ast_new_leaf(AST_TYPE_SPECIFIER, (void *) &(ttype)); }
    ;

declaration
    : declaration_specifiers init_declarator_list ';' {
        $$ = ast_new_node( AST_DECLARATION, 2, ast_all_children(2, $1, $2) );    
    }
    ;

declaration_specifiers
    : basic_type_specifier {
        $$= $1;
    }
    ;

init_declarator_list
    : init_declarator {
        $$ = $1;
    }
    | init_declarator_list ',' init_declarator {
        $$ = ast_new_node( AST_COMMA, 2, ast_all_children(2, $1, $3) );
    }
    ;

init_declarator
    : declarator {
        $$ = $1;
    }
    | declarator '=' initializer
    ;

declarator
    : direct_declarator {
        $$ = $1;
    }
    ;

direct_declarator
    : IDENTIFIER {
        $$ = ast_new_leaf(IDENTIFIER, $1);
    }
    | IDENTIFIER '(' parameter_list ')'
    | IDENTIFIER '(' ')'
    | direct_declarator BELONG IDENTIFIER
    ;

parameter_list
    : parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration
    : declaration_specifiers IDENTIFIER
    | function_literal_type_sepcifier IDENTIFIER
    ;

initializer
    : assignment_expression
    | '[' initializer_list ']'
    | '[' ']'
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
