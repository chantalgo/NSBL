
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
     BOOLEAN = 258,
     NUMBER = 259,
     STRING = 260,
     LIST = 261,
     VERTEX = 262,
     EDGE = 263,
     GRAPH = 264,
     IDENTIFIER = 265,
     NUMBER_CONSTANT = 266,
     STRING_LITERAL = 267,
     TRUE = 268,
     FALSE = 269,
     DEF = 270,
     OUTCOMING_EDGES = 271,
     INCOMING_EDGES = 272,
     STARTING_VERTICES = 273,
     ENDING_VERTICES = 274,
     ALL_VERTICES = 275,
     ALL_EDGES = 276,
     OR = 277,
     AND = 278,
     EQ = 279,
     NE = 280,
     GT = 281,
     LT = 282,
     GE = 283,
     LE = 284,
     ELLIPSIS = 285,
     ADD_ASSIGN = 286,
     SUB_ASSIGN = 287,
     MUL_ASSIGN = 288,
     DIV_ASSIGN = 289,
     EAT = 290,
     ARROW = 291,
     PIPE = 292,
     AT = 293,
     IF = 294,
     ELSE = 295,
     FOR = 296,
     WHILE = 297,
     BREAK = 298,
     CONTINUE = 299,
     RETURN = 300,
     LOWER_THAN_ELSE = 301
   };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define NUMBER 259
#define STRING 260
#define LIST 261
#define VERTEX 262
#define EDGE 263
#define GRAPH 264
#define IDENTIFIER 265
#define NUMBER_CONSTANT 266
#define STRING_LITERAL 267
#define TRUE 268
#define FALSE 269
#define DEF 270
#define OUTCOMING_EDGES 271
#define INCOMING_EDGES 272
#define STARTING_VERTICES 273
#define ENDING_VERTICES 274
#define ALL_VERTICES 275
#define ALL_EDGES 276
#define OR 277
#define AND 278
#define EQ 279
#define NE 280
#define GT 281
#define LT 282
#define GE 283
#define LE 284
#define ELLIPSIS 285
#define ADD_ASSIGN 286
#define SUB_ASSIGN 287
#define MUL_ASSIGN 288
#define DIV_ASSIGN 289
#define EAT 290
#define ARROW 291
#define PIPE 292
#define AT 293
#define IF 294
#define ELSE 295
#define FOR 296
#define WHILE 297
#define BREAK 298
#define CONTINUE 299
#define RETURN 300
#define LOWER_THAN_ELSE 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


