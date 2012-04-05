
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
     IDENTIFIER = 267,
     INTEGER_CONSTANT = 268,
     FLOAT_CONSTANT = 269,
     STRING_LITERAL = 270,
     BOOL_TRUE = 271,
     BOOL_FALSE = 272,
     FUNC_LITERAL = 273,
     OUTCOMING_EDGES = 274,
     INCOMING_EDGES = 275,
     STARTING_VERTICES = 276,
     ENDING_VERTICES = 277,
     ALL_VERTICES = 278,
     ALL_EDGES = 279,
     ADD = 280,
     SUB = 281,
     MUL = 282,
     DIV = 283,
     OR = 284,
     AND = 285,
     EQ = 286,
     NE = 287,
     GT = 288,
     LT = 289,
     GE = 290,
     LE = 291,
     ADD_ASSIGN = 292,
     SUB_ASSIGN = 293,
     MUL_ASSIGN = 294,
     DIV_ASSIGN = 295,
     APPEND = 296,
     ARROW = 297,
     PIPE = 298,
     AT = 299,
     MARK = 300,
     BELONG = 301,
     IF = 302,
     ELSE = 303,
     FOR = 304,
     FOREACH = 305,
     WHILE = 306,
     BREAK = 307,
     CONTINUE = 308,
     RETURN = 309,
     AST_TYPE_SPECIFIER = 310,
     AST_DECLARATION = 311,
     AST_COMMA = 312,
     AST_ASSIGN = 313,
     AST_CAST = 314,
     AST_UNARY_PLUS = 315,
     AST_UNARY_MINUS = 316,
     AST_UNARY_NOT = 317,
     AST_FUNC_DECLARATOR = 318,
     AST_PARA_DECLARATION = 319,
     AST_FUNC = 320,
     AST_INIT_ASSGN = 321,
     AST_LIST_INIT = 322,
     AST_MATCH = 323,
     AST_ATTIBUTE = 324,
     AST_GRAPH_PROP = 325,
     AST_STAT_LIST = 326,
     AST_COMP_STAT = 327,
     AST_EXT_STAT_COMMA = 328,
     AST_IF_STAT = 329,
     AST_IFELSE_STAT = 330,
     AST_WHILE = 331,
     AST_FOR_XXX = 332,
     AST_FOR_XXO = 333,
     AST_FOR_XOX = 334,
     AST_FOR_XOO = 335,
     AST_FOR_OXX = 336,
     AST_FOR_OXO = 337,
     AST_FOR_OOX = 338,
     AST_FOR_OOO = 339,
     AST_FOREACH = 340,
     AST_JUMP_CONTINUE = 341,
     AST_JUMP_BREAK = 342,
     AST_JUMP_RETURN = 343,
     AST_POSTFIX_EPR = 344,
     LOWER_THAN_ELSE = 345
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
#define IDENTIFIER 267
#define INTEGER_CONSTANT 268
#define FLOAT_CONSTANT 269
#define STRING_LITERAL 270
#define BOOL_TRUE 271
#define BOOL_FALSE 272
#define FUNC_LITERAL 273
#define OUTCOMING_EDGES 274
#define INCOMING_EDGES 275
#define STARTING_VERTICES 276
#define ENDING_VERTICES 277
#define ALL_VERTICES 278
#define ALL_EDGES 279
#define ADD 280
#define SUB 281
#define MUL 282
#define DIV 283
#define OR 284
#define AND 285
#define EQ 286
#define NE 287
#define GT 288
#define LT 289
#define GE 290
#define LE 291
#define ADD_ASSIGN 292
#define SUB_ASSIGN 293
#define MUL_ASSIGN 294
#define DIV_ASSIGN 295
#define APPEND 296
#define ARROW 297
#define PIPE 298
#define AT 299
#define MARK 300
#define BELONG 301
#define IF 302
#define ELSE 303
#define FOR 304
#define FOREACH 305
#define WHILE 306
#define BREAK 307
#define CONTINUE 308
#define RETURN 309
#define AST_TYPE_SPECIFIER 310
#define AST_DECLARATION 311
#define AST_COMMA 312
#define AST_ASSIGN 313
#define AST_CAST 314
#define AST_UNARY_PLUS 315
#define AST_UNARY_MINUS 316
#define AST_UNARY_NOT 317
#define AST_FUNC_DECLARATOR 318
#define AST_PARA_DECLARATION 319
#define AST_FUNC 320
#define AST_INIT_ASSGN 321
#define AST_LIST_INIT 322
#define AST_MATCH 323
#define AST_ATTIBUTE 324
#define AST_GRAPH_PROP 325
#define AST_STAT_LIST 326
#define AST_COMP_STAT 327
#define AST_EXT_STAT_COMMA 328
#define AST_IF_STAT 329
#define AST_IFELSE_STAT 330
#define AST_WHILE 331
#define AST_FOR_XXX 332
#define AST_FOR_XXO 333
#define AST_FOR_XOX 334
#define AST_FOR_XOO 335
#define AST_FOR_OXX 336
#define AST_FOR_OXO 337
#define AST_FOR_OOX 338
#define AST_FOR_OOO 339
#define AST_FOREACH 340
#define AST_JUMP_CONTINUE 341
#define AST_JUMP_BREAK 342
#define AST_JUMP_RETURN 343
#define AST_POSTFIX_EPR 344
#define LOWER_THAN_ELSE 345




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "Parser.y"

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
#line 246 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


