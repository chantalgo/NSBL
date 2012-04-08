
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     BOOLEAN = 259,
     INTEGER = 260,
     FLOAT = 261,
     STRING = 262,
     LIST = 263,
     VERTEX = 264,
     EDGE = 265,
     GRAPH = 266,
     DYN_ATTRIBUTE = 267,
     IDENTIFIER = 268,
     INTEGER_CONSTANT = 269,
     FLOAT_CONSTANT = 270,
     STRING_LITERAL = 271,
     BOOL_TRUE = 272,
     BOOL_FALSE = 273,
     FUNC_LITERAL = 274,
     OUTCOMING_EDGES = 275,
     INCOMING_EDGES = 276,
     STARTING_VERTICES = 277,
     ENDING_VERTICES = 278,
     ALL_VERTICES = 279,
     ALL_EDGES = 280,
     ADD = 281,
     SUB = 282,
     MUL = 283,
     DIV = 284,
     OR = 285,
     AND = 286,
     EQ = 287,
     NE = 288,
     GT = 289,
     LT = 290,
     GE = 291,
     LE = 292,
     ADD_ASSIGN = 293,
     SUB_ASSIGN = 294,
     MUL_ASSIGN = 295,
     DIV_ASSIGN = 296,
     APPEND = 297,
     ARROW = 298,
     PIPE = 299,
     AT = 300,
     MARK = 301,
     BELONG = 302,
     IF = 303,
     ELSE = 304,
     FOR = 305,
     FOREACH = 306,
     WHILE = 307,
     BREAK = 308,
     CONTINUE = 309,
     RETURN = 310,
     AST_TYPE_SPECIFIER = 311,
     AST_DECLARATION = 312,
     AST_COMMA = 313,
     AST_ASSIGN = 314,
     AST_CAST = 315,
     AST_UNARY_PLUS = 316,
     AST_UNARY_MINUS = 317,
     AST_UNARY_NOT = 318,
     AST_FUNC_DECLARATOR = 319,
     AST_PARA_DECLARATION = 320,
     AST_FUNC = 321,
     AST_INIT_ASSGN = 322,
     AST_LIST_INIT = 323,
     AST_MATCH = 324,
     AST_ATTIBUTE = 325,
     AST_GRAPH_PROP = 326,
     AST_STAT_LIST = 327,
     AST_COMP_STAT = 328,
     AST_COMP_STAT_NO_SCOPE = 329,
     AST_EXT_STAT_COMMA = 330,
     AST_IF_STAT = 331,
     AST_IFELSE_STAT = 332,
     AST_WHILE = 333,
     AST_FOR = 334,
     AST_FOREACH = 335,
     AST_JUMP_CONTINUE = 336,
     AST_JUMP_BREAK = 337,
     AST_JUMP_RETURN = 338,
     AST_FUNC_CALL = 339,
     AST_ARG_EXPS = 340,
     AST_EXP_STAT = 341,
     LOWER_THAN_ELSE = 342
   };
#endif
/* Tokens.  */
#define VOID 258
#define BOOLEAN 259
#define INTEGER 260
#define FLOAT 261
#define STRING 262
#define LIST 263
#define VERTEX 264
#define EDGE 265
#define GRAPH 266
#define DYN_ATTRIBUTE 267
#define IDENTIFIER 268
#define INTEGER_CONSTANT 269
#define FLOAT_CONSTANT 270
#define STRING_LITERAL 271
#define BOOL_TRUE 272
#define BOOL_FALSE 273
#define FUNC_LITERAL 274
#define OUTCOMING_EDGES 275
#define INCOMING_EDGES 276
#define STARTING_VERTICES 277
#define ENDING_VERTICES 278
#define ALL_VERTICES 279
#define ALL_EDGES 280
#define ADD 281
#define SUB 282
#define MUL 283
#define DIV 284
#define OR 285
#define AND 286
#define EQ 287
#define NE 288
#define GT 289
#define LT 290
#define GE 291
#define LE 292
#define ADD_ASSIGN 293
#define SUB_ASSIGN 294
#define MUL_ASSIGN 295
#define DIV_ASSIGN 296
#define APPEND 297
#define ARROW 298
#define PIPE 299
#define AT 300
#define MARK 301
#define BELONG 302
#define IF 303
#define ELSE 304
#define FOR 305
#define FOREACH 306
#define WHILE 307
#define BREAK 308
#define CONTINUE 309
#define RETURN 310
#define AST_TYPE_SPECIFIER 311
#define AST_DECLARATION 312
#define AST_COMMA 313
#define AST_ASSIGN 314
#define AST_CAST 315
#define AST_UNARY_PLUS 316
#define AST_UNARY_MINUS 317
#define AST_UNARY_NOT 318
#define AST_FUNC_DECLARATOR 319
#define AST_PARA_DECLARATION 320
#define AST_FUNC 321
#define AST_INIT_ASSGN 322
#define AST_LIST_INIT 323
#define AST_MATCH 324
#define AST_ATTIBUTE 325
#define AST_GRAPH_PROP 326
#define AST_STAT_LIST 327
#define AST_COMP_STAT 328
#define AST_COMP_STAT_NO_SCOPE 329
#define AST_EXT_STAT_COMMA 330
#define AST_IF_STAT 331
#define AST_IFELSE_STAT 332
#define AST_WHILE 333
#define AST_FOR 334
#define AST_FOREACH 335
#define AST_JUMP_CONTINUE 336
#define AST_JUMP_BREAK 337
#define AST_JUMP_RETURN 338
#define AST_FUNC_CALL 339
#define AST_ARG_EXPS 340
#define AST_EXP_STAT 341
#define LOWER_THAN_ELSE 342




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 23 "Parser.y"

    struct Node*    node;
    struct {
        char *          s;
        long long       l;
    }LString;
    struct {
        int             i;
        long long       l;
    }LInteger;



/* Line 1676 of yacc.c  */
#line 240 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


