
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Parser.y"

#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin; /* Input for yacc parser. */
extern void yyerror(char *str); /* Our version. */
extern int yywrap(void); /* Our version. */
extern int yylex(void); /* Lexical analyzer function. */
extern int yyparse(void); /* Parser function. */

#include "ASTree.h"
#include "SymbolTable.h"
#include "SymbolTableUtil.h"
#include "util.h"
#include "CodeGen.h"
#include "global.h"


/* Line 189 of yacc.c  */
#line 92 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 316 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 328 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     2,     2,     2,     2,     2,     2,
       7,     8,     2,     2,    12,     2,    14,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    13,    11,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     9,     2,    10,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     5,     2,     6,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    29,    31,    33,    36,    39,    45,
      48,    52,    58,    66,    72,    82,    91,   100,   108,   117,
     125,   133,   140,   148,   151,   154,   158,   161,   163,   165,
     167,   171,   173,   177,   179,   181,   183,   185,   187,   189,
     191,   195,   197,   201,   203,   207,   211,   213,   217,   221,
     225,   229,   231,   235,   239,   241,   245,   249,   251,   256,
     258,   261,   263,   265,   267,   269,   275,   283,   288,   292,
     296,   307,   311,   315,   317,   319,   321,   323,   327,   329,
     331,   333,   335,   337,   339,   341,   345,   347,   350,   352,
     354,   356,   358,   367,   378,   382,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   405,   409,   411,   413,
     417,   419,   423,   425,   429,   435,   440,   442,   444,   448,
     451,   454,   457,   459,   463,   466,   468,   472,   473,   474,
     475,   476,   477
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     101,     0,    -1,   102,    -1,   103,    -1,   102,   103,    -1,
     134,    -1,   104,    -1,   105,    -1,   107,    -1,   109,    -1,
     110,    -1,   111,    -1,   112,    -1,   113,    11,    -1,    11,
      -1,   104,    -1,   106,   104,    -1,     5,     6,    -1,     5,
     149,   106,   150,     6,    -1,     5,     6,    -1,     5,   106,
       6,    -1,    60,     7,   113,     8,   104,    -1,    60,     7,
     113,     8,   104,    61,   104,    -1,    64,     7,   113,     8,
     104,    -1,    62,     7,   113,    11,   113,    11,   113,     8,
     104,    -1,    62,     7,   113,    11,   113,    11,     8,   104,
      -1,    62,     7,   113,    11,    11,   113,     8,   104,    -1,
      62,     7,   113,    11,    11,     8,   104,    -1,    62,     7,
      11,   113,    11,   113,     8,   104,    -1,    62,     7,    11,
     113,    11,     8,   104,    -1,    62,     7,    11,    11,   113,
       8,   104,    -1,    62,     7,    11,    11,     8,   104,    -1,
      63,     7,    25,    13,   125,     8,   104,    -1,    65,    11,
      -1,    66,    11,    -1,    67,   113,    11,    -1,    67,    11,
      -1,   138,    -1,   133,    -1,   114,    -1,   113,    12,   114,
      -1,   116,    -1,   123,   115,   114,    -1,     3,    -1,    50,
      -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,   117,
      -1,   116,    42,   117,    -1,   118,    -1,   117,    43,   118,
      -1,   119,    -1,   118,    44,   119,    -1,   118,    45,   119,
      -1,   120,    -1,   119,    47,   120,    -1,   119,    46,   120,
      -1,   119,    49,   120,    -1,   119,    48,   120,    -1,   121,
      -1,   120,    38,   121,    -1,   120,    39,   121,    -1,   122,
      -1,   121,    40,   122,    -1,   121,    41,   122,    -1,   123,
      -1,     7,   139,     8,   122,    -1,   125,    -1,   124,   122,
      -1,    38,    -1,    39,    -1,     4,    -1,   126,    -1,   126,
      13,   126,    55,   126,    -1,   126,    13,   126,    55,   126,
      58,   126,    -1,    25,     7,   129,     8,    -1,    25,     7,
       8,    -1,   125,    56,   128,    -1,   125,     9,   153,   151,
     149,   116,   150,   152,   154,    10,    -1,   125,    14,    25,
      -1,   125,    14,   127,    -1,   131,    -1,    25,    -1,   132,
      -1,    28,    -1,     7,   113,     8,    -1,    36,    -1,    37,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,   130,
      -1,   129,    12,   130,    -1,   114,    -1,    57,    25,    -1,
      26,    -1,    27,    -1,    29,    -1,    30,    -1,   136,   151,
     143,     3,   108,    11,   150,   152,    -1,   136,   151,   143,
      13,   139,     3,   108,   150,   152,    11,    -1,   135,   108,
     150,    -1,   139,   143,    -1,    31,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,   139,   140,    11,    -1,   137,
      -1,   141,    -1,   140,    12,   141,    -1,   142,    -1,   142,
       3,   147,    -1,    25,    -1,   142,    59,    25,    -1,   144,
     149,     7,   145,     8,    -1,   144,   149,     7,     8,    -1,
      25,    -1,   146,    -1,   145,    12,   146,    -1,   139,    25,
      -1,   139,   131,    -1,   136,    25,    -1,   114,    -1,     9,
     148,    10,    -1,     9,    10,    -1,   147,    -1,   148,    12,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   161,   162,   174,   177,   187,   188,   189,
     190,   191,   192,   196,   199,   203,   204,   213,   216,   222,
     225,   231,   234,   240,   243,   246,   249,   252,   255,   258,
     261,   264,   267,   273,   274,   275,   276,   280,   281,   289,
     290,   296,   297,   303,   304,   305,   306,   307,   308,   312,
     313,   319,   320,   326,   327,   330,   336,   337,   340,   343,
     346,   352,   353,   356,   362,   363,   366,   372,   373,   379,
     380,   386,   387,   388,   392,   393,   396,   397,   404,   411,
     414,   417,   420,   426,   441,   445,   446,   447,   456,   457,
     461,   462,   463,   464,   468,   469,   475,   482,   492,   493,
     494,   495,   503,   506,   516,   523,   534,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   550,   557,   563,   566,
     572,   575,   581,   584,   590,   597,   606,   612,   613,   619,
     625,   630,   637,   638,   642,   649,   650,   660,   666,   670,
     674,   678,   682
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'!'", "'{'", "'}'", "'('", "')'",
  "'['", "']'", "';'", "','", "':'", "'.'", "VOID", "BOOLEAN", "INTEGER",
  "FLOAT", "STRING", "LIST", "VERTEX", "EDGE", "GRAPH", "DYN_ATTRIBUTE",
  "IDENTIFIER", "INTEGER_CONSTANT", "FLOAT_CONSTANT", "STRING_LITERAL",
  "BOOL_TRUE", "BOOL_FALSE", "FUNC_LITERAL", "OUTCOMING_EDGES",
  "INCOMING_EDGES", "STARTING_VERTICES", "ENDING_VERTICES", "ALL_VERTICES",
  "ALL_EDGES", "ADD", "SUB", "MUL", "DIV", "OR", "AND", "EQ", "NE", "GT",
  "LT", "GE", "LE", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "APPEND", "ARROW", "PIPE", "AT", "MARK", "BELONG", "IF", "ELSE", "FOR",
  "FOREACH", "WHILE", "BREAK", "CONTINUE", "RETURN", "AST_TYPE_SPECIFIER",
  "AST_DECLARATION", "AST_COMMA", "AST_ASSIGN", "AST_CAST",
  "AST_UNARY_PLUS", "AST_UNARY_MINUS", "AST_UNARY_NOT",
  "AST_FUNC_DECLARATOR", "AST_PARA_DECLARATION", "AST_FUNC",
  "AST_INIT_ASSGN", "AST_LIST_INIT", "AST_MATCH", "AST_ATTIBUTE",
  "AST_GRAPH_PROP", "AST_STAT_LIST", "AST_COMP_STAT",
  "AST_COMP_STAT_NO_SCOPE", "AST_EXT_STAT_COMMA", "AST_IF_STAT",
  "AST_IFELSE_STAT", "AST_WHILE", "AST_FOR", "AST_FOREACH",
  "AST_JUMP_CONTINUE", "AST_JUMP_BREAK", "AST_JUMP_RETURN",
  "AST_FUNC_CALL", "AST_ARG_EXPS", "AST_EXP_STAT", "LOWER_THAN_ELSE",
  "$accept", "start_nonterminal", "translation_unit", "external_statement",
  "statement", "expression_statement", "statement_list",
  "compound_statement", "compound_statement_no_scope",
  "selection_statement", "iteration_statement", "jump_statement",
  "declaration_statement", "expression", "assignment_expression",
  "assignment_operator", "logical_OR_expression", "logical_AND_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "graph_property", "pipe_property", "argument_expression_list",
  "argument_expression", "attribute", "constant",
  "function_literal_declaration", "function_definition", "function_head",
  "function_literal_type_specifier", "basic_type_specifier", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "simple_declarator", "func_declarator", "func_id", "parameter_list",
  "parameter_declaration", "initializer", "initializer_list", "scope_in",
  "scope_out", "dynamic_scope_left", "dynamic_scope_right",
  "no_type_check_on_dynamic_left", "no_type_check_on_dynamic_right", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    33,   123,   125,    40,    41,    91,
      93,    59,    44,    58,    46,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   102,   102,   103,   103,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   119,   119,   119,   119,
     119,   120,   120,   120,   121,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   128,   129,   129,   130,   131,   132,   132,
     132,   132,   133,   133,   134,   135,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   138,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   145,   145,   146,
     146,   146,   147,   147,   147,   148,   148,   149,   150,   151,
     152,   153,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     5,     2,
       3,     5,     7,     5,     9,     8,     8,     7,     8,     7,
       7,     6,     7,     2,     2,     3,     2,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       2,     1,     1,     1,     1,     5,     7,     4,     3,     3,
      10,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     8,    10,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     5,     4,     1,     1,     3,     2,
       2,     2,     1,     3,     2,     1,     3,     0,     0,     0,
       0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    73,   137,     0,    14,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    84,    98,    99,    86,   100,   101,
     106,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     6,     7,     8,     9,    10,    11,
      12,     0,    39,    41,    49,    51,    53,    56,    61,    64,
      67,     0,    69,    74,    83,    85,    38,     5,     0,   139,
     117,    37,     0,    17,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    33,    34,    36,     0,     1,     4,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,     0,
      70,    67,   141,     0,     0,     0,     0,   138,     0,   122,
       0,   118,   120,   105,   137,    15,   138,     0,    87,     0,
      78,    96,     0,    94,     0,     0,     0,     0,     0,    35,
      40,    50,    52,    54,    55,    58,    57,    60,    59,    62,
      63,    65,    66,    42,   139,    81,    88,    89,    82,    90,
      91,    92,    93,    79,     0,    84,     0,    19,     0,   104,
     126,     0,   116,     0,     0,     0,     0,    16,     0,   122,
      68,    77,     0,     0,     0,     0,     0,     0,     0,   137,
       0,    20,     0,     0,   119,     0,   132,   121,   123,     0,
      18,    95,    21,     0,     0,     0,     0,     0,     0,    23,
       0,    75,     0,     0,   134,   135,     0,   125,     0,     0,
       0,   127,     0,    31,     0,     0,     0,     0,     0,     0,
       0,   138,     0,   138,     0,   133,     0,   131,   129,   130,
     124,     0,    22,    30,    29,     0,    27,     0,     0,     0,
      32,   140,    76,   140,   138,   136,   128,    28,    26,    25,
       0,   142,   102,   140,    24,     0,     0,    80,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    32,    33,    34,    35,   116,    36,   107,    37,
      38,    39,    40,    41,    42,    99,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   148,   153,   122,
     123,    54,    55,    56,    57,    58,    59,    60,    61,   117,
     110,   111,   112,   113,   114,   210,   211,   187,   206,    64,
     159,   108,   251,   144,   255
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -209
static const yytype_int16 yypact[] =
{
     335,  -209,     6,   389,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,     2,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,     8,    45,    56,    59,    96,    86,    97,
     422,   124,   335,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,    94,  -209,    76,    83,    93,   119,   131,   140,  -209,
      41,   584,    40,   136,  -209,  -209,  -209,  -209,   135,  -209,
    -209,  -209,   126,  -209,   335,    19,   149,   428,  -209,   584,
     461,   134,   584,  -209,  -209,  -209,   185,  -209,  -209,  -209,
     584,   584,   584,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   584,  -209,  -209,  -209,  -209,  -209,  -209,   584,
    -209,  -209,  -209,   -11,    55,   118,   207,  -209,   137,   157,
     197,  -209,     3,  -209,  -209,  -209,   335,   146,  -209,   584,
    -209,  -209,    52,  -209,    53,   467,   208,   164,    90,  -209,
    -209,    83,    93,   119,   119,   131,   131,   131,   131,   140,
     140,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,   584,  -209,   133,  -209,   271,  -209,
    -209,    17,  -209,   146,   103,   148,   175,  -209,   189,  -209,
    -209,  -209,   584,   335,   500,   230,   506,   288,   335,  -209,
     118,  -209,   135,   304,  -209,    12,  -209,  -209,  -209,   232,
    -209,  -209,   129,   335,    92,   539,   545,   245,    15,  -209,
     584,   152,   187,   213,  -209,  -209,    36,  -209,   196,   -23,
     108,  -209,   335,  -209,   335,   335,   109,   335,   127,   578,
     335,    76,   118,  -209,   135,  -209,   103,  -209,  -209,  -209,
    -209,   184,  -209,  -209,  -209,   335,  -209,   335,   335,   142,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
     335,  -209,  -209,  -209,  -209,   229,   249,  -209,  -209
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,   233,   -59,  -209,   155,  -209,  -171,  -209,
    -209,  -209,  -209,    -2,   -63,  -209,    62,   198,   186,   160,
      99,   169,   -33,    -8,  -209,    89,   -95,  -209,  -209,  -209,
     111,    71,  -209,  -209,  -209,  -209,  -176,  -209,  -209,     0,
    -209,   121,  -209,   173,  -209,  -209,    54,  -170,  -209,  -107,
    -108,   159,  -208,  -209,  -209
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -127
static const yytype_int16 yytable[] =
{
      62,    65,   228,    66,   121,   115,   164,   166,   168,    67,
     156,   202,    63,   208,   145,   205,     1,   130,   100,     3,
     182,   185,   204,   220,   102,   146,   147,   118,    76,   103,
     183,    80,    62,    68,    23,   252,   143,    14,    15,    16,
      17,    18,    19,   101,    93,   256,   225,   115,   226,   102,
      21,    22,    69,   244,   103,   208,   245,   167,   141,   142,
     171,   173,   165,    70,   172,    80,    71,   124,   126,    23,
     128,   104,   200,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   201,   170,   149,   150,   151,
     152,    94,    95,    96,    97,    98,   104,    73,   178,   167,
     214,   186,    80,    72,    80,    79,    80,     1,    74,   121,
       3,   101,   185,   241,   192,   243,   230,   235,    81,   199,
     231,    80,   186,   175,    77,   154,    82,   242,    14,    15,
      16,    17,    18,    19,   213,   237,   253,    83,    84,    80,
     106,    21,    22,   155,    15,    16,    17,    18,    19,   105,
     250,   109,    65,   232,    80,   233,   234,   119,   236,   127,
      23,   240,   160,   186,  -126,    85,    86,    87,    88,    89,
      90,   169,   194,   188,   197,    23,   247,   177,   248,   249,
      91,    92,   189,   203,   135,   136,   137,   138,   180,   209,
     212,   254,   101,   216,   218,   190,   129,    80,   223,     5,
       6,     7,     8,     9,    10,    11,    12,    13,   162,   163,
     222,     1,     2,   157,     3,    20,   224,   239,     4,   176,
      80,   227,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   209,    14,    15,    16,    17,    18,    19,    20,   257,
     207,   195,    80,   133,   134,    21,    22,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   219,    80,   139,   140,
     258,   158,   221,    20,    23,    78,   198,    24,   132,    25,
      26,    27,    28,    29,    30,     1,     2,   181,     3,   131,
     229,   161,     4,   191,   184,   246,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   154,    14,    15,    16,    17,
      18,    19,    20,   179,     0,     0,     0,     0,     0,    21,
      22,     0,     0,    14,    15,    16,    17,    18,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    23,     0,
       0,    24,     0,    25,    26,    27,    28,    29,    30,     1,
       2,     0,     3,     0,     0,    23,     4,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     1,     0,    24,     3,    25,    26,    27,
      28,    29,    30,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     1,    21,    22,     3,
       0,     0,     1,    75,     0,     3,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    14,    15,    16,
      17,    18,    19,    14,    15,    16,    17,    18,    19,     0,
      21,    22,     0,     0,     0,     1,    21,    22,     3,     0,
       0,     1,   125,     0,     3,     0,     0,     0,   174,    23,
       0,     0,     0,     0,     0,    23,    14,    15,    16,    17,
      18,    19,    14,    15,    16,    17,    18,    19,     0,    21,
      22,     0,     0,     0,     1,    21,    22,     3,   193,     0,
       1,     0,     0,     3,     0,     0,     0,   196,    23,     0,
       0,     0,     0,     0,    23,    14,    15,    16,    17,    18,
      19,    14,    15,    16,    17,    18,    19,     0,    21,    22,
       0,     0,     0,     1,    21,    22,     3,   215,     0,     1,
       0,     0,     3,   217,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    23,    14,    15,    16,    17,    18,    19,
      14,    15,    16,    17,    18,    19,     0,    21,    22,     0,
       0,     0,     1,    21,    22,     3,   238,     0,     1,     0,
       0,     3,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,    23,    14,    15,    16,    17,    18,    19,    14,
      15,    16,    17,    18,    19,     0,    21,    22,     0,     0,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    23
};

static const yytype_int16 yycheck[] =
{
       0,     3,    25,     3,    67,    64,     3,   114,   116,     7,
     105,   182,     6,   189,    25,   185,     4,    80,    51,     7,
       3,     9,    10,     8,     9,    36,    37,     8,    30,    14,
      13,    12,    32,    25,    57,   243,    99,    25,    26,    27,
      28,    29,    30,    51,     3,   253,    10,   106,    12,     9,
      38,    39,     7,   224,    14,   231,   226,   116,    91,    92,
       8,     8,    59,     7,    12,    12,     7,    69,    70,    57,
      72,    56,   179,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   180,   119,    32,    33,    34,
      35,    50,    51,    52,    53,    54,    56,    11,     8,   158,
       8,   164,    12,     7,    12,    11,    12,     4,    11,   172,
       7,   119,     9,   221,   173,   223,     8,     8,    42,   178,
      12,    12,   185,   125,     0,     7,    43,   222,    25,    26,
      27,    28,    29,    30,   193,     8,   244,    44,    45,    12,
       5,    38,    39,    25,    26,    27,    28,    29,    30,    13,
       8,    25,   154,   212,    12,   214,   215,     8,   217,    25,
      57,   220,    25,   226,     7,    46,    47,    48,    49,    38,
      39,    25,   174,    25,   176,    57,   235,    13,   237,   238,
      40,    41,     7,   183,    85,    86,    87,    88,    55,   189,
      61,   250,   200,   195,   196,     6,    11,    12,    11,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    11,    12,
      58,     4,     5,     6,     7,    31,     3,   219,    11,    11,
      12,    25,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   231,    25,    26,    27,    28,    29,    30,    31,    10,
       8,    11,    12,    83,    84,    38,    39,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    11,    12,    89,    90,
      11,   106,   200,    31,    57,    32,   177,    60,    82,    62,
      63,    64,    65,    66,    67,     4,     5,     6,     7,    81,
     209,   108,    11,   172,   163,   231,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     7,    25,    26,    27,    28,
      29,    30,    31,   144,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    25,    26,    27,    28,    29,    30,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    57,    -1,
      -1,    60,    -1,    62,    63,    64,    65,    66,    67,     4,
       5,    -1,     7,    -1,    -1,    57,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,     4,    -1,    60,     7,    62,    63,    64,
      65,    66,    67,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    38,    39,     7,
      -1,    -1,     4,    11,    -1,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    25,    26,    27,
      28,    29,    30,    25,    26,    27,    28,    29,    30,    -1,
      38,    39,    -1,    -1,    -1,     4,    38,    39,     7,    -1,
      -1,     4,    11,    -1,     7,    -1,    -1,    -1,    11,    57,
      -1,    -1,    -1,    -1,    -1,    57,    25,    26,    27,    28,
      29,    30,    25,    26,    27,    28,    29,    30,    -1,    38,
      39,    -1,    -1,    -1,     4,    38,    39,     7,     8,    -1,
       4,    -1,    -1,     7,    -1,    -1,    -1,    11,    57,    -1,
      -1,    -1,    -1,    -1,    57,    25,    26,    27,    28,    29,
      30,    25,    26,    27,    28,    29,    30,    -1,    38,    39,
      -1,    -1,    -1,     4,    38,    39,     7,     8,    -1,     4,
      -1,    -1,     7,     8,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    57,    25,    26,    27,    28,    29,    30,
      25,    26,    27,    28,    29,    30,    -1,    38,    39,    -1,
      -1,    -1,     4,    38,    39,     7,     8,    -1,     4,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    57,    25,    26,    27,    28,    29,    30,    25,
      26,    27,    28,    29,    30,    -1,    38,    39,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     7,    11,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      31,    38,    39,    57,    60,    62,    63,    64,    65,    66,
      67,   101,   102,   103,   104,   105,   107,   109,   110,   111,
     112,   113,   114,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     6,   149,   113,   139,     7,    25,     7,
       7,     7,     7,    11,    11,    11,   113,     0,   103,    11,
      12,    42,    43,    44,    45,    46,    47,    48,    49,    38,
      39,    40,    41,     3,    50,    51,    52,    53,    54,   115,
     122,   123,     9,    14,    56,    13,     5,   108,   151,    25,
     140,   141,   142,   143,   144,   104,   106,   139,     8,     8,
       8,   114,   129,   130,   113,    11,   113,    25,   113,    11,
     114,   117,   118,   119,   119,   120,   120,   120,   120,   121,
     121,   122,   122,   114,   153,    25,    36,    37,   127,    32,
      33,    34,    35,   128,     7,    25,   126,     6,   106,   150,
      25,   143,    11,    12,     3,    59,   149,   104,   150,    25,
     122,     8,    12,     8,    11,   113,    11,    13,     8,   151,
      55,     6,     3,    13,   141,     9,   114,   147,    25,     7,
       6,   130,   104,     8,   113,    11,    11,   113,   125,   104,
     149,   126,   108,   139,    10,   147,   148,     8,   136,   139,
     145,   146,    61,   104,     8,     8,   113,     8,   113,    11,
       8,   116,    58,    11,     3,    10,    12,    25,    25,   131,
       8,    12,   104,   104,   104,     8,   104,     8,     8,   113,
     104,   150,   126,   150,   108,   147,   146,   104,   104,   104,
       8,   152,   152,   150,   104,   154,   152,    10,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 130 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
        showASTandST((yyval.node),"Syntax + Semantic P1");
        if(!ERRNO) {// no syntax error, or declaration error
            char *mainBodyCode=NULL, *funCode=NULL,*mainCode;
            char *globalDecl=NULL;
            codeIndentInit();
            codeAllGen((yyval.node), &mainBodyCode, &funCode);
            codeAllFuncLiteral((yyval.node), &funCode);
            codeAllGlobal((yyval.node),&globalDecl);
            mainCode = wapperMainCode(mainBodyCode);        
            codeIndentFree();
            showASTandST((yyval.node),"Semantic P2 + Code Gen");
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
        astFreeTree((yyval.node));            // destroy AST
        
    }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 161 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 162 "Parser.y"
    {
        struct Node* leftNode = astLeftmostNode((yyvsp[(1) - (2)].node));
        long long ll = -1; 
        if(leftNode!=NULL) ll = leftNode->line;
        (yyval.node) = astNewNode( AST_EXT_STAT_COMMA, 2, astAllChildren( 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node) ), ll );
    }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 174 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 177 "Parser.y"
    { 
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 187 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 188 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 189 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 190 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 191 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 192 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 196 "Parser.y"
    { 
        (yyval.node) = astNewNode( AST_EXP_STAT, 1, astAllChildren(1, (yyvsp[(1) - (2)].node)), (yyvsp[(1) - (2)].node)->line);
    }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 199 "Parser.y"
    { (yyval.node) = astNewNode( AST_EXP_STAT, 0, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 203 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 204 "Parser.y"
    {
        struct Node* leftNode = astLeftmostNode((yyvsp[(1) - (2)].node));
        long long ll = -1;
        if(leftNode!=NULL) ll = leftNode->line;
        (yyval.node) = astNewNode( AST_STAT_LIST, 2, astAllChildren(2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)), ll );
    }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 213 "Parser.y"
    { 
        (yyval.node) = astNewNode( AST_COMP_STAT, 0, NULL, (yyvsp[(1) - (2)].LString).l );
    }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 216 "Parser.y"
    { 
        (yyval.node) = astNewNode( AST_COMP_STAT, 1, astAllChildren(1, (yyvsp[(3) - (5)].node)), (yyvsp[(1) - (5)].LString).l );
    }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 222 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMP_STAT_NO_SCOPE, 0, NULL, (yyvsp[(1) - (2)].LString).l );
    }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 225 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMP_STAT_NO_SCOPE, 1, astAllChildren(1, (yyvsp[(2) - (3)].node)), (yyvsp[(1) - (3)].LString).l );
    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 231 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_IF_STAT, 2, astAllChildren(2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)), (yyvsp[(1) - (5)].LString).l );
    }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 234 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_IFELSE_STAT, 3, astAllChildren(3,(yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)), (yyvsp[(1) - (7)].LString).l);
    }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 240 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_WHILE, 2, astAllChildren(2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)), (yyvsp[(1) - (5)].LString).l);
    }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 243 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)), (yyvsp[(1) - (9)].LString).l);
    }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 246 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, (yyvsp[(3) - (8)].node), (yyvsp[(5) - (8)].node), NULL, (yyvsp[(8) - (8)].node)), (yyvsp[(1) - (8)].LString).l);
    }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 249 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, (yyvsp[(3) - (8)].node), NULL, (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node)), (yyvsp[(1) - (8)].LString).l);
    }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 252 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, (yyvsp[(3) - (7)].node), NULL, NULL, (yyvsp[(7) - (7)].node)), (yyvsp[(1) - (7)].LString).l);
    }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 255 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node)), (yyvsp[(1) - (8)].LString).l);
    }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 258 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, (yyvsp[(4) - (7)].node), NULL, (yyvsp[(7) - (7)].node)), (yyvsp[(1) - (7)].LString).l);
    }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 261 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, NULL,(yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)), (yyvsp[(1) - (7)].LString).l);
    }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 264 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOR, 4, astAllChildren(4, NULL, NULL, NULL, (yyvsp[(6) - (6)].node)), (yyvsp[(1) - (6)].LString).l);
    }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 267 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FOREACH, 3, astAllChildren(3, astNewLeaf(IDENTIFIER, (yyvsp[(3) - (7)].LString).s, (yyvsp[(3) - (7)].LString).l), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)), (yyvsp[(1) - (7)].LString).l);
    }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 273 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_BREAK, 0, NULL, (yyvsp[(1) - (2)].LString).l);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 274 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_CONTINUE, 0, NULL, (yyvsp[(1) - (2)].LString).l);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 275 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_RETURN, 1, astAllChildren(1, (yyvsp[(2) - (3)].node)), (yyvsp[(1) - (3)].LString).l);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 276 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_RETURN, 0, NULL, (yyvsp[(1) - (2)].LString).l);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 280 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 281 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 289 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 290 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 296 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 297 "Parser.y"
    {
       (yyval.node) = astNewNode ( (yyvsp[(2) - (3)].LInteger).i, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LInteger).l ); 
    }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 303 "Parser.y"
    { (yyval.LInteger).i = AST_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 304 "Parser.y"
    { (yyval.LInteger).i = ADD_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 305 "Parser.y"
    { (yyval.LInteger).i = SUB_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 306 "Parser.y"
    { (yyval.LInteger).i = MUL_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 307 "Parser.y"
    { (yyval.LInteger).i = DIV_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 308 "Parser.y"
    { (yyval.LInteger).i = APPEND;     (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 312 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 313 "Parser.y"
    {
        (yyval.node) = astNewNode ( OR, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 319 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 320 "Parser.y"
    {
        (yyval.node) = astNewNode ( AND, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 326 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 327 "Parser.y"
    {
        (yyval.node) = astNewNode ( EQ, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 330 "Parser.y"
    {
        (yyval.node) = astNewNode ( NE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 336 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 337 "Parser.y"
    {
        (yyval.node) = astNewNode ( LT, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 340 "Parser.y"
    {
        (yyval.node) = astNewNode ( GT, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 343 "Parser.y"
    {
        (yyval.node) = astNewNode ( LE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 346 "Parser.y"
    {
        (yyval.node) = astNewNode ( GE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 352 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 353 "Parser.y"
    {
        (yyval.node) = astNewNode ( ADD, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 356 "Parser.y"
    {
        (yyval.node) = astNewNode ( SUB, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 362 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 363 "Parser.y"
    {
        (yyval.node) = astNewNode ( MUL, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 366 "Parser.y"
    {
        (yyval.node) = astNewNode ( DIV, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 372 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 373 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_CAST, 2, astAllChildren(2, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)), (yyvsp[(2) - (4)].node)->line );
    }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 379 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 380 "Parser.y"
    {
        (yyval.node) = astNewNode ( (yyvsp[(1) - (2)].LInteger).i, 1, astAllChildren(1, (yyvsp[(2) - (2)].node)), (yyvsp[(1) - (2)].LInteger).l );
    }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 386 "Parser.y"
    { (yyval.LInteger).i = AST_UNARY_PLUS;  (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 387 "Parser.y"
    { (yyval.LInteger).i = AST_UNARY_MINUS; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 388 "Parser.y"
    { (yyval.LInteger).i = AST_UNARY_NOT;   (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 392 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 393 "Parser.y"
    {
        (yyval.node) = astNewNode ( ARROW, 3, astAllChildren(3, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)), (yyvsp[(2) - (5)].LString).l );
    }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 397 "Parser.y"
    {
        struct Node* tn = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (4)].LString).s, (yyvsp[(1) - (4)].LString).l);
        (yyval.node) = astNewNode(AST_FUNC_CALL, 2, astAllChildren(2, tn, (yyvsp[(3) - (4)].node)), tn->line);
        //$$->typeCon = astTypeConArgList($3,NULL);   // type construct for arguments
        //sTableLookupFunc($$);                       // Lookup this func
        //astFreeTypeCon($$->typeCon);
    }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 404 "Parser.y"
    {
        struct Node* tn = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (3)].LString).s, (yyvsp[(1) - (3)].LString).l);
        (yyval.node) = astNewNode(AST_FUNC_CALL, 1, astAllChildren(1, tn), tn->line);
        //$$->typeCon = astTypeConArgList(NULL, NULL);    // empty
        //sTableLookupFunc($$);
        //astFreeTypeCon($$->typeCon);
    }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 411 "Parser.y"
    {
        (yyval.node) = astNewNode ( PIPE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 414 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_MATCH, 2, astAllChildren(2, (yyvsp[(1) - (10)].node), (yyvsp[(6) - (10)].node)), (yyvsp[(2) - (10)].LString).l );
    }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 417 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_ATTIBUTE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), astNewLeaf(IDENTIFIER, (yyvsp[(3) - (3)].LString).s, (yyvsp[(3) - (3)].LString).l)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 420 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_GRAPH_PROP, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 426 "Parser.y"
    { 
        (yyval.node) = (yyvsp[(1) - (1)].node); 
        if(isNoTypeCheck==0){   // Func_Literal
            sTableLookupId((yyval.node));                 // Lookup ATTRIBUTE
        }
        else {  // Match operator
            // As here we may use `attribute' directly without declaration,
            // so it must be inserted into symbol table when first meets an `attribute'
            (yyval.node)->type = DYNAMIC_T;                       // 1. set type 
            (yyval.node)->symbol = sTableTryLookupId((yyval.node));         // 2. try look up myself in symtable
            if ( (yyval.node)->symbol==NULL ) {                   // if not exsit, insert it
                sTableInsertId((yyval.node), DYNAMIC_T);
            }
        }
    }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 441 "Parser.y"
    { 
        (yyval.node) = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); 
        sTableLookupId((yyval.node));                 // Lookup IDENTIFIER in Symbol Table 
    }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 445 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 446 "Parser.y"
    { (yyval.node) = astNewLeaf(STRING_LITERAL, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 447 "Parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 456 "Parser.y"
    { (yyval.node) = astNewLeaf(ALL_VERTICES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 457 "Parser.y"
    { (yyval.node) = astNewLeaf(ALL_EDGES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 461 "Parser.y"
    { (yyval.node) = astNewLeaf(OUTCOMING_EDGES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 462 "Parser.y"
    { (yyval.node) = astNewLeaf(INCOMING_EDGES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 463 "Parser.y"
    { (yyval.node) = astNewLeaf(STARTING_VERTICES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 464 "Parser.y"
    { (yyval.node) = astNewLeaf(ENDING_VERTICES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 468 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 469 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 475 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_ARG_EXPS, 1, astAllChildren(1, (yyvsp[(1) - (1)].node)), (yyvsp[(1) - (1)].node)->line );
        //$$->type = $1->type;
    }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 482 "Parser.y"
    { 
        if (isDynamicScope==0) {
            ERRNO = ErrorDynamicAttributeUsedInNonDynamicScope;
            errorInfo(ERRNO, (yyvsp[(2) - (2)].LString).l, "dynamic attribute `%s' is used in non-dynamic scope\n", (yyvsp[(2) - (2)].LString).s);
        }
        (yyval.node) = astNewLeaf ( DYN_ATTRIBUTE, (yyvsp[(2) - (2)].LString).s, (yyvsp[(2) - (2)].LString).l );
    }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 492 "Parser.y"
    { (yyval.node) = astNewLeaf(INTEGER_CONSTANT, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 493 "Parser.y"
    { (yyval.node) = astNewLeaf(FLOAT_CONSTANT, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 494 "Parser.y"
    { (yyval.node) = astNewLeaf(BOOL_TRUE, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 495 "Parser.y"
    { (yyval.node) = astNewLeaf(BOOL_FALSE, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 503 "Parser.y"
    {
        // not used anymore
    }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 506 "Parser.y"
    {
        (yyval.node) = astNewNode((yyvsp[(1) - (10)].LInteger).i, 3, astAllChildren(3, (yyvsp[(3) - (10)].node), (yyvsp[(5) - (10)].node), (yyvsp[(7) - (10)].node)), (yyvsp[(1) - (10)].LInteger).l);
        (yyval.node)->typeCon = (yyvsp[(3) - (10)].node)->typeCon;
        (yyval.node)->scope[0] = (yyvsp[(3) - (10)].node)->scope[0];
        (yyval.node)->scope[1] = (yyvsp[(3) - (10)].node)->scope[1];
        sTableDeclare((yyval.node));
    }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 516 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (3)].node);
        (yyval.node)->child[2] = (yyvsp[(2) - (3)].node);   // fill up the third field       
    }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 523 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FUNC, 3, astAllChildren(3, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL), (yyvsp[(2) - (2)].node)->line); // third field empty
        (yyval.node)->typeCon = (yyvsp[(2) - (2)].node)->typeCon;
        (yyval.node)->scope[0] = (yyvsp[(2) - (2)].node)->scope[0];     // Scope Level
        (yyval.node)->scope[1] = (yyvsp[(2) - (2)].node)->scope[1];     // Scope Id
        sTableDeclare((yyval.node));  // We must declare before coming into compound stat, for recursive call
        // tmp no longer needed after here
    }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 534 "Parser.y"
    { (yyval.LInteger).i = FUNC_LITERAL; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 538 "Parser.y"
    { int ttype = VOID_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 539 "Parser.y"
    { int ttype = BOOL_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 540 "Parser.y"
    { int ttype = INT_T;    (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 541 "Parser.y"
    { int ttype = FLOAT_T;  (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 542 "Parser.y"
    { int ttype = STRING_T; (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 543 "Parser.y"
    { int ttype = LIST_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 544 "Parser.y"
    { int ttype = VERTEX_T; (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 545 "Parser.y"
    { int ttype = EDGE_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 546 "Parser.y"
    { int ttype = GRAPH_T;  (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 550 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_DECLARATION, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node)), (yyvsp[(1) - (3)].node)->line );    
        sTableDeclare((yyval.node));
    }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 557 "Parser.y"
    {
        (yyval.node)= (yyvsp[(1) - (1)].node);
    }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 563 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 566 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 572 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 575 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_ASSIGN, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 581 "Parser.y"
    {
        (yyval.node) = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l);
    }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 584 "Parser.y"
    {
        (yyval.node) = astNewNode( BELONG, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), astNewLeaf(IDENTIFIER, (yyvsp[(3) - (3)].LString).s, (yyvsp[(3) - (3)].LString).l)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 590 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_FUNC_DECLARATOR, 2, astAllChildren(2, (yyvsp[(1) - (5)].node), (yyvsp[(4) - (5)].node)), (yyvsp[(1) - (5)].node)->line );
        // generate type Constructor for parameters
        (yyval.node)->typeCon = astTypeConParaList( (yyvsp[(4) - (5)].node), NULL );
        (yyval.node)->scope[0] = (yyvsp[(1) - (5)].node)->scope[0];     // Scope Level
        (yyval.node)->scope[1] = (yyvsp[(1) - (5)].node)->scope[1];     // Scope Id
    }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 597 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_FUNC_DECLARATOR, 1, astAllChildren(1, (yyvsp[(1) - (4)].node) ), (yyvsp[(1) - (4)].node)->line );
        (yyval.node)->typeCon = astTypeConParaList( NULL, NULL );
        (yyval.node)->scope[0] = (yyvsp[(1) - (4)].node)->scope[0];     // Scope Level
        (yyval.node)->scope[1] = (yyvsp[(1) - (4)].node)->scope[1];     // Scope Id
    }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 606 "Parser.y"
    {
        (yyval.node) = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l);
    }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 612 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 613 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 619 "Parser.y"
    {
        struct Node* tn = astNewLeaf(IDENTIFIER, (yyvsp[(2) - (2)].LString).s, (yyvsp[(2) - (2)].LString).l);
        (yyval.node) = astNewNode( AST_PARA_DECLARATION, 2, astAllChildren(2, (yyvsp[(1) - (2)].node), tn), (yyvsp[(1) - (2)].node)->line);
        sTableDeclare((yyval.node));
        (yyval.node)->type = tn->type;
    }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 625 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_PARA_DECLARATION, 2, astAllChildren(2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)), (yyvsp[(1) - (2)].node)->line);
        sTableDeclare((yyval.node));
        (yyval.node)->type = (yyvsp[(2) - (2)].node)->type;
    }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 630 "Parser.y"
    {
        (yyval.node) = astNewNode( FUNC_LITERAL, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, (yyvsp[(2) - (2)].LString).s, (yyvsp[(2) - (2)].LString).l)), (yyvsp[(1) - (2)].LInteger).l);
        (yyval.node)->type = FUNC_LITERAL_T;
    }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 637 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 638 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_LIST_INIT, 1, astAllChildren(1, (yyvsp[(2) - (3)].node)), (yyvsp[(1) - (3)].LString).l );
        (yyval.node)->type = LIST_T;
    }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 642 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_LIST_INIT, 0, NULL, (yyvsp[(1) - (2)].LString).l );
        (yyval.node)->type = LIST_T;
    }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 649 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 650 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)), (yyvsp[(2) - (3)].LString).l );
    }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 660 "Parser.y"
    { sStackPush( sNewScopeId() ); 
              maxLevel = (maxLevel<sStackLevel) ? sStackLevel : maxLevel;
            }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 666 "Parser.y"
    { sStackPop(); }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 670 "Parser.y"
    { isDynamicScope = 1; }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 674 "Parser.y"
    { isDynamicScope = 0; }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 678 "Parser.y"
    { isNoTypeCheck = 1; }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 682 "Parser.y"
    { isNoTypeCheck = 0; }
    break;



/* Line 1455 of yacc.c  */
#line 3083 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 684 "Parser.y"


void yyerror(char *s) {
    printf("%s\n", s);
}

void main_init(char * fileName) {
    init_util();
    sTableInit();
    sStackInit();
    isDynamicScope = 0;
    isNoTypeCheck = 0;
    maxLevel = 0;
    inLoop = 0;
    inFunc = 0;
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
    return 0;
}

