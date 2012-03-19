
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
     TRUE = 271,
     FALSE = 272,
     FUNC_LITERAL = 273,
     OUTCOMING_EDGES = 274,
     INCOMING_EDGES = 275,
     STARTING_VERTICES = 276,
     ENDING_VERTICES = 277,
     ALL_VERTICES = 278,
     ALL_EDGES = 279,
     OR = 280,
     AND = 281,
     EQ = 282,
     NE = 283,
     GT = 284,
     LT = 285,
     GE = 286,
     LE = 287,
     ADD_ASSIGN = 288,
     SUB_ASSIGN = 289,
     MUL_ASSIGN = 290,
     DIV_ASSIGN = 291,
     APPEND = 292,
     ARROW = 293,
     PIPE = 294,
     AT = 295,
     MARK = 296,
     BELONG = 297,
     IF = 298,
     ELSE = 299,
     FOR = 300,
     FOREACH = 301,
     WHILE = 302,
     BREAK = 303,
     CONTINUE = 304,
     RETURN = 305,
     LOWER_THAN_ELSE = 306
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
#define TRUE 271
#define FALSE 272
#define FUNC_LITERAL 273
#define OUTCOMING_EDGES 274
#define INCOMING_EDGES 275
#define STARTING_VERTICES 276
#define ENDING_VERTICES 277
#define ALL_VERTICES 278
#define ALL_EDGES 279
#define OR 280
#define AND 281
#define EQ 282
#define NE 283
#define GT 284
#define LT 285
#define GE 286
#define LE 287
#define ADD_ASSIGN 288
#define SUB_ASSIGN 289
#define MUL_ASSIGN 290
#define DIV_ASSIGN 291
#define APPEND 292
#define ARROW 293
#define PIPE 294
#define AT 295
#define MARK 296
#define BELONG 297
#define IF 298
#define ELSE 299
#define FOR 300
#define FOREACH 301
#define WHILE 302
#define BREAK 303
#define CONTINUE 304
#define RETURN 305
#define LOWER_THAN_ELSE 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


