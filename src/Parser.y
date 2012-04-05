%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin; /* Input for yacc parser. */
extern void yyerror(char *str); /* Our version. */
extern int yywrap(void); /* Our version. */
extern int yylex(void); /* Lexical analyzer function. */
extern int yyparse(void); /* Parser function. */

#include "global.h"
#include "ASTree.h"
#include "SymbolTable.h"
#include "SymbolTableUtil.h"
#include "util.h"
%}

/**************************
 * Field names            *
 **************************/
%union{
    struct Node*    node;
    struct {
        char *          s;
        long long       l;
    }LString;
    struct {
        int             i;
        long long       l;
    }LInteger;
}
// basic
%type <LInteger> assignment_operator unary_operator 
%type <LString> IDENTIFIER STRING_LITERAL INTEGER_CONSTANT FLOAT_CONSTANT
%type <LString> '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN APPEND
%type <LString> ADD SUB MUL DIV '!'
%type <LString> EQ NE LE GE LT GT OR AND BELONG
%type <LString> ARROW PIPE AT
%type <LString> BOOL_TRUE BOOL_FALSE
%type <LString> OUTCOMING_EDGES INCOMING_EDGES STARTING_VERTICES ENDING_VERTICES
%type <LString> ALL_VERTICES ALL_EDGES
%type <LString> VOID BOOLEAN INTEGER FLOAT STRING LIST VERTEX EDGE GRAPH
%type <LString> FUNC_LITERAL
%type <LString> IF ELSE FOR FOREACH WHILE BREAK CONTINUE RETURN MARK
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
%type <node> start_nonterminal translation_unit
%type <node> external_statement statement 
%type <node> expression_statement compound_statement selection_statement 
%type <node> iteration_statement jump_statement declaration_statement
%type <node> statement_list 

/**************************
 *      TOKEN LIST        *
 **************************/
/* TYPE RELATED */
%token VOID BOOLEAN INTEGER FLOAT STRING LIST VERTEX EDGE GRAPH
%token IDENTIFIER INTEGER_CONSTANT FLOAT_CONSTANT STRING_LITERAL
%token BOOL_TRUE BOOL_FALSE
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
%token AST_FUNC_DECLARATOR AST_PARA_DECLARATION 
%token AST_INIT_ASSGN AST_LIST_INIT
%token AST_MATCH AST_ATTIBUTE AST_GRAPH_PROP
%token AST_STAT_LIST AST_COMP_STAT AST_EXT_STAT_COMMA
/**************************
 *  PRECEDENCE & ASSOC    *
 **************************/
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/**************************
 *     START SYMBOL       *
 **************************/
%start start_nonterminal

%%

/**************************
 *   BASIC CONCEPTS       *
 **************************/
start_nonterminal
    : translation_unit {
        $$ = $1;
        astFreeTree($$);
    }
    ;

translation_unit
    : external_statement           { $$ = $1; } 
    | translation_unit external_statement {
        $$ = astNewNode( AST_EXT_STAT_COMMA, 2, astAllChildren( 2, $1, $2 ) );
    }
    ;

/**************************
 *   STATEMENTS           *
 **************************/
external_statement
    : function_definition
    | statement{ 
        $$ = $1; 
        fprintf(stdout, "==EXTERNAL STATEMENT==\n");
        astOutTree($$, stdout, 0);
        fprintf(stdout, "======================\n");
        sTableShow(stdout);
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
        $$ = astNewNode( AST_STAT_LIST, 2, astAllChildren(2, $1, $2) );
    }
    ;

compound_statement
    : '{' '}' { 
        $$ = astNewNode( AST_COMP_STAT, 0, NULL );
    }
    | '{' scope_in statement_list scope_out '}'   { 
        $$ = astNewNode( AST_COMP_STAT, 1, astAllChildren(1, $3) );
    }
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
    : declaration                       { $$ = $1; }
    | function_literal_declaration      
    ;

/**************************
 *   EXPRESSIONS          *
 **************************/

expression
    : assignment_expression { $$ = $1; }
    | expression ',' assignment_expression  {
        $$ = astNewNode ( AST_COMMA, 2, astAllChildren(2, $1, $3) );
    }
    ;

assignment_expression
    : logical_OR_expression { $$ = $1; }
    | unary_expression assignment_operator assignment_expression {
       $$ = astNewNode ( $2.i, 2, astAllChildren(2, $1, $3) ); 
    }
    ;

assignment_operator
    : '='               { $$.i = AST_ASSIGN; $$.l = $1.l; }
    | ADD_ASSIGN        { $$.i = ADD_ASSIGN; $$.l = $1.l; }
    | SUB_ASSIGN        { $$.i = SUB_ASSIGN; $$.l = $1.l; }
    | MUL_ASSIGN        { $$.i = MUL_ASSIGN; $$.l = $1.l; }
    | DIV_ASSIGN        { $$.i = DIV_ASSIGN; $$.l = $1.l; }
    | APPEND            { $$.i = APPEND;     $$.l = $1.l; }
    ;

logical_OR_expression
    : logical_AND_expression { $$ = $1; }
    | logical_OR_expression OR logical_AND_expression {
        $$ = astNewNode ( OR, 2, astAllChildren(2, $1, $3) );
    }
    ;

logical_AND_expression
    : equality_expression { $$ = $1; }
    | logical_AND_expression AND equality_expression {
        $$ = astNewNode ( AND, 2, astAllChildren(2, $1, $3) );
    }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        $$ = astNewNode ( EQ, 2, astAllChildren(2, $1, $3) );
    }
    | equality_expression NE relational_expression {
        $$ = astNewNode ( NE, 2, astAllChildren(2, $1, $3) );
    }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        $$ = astNewNode ( LT, 2, astAllChildren(2, $1, $3) );
    }
    | relational_expression GT additive_expression {
        $$ = astNewNode ( GT, 2, astAllChildren(2, $1, $3) );
    }
    | relational_expression LE additive_expression {
        $$ = astNewNode ( LE, 2, astAllChildren(2, $1, $3) );
    }
    | relational_expression GE additive_expression {
        $$ = astNewNode ( GE, 2, astAllChildren(2, $1, $3) );
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression ADD multiplicative_expression {
        $$ = astNewNode ( ADD, 2, astAllChildren(2, $1, $3) );
    }
    | additive_expression SUB multiplicative_expression {
        $$ = astNewNode ( SUB, 2, astAllChildren(2, $1, $3) );
    }
    ;

multiplicative_expression
    : cast_expression { $$ = $1; }
    | multiplicative_expression MUL cast_expression {
        $$ = astNewNode ( MUL, 2, astAllChildren(2, $1, $3) );
    }
    | multiplicative_expression DIV cast_expression {
        $$ = astNewNode ( DIV, 2, astAllChildren(2, $1, $3) );
    }
    ;

cast_expression
    : unary_expression { $$ = $1; }
    | '(' declaration_specifiers ')' cast_expression {
        $$ = astNewNode ( AST_CAST, 2, astAllChildren(2, $2, $4) );
    }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | unary_operator cast_expression {
        $$ = astNewNode ( $1.i, 1, astAllChildren(1, $2) );
    }
    ;

unary_operator
    : ADD   { $$.i = AST_UNARY_PLUS;  $$.l = $1.l; }
    | SUB   { $$.i = AST_UNARY_MINUS; $$.l = $1.l; }
    | '!'   { $$.i = AST_UNARY_NOT;   $$.l = $1.l; }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | primary_expression ':' primary_expression ARROW primary_expression {
        $$ = astNewNode ( ARROW, 3, astAllChildren(3, $1, $3, $5) );
    }
    | primary_expression ':' primary_expression ARROW primary_expression MARK primary_expression 
    | postfix_expression '(' argument_expression_list ')' {
    }
    | postfix_expression '(' ')'
    | postfix_expression PIPE pipe_property {
        $$ = astNewNode ( PIPE, 2, astAllChildren(2, $1, $3) );
    }
    | postfix_expression '[' logical_OR_expression ']' {
        $$ = astNewNode ( AST_MATCH, 2, astAllChildren(2, $1, $3) );
    }
    | postfix_expression '.' IDENTIFIER {
        $$ = astNewNode ( AST_ATTIBUTE, 2, astAllChildren(2, $1, $3) );
    }
    | postfix_expression '.' graph_property {
        $$ = astNewNode ( AST_GRAPH_PROP, 2, astAllChildren(2, $1, $3) );
    }
    ;

primary_expression
    : attribute             { $$ = $1; }
    | IDENTIFIER            { 
        $$ = astNewLeaf(IDENTIFIER, $1.s, $1.l); 
        sTableLookupId($$);
    }
    | constant              { $$ = $1; }
    | STRING_LITERAL        { $$ = astNewLeaf(STRING_LITERAL, $1.s, $1.l); }
    | '(' expression ')'    { $$ = $2; }
    ;

graph_property
    : ALL_VERTICES          { $$ = astNewLeaf(ALL_VERTICES, NULL, $1.l); }
    | ALL_EDGES             { $$ = astNewLeaf(ALL_EDGES, NULL, $1.l); }
    ;

pipe_property
    : OUTCOMING_EDGES       { $$ = astNewLeaf(OUTCOMING_EDGES, NULL, $1.l); }
    | INCOMING_EDGES        { $$ = astNewLeaf(INCOMING_EDGES, NULL, $1.l); }
    | STARTING_VERTICES     { $$ = astNewLeaf(STARTING_VERTICES, NULL, $1.l); }
    | ENDING_VERTICES       { $$ = astNewLeaf(ENDING_VERTICES, NULL, $1.l); }
    ;

argument_expression_list
    : assignment_expression { $$ = $1; }
    | argument_expression_list ',' assignment_expression {
        $$ = astNewNode ( AST_COMMA, 2, astAllChildren(2, $1, $3) );
    }
    ;

attribute
    : AT IDENTIFIER{ 
        $$ = astNewNode ( AT, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, $2.s, $2.l))  );
    }
    ;

constant
    : INTEGER_CONSTANT      { $$ = astNewLeaf(INTEGER_CONSTANT, $1.s, $1.l); }
    | FLOAT_CONSTANT        { $$ = astNewLeaf(FLOAT_CONSTANT, $1.s, $1.l); }
    | BOOL_TRUE             { $$ = astNewLeaf(BOOL_TRUE, NULL, $1.l); }
    | BOOL_FALSE            { $$ = astNewLeaf(BOOL_FALSE, NULL, $1.l); }
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
    : VOID      { int ttype = VOID_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | BOOLEAN   { int ttype = BOOL_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | INTEGER   { int ttype = INT_T;    $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | FLOAT     { int ttype = FLOAT_T;  $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | STRING    { int ttype = STRING_T; $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | LIST      { int ttype = LIST_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | VERTEX    { int ttype = VERTEX_T; $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | EDGE      { int ttype = EDGE_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | GRAPH     { int ttype = GRAPH_T;  $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    ;

declaration
    : declaration_specifiers init_declarator_list ';' {
        $$ = astNewNode( AST_DECLARATION, 2, astAllChildren(2, $1, $2) );    
        sTableDeclare($$);
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
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3) );
    }
    ;

init_declarator
    : declarator {
        $$ = $1;
    }
    | declarator '=' initializer {
        $$ = astNewNode( AST_ASSIGN, 2, astAllChildren(2, $1, $3) );
    }
    ;

declarator
    : direct_declarator {
        $$ = $1;
    }
    ;

direct_declarator
    : IDENTIFIER {
        $$ = astNewLeaf(IDENTIFIER, $1.s, $1.l);
    }
    | IDENTIFIER '(' parameter_list ')' {
        $$ = astNewNode( AST_FUNC_DECLARATOR, 2, astAllChildren(2, astNewLeaf(IDENTIFIER, $1.s, $1.l), $3) );
    }
    | IDENTIFIER '(' ')' {
        $$ = astNewNode( AST_FUNC_DECLARATOR, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, $1.s, $1.l) ) );
    }
    | direct_declarator BELONG IDENTIFIER {
        $$ = astNewNode( BELONG, 2, astAllChildren(2, $1, $3) );
    }
    ;

parameter_list
    : parameter_declaration { $$ = $1; }
    | parameter_list ',' parameter_declaration {
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3) );
    }
    ;

parameter_declaration
    : declaration_specifiers IDENTIFIER {
        $$ = astNewNode( AST_PARA_DECLARATION, 2, astAllChildren(2, $1, astNewLeaf(IDENTIFIER, $2.s, $2.l)));
    }
    | function_literal_type_sepcifier IDENTIFIER {
    }
    ;

initializer
    : assignment_expression { $$ = $1; }
    | '[' initializer_list ']' {
        $$ = astNewNode( AST_LIST_INIT, 1, astAllChildren(1, $2) );
    }
    | '[' ']' {
        $$ = astNewNode( AST_LIST_INIT, 0, NULL );
    }
    ;

initializer_list
    : initializer { $$ = $1; }
    | initializer_list ',' initializer {
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3) );
    }
    ;

/*************************
 * auxiliary nonterminal *
 *************************/

scope_in
    :       { sStackPush( sNewScopeId() ); }
    ;

scope_out
    :       { sStackPop(); }
    ;

%%

void yyerror(char *s) {
    printf("%s\n", s);
}

void main_init() {
    init_util();
    sTableInit();
    sStackInit();
}

void main_clean() {
    sTableDestroy();
    sStackDestroy();
}

int main(int argc, char * const * argv) {
    if (argc<=1) { // missing file
        fprintf(stdout, "missing input file\n");
        exit(1);
    }
    main_init();
    yyin = fopen(argv[1], "r");
    yyparse();
    fclose(yyin);
    main_clean();
    return 0;
}
