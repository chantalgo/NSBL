%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin; /* Input for yacc parser. */
extern void yyerror(const char *str); /* Our version. */
extern int yywrap(void); /* Our version. */
extern int yylex(void); /* Lexical analyzer function. */
extern int yyparse(void); /* Parser function. */

#include "ASTree.h"
#include "SymbolTable.h"
#include "SymbolTableUtil.h"
#include "util.h"
#include "CodeGen.h"
#include "global.h"
%}
/**************************
 * General Options        *
 **************************/
%error-verbose 

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
%type <LInteger> assignment_operator unary_operator function_literal_type_specifier 
%type <LString> IDENTIFIER STRING_LITERAL INTEGER_CONSTANT FLOAT_CONSTANT
%type <LString> '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN APPEND
%type <LString> ADD SUB MUL DIV '!'
%type <LString> EQ NE LE GE LT GT OR AND LIN ROUT PRINT
%type <LString> ARROW PIPE AT
%type <LString> BOOL_TRUE BOOL_FALSE
%type <LString> OUTCOMING_EDGES INCOMING_EDGES STARTING_VERTICES ENDING_VERTICES
%type <LString> ALL_VERTICES ALL_EDGES 
%type <LString> VOID BOOLEAN INTEGER FLOAT STRING VLIST ELIST VERTEX EDGE GRAPH
%type <LString> FUNC_LITERAL
%type <LString> IF ELSE FOR FOREACH WHILE BREAK CONTINUE RETURN MARK
%type <LString> '{' '}' '(' ')' '[' ']' ';' ',' ':' '.' '?' DEL LENGTH 
// declaration
%type <node> declaration
%type <node> basic_type_specifier declaration_specifiers 
%type <node> init_declarator_list init_declarator simple_declarator
%type <node> parameter_list parameter_declaration
%type <node> initializer initializer_list
%type <node> del_declarator del_declarator_list deletion

// expression
%type <node> expression assignment_expression logical_OR_expression 
%type <node> logical_AND_expression equality_expression relational_expression
%type <node> additive_expression multiplicative_expression cast_expression
%type <node> unary_expression postfix_expression primary_expression
%type <node> graph_property pipe_property argument_expression_list argument_expression
%type <node> attribute constant

// statments
%type <node> start_nonterminal translation_unit
%type <node> external_statement statement 
%type <node> expression_statement compound_statement selection_statement compound_statement_no_scope deletion_statement 
%type <node> iteration_statement jump_statement declaration_statement
%type <node> statement_list foreach_declaration
%type <node> io_statement io_ext io_ext_list

// function
%type <node> function_definition
%type <node> function_literal_declaration
%type <node> function_head func_declarator func_id 

/**************************
 *      TOKEN LIST        *
 **************************/
/* TYPE RELATED */
%token VOID BOOLEAN INTEGER FLOAT STRING VLIST ELIST VERTEX EDGE GRAPH DYN_ATTRIBUTE
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
%token LIN ROUT PRINT LENGTH
/* CONTROL */
%token IF ELSE
%token FOR FOREACH WHILE
%token BREAK CONTINUE
%token RETURN
/* del */
%token DEL
/* used in AST */
%token AST_TYPE_SPECIFIER AST_DECLARATION AST_COMMA
%token AST_ASSIGN AST_CAST
%token AST_UNARY_PLUS AST_UNARY_MINUS AST_UNARY_NOT
%token AST_FUNC_DECLARATOR AST_PARA_DECLARATION AST_FUNC 

%token AST_INIT_ASSGN AST_LIST_INIT
%token AST_MATCH AST_ATTRIBUTE AST_GRAPH_PROP
%token AST_STAT_LIST AST_COMP_STAT AST_COMP_STAT_NO_SCOPE AST_EXT_STAT_COMMA

%token AST_IF_STAT AST_IFELSE_STAT
%token AST_WHILE AST_FOR AST_FOREACH
%token AST_JUMP_CONTINUE AST_JUMP_BREAK AST_JUMP_RETURN
%token AST_FUNC_CALL AST_ARG_EXPS AST_EXP_STAT
%token AST_ERROR AST_LIST_MEMBER
%token AST_PRINT AST_PRINT_COMMA AST_PRINT_STAT AST_READ_GRAPH AST_WRITE_GRAPH
%token AST_DEL_ATTRIBUTE AST_LENGTH
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
        showASTandST($$,"Syntax + Semantic P1");
        if(!ERRNO) {// no syntax error, or declaration error
            char *mainBodyCode=NULL, *funCode=NULL,*mainCode;
            char *globalDecl=NULL;
            codeInclude(&globalDecl);
            codeIndentInit();
            codeAllGen($$, &mainBodyCode, &funCode);
            codeAllFuncLiteral($$, &funCode);
            codeAllGlobal($$,&globalDecl);
            mainCode = wapperMainCode(mainBodyCode);        
            codeIndentFree();
            showASTandST($$,"Semantic P2 + Code Gen");
            if(!ERRNO){
                OUTFILESTREAM = fopen(OUTFILE,"w");
                if(globalDecl!=NULL) exportCode(globalDecl);    // global
                if(funCode!=NULL) exportCode(funCode);          // func
                exportCode(mainCode);                           // main
                fclose(OUTFILESTREAM);
            }
            free(mainBodyCode);
            free(funCode);
            free(mainCode);
            free(globalDecl);
        }
        astFreeTree($$);            // destroy AST
        
    }
    ;

translation_unit
    : external_statement           { $$ = $1; } 
    | translation_unit external_statement {
        struct Node* leftNode = astLeftmostNode($1);
        long long ll = -1; 
        if(leftNode!=NULL) ll = leftNode->line;
        $$ = astNewNode( AST_EXT_STAT_COMMA, 2, astAllChildren( 2, $1, $2 ), ll );
    }
    ;

/**************************
 *   STATEMENTS           *
 **************************/
external_statement
    : function_definition{
        $$ = $1;
    }
    | statement{ 
        $$ = $1;
    }
    ;

statement
    : expression_statement          { $$ = $1; }
    | compound_statement            { $$ = $1; }
    | selection_statement           { $$ = $1; }
    | iteration_statement           { $$ = $1; }
    | jump_statement                { $$ = $1; }
    | declaration_statement         { $$ = $1; }
    | deletion_statement            { $$ = $1; }
    | io_statement		            { $$ = $1; }	
    ;

expression_statement
    : expression ';'{ 
        $$ = astNewNode( AST_EXP_STAT, 1, astAllChildren(1, $1), $1->line);
    }
    | ';' { $$ = astNewNode( AST_EXP_STAT, 0, NULL, $1.l); }
    | expression error {
        astFreeTree($1); $$ = NULL;
        }
    ;

statement_list
    : statement                     { $$ = $1; }
    | statement_list statement{
        struct Node* leftNode = astLeftmostNode($1);
        long long ll = -1;
        if(leftNode!=NULL) ll = leftNode->line;
        $$ = astNewNode( AST_STAT_LIST, 2, astAllChildren(2, $1, $2), ll );
    }
    | '{' error { $$ = NULL; }
    | '{' scope_in statement_list scope_out error {
        astFreeTree($3);
        $$ = NULL;
    }
    ;

compound_statement
    : '{' '}' { 
        $$ = astNewNode( AST_COMP_STAT, 0, NULL, $1.l );
    }
    | '{' scope_in statement_list scope_out '}'   { 
        $$ = astNewNode( AST_COMP_STAT, 1, astAllChildren(1, $3), $1.l );
    }
    ;

compound_statement_no_scope
    : '{' '}' {
        $$ = astNewNode( AST_COMP_STAT_NO_SCOPE, 0, NULL, $1.l );
    }
    | '{' statement_list '}'   {
        $$ = astNewNode( AST_COMP_STAT_NO_SCOPE, 1, astAllChildren(1, $2), $1.l );
    }
    | '{' error { $$ = NULL; }
    | '{' statement_list error {
        astFreeTree($2);
        $$ = NULL;
    }
    ;

selection_statement
    : IF '(' expression ')' statement  {
        $$ = astNewNode(AST_IF_STAT, 2, astAllChildren(2, $3, $5), $1.l );
    } %prec LOWER_THAN_ELSE ;
    | IF '(' expression ')' statement ELSE statement {
        $$ = astNewNode(AST_IFELSE_STAT, 3, astAllChildren(3,$3, $5, $7), $1.l);
    }
    ;

iteration_statement
    : WHILE '(' expression ')' statement {
        $$ = astNewNode(AST_WHILE, 2, astAllChildren(2, $3, $5), $1.l);
    }
    | FOR '(' expression ';' expression ';' expression ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, $3, $5, $7, $9), $1.l);
    }
    | FOR '(' expression ';' expression ';' ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, $3, $5, NULL, $8), $1.l);
    }
    | FOR '(' expression ';' ';' expression ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, $3, NULL, $6, $8), $1.l);
    }
    | FOR '(' expression ';' ';' ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, $3, NULL, NULL, $7), $1.l);
    }
    | FOR '(' ';' expression ';' expression ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, $4, $6, $8), $1.l);
    }
    | FOR '(' ';' expression ';' ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, $4, NULL, $7), $1.l);
    }
    | FOR '(' ';' ';' expression ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, NULL,$5, $7), $1.l);
    }
    | FOR '(' ';' ';' ')' statement {
        $$ = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, NULL, NULL, $6), $1.l);
    }
    | FOREACH '(' foreach_declaration ':' postfix_expression ')' statement {
        $$ = astNewNode(AST_FOREACH, 3, astAllChildren(3, $3, $5, $7), $1.l);
    }
    ;

foreach_declaration
	: basic_type_specifier IDENTIFIER {
		$$ = astNewNode(AST_DECLARATION, 2, astAllChildren(2, $1, astNewLeaf(IDENTIFIER, $2.s, $2.l)), $2.l);
		sTableDeclare($$);
	}

jump_statement
    : BREAK ';'                         {$$ = astNewNode(AST_JUMP_BREAK, 0, NULL, $1.l);}
    | CONTINUE ';'                      {$$ = astNewNode(AST_JUMP_CONTINUE, 0, NULL, $1.l);}
    | RETURN expression ';'             {$$ = astNewNode(AST_JUMP_RETURN, 1, astAllChildren(1, $2), $1.l);}
    | RETURN ';'                        {$$ = astNewNode(AST_JUMP_RETURN, 0, NULL, $1.l);}
    | BREAK error                       {$$ = NULL;}
    | CONTINUE error                    {$$ = NULL;}
    | RETURN expression error           {$$ = NULL; astFreeTree($2);}
    | RETURN error                      {$$ = NULL;}
    ;

declaration_statement
    : declaration                       { $$ = $1; }
    | function_literal_declaration      { $$ = $1; }
    ;

deletion_statement
    : deletion                          { $$ = $1; }
    ;

io_statement
    : PRINT io_ext_list ';' {
        $$ =  astNewNode(AST_PRINT_STAT, 1, astAllChildren(1, $2), $1.l); 
    }
    | IDENTIFIER LIN IDENTIFIER ';'	
    {
        // FILE << Graph
        struct Node* tn1 = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        struct Node* tn3 = astNewLeaf(IDENTIFIER, $3.s, $3.l);
        sTableLookupId(tn1);
        sTableLookupId(tn3);
        $$ = astNewNode(AST_WRITE_GRAPH, 2, astAllChildren(2, tn1, tn3), $2.l);
    } 
    | IDENTIFIER ROUT IDENTIFIER ';' {
        // FILE << Graph
        struct Node* tn1 = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        struct Node* tn3 = astNewLeaf(IDENTIFIER, $3.s, $3.l);
        sTableLookupId(tn1);
        sTableLookupId(tn3);
        $$ = astNewNode(AST_READ_GRAPH, 2, astAllChildren(2, tn1, tn3), $2.l);
    } 
    ;	

io_ext_list
    : io_ext                        { $$ = $1; }
    | io_ext_list io_ext            { $$ = astNewNode(AST_PRINT_COMMA, 2, astAllChildren(2, $1, $2), $1->line); }

io_ext
    : LIN assignment_expression {
        $$ = astNewNode(AST_PRINT, 1, astAllChildren(1, $2),$1.l);
    } 
    ;

/**************************
 *   EXPRESSIONS          *
 **************************/

expression
    : assignment_expression { $$ = $1; }
    | expression ',' assignment_expression  {
        $$ = astNewNode ( AST_COMMA, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

assignment_expression
    : logical_OR_expression { $$ = $1; }
    | postfix_expression assignment_operator assignment_expression {
       $$ = astNewNode ( $2.i, 2, astAllChildren(2, $1, $3), $2.l ); 
    }
    ;

assignment_operator
    : '='               { $$.i = AST_ASSIGN; $$.l = $1.l; }
    //| ADD_ASSIGN        { $$.i = ADD_ASSIGN; $$.l = $1.l; }
    //| SUB_ASSIGN        { $$.i = SUB_ASSIGN; $$.l = $1.l; }
    //| MUL_ASSIGN        { $$.i = MUL_ASSIGN; $$.l = $1.l; }
    //| DIV_ASSIGN        { $$.i = DIV_ASSIGN; $$.l = $1.l; }
    | APPEND            { $$.i = APPEND;     $$.l = $1.l; }
    ;

logical_OR_expression
    : logical_AND_expression { $$ = $1; }
    | logical_OR_expression OR logical_AND_expression {
        $$ = astNewNode ( OR, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

logical_AND_expression
    : equality_expression { $$ = $1; }
    | logical_AND_expression AND equality_expression {
        $$ = astNewNode ( AND, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        $$ = astNewNode ( EQ, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | equality_expression NE relational_expression {
        $$ = astNewNode ( NE, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        $$ = astNewNode ( LT, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | relational_expression GT additive_expression {
        $$ = astNewNode ( GT, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | relational_expression LE additive_expression {
        $$ = astNewNode ( LE, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | relational_expression GE additive_expression {
        $$ = astNewNode ( GE, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression ADD multiplicative_expression {
        $$ = astNewNode ( ADD, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | additive_expression SUB multiplicative_expression {
        $$ = astNewNode ( SUB, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

multiplicative_expression
    : cast_expression { $$ = $1; }
    | multiplicative_expression MUL cast_expression {
        $$ = astNewNode ( MUL, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | multiplicative_expression DIV cast_expression {
        $$ = astNewNode ( DIV, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

cast_expression
    : unary_expression { $$ = $1; }
    | '(' declaration_specifiers ')' cast_expression {
        $$ = astNewNode ( AST_CAST, 2, astAllChildren(2, $2, $4), $2->line );
    }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | unary_operator cast_expression {
        $$ = astNewNode ( $1.i, 1, astAllChildren(1, $2), $1.l );
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
        $$ = astNewNode ( ARROW, 3, astAllChildren(3, $1, $3, $5), $2.l );
    }
    | IDENTIFIER '(' argument_expression_list ')' {
        struct Node* tn = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        $$ = astNewNode(AST_FUNC_CALL, 2, astAllChildren(2, tn, $3), tn->line);
        //$$->typeCon = astTypeConArgList($3,NULL);   // type construct for arguments
        //sTableLookupFunc($$);                       // Lookup this func
        //astFreeTypeCon($$->typeCon);
    }
    | IDENTIFIER '(' ')' {
        struct Node* tn = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        $$ = astNewNode(AST_FUNC_CALL, 1, astAllChildren(1, tn), tn->line);
        //$$->typeCon = astTypeConArgList(NULL, NULL);    // empty
        //sTableLookupFunc($$);
        //astFreeTypeCon($$->typeCon);
    }
    | postfix_expression PIPE pipe_property {
        $$ = astNewNode ( PIPE, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | postfix_expression '?' '[' no_type_check_on_dynamic_left dynamic_scope_left scope_in logical_OR_expression scope_out dynamic_scope_right no_type_check_on_dynamic_right ']' {
        $$ = astNewNode ( AST_MATCH, 2, astAllChildren(2, $1, $7), $2.l );
    }
    | postfix_expression '[' expression ']' {
        $$ = astNewNode ( AST_LIST_MEMBER, 2, astAllChildren(2, $1, $3), $2.l );
    }
    | IDENTIFIER '.' IDENTIFIER {
        struct Node * tn1 = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        struct Node * tn3 = astNewLeaf(IDENTIFIER, $3.s, $3.l);
        sTableLookupId(tn1);
        $$ = astNewNode ( AST_ATTRIBUTE, 2, astAllChildren(2, tn1, tn3), $2.l );
        char * ctmp = tn3->lexval.sval;
        $$->child[1]->lexval.sval = strCatAlloc("", 2, "::",ctmp );
        free(ctmp);
    }
    | IDENTIFIER '.' graph_property {
        struct Node * tn1 = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        sTableLookupId(tn1);
        $$ = astNewNode ( AST_GRAPH_PROP, 2, astAllChildren(2, tn1, $3), $2.l );
    }
    ;

primary_expression
    : attribute             { 
        $$ = $1; 
        if(isNoTypeCheck==0){   // Func_Literal  // not used, JZ
            sTableLookupId($$);                 // Lookup ATTRIBUTE
        }
        else {  // Match operator
            // As here we may use `attribute' directly without declaration,
            // so it must be inserted into symbol table when first meets an `attribute'
            $$->type = DYNAMIC_T;                       // 1. set type 
            $$->symbol = sTableTryLookupId($$);         // 2. try look up myself in symtable
            if ( $$->symbol==NULL ) {                   // if not exsit, insert it
                sTableInsertId($$, DYNAMIC_T);
            }
        }
    }
    | IDENTIFIER            { 
        $$ = astNewLeaf(IDENTIFIER, $1.s, $1.l); 
        sTableLookupId($$);                 // Lookup IDENTIFIER in Symbol Table 
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
    : argument_expression { $$ = $1; }
    | argument_expression_list ',' argument_expression {
        $$ = astNewNode ( AST_COMMA, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

argument_expression
    : assignment_expression {
        $$ = astNewNode ( AST_ARG_EXPS, 1, astAllChildren(1, $1), $1->line );
    }
    ;

attribute
    : AT IDENTIFIER{ 
        if (isDynamicScope==0) {
            ERRNO = ErrorDynamicAttributeUsedInNonDynamicScope;
            errorInfo(ERRNO, $2.l, "dynamic attribute `%s' is used in non-dynamic scope\n", $2.s);
        }
        $$ = astNewLeaf ( DYN_ATTRIBUTE, $2.s, $2.l );
    }
    ;

constant
    : INTEGER_CONSTANT      { $$ = astNewLeaf(INTEGER_CONSTANT, $1.s, $1.l); }
    | FLOAT_CONSTANT        { $$ = astNewLeaf(FLOAT_CONSTANT, $1.s, $1.l); }
    | BOOL_TRUE             { $$ = astNewLeaf(BOOL_TRUE, NULL, $1.l); }
    | BOOL_FALSE            { $$ = astNewLeaf(BOOL_FALSE, NULL, $1.l); }
    | LENGTH '(' IDENTIFIER ')' {
        struct Node * tnode = astNewLeaf(IDENTIFIER, $3.s, $3.l);
        sTableLookupId(tnode);
        $$ = astNewNode(AST_LENGTH, 1, astAllChildren(1, tnode), $1.l );
    }
    ;

/**************************
 *   DECLARATION          *
 **************************/

function_literal_declaration
    : function_literal_type_specifier func_declarator ':' declaration_specifiers '=' no_type_check_on_dynamic_left dynamic_scope_left compound_statement_no_scope dynamic_scope_right no_type_check_on_dynamic_right scope_out ';' {
        $$ = astNewNode($1.i, 3, astAllChildren(3, $2, $4, $8), $1.l);
        $$->typeCon = $2->typeCon;
        $$->scope[0] = $2->scope[0];
        $$->scope[1] = $2->scope[1];
        sTableDeclare($$);
    }
    | function_literal_type_specifier func_declarator ':' declaration_specifiers '=' no_type_check_on_dynamic_left dynamic_scope_left compound_statement_no_scope dynamic_scope_right no_type_check_on_dynamic_right scope_out error {
        astFreeTree($2);
        astFreeTree($4);
        astFreeTree($8);
        $$ = NULL;
    }
    ;

function_definition
    : function_head compound_statement_no_scope scope_out{
        $$ = $1;
        $$->child[2] = $2;   // fill up the third field       
    }
    ;

function_head
    : declaration_specifiers func_declarator {
        $$ = astNewNode(AST_FUNC, 3, astAllChildren(3, $1, $2, NULL), $2->line); // third field empty
        $$->typeCon = $2->typeCon;
        $$->scope[0] = $2->scope[0];     // Scope Level
        $$->scope[1] = $2->scope[1];     // Scope Id
        sTableDeclare($$);  // We must declare before coming into compound stat, for recursive call
        // tmp no longer needed after here
    }
    ;

function_literal_type_specifier
    : FUNC_LITERAL        { $$.i = FUNC_LITERAL; $$.l = $1.l; }
    ;

basic_type_specifier
    : VOID      { int ttype = VOID_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | BOOLEAN   { int ttype = BOOL_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | INTEGER   { int ttype = INT_T;    $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | FLOAT     { int ttype = FLOAT_T;  $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | STRING    { int ttype = STRING_T; $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | VLIST     { int ttype = VLIST_T;  $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | ELIST     { int ttype = ELIST_T;  $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | VERTEX    { int ttype = VERTEX_T; $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | EDGE      { int ttype = EDGE_T;   $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    | GRAPH     { int ttype = GRAPH_T;  $$= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), $1.l); }
    ;

declaration
    : declaration_specifiers init_declarator_list ';' {
        $$ = astNewNode( AST_DECLARATION, 2, astAllChildren(2, $1, $2), $1->line );    
        sTableDeclare($$);
    }
     | declaration_specifiers init_declarator_list error {
     astFreeTree($1);
     astFreeTree($2);
     $$ = NULL;
    }
    ;

deletion
    : DEL del_declarator_list ';' {
        $$ = astNewNode( DEL, 1, astAllChildren(1, $2), $1.l);
    }
    | DEL del_declarator_list error {
        astFreeTree($2);
        $$ = NULL;
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
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

init_declarator
    : simple_declarator {
        $$ = $1;
    }
    | simple_declarator '=' initializer {
        $$ = astNewNode( AST_ASSIGN, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

del_declarator_list
    : del_declarator    { $$ = $1; }
    | del_declarator_list ',' del_declarator {
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

del_declarator
    : IDENTIFIER { 
        $$ = astNewLeaf(IDENTIFIER, $1.s, $1.l);
        sTableLookupId($$); 
    }
    | IDENTIFIER '.' IDENTIFIER {
        struct Node* tnode = astNewLeaf(IDENTIFIER, $1.s, $1.l); 
        sTableLookupId(tnode);    // check the exsitence of object
        if(tnode->type<=FLOAT_T || tnode->type>=FUNC_T) {
            ERRNO = ErrorDelAttrFromWrongType; 
            errorInfo(ERRNO,tnode->line,"del an attribute from an object of type `%s'.\n",sTypeName(tnode->type) );
        }
        $$ = astNewNode( AST_DEL_ATTRIBUTE, 2, astAllChildren(2, tnode, astNewLeaf(IDENTIFIER, $3.s, $3.l)), $2.l );
        // set lexval for ID2
        char * ctmp = $$->child[1]->lexval.sval;
        $$->child[1]->lexval.sval = strCatAlloc("", 2, "::", ctmp);
        free(ctmp);
    }
    ;

simple_declarator
    : IDENTIFIER {
        $$ = astNewLeaf(IDENTIFIER, $1.s, $1.l);
    }
    ;

func_declarator
    : func_id  scope_in '(' parameter_list ')' {
        $$ = astNewNode( AST_FUNC_DECLARATOR, 2, astAllChildren(2, $1, $4), $1->line );
        // generate type Constructor for parameters
        $$->typeCon = astTypeConParaList( $4, NULL );
        $$->scope[0] = $1->scope[0];     // Scope Level
        $$->scope[1] = $1->scope[1];     // Scope Id
    }
    | func_id scope_in '(' ')' {
        $$ = astNewNode( AST_FUNC_DECLARATOR, 1, astAllChildren(1, $1 ), $1->line );
        $$->typeCon = astTypeConParaList( NULL, NULL );
        $$->scope[0] = $1->scope[0];     // Scope Level
        $$->scope[1] = $1->scope[1];     // Scope Id
    }
    ;

func_id
    : IDENTIFIER {
        $$ = astNewLeaf(IDENTIFIER, $1.s, $1.l);
    }
    ;

parameter_list
    : parameter_declaration { $$ = $1; }
    | parameter_list ',' parameter_declaration {
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

parameter_declaration
    : declaration_specifiers IDENTIFIER {
        struct Node* tn = astNewLeaf(IDENTIFIER, $2.s, $2.l);
        $$ = astNewNode( AST_PARA_DECLARATION, 2, astAllChildren(2, $1, tn), $1->line);
        sTableDeclare($$);
        $$->type = tn->type;
    }
    //| declaration_specifiers attribute {
    //    $$ = astNewNode( AST_PARA_DECLARATION, 2, astAllChildren(2, $1, $2), $1->line);
    //    sTableDeclare($$);
    //    $$->type = $2->type;
    //}
    | function_literal_type_specifier IDENTIFIER {
        $$ = astNewNode( FUNC_LITERAL, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, $2.s, $2.l)), $1.l);
        $$->type = FUNC_LITERAL_T;
    }
    ;

initializer
    : assignment_expression { $$ = $1; }
    | '[' initializer_list ']' {
        $$ = astNewNode( AST_LIST_INIT, 1, astAllChildren(1, $2), $1.l );
    }
    | '[' ']' {
        $$ = astNewNode( AST_LIST_INIT, 0, NULL, $1.l );
    }
    ;

initializer_list
    : initializer { $$ = $1; }
    | initializer_list ',' initializer {
        $$ = astNewNode( AST_COMMA, 2, astAllChildren(2, $1, $3), $2.l );
    }
    ;

/*************************
 * auxiliary nonterminal *
 *************************/

scope_in
    :       { sStackPush( sNewScopeId() ); 
              maxLevel = (maxLevel<sStackLevel) ? sStackLevel : maxLevel;
            }
    ;

scope_out
    :       { sStackPop(); }
    ;

dynamic_scope_left
    :       { isDynamicScope = 1; }
    ;

dynamic_scope_right
    :       { isDynamicScope = 0; }
    ;

no_type_check_on_dynamic_left
    :       { isNoTypeCheck = 1; }
    ;

no_type_check_on_dynamic_right
    :       { isNoTypeCheck = 0; }
    ;
%%

void yyerror(const char *s) {
errorInfo(ErrorSyntax, yylval.LString.l, "%s\n",s);
}

void main_init(char * fileName) {
    init_util();
    sTableInit();
    sStackInit();
    isDynamicScope = 0;
    isNoTypeCheck = 0;
    maxLevel = 0;
    inLoop = 0;
    inFunc = -1;
    inMATCH = 0;
    existMATCH = 0;
    matchStaticVab = NULL;
    matchStrDecl = NULL;
	existPIPE = 0;
    returnList = NULL;
    noReturn = NULL;
    OUTFILE = strCatAlloc("",2,fileName,".c");
}

void main_clean() {
    sTableDestroy();
    sStackDestroy();
    free(OUTFILE);
}

int main(int argc, char * const * argv) {
    if (argc<=1) { // missing file
        fprintf(stdout, "missing input file\n");
        exit(1);
    }
    main_init(argv[1]);
    yyin = fopen(argv[1], "r");
    
    yyparse();
    fclose(yyin);
    main_clean();
    if(ERRNO!=0) {
        fprintf(stderr, "error code = %d\n", ERRNO);
    }
    return ERRNO;
}
