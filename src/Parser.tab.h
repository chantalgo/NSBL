
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
     NUMBER = 260,
     STRING = 261,
     LIST = 262,
     VERTEX = 263,
     EDGE = 264,
     GRAPH = 265,
     IDENTIFIER = 266,
     NUMBER_CONSTANT = 267,
     STRING_LITERAL = 268,
     TRUE = 269,
     FALSE = 270,
     FUNC_LITERAL = 271,
     OUTCOMING_EDGES = 272,
     INCOMING_EDGES = 273,
     STARTING_VERTICES = 274,
     ENDING_VERTICES = 275,
     ALL_VERTICES = 276,
     ALL_EDGES = 277,
     OR = 278,
     AND = 279,
     EQ = 280,
     NE = 281,
     GT = 282,
     LT = 283,
     GE = 284,
     LE = 285,
     ADD_ASSIGN = 286,
     SUB_ASSIGN = 287,
     MUL_ASSIGN = 288,
     DIV_ASSIGN = 289,
     EAT = 290,
     ARROW = 291,
     PIPE = 292,
     AT = 293,
     MARK = 294,
     IF = 295,
     ELSE = 296,
     FOR = 297,
     FOREACH = 298,
     WHILE = 299,
     BREAK = 300,
     CONTINUE = 301,
     RETURN = 302,
     LOWER_THAN_ELSE = 303
   };
#endif
/* Tokens.  */
#define VOID 258
#define BOOLEAN 259
#define NUMBER 260
#define STRING 261
#define LIST 262
#define VERTEX 263
#define EDGE 264
#define GRAPH 265
#define IDENTIFIER 266
#define NUMBER_CONSTANT 267
#define STRING_LITERAL 268
#define TRUE 269
#define FALSE 270
#define FUNC_LITERAL 271
#define OUTCOMING_EDGES 272
#define INCOMING_EDGES 273
#define STARTING_VERTICES 274
#define ENDING_VERTICES 275
#define ALL_VERTICES 276
#define ALL_EDGES 277
#define OR 278
#define AND 279
#define EQ 280
#define NE 281
#define GT 282
#define LT 283
#define GE 284
#define LE 285
#define ADD_ASSIGN 286
#define SUB_ASSIGN 287
#define MUL_ASSIGN 288
#define DIV_ASSIGN 289
#define EAT 290
#define ARROW 291
#define PIPE 292
#define AT 293
#define MARK 294
#define IF 295
#define ELSE 296
#define FOR 297
#define FOREACH 298
#define WHILE 299
#define BREAK 300
#define CONTINUE 301
#define RETURN 302
#define LOWER_THAN_ELSE 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


