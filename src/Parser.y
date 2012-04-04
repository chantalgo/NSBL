%{
#include <stdio.h>
#include <stdlib.h>

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
    char *          string;
    int             integer;
}
// basic
%type <integer> assignment_operator unary_operator 
%type <string> IDENTIFIER STRING_LITERAL INTEGER_CONSTANT FLOAT_CONSTANT
// declaration
%type <node> declaration
%type <node> basic_type_specifier declaration_specifiers 
%type <node> init_declarator_list init_declarator declarator direct_declarator
%type <node> parameter_list parameter_declaration
%type <node> initializer initializer_list

// expression
%type <node> expression assignment_expression logical_OR_expression 
%type <node> logical_AND_expression equality_expression relational_expression
%type <node> additive_expression multiplicative_expression cast_expression
%type <node> unary_expression postfix_expression primary_expression
%type <node> graph_property pipe_property argument_expression_list
%type <node> attribute constant

// statments
%type <node> external_statement statement 
%type <node> expression_statement compound_statement selection_statement 
%type <node> iteration_statement jump_statement declaration_statement
%type <node> statement_list 

// function
%type <integer> function_literal_type_specifier
%type <node> function_definition
%type <node> function_literal_declaration

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
%token ADD SUB MUL DIV
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
/* used in AST */
%token AST_TYPE_SPECIFIER AST_DECLARATION AST_COMMA
%token AST_ASSIGN AST_CAST
%token AST_UNARY_PLUS AST_UNARY_MINUS AST_UNARY_NOT
%token AST_FUNC_DECLARATOR AST_PARA_DECLARATION AST_FUNC
%token AST_LIST_INIT
%token AST_MATCH AST_ATTIBUTE AST_GRAPH_PROP
%token AST_STAT_LIST AST_COMP_STAT
%token AST_IF_STAT AST_IFELSE_STAT
%token AST_WHILE AST_FOR_XXX AST_FOR_XXO AST_FOR_XOX AST_FOR_XOO AST_FOR_OXX AST_FOR_OXO AST_FOR_OOX AST_FOR_OOO AST_FOREACH
%token AST_JUMP_CONTINUE AST_JUMP_BREAK AST_JUMP_RETURN
%token AST_POSTFIX_EPR
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
    : function_definition{
		$$ = $1;
		fprintf(stdout, "==FUNCTION DEFINITION==\n");
		ast_output_subtree($$, stdout, 0);
		fprintf(stdout, "=======================\n");
	}
    | statement{ 
        $$ = $1; 
        fprintf(stdout, "==EXTERNAL STATEMENT==\n");
        ast_output_subtree($$, stdout, 0);
        fprintf(stdout, "======================\n");
    }
    ;

statement
    : expression_statement          { $$ = $1; }
    | compound_statement            { $$ = $1; }
    | selection_statement           { $$ = $1; }
    | iteration_statement           { $$ = $1; }
    | jump_statement                { $$ = $1; }
    | declaration_statement         { $$ = $1; }
    ;

expression_statement
    : expression ';'                { $$ = $1; }
    | ';'                           { $$ = NULL; }
    ;

statement_list
    : statement                     { $$ = $1; }
    | statement_list statement{
        $$ = ast_new_node( AST_STAT_LIST, 2, ast_all_children(2, $1, $2) );
    }
    ;

compound_statement
    : '{' '}' { 
        $$ = ast_new_node( AST_COMP_STAT, 0, NULL );
    }
    | '{' statement_list '}' { 
        $$ = ast_new_node( AST_COMP_STAT, 1, ast_all_children(1, $2) );
    }
    ;

selection_statement
    : IF '(' expression ')' statement {$$ = ast_new_node(AST_IF_STAT, 2, ast_all_children(2, $3, $5));} %prec LOWER_THAN_ELSE ;	
    | IF '(' expression ')' statement ELSE statement			{$$ = ast_new_node(AST_IFELSE_STAT, 3, ast_all_children(3,$3, $5, $7));}
    ;

iteration_statement
    : WHILE '(' expression ')' statement								{$$ = ast_new_node(AST_WHILE, 2, ast_all_children(2, $3, $5));}
    | FOR '(' expression ';' expression ';' expression ')' statement	{$$ = ast_new_node(AST_FOR_XXX, 4, ast_all_children(4, $3, $5, $7, $9));}
    | FOR '(' expression ';' expression ';' ')' statement				{$$ = ast_new_node(AST_FOR_XXO, 3, ast_all_children(3, $3, $5, $8));}
    | FOR '(' expression ';' ';' expression ')' statement				{$$ = ast_new_node(AST_FOR_XOX, 3, ast_all_children(3, $3, $6, $8));}
    | FOR '(' expression ';' ';' ')' statement							{$$ = ast_new_node(AST_FOR_XOO, 2, ast_all_children(2, $3, $7));}
    | FOR '(' ';' expression ';' expression ')' statement				{$$ = ast_new_node(AST_FOR_OXX, 3, ast_all_children(3, $4, $6, $8));}
    | FOR '(' ';' expression ';' ')' statement							{$$ = ast_new_node(AST_FOR_OXO, 2, ast_all_children(2, $4, $7));}
    | FOR '(' ';' ';' expression ')' statement							{$$ = ast_new_node(AST_FOR_OOX, 2, ast_all_children(2, $5, $7));}
    | FOR '(' ';' ';' ')' statement										{$$ = ast_new_node(AST_FOR_OOO, 1, ast_all_children(1, $6));}
    | FOREACH '(' IDENTIFIER ':' postfix_expression ')' statement		{$$ = ast_new_node(AST_FOREACH, 3, ast_all_children(3, $3, $5, $7));}
    ;

jump_statement
    : BREAK ';'							{$$ = ast_new_node(AST_JUMP_BREAK, 0, NULL);}
    | CONTINUE ';'						{$$ = ast_new_node(AST_JUMP_CONTINUE, 0, NULL);}
    | RETURN expression ';'				{$$ = ast_new_node(AST_JUMP_RETURN, 1, ast_all_children(1, $2));}
    | RETURN ';'						{$$ = ast_new_node(AST_JUMP_RETURN, 0, NULL);}
    ;

declaration_statement
    : declaration                       { $$ = $1; }
    | function_literal_declaration      
    ;

/**************************
 *   EXPRESSIONS          *
 **************************/

expression
    : assignment_expression { $$ = $1; }
    | expression ',' assignment_expression  {
        $$ = ast_new_node ( AST_COMMA, 2, ast_all_children(2, $1, $3) );
    }
    ;

assignment_expression
    : logical_OR_expression { $$ = $1; }
    | unary_expression assignment_operator assignment_expression {
       $$ = ast_new_node ( $2, 2, ast_all_children(2, $1, $3) ); 
    }
    ;

assignment_operator
    : '='               { $$ = AST_ASSIGN; }
    | ADD_ASSIGN        { $$ = ADD_ASSIGN; }
    | SUB_ASSIGN        { $$ = SUB_ASSIGN; }
    | MUL_ASSIGN        { $$ = MUL_ASSIGN; }
    | DIV_ASSIGN        { $$ = DIV_ASSIGN; }
    | APPEND            { $$ = APPEND; }
    ;

logical_OR_expression
    : logical_AND_expression { $$ = $1; }
    | logical_OR_expression OR logical_AND_expression {
        $$ = ast_new_node ( OR, 2, ast_all_children(2, $1, $3) );
    }
    ;

logical_AND_expression
    : equality_expression { $$ = $1; }
    | logical_AND_expression AND equality_expression {
        $$ = ast_new_node ( AND, 2, ast_all_children(2, $1, $3) );
    }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        $$ = ast_new_node ( EQ, 2, ast_all_children(2, $1, $3) );
    }
    | equality_expression NE relational_expression {
        $$ = ast_new_node ( NE, 2, ast_all_children(2, $1, $3) );
    }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        $$ = ast_new_node ( LT, 2, ast_all_children(2, $1, $3) );
    }
    | relational_expression GT additive_expression {
        $$ = ast_new_node ( GT, 2, ast_all_children(2, $1, $3) );
    }
    | relational_expression LE additive_expression {
        $$ = ast_new_node ( LE, 2, ast_all_children(2, $1, $3) );
    }
    | relational_expression GE additive_expression {
        $$ = ast_new_node ( GE, 2, ast_all_children(2, $1, $3) );
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression ADD multiplicative_expression {
        $$ = ast_new_node ( ADD, 2, ast_all_children(2, $1, $3) );
    }
    | additive_expression SUB multiplicative_expression {
        $$ = ast_new_node ( SUB, 2, ast_all_children(2, $1, $3) );
    }
    ;

multiplicative_expression
    : cast_expression { $$ = $1; }
    | multiplicative_expression MUL cast_expression {
        $$ = ast_new_node ( MUL, 2, ast_all_children(2, $1, $3) );
    }
    | multiplicative_expression DIV cast_expression {
        $$ = ast_new_node ( DIV, 2, ast_all_children(2, $1, $3) );
    }
    ;

cast_expression
    : unary_expression { $$ = $1; }
    | '(' declaration_specifiers ')' cast_expression {
        $$ = ast_new_node ( AST_CAST, 2, ast_all_children(2, $2, $4) );
    }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | unary_operator cast_expression {
        $$ = ast_new_node ( $1, 1, ast_all_children(1, $2) );
    }
    ;

unary_operator
    : ADD   { $$ = AST_UNARY_PLUS; }
    | SUB   { $$ = AST_UNARY_MINUS; }
    | '!'   { $$ = AST_UNARY_NOT; }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | primary_expression ':' primary_expression ARROW primary_expression {
        $$ = ast_new_node ( ARROW, 3, ast_all_children(3, $1, $3, $5) );
    }
    | primary_expression ':' primary_expression ARROW primary_expression MARK primary_expression 
    | postfix_expression '(' argument_expression_list ')' 											{$$ = ast_new_node(AST_POSTFIX_EPR, 2, ast_all_children(2, $1, $3));}
    | postfix_expression '(' ')'																	{$$ = ast_new_node(AST_POSTFIX_EPR, 1, ast_all_children(1, $1));}
    | postfix_expression PIPE pipe_property {
        $$ = ast_new_node ( PIPE, 2, ast_all_children(2, $1, $3) );
    }
    | postfix_expression '[' logical_OR_expression ']' {
        $$ = ast_new_node ( AST_MATCH, 2, ast_all_children(2, $1, $3) );
    }
    | postfix_expression '.' IDENTIFIER {
        $$ = ast_new_node ( AST_ATTIBUTE, 2, ast_all_children(2, $1, $3) );
    }
    | postfix_expression '.' graph_property {
        $$ = ast_new_node ( AST_GRAPH_PROP, 2, ast_all_children(2, $1, $3) );
    }
    ;

primary_expression
    : attribute             { $$ = $1; }
    | IDENTIFIER            { $$ = ast_new_leaf(IDENTIFIER, $1); }
    | constant              { $$ = $1; }
    | STRING_LITERAL        { $$ = ast_new_leaf(STRING_LITERAL, $1); }
    | '(' expression ')'    { $$ = $2; }
    ;

graph_property
    : ALL_VERTICES          { $$ = ast_new_leaf(ALL_VERTICES, NULL); }
    | ALL_EDGES             { $$ = ast_new_leaf(ALL_EDGES, NULL); }
    ;

pipe_property
    : OUTCOMING_EDGES       { $$ = ast_new_leaf(OUTCOMING_EDGES, NULL); }
    | INCOMING_EDGES        { $$ = ast_new_leaf(INCOMING_EDGES, NULL); }
    | STARTING_VERTICES     { $$ = ast_new_leaf(STARTING_VERTICES, NULL); }
    | ENDING_VERTICES       { $$ = ast_new_leaf(ENDING_VERTICES, NULL); }
    ;

argument_expression_list
    : assignment_expression { $$ = $1; }
    | argument_expression_list ',' assignment_expression {
        $$ = ast_new_node ( AST_COMMA, 2, ast_all_children(2, $1, $3) );
    }
    ;

attribute
    : AT IDENTIFIER{ 
        $$ = ast_new_node ( AT, 1, ast_all_children(1, $2) );
    }
    ;

constant
    : INTEGER_CONSTANT      { $$ = ast_new_leaf(INTEGER_CONSTANT, (void *) $1); }
    | FLOAT_CONSTANT        { $$ = ast_new_leaf(FLOAT_CONSTANT, (void *) $1); }
    | TRUE                  { $$ = ast_new_leaf(TRUE, NULL); }
    | FALSE                 { $$ = ast_new_leaf(FALSE, NULL); }
    ;

/**************************
 *   DECLARATION          *
 **************************/

function_literal_declaration
    : function_literal_type_specifier declarator '=' compound_statement ';'									{$$ = ast_new_node($1, 2, ast_all_children(2, $2, $4));}
    | function_literal_type_specifier declarator ':' declaration_specifiers '=' compound_statement ';'		{$$ = ast_new_node($1, 3, ast_all_children(3, $2, $4, $6));}
    ;

function_definition
    : declaration_specifiers declarator compound_statement						{$$ = ast_new_node(AST_FUNC, 3, ast_all_children(3, $1, $2, $3));}
    ;

function_literal_type_specifier
    : FUNC_LITERAL		{$$ = FUNC_LITERAL;}
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
    | declarator '=' initializer {
        $$ = ast_new_node( AST_ASSIGN, 2, ast_all_children(2, $1, $3) );
    }
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
    | IDENTIFIER '(' parameter_list ')' {
        $$ = ast_new_node( AST_FUNC_DECLARATOR, 2, ast_all_children(2, ast_new_leaf(IDENTIFIER, $1), $3) );
    }
    | IDENTIFIER '(' ')' {
        $$ = ast_new_node( AST_FUNC_DECLARATOR, 1, ast_all_children(1, ast_new_leaf(IDENTIFIER, $1) ) );
    }
    | direct_declarator BELONG IDENTIFIER {
        $$ = ast_new_node( BELONG, 2, ast_all_children(2, $1, $3) );
    }
    ;

parameter_list
    : parameter_declaration { $$ = $1; }
    | parameter_list ',' parameter_declaration {
        $$ = ast_new_node( AST_COMMA, 2, ast_all_children(2, $1, $3) );
    }
    ;

parameter_declaration
    : declaration_specifiers IDENTIFIER {
        $$ = ast_new_node( AST_PARA_DECLARATION, 2, ast_all_children(2, $1, ast_new_leaf(IDENTIFIER, $2)));
    }
    | function_literal_type_specifier IDENTIFIER {
    }
    ;

initializer
    : assignment_expression { $$ = $1; }
    | '[' initializer_list ']' {
        $$ = ast_new_node( AST_LIST_INIT, 1, ast_all_children(1, $2) );
    }
    | '[' ']' {
        $$ = ast_new_node( AST_LIST_INIT, 0, NULL );
    }
    ;

initializer_list
    : initializer { $$ = $1; }
    | initializer_list ',' initializer {
        $$ = ast_new_node( AST_COMMA, 2, ast_all_children(2, $1, $3) );
    }
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
