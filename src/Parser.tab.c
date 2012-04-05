
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

#include "global.h"
#include "ASTree.h"
#include "SymbolTable.h"
#include "SymbolTableUtil.h"
#include "util.h"


/* Line 189 of yacc.c  */
#line 91 "y.tab.c"

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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 321 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 333 "y.tab.c"

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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   655

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     2,     2,     2,     2,     2,     2,
      96,    97,     2,     2,    99,     2,   102,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    98,    93,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   101,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,     2,    95,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92
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
     296,   301,   305,   309,   311,   313,   315,   317,   321,   323,
     325,   327,   329,   331,   333,   335,   339,   342,   344,   346,
     348,   350,   357,   366,   371,   373,   375,   377,   379,   381,
     383,   385,   387,   389,   391,   395,   397,   399,   403,   405,
     409,   411,   415,   421,   426,   428,   432,   435,   438,   440,
     444,   447,   449,   453,   454
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   105,    -1,   106,    -1,   105,   106,    -1,
     136,    -1,   107,    -1,   108,    -1,   110,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    93,    -1,    93,
      -1,   107,    -1,   109,   107,    -1,    94,    95,    -1,    94,
     149,   109,   150,    95,    -1,    94,    95,    -1,    94,   109,
      95,    -1,    49,    96,   116,    97,   107,    -1,    49,    96,
     116,    97,   107,    50,   107,    -1,    53,    96,   116,    97,
     107,    -1,    51,    96,   116,    93,   116,    93,   116,    97,
     107,    -1,    51,    96,   116,    93,   116,    93,    97,   107,
      -1,    51,    96,   116,    93,    93,   116,    97,   107,    -1,
      51,    96,   116,    93,    93,    97,   107,    -1,    51,    96,
      93,   116,    93,   116,    97,   107,    -1,    51,    96,    93,
     116,    93,    97,   107,    -1,    51,    96,    93,    93,   116,
      97,   107,    -1,    51,    96,    93,    93,    97,   107,    -1,
      52,    96,    14,    98,   128,    97,   107,    -1,    54,    93,
      -1,    55,    93,    -1,    56,   116,    93,    -1,    56,    93,
      -1,   139,    -1,   135,    -1,   117,    -1,   116,    99,   117,
      -1,   119,    -1,   126,   118,   117,    -1,     3,    -1,    39,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,   120,
      -1,   119,    31,   120,    -1,   121,    -1,   120,    32,   121,
      -1,   122,    -1,   121,    33,   122,    -1,   121,    34,   122,
      -1,   123,    -1,   122,    36,   123,    -1,   122,    35,   123,
      -1,   122,    38,   123,    -1,   122,    37,   123,    -1,   124,
      -1,   123,    27,   124,    -1,   123,    28,   124,    -1,   125,
      -1,   124,    29,   125,    -1,   124,    30,   125,    -1,   126,
      -1,    96,   140,    97,   125,    -1,   128,    -1,   127,   125,
      -1,    27,    -1,    28,    -1,     4,    -1,   129,    -1,   129,
      98,   129,    44,   129,    -1,   129,    98,   129,    44,   129,
      47,   129,    -1,    14,    96,   132,    97,    -1,    14,    96,
      97,    -1,   128,    45,   131,    -1,   128,   100,   119,   101,
      -1,   128,   102,    14,    -1,   128,   102,   130,    -1,   133,
      -1,    14,    -1,   134,    -1,    17,    -1,    96,   116,    97,
      -1,    25,    -1,    26,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,   117,    -1,   132,    99,   117,    -1,    46,
      14,    -1,    15,    -1,    16,    -1,    18,    -1,    19,    -1,
     137,   144,     3,   111,    93,   150,    -1,   137,   144,    98,
     140,     3,   111,   150,    93,    -1,   140,   144,   111,   150,
      -1,    20,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,   140,   141,    93,    -1,   138,    -1,   142,    -1,   141,
      99,   142,    -1,   143,    -1,   143,     3,   147,    -1,    14,
      -1,   143,    48,    14,    -1,    14,    96,   149,   145,    97,
      -1,    14,    96,   149,    97,    -1,   146,    -1,   145,    99,
     146,    -1,   140,    14,    -1,   137,    14,    -1,   117,    -1,
     100,   148,   101,    -1,   100,   101,    -1,   147,    -1,   148,
      99,   147,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   133,   134,   143,   150,   160,   161,   162,
     163,   164,   165,   169,   170,   174,   175,   181,   184,   190,
     193,   199,   200,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   217,   218,   219,   220,   224,   225,   233,
     234,   240,   241,   247,   248,   249,   250,   251,   252,   256,
     257,   263,   264,   270,   271,   274,   280,   281,   284,   287,
     290,   296,   297,   300,   306,   307,   310,   316,   317,   323,
     324,   330,   331,   332,   336,   337,   340,   341,   344,   347,
     350,   353,   356,   362,   363,   367,   368,   369,   378,   379,
     383,   384,   385,   386,   390,   391,   397,   403,   404,   405,
     406,   414,   417,   423,   429,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   445,   452,   458,   461,   467,   470,
     476,   479,   485,   488,   494,   495,   501,   505,   511,   512,
     515,   521,   522,   532,   536
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'!'", "VOID", "BOOLEAN",
  "INTEGER", "FLOAT", "STRING", "LIST", "VERTEX", "EDGE", "GRAPH",
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
  "AST_GRAPH_PROP", "AST_STAT_LIST", "AST_COMP_STAT", "AST_EXT_STAT_COMMA",
  "AST_IF_STAT", "AST_IFELSE_STAT", "AST_WHILE", "AST_FOR_XXX",
  "AST_FOR_XXO", "AST_FOR_XOX", "AST_FOR_XOO", "AST_FOR_OXX",
  "AST_FOR_OXO", "AST_FOR_OOX", "AST_FOR_OOO", "AST_FOREACH",
  "AST_JUMP_CONTINUE", "AST_JUMP_BREAK", "AST_JUMP_RETURN",
  "AST_POSTFIX_EPR", "LOWER_THAN_ELSE", "';'", "'{'", "'}'", "'('", "')'",
  "':'", "','", "'['", "']'", "'.'", "$accept", "start_nonterminal",
  "translation_unit", "external_statement", "statement",
  "expression_statement", "statement_list", "compound_statement",
  "compound_statement_no_scope", "selection_statement",
  "iteration_statement", "jump_statement", "declaration_statement",
  "expression", "assignment_expression", "assignment_operator",
  "logical_OR_expression", "logical_AND_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "graph_property", "pipe_property", "argument_expression_list",
  "attribute", "constant", "function_literal_declaration",
  "function_definition", "function_literal_type_specifier",
  "basic_type_specifier", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "simple_declarator",
  "func_declarator", "parameter_list", "parameter_declaration",
  "initializer", "initializer_list", "scope_in", "scope_out", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    33,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,    59,   123,   125,    40,    41,    58,    44,
      91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   122,   122,
     122,   123,   123,   123,   124,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   130,   130,
     131,   131,   131,   131,   132,   132,   133,   134,   134,   134,
     134,   135,   135,   136,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     147,   148,   148,   149,   150
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
       4,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     6,     8,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     5,     4,     1,     3,     2,     2,     1,     3,
       2,     1,     3,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    73,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    84,    97,    98,    86,    99,   100,   104,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,    14,   133,
       0,     0,     2,     3,     6,     7,     8,     9,    10,    11,
      12,     0,    39,    41,    49,    51,    53,    56,    61,    64,
      67,     0,    69,    74,    83,    85,    38,     5,     0,   115,
      37,     0,     0,    96,     0,     0,     0,     0,    33,    34,
      36,     0,    17,     0,     0,     0,     1,     4,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,     0,    70,
      67,     0,     0,     0,     0,     0,     0,   120,     0,   116,
     118,     0,    78,    94,     0,     0,     0,     0,     0,     0,
      35,    15,   134,     0,    87,     0,    40,    50,    52,    54,
      55,    58,    57,    60,    59,    62,    63,    65,    66,    42,
      90,    91,    92,    93,    79,     0,    81,    88,    89,    82,
      84,     0,     0,   133,     0,     0,   114,     0,     0,     0,
       0,   134,    77,     0,     0,     0,     0,     0,     0,     0,
      16,     0,   120,    68,    80,     0,     0,     0,     0,   117,
       0,   128,   119,   121,    19,     0,   103,    95,    21,     0,
       0,     0,     0,     0,     0,    23,    18,    75,   123,     0,
       0,     0,   124,   134,     0,   130,   131,     0,    20,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     126,   122,     0,   101,   134,     0,   129,    22,    30,    29,
       0,    27,     0,     0,     0,    32,    76,   125,     0,   132,
      28,    26,    25,     0,   102,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    32,    33,    34,    35,   122,    36,   161,    37,
      38,    39,    40,    41,    42,    98,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   149,   144,   114,
      54,    55,    56,    57,    58,    59,    60,   123,   108,   109,
     110,   106,   201,   202,   182,   207,    73,   171
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -169
static const yytype_int16 yypact[] =
{
     389,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,   -75,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
      22,   -56,   -50,   -38,   -28,    -5,     6,   459,  -169,   -24,
     442,    93,   389,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,   -71,  -169,   116,    83,    90,   100,    84,   102,  -169,
      78,   529,   -11,    55,  -169,  -169,  -169,  -169,   160,  -169,
    -169,   164,   167,  -169,   529,   475,   174,   529,  -169,  -169,
    -169,   -64,  -169,   389,   -66,    95,  -169,  -169,  -169,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,  -169,  -169,  -169,  -169,  -169,  -169,   529,  -169,
    -169,   135,   529,    30,    48,   113,     2,   113,    -1,  -169,
      21,   125,  -169,  -169,    31,    43,   495,     9,    98,    46,
    -169,  -169,   389,   201,  -169,   529,  -169,    83,    90,   100,
     100,    84,    84,    84,    84,   102,   102,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,   -25,  -169,  -169,  -169,  -169,
    -169,   529,   177,  -169,   125,   413,  -169,   201,    68,   211,
     283,  -169,  -169,   529,   389,   183,    10,   512,   546,   389,
    -169,   136,  -169,  -169,  -169,    48,     7,   137,   230,  -169,
      33,  -169,  -169,  -169,  -169,   336,  -169,  -169,   184,   389,
      53,   189,   222,    14,   -22,  -169,  -169,   204,  -169,   234,
     238,    80,  -169,  -169,   125,  -169,  -169,    74,  -169,   389,
    -169,   389,   389,    92,   389,   115,   228,   389,    48,  -169,
    -169,  -169,   360,  -169,  -169,    68,  -169,  -169,  -169,  -169,
     389,  -169,   389,   389,   121,  -169,  -169,  -169,   161,  -169,
    -169,  -169,  -169,   389,  -169,  -169
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,   221,   -63,  -169,    97,  -169,  -147,  -169,
    -169,  -169,  -169,   -26,   -53,  -169,   156,   179,   180,   141,
      76,   139,   -48,   530,  -169,    94,  -102,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -168,  -169,  -169,     0,  -169,   103,
    -169,   205,  -169,    45,  -155,  -169,   112,  -150
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      61,    71,   152,    99,    74,   154,    80,   177,   199,   113,
     121,   186,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    62,    78,   101,   158,   206,   126,    17,    79,   120,
      75,   124,    61,    79,   101,    79,    63,     1,   115,   117,
      64,   119,   137,   138,   146,   139,    65,    11,    12,    13,
      14,    15,    16,   223,   199,   147,   148,   224,    66,   170,
      18,    19,   150,    12,    13,    14,    15,    16,    67,   159,
     239,    72,     1,   197,   238,   217,   174,   173,   102,    20,
     103,    92,    11,    12,    13,    14,    15,    16,    68,   102,
     166,   103,   156,    76,    20,    18,    19,   121,   157,    69,
     155,   188,   167,   191,   198,   181,   195,   216,    79,    79,
     187,    88,    89,    79,    20,    81,   236,    93,    94,    95,
      96,    97,   170,    82,    83,    74,   210,   181,   162,    30,
     163,    90,    91,   180,   205,    84,    85,    86,    87,   190,
     164,   193,    79,   169,   151,    79,   227,    80,   228,   229,
     211,   231,    79,   104,   235,   178,   140,   141,   142,   143,
     131,   132,   133,   134,    30,   213,   215,   240,   180,   241,
     242,     1,   181,   225,   105,   226,   200,   221,   107,   222,
     245,    11,    12,    13,    14,    15,    16,     1,   118,   230,
     234,    79,   125,     1,    18,    19,   168,    11,    12,    13,
      14,    15,    16,    11,    12,    13,    14,    15,    16,   153,
      18,    19,   232,    20,    79,   172,    18,    19,   243,   160,
      79,   175,   200,   129,   130,   183,     1,   135,   136,    20,
     203,   196,     1,   204,   209,    20,    11,    12,    13,    14,
      15,    16,    11,    12,    13,    14,    15,    16,   219,    18,
      19,   218,   220,    77,   244,    18,    19,   185,   145,   127,
     179,   128,   194,    30,   112,   176,   111,   237,    20,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    30,
     189,     0,     0,     0,     0,    30,   212,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    30,   214,
       0,     0,     0,     0,    30,   233,     0,     0,     0,    20,
       0,     0,    21,     0,    22,    23,    24,    25,    26,    27,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,    18,    19,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,    28,    29,   184,    30,
      17,     0,    20,     0,     0,    21,     0,    22,    23,    24,
      25,    26,    27,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,    18,    19,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,    28,
      29,   208,    30,     0,     0,    20,     0,     0,    21,     0,
      22,    23,    24,    25,    26,    27,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     1,     0,     0,     0,     0,     0,    18,
      19,     0,     0,    11,    12,    13,    14,    15,    16,     1,
       0,     0,    28,    29,     0,    30,    18,    19,    20,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     1,
       0,     0,    18,    19,     0,    20,     0,     0,     0,    11,
      12,    13,    14,    15,    16,     0,     1,     0,     0,     0,
       0,    20,    18,    19,     0,     0,    11,    12,    13,    14,
      15,    16,     0,     1,     0,     0,     0,     0,    30,    18,
      19,    20,     0,    11,    12,    13,    14,    15,    16,     0,
       0,     0,    70,     0,     0,    30,    18,    19,    20,     0,
      11,    12,    13,    14,    15,    16,     0,     0,   116,     0,
       0,    30,     0,     0,     0,    20,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   165,     0,
       0,    30,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,     0,     0,    30,     0,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100
};

static const yytype_int16 yycheck[] =
{
       0,    27,   104,    51,    30,     3,    31,   154,   176,    62,
      73,   161,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    96,    93,    45,     3,   180,    79,    20,    99,    93,
      30,    97,    32,    99,    45,    99,    14,     4,    64,    65,
      96,    67,    90,    91,    14,    98,    96,    14,    15,    16,
      17,    18,    19,   203,   222,    25,    26,   204,    96,   122,
      27,    28,    14,    15,    16,    17,    18,    19,    96,    48,
     225,    95,     4,   175,   224,    97,   101,   125,   100,    46,
     102,     3,    14,    15,    16,    17,    18,    19,    93,   100,
     116,   102,    93,     0,    46,    27,    28,   160,    99,    93,
      98,   164,    93,    93,    97,   158,   169,    93,    99,    99,
     163,    27,    28,    99,    46,    32,   218,    39,    40,    41,
      42,    43,   185,    33,    34,   151,   189,   180,    97,    96,
      99,    29,    30,   100,   101,    35,    36,    37,    38,   165,
      97,   167,    99,    97,    96,    99,   209,    31,   211,   212,
      97,   214,    99,    98,   217,   155,    21,    22,    23,    24,
      84,    85,    86,    87,    96,   191,   192,   230,   100,   232,
     233,     4,   225,    99,    14,   101,   176,    97,    14,    99,
     243,    14,    15,    16,    17,    18,    19,     4,    14,    97,
     216,    99,    97,     4,    27,    28,    98,    14,    15,    16,
      17,    18,    19,    14,    15,    16,    17,    18,    19,    96,
      27,    28,    97,    46,    99,    14,    27,    28,    97,    94,
      99,    44,   222,    82,    83,    14,     4,    88,    89,    46,
      93,    95,     4,     3,    50,    46,    14,    15,    16,    17,
      18,    19,    14,    15,    16,    17,    18,    19,    14,    27,
      28,    47,    14,    32,    93,    27,    28,   160,   102,    80,
     157,    81,   168,    96,    97,   153,    61,   222,    46,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    96,
      97,    -1,    -1,    -1,    -1,    96,    97,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    46,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    93,    94,    95,    96,
      20,    -1,    46,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    93,
      94,    95,    96,    -1,    -1,    46,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,     4,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    14,    15,    16,    17,    18,    19,     4,
      -1,    -1,    93,    94,    -1,    96,    27,    28,    46,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    27,    28,    -1,    46,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    -1,     4,    -1,    -1,    -1,
      -1,    46,    27,    28,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,     4,    -1,    -1,    -1,    -1,    96,    27,
      28,    46,    -1,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    93,    -1,    -1,    96,    27,    28,    46,    -1,
      14,    15,    16,    17,    18,    19,    -1,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    96,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    27,    28,
      46,    49,    51,    52,    53,    54,    55,    56,    93,    94,
      96,   104,   105,   106,   107,   108,   110,   112,   113,   114,
     115,   116,   117,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   133,   134,   135,   136,   137,   138,
     139,   140,    96,    14,    96,    96,    96,    96,    93,    93,
      93,   116,    95,   149,   116,   140,     0,   106,    93,    99,
      31,    32,    33,    34,    35,    36,    37,    38,    27,    28,
      29,    30,     3,    39,    40,    41,    42,    43,   118,   125,
     126,    45,   100,   102,    98,    14,   144,    14,   141,   142,
     143,   144,    97,   117,   132,   116,    93,   116,    14,   116,
      93,   107,   109,   140,    97,    97,   117,   120,   121,   122,
     122,   123,   123,   123,   123,   124,   124,   125,   125,   117,
      21,    22,    23,    24,   131,   119,    14,    25,    26,   130,
      14,    96,   129,    96,     3,    98,    93,    99,     3,    48,
      94,   111,    97,    99,    97,    93,   116,    93,    98,    97,
     107,   150,    14,   125,   101,    44,   149,   111,   140,   142,
     100,   117,   147,    14,    95,   109,   150,   117,   107,    97,
     116,    93,    93,   116,   128,   107,    95,   129,    97,   137,
     140,   145,   146,    93,     3,   101,   147,   148,    95,    50,
     107,    97,    97,   116,    97,   116,    93,    97,    47,    14,
      14,    97,    99,   150,   111,    99,   101,   107,   107,   107,
      97,   107,    97,    97,   116,   107,   129,   146,   150,   147,
     107,   107,   107,    97,    93,   107
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
#line 126 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
        astFreeTree((yyval.node));
    }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 133 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 134 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_EXT_STAT_COMMA, 2, astAllChildren( 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node) ) );
    }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 143 "Parser.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		fprintf(stdout, "==FUNCTION DEFINITION==\n");
        astOutTree((yyval.node), stdout, 0);
		fprintf(stdout, "=======================\n");
        sTableShow(stdout);
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 150 "Parser.y"
    { 
        (yyval.node) = (yyvsp[(1) - (1)].node); 
        fprintf(stdout, "==EXTERNAL STATEMENT==\n");
        astOutTree((yyval.node), stdout, 0);
        fprintf(stdout, "======================\n");
        sTableShow(stdout);
    }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 160 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 161 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 162 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 163 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 164 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 165 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 169 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 170 "Parser.y"
    { (yyval.node) = NULL; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 174 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 175 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_STAT_LIST, 2, astAllChildren(2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)) );
    }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 181 "Parser.y"
    { 
        (yyval.node) = astNewNode( AST_COMP_STAT, 0, NULL );
    }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 184 "Parser.y"
    { 
        (yyval.node) = astNewNode( AST_COMP_STAT, 1, astAllChildren(1, (yyvsp[(3) - (5)].node)) );
    }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 190 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMP_STAT, 0, NULL );
    }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 193 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMP_STAT, 1, astAllChildren(1, (yyvsp[(2) - (3)].node)) );
    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 199 "Parser.y"
    {(yyval.node) = astNewNode(AST_IF_STAT, 2, astAllChildren(2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 200 "Parser.y"
    {(yyval.node) = astNewNode(AST_IFELSE_STAT, 3, astAllChildren(3,(yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)));}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 204 "Parser.y"
    {(yyval.node) = astNewNode(AST_WHILE, 2, astAllChildren(2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 205 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_XXX, 4, astAllChildren(4, (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)));}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 206 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_XXO, 3, astAllChildren(3, (yyvsp[(3) - (8)].node), (yyvsp[(5) - (8)].node), (yyvsp[(8) - (8)].node)));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 207 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_XOX, 3, astAllChildren(3, (yyvsp[(3) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node)));}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 208 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_XOO, 2, astAllChildren(2, (yyvsp[(3) - (7)].node), (yyvsp[(7) - (7)].node)));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 209 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_OXX, 3, astAllChildren(3, (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node)));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 210 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_OXO, 2, astAllChildren(2, (yyvsp[(4) - (7)].node), (yyvsp[(7) - (7)].node)));}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 211 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_OOX, 2, astAllChildren(2, (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)));}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 212 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOR_OOO, 1, astAllChildren(1, (yyvsp[(6) - (6)].node)));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 213 "Parser.y"
    {(yyval.node) = astNewNode(AST_FOREACH, 3, astAllChildren(3, astNewLeaf(IDENTIFIER, (yyvsp[(3) - (7)].LString).s, (yyvsp[(3) - (7)].LString).l), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 217 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_BREAK, 0, NULL);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 218 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_CONTINUE, 0, NULL);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 219 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_RETURN, 1, astAllChildren(1, (yyvsp[(2) - (3)].node)));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 220 "Parser.y"
    {(yyval.node) = astNewNode(AST_JUMP_RETURN, 0, NULL);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 224 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 233 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 234 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 240 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 241 "Parser.y"
    {
       (yyval.node) = astNewNode ( (yyvsp[(2) - (3)].LInteger).i, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ); 
    }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 247 "Parser.y"
    { (yyval.LInteger).i = AST_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 248 "Parser.y"
    { (yyval.LInteger).i = ADD_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 249 "Parser.y"
    { (yyval.LInteger).i = SUB_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 250 "Parser.y"
    { (yyval.LInteger).i = MUL_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 251 "Parser.y"
    { (yyval.LInteger).i = DIV_ASSIGN; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 252 "Parser.y"
    { (yyval.LInteger).i = APPEND;     (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 256 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 257 "Parser.y"
    {
        (yyval.node) = astNewNode ( OR, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 263 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 264 "Parser.y"
    {
        (yyval.node) = astNewNode ( AND, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 270 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 271 "Parser.y"
    {
        (yyval.node) = astNewNode ( EQ, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 274 "Parser.y"
    {
        (yyval.node) = astNewNode ( NE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 280 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 281 "Parser.y"
    {
        (yyval.node) = astNewNode ( LT, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 284 "Parser.y"
    {
        (yyval.node) = astNewNode ( GT, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 287 "Parser.y"
    {
        (yyval.node) = astNewNode ( LE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 290 "Parser.y"
    {
        (yyval.node) = astNewNode ( GE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 296 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 297 "Parser.y"
    {
        (yyval.node) = astNewNode ( ADD, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 300 "Parser.y"
    {
        (yyval.node) = astNewNode ( SUB, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 306 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 307 "Parser.y"
    {
        (yyval.node) = astNewNode ( MUL, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 310 "Parser.y"
    {
        (yyval.node) = astNewNode ( DIV, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 316 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 317 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_CAST, 2, astAllChildren(2, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)) );
    }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 323 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 324 "Parser.y"
    {
        (yyval.node) = astNewNode ( (yyvsp[(1) - (2)].LInteger).i, 1, astAllChildren(1, (yyvsp[(2) - (2)].node)) );
    }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 330 "Parser.y"
    { (yyval.LInteger).i = AST_UNARY_PLUS;  (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 331 "Parser.y"
    { (yyval.LInteger).i = AST_UNARY_MINUS; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 332 "Parser.y"
    { (yyval.LInteger).i = AST_UNARY_NOT;   (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 336 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 337 "Parser.y"
    {
        (yyval.node) = astNewNode ( ARROW, 3, astAllChildren(3, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)) );
    }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 341 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_POSTFIX_EPR, 2, astAllChildren(2, astNewLeaf(IDENTIFIER, (yyvsp[(1) - (4)].LString).s, (yyvsp[(1) - (4)].LString).l), (yyvsp[(3) - (4)].node)));
    }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 344 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_POSTFIX_EPR, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, (yyvsp[(1) - (3)].LString).s, (yyvsp[(1) - (3)].LString).l)));
    }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 347 "Parser.y"
    {
        (yyval.node) = astNewNode ( PIPE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 350 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_MATCH, 2, astAllChildren(2, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)) );
    }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 353 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_ATTIBUTE, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), astNewLeaf(IDENTIFIER, (yyvsp[(3) - (3)].LString).s, (yyvsp[(3) - (3)].LString).l)) );
    }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 356 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_GRAPH_PROP, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 362 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 363 "Parser.y"
    { 
        (yyval.node) = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); 
        sTableLookupId((yyval.node));
    }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 367 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 368 "Parser.y"
    { (yyval.node) = astNewLeaf(STRING_LITERAL, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 369 "Parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 378 "Parser.y"
    { (yyval.node) = astNewLeaf(ALL_VERTICES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 379 "Parser.y"
    { (yyval.node) = astNewLeaf(ALL_EDGES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 383 "Parser.y"
    { (yyval.node) = astNewLeaf(OUTCOMING_EDGES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 384 "Parser.y"
    { (yyval.node) = astNewLeaf(INCOMING_EDGES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 385 "Parser.y"
    { (yyval.node) = astNewLeaf(STARTING_VERTICES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 386 "Parser.y"
    { (yyval.node) = astNewLeaf(ENDING_VERTICES, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 390 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 391 "Parser.y"
    {
        (yyval.node) = astNewNode ( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 397 "Parser.y"
    { 
        (yyval.node) = astNewNode ( AT, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, (yyvsp[(2) - (2)].LString).s, (yyvsp[(2) - (2)].LString).l))  );
    }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 403 "Parser.y"
    { (yyval.node) = astNewLeaf(INTEGER_CONSTANT, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 404 "Parser.y"
    { (yyval.node) = astNewLeaf(FLOAT_CONSTANT, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 405 "Parser.y"
    { (yyval.node) = astNewLeaf(BOOL_TRUE, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 406 "Parser.y"
    { (yyval.node) = astNewLeaf(BOOL_FALSE, NULL, (yyvsp[(1) - (1)].LString).l); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 414 "Parser.y"
    {
        (yyval.node) = astNewNode((yyvsp[(1) - (6)].LInteger).i, 2, astAllChildren(2, (yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node)));
    }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 417 "Parser.y"
    {
        (yyval.node) = astNewNode((yyvsp[(1) - (8)].LInteger).i, 3, astAllChildren(3, (yyvsp[(2) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node)));
    }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 423 "Parser.y"
    {
        (yyval.node) = astNewNode(AST_FUNC, 3, astAllChildren(3, (yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node)));
    }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 429 "Parser.y"
    { (yyval.LInteger).i = FUNC_LITERAL; (yyval.LInteger).l = (yyvsp[(1) - (1)].LString).l; }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 433 "Parser.y"
    { int ttype = VOID_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 434 "Parser.y"
    { int ttype = BOOL_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 435 "Parser.y"
    { int ttype = INT_T;    (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 436 "Parser.y"
    { int ttype = FLOAT_T;  (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 437 "Parser.y"
    { int ttype = STRING_T; (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 438 "Parser.y"
    { int ttype = LIST_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 439 "Parser.y"
    { int ttype = VERTEX_T; (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 440 "Parser.y"
    { int ttype = EDGE_T;   (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 441 "Parser.y"
    { int ttype = GRAPH_T;  (yyval.node)= astNewLeaf(AST_TYPE_SPECIFIER, &(ttype), (yyvsp[(1) - (1)].LString).l); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 445 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_DECLARATION, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node)) );    
        sTableDeclare((yyval.node));
    }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 452 "Parser.y"
    {
        (yyval.node)= (yyvsp[(1) - (1)].node);
    }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 458 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 461 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 467 "Parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 470 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_ASSIGN, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 476 "Parser.y"
    {
        (yyval.node) = astNewLeaf(IDENTIFIER, (yyvsp[(1) - (1)].LString).s, (yyvsp[(1) - (1)].LString).l);
    }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 479 "Parser.y"
    {
        (yyval.node) = astNewNode( BELONG, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), astNewLeaf(IDENTIFIER, (yyvsp[(3) - (3)].LString).s, (yyvsp[(3) - (3)].LString).l)) );
    }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 485 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_FUNC_DECLARATOR, 2, astAllChildren(2, astNewLeaf(IDENTIFIER, (yyvsp[(1) - (5)].LString).s, (yyvsp[(1) - (5)].LString).l), (yyvsp[(4) - (5)].node)) );
    }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 488 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_FUNC_DECLARATOR, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, (yyvsp[(1) - (4)].LString).s, (yyvsp[(1) - (4)].LString).l) ) );
    }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 494 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 495 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 501 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_PARA_DECLARATION, 2, astAllChildren(2, (yyvsp[(1) - (2)].node), astNewLeaf(IDENTIFIER, (yyvsp[(2) - (2)].LString).s, (yyvsp[(2) - (2)].LString).l)));
        sTableDeclare((yyval.node));
    }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 505 "Parser.y"
    {
	    (yyval.node) = astNewNode( FUNC_LITERAL, 1, astAllChildren(1, astNewLeaf(IDENTIFIER, (yyvsp[(2) - (2)].LString).s, (yyvsp[(2) - (2)].LString).l)));
    }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 511 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 512 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_LIST_INIT, 1, astAllChildren(1, (yyvsp[(2) - (3)].node)) );
    }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 515 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_LIST_INIT, 0, NULL );
    }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 521 "Parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 522 "Parser.y"
    {
        (yyval.node) = astNewNode( AST_COMMA, 2, astAllChildren(2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) );
    }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 532 "Parser.y"
    { sStackPush( sNewScopeId() ); }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 536 "Parser.y"
    { sStackPop(); }
    break;



/* Line 1455 of yacc.c  */
#line 2907 "y.tab.c"
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
#line 539 "Parser.y"


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

