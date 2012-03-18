
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



/* Line 189 of yacc.c  */
#line 86 "y.tab.c"

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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 224 "y.tab.c"

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   597

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNRULES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,     2,     2,     2,
      52,    53,    59,    57,    55,    58,    64,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    49,
       2,    56,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    27,    29,    31,    34,    37,    41,    47,
      55,    61,    71,    80,    89,    97,   106,   114,   122,   129,
     137,   140,   143,   147,   150,   152,   154,   156,   160,   162,
     166,   168,   170,   172,   174,   176,   178,   180,   184,   186,
     190,   192,   196,   200,   202,   206,   210,   214,   218,   220,
     224,   228,   230,   234,   238,   240,   243,   245,   247,   249,
     251,   257,   265,   270,   274,   278,   283,   287,   291,   293,
     295,   297,   299,   303,   305,   307,   309,   311,   313,   315,
     317,   321,   324,   326,   328,   330,   336,   344,   348,   350,
     352,   354,   356,   358,   360,   362,   364,   366,   370,   372,
     374,   378,   380,   384,   386,   388,   393,   397,   399,   403,
     406,   409,   411,   415,   420,   422
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    66,    67,    -1,    95,    -1,
      68,    -1,    69,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    49,    -1,    49,    -1,    68,
      -1,    70,    68,    -1,    50,    51,    -1,    50,    70,    51,
      -1,    40,    52,    76,    53,    68,    -1,    40,    52,    76,
      53,    68,    41,    68,    -1,    44,    52,    76,    53,    68,
      -1,    42,    52,    76,    49,    76,    49,    76,    53,    68,
      -1,    42,    52,    76,    49,    76,    49,    53,    68,    -1,
      42,    52,    76,    49,    49,    76,    53,    68,    -1,    42,
      52,    76,    49,    49,    53,    68,    -1,    42,    52,    49,
      76,    49,    76,    53,    68,    -1,    42,    52,    49,    76,
      49,    53,    68,    -1,    42,    52,    49,    49,    76,    53,
      68,    -1,    42,    52,    49,    49,    53,    68,    -1,    43,
      52,    11,    54,    87,    53,    68,    -1,    45,    49,    -1,
      46,    49,    -1,    47,    76,    49,    -1,    47,    49,    -1,
      98,    -1,    94,    -1,    77,    -1,    76,    55,    77,    -1,
      79,    -1,    85,    78,    77,    -1,    56,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,    80,    -1,
      79,    23,    80,    -1,    81,    -1,    80,    24,    81,    -1,
      82,    -1,    81,    25,    82,    -1,    81,    26,    82,    -1,
      83,    -1,    82,    28,    83,    -1,    82,    27,    83,    -1,
      82,    30,    83,    -1,    82,    29,    83,    -1,    84,    -1,
      83,    57,    84,    -1,    83,    58,    84,    -1,    85,    -1,
      84,    59,    85,    -1,    84,    60,    85,    -1,    87,    -1,
      86,    85,    -1,    57,    -1,    58,    -1,    61,    -1,    88,
      -1,    88,    54,    88,    36,    88,    -1,    88,    54,    88,
      36,    88,    39,    88,    -1,    87,    52,    91,    53,    -1,
      87,    52,    53,    -1,    87,    37,    90,    -1,    87,    62,
      79,    63,    -1,    87,    64,    11,    -1,    87,    64,    89,
      -1,    92,    -1,    11,    -1,    93,    -1,    13,    -1,    52,
      76,    53,    -1,    21,    -1,    22,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    77,    -1,    91,    55,    77,
      -1,    38,    11,    -1,    12,    -1,    14,    -1,    15,    -1,
      96,   102,    56,    71,    49,    -1,    96,   102,    54,    99,
      56,    71,    49,    -1,    99,   102,    71,    -1,    16,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    99,   100,    49,    -1,
      97,    -1,   101,    -1,   100,    55,   101,    -1,   102,    -1,
     102,    56,   106,    -1,   103,    -1,    11,    -1,    11,    52,
     104,    53,    -1,    11,    52,    53,    -1,   105,    -1,   104,
      55,   105,    -1,    99,    11,    -1,    96,    11,    -1,    77,
      -1,    50,   107,    51,    -1,    50,   107,    55,    51,    -1,
     106,    -1,   107,    55,   106,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    62,    63,    67,    68,    69,    70,
      71,    72,    76,    77,    81,    82,    86,    87,    91,    92,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     109,   110,   111,   112,   116,   117,   125,   126,   130,   131,
     135,   136,   137,   138,   139,   140,   144,   145,   149,   150,
     154,   155,   156,   160,   161,   162,   163,   164,   168,   169,
     170,   174,   175,   176,   180,   181,   185,   186,   187,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   203,   204,
     205,   206,   207,   211,   212,   216,   217,   218,   219,   223,
     224,   228,   232,   233,   234,   242,   243,   247,   251,   255,
     256,   257,   258,   259,   260,   261,   262,   266,   270,   274,
     275,   279,   280,   284,   288,   289,   290,   294,   295,   299,
     300,   304,   305,   306,   310,   311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "BOOLEAN", "NUMBER", "STRING",
  "LIST", "VERTEX", "EDGE", "GRAPH", "IDENTIFIER", "NUMBER_CONSTANT",
  "STRING_LITERAL", "TRUE", "FALSE", "FUNC_LITERAL", "OUTCOMING_EDGES",
  "INCOMING_EDGES", "STARTING_VERTICES", "ENDING_VERTICES", "ALL_VERTICES",
  "ALL_EDGES", "OR", "AND", "EQ", "NE", "GT", "LT", "GE", "LE",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "EAT", "ARROW",
  "PIPE", "AT", "MARK", "IF", "ELSE", "FOR", "FOREACH", "WHILE", "BREAK",
  "CONTINUE", "RETURN", "LOWER_THAN_ELSE", "';'", "'{'", "'}'", "'('",
  "')'", "':'", "','", "'='", "'+'", "'-'", "'*'", "'/'", "'!'", "'['",
  "']'", "'.'", "$accept", "translation_unit", "external_statement",
  "statement", "expression_statement", "statement_list",
  "compound_statement", "selection_statement", "iteration_statement",
  "jump_statement", "declaration_statement", "expression",
  "assignment_expression", "assignment_operator", "logical_OR_expression",
  "logical_AND_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "graph_property", "pipe_property", "argument_expression_list",
  "attribute", "constant", "function_literal_declaration",
  "function_definition", "function_literal_type_sepcifier",
  "basic_type_specifier", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "parameter_list", "parameter_declaration",
  "initializer", "initializer_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    59,
     123,   125,    40,    41,    58,    44,    61,    43,    45,    42,
      47,    33,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    90,    90,    91,
      91,    92,    93,    93,    93,    94,    94,    95,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    99,   100,
     100,   101,   101,   102,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     2,     3,     5,     7,
       5,     9,     8,     8,     7,     8,     7,     7,     6,     7,
       2,     2,     3,     2,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     2,     1,     1,     1,     1,
       5,     7,     4,     3,     3,     4,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     1,     1,     5,     7,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     1,     3,     1,     1,     4,     3,     1,     3,     2,
       2,     1,     3,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   100,   101,   102,   103,   104,   105,   106,    79,
      92,    81,    93,    94,    98,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,    66,    67,    68,     0,
       2,     5,     6,     7,     8,     9,    10,    11,     0,    36,
      38,    46,    48,    50,    53,    58,    61,     0,    64,    69,
      78,    80,    35,     4,     0,   108,    34,     0,    91,     0,
       0,     0,     0,    30,    31,    33,     0,    16,    14,     0,
       0,     0,     1,     3,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
      43,    44,    45,    40,     0,    65,     0,     0,     0,     0,
       0,   114,     0,   113,     0,   109,   111,     0,     0,     0,
       0,     0,    32,    17,    15,   111,    82,    37,    47,    61,
      49,    51,    52,    55,    54,    57,    56,    59,    60,    62,
      63,    39,    85,    86,    87,    88,    74,    73,    89,     0,
       0,    76,    83,    84,    77,     0,     0,     0,     0,   107,
       0,     0,    97,     0,     0,     0,     0,     0,     0,    72,
       0,    75,     0,   116,     0,     0,     0,   117,     0,     0,
     110,     0,   121,   112,    18,     0,     0,     0,     0,     0,
       0,    20,    90,    70,   120,   119,   115,     0,     0,    95,
     124,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,   122,     0,    19,    27,    26,     0,
      24,     0,     0,     0,    29,    71,    96,   123,   125,    25,
      23,    22,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,    69,    33,    34,    35,    36,
      37,    38,    39,    94,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   144,   136,   139,    50,    51,    52,
      53,    54,    55,    56,    70,   104,   105,   115,   103,   166,
     167,   173,   191
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -149
static const yytype_int16 yypact[] =
{
     314,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,    19,   -30,    -8,    33,    41,
      62,    65,    -2,  -149,   196,   536,  -149,  -149,  -149,    63,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   -23,  -149,
      99,   103,    36,    89,   172,   173,   127,   536,   102,    90,
    -149,  -149,  -149,  -149,   120,  -149,  -149,   120,  -149,   536,
     378,   164,   536,  -149,  -149,  -149,   -12,  -149,  -149,   255,
     120,   -13,  -149,  -149,  -149,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,  -149,  -149,
    -149,  -149,  -149,  -149,   536,  -149,   162,    85,   536,    13,
     335,   125,    -3,  -149,     3,  -149,     4,    28,   385,    31,
     132,    73,  -149,  -149,  -149,   175,  -149,  -149,   103,  -149,
      36,    89,    89,   172,   172,   172,   172,   173,   173,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,    77,
     -15,  -149,  -149,  -149,  -149,   201,    11,   187,   194,  -149,
     120,   395,  -149,   314,   406,    35,   457,   335,   314,  -149,
     536,  -149,   335,  -149,   244,   245,    92,  -149,   224,   232,
    -149,   395,  -149,  -149,   241,   314,   100,   464,   474,    39,
      88,  -149,  -149,   247,  -149,  -149,  -149,   269,   194,  -149,
    -149,   -22,   314,  -149,   314,   314,   110,   314,   114,   485,
     314,   335,  -149,   234,  -149,   327,  -149,  -149,  -149,   314,
    -149,   314,   314,   119,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,   314,  -149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   258,   -24,  -149,  -149,   -99,  -149,  -149,  -149,
    -149,   -21,   -69,  -149,   186,   212,   213,   171,   145,   167,
     137,  -149,   134,   -97,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -141,  -149,  -149,     2,  -149,   139,    38,  -149,  -149,
     105,  -148,  -149
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      68,    66,    57,   145,    71,   164,   117,   152,    76,     9,
      10,    11,    12,    13,     1,     2,     3,     4,     5,     6,
       7,     8,    59,   190,   141,   131,    74,    14,   138,   204,
      58,    57,    75,   205,   142,   143,    15,   112,   107,   109,
     116,   111,    75,    75,    60,   114,   164,    65,   161,   169,
      25,   147,   149,   148,    24,    26,    27,   218,   150,    28,
     151,    78,    79,    72,   163,   183,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     156,   153,   172,    75,   177,    61,    75,   155,   199,   203,
      75,   182,   102,    62,    75,   106,     9,    10,    11,    12,
      13,    15,   172,    16,   215,    17,    18,    19,    20,    21,
      22,    63,    23,    24,    64,    25,    80,    81,    82,    83,
      26,    27,    76,    15,    28,    96,   158,    77,    75,   174,
     159,   101,   160,   176,   181,   179,   172,    25,   137,    96,
      97,   200,    26,    27,   100,   186,    28,   187,   165,   168,
      98,   193,    99,   194,    97,    75,   196,   198,    88,    89,
      90,    91,    92,   209,    98,    75,    99,   211,   206,    75,
     207,   208,   222,   210,    75,   110,   214,   146,   213,   132,
     133,   134,   135,    93,    95,   219,   157,   220,   221,   165,
       1,     2,     3,     4,     5,     6,     7,     8,   223,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   129,   130,   123,   124,   125,   126,    84,
      85,   151,    86,    87,    15,   119,    16,   162,    17,    18,
      19,    20,    21,    22,    24,    23,    24,    67,    25,   121,
     122,   127,   128,    26,    27,   184,   185,    28,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     1,     2,     3,     4,     5,     6,     7,     8,
     188,   189,   192,   216,   140,    14,   201,    73,   118,   170,
     120,   180,   202,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,     0,    23,    24,   113,    25,     0,     0,
       0,     0,    26,    27,     0,     0,    28,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,     0,     0,     0,     9,    10,    11,    12,
      13,     0,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    15,    25,     0,     0,     0,
       0,    26,    27,    15,     0,    28,     0,   171,   217,    25,
       0,     0,     0,     0,    26,    27,     0,    25,    28,     9,
      10,    11,    12,    13,     0,     0,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    15,     9,    10,    11,
      12,    13,     0,    15,     0,     0,     0,   108,     0,     0,
      25,     0,     0,    15,   154,    26,    27,    25,     0,    28,
       0,     0,    26,    27,    15,   171,    28,    25,     0,     0,
       0,     0,    26,    27,     0,     0,    28,     0,    25,   175,
       0,     0,     0,    26,    27,     0,     0,    28,     9,    10,
      11,    12,    13,     0,     0,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    15,     9,    10,    11,    12,
      13,     0,    15,     0,     0,     0,   178,     0,     0,    25,
       0,     0,    15,     0,    26,    27,    25,   195,    28,     0,
       0,    26,    27,    15,     0,    28,    25,   197,     0,     0,
       0,    26,    27,     0,     0,    28,     0,    25,   212,     0,
       0,     0,    26,    27,     0,     0,    28,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    26,    27,     0,     0,    28
};

static const yytype_int16 yycheck[] =
{
      24,    22,     0,   100,    25,   146,    75,   106,    23,    11,
      12,    13,    14,    15,     3,     4,     5,     6,     7,     8,
       9,    10,    52,   171,    11,    94,    49,    16,    97,    51,
      11,    29,    55,    55,    21,    22,    38,    49,    59,    60,
      53,    62,    55,    55,    52,    69,   187,    49,    63,   148,
      52,    54,    49,    56,    50,    57,    58,   205,    55,    61,
      56,    25,    26,     0,    53,   162,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      49,    53,   151,    55,    49,    52,    55,   108,    49,   188,
      55,   160,    54,    52,    55,    57,    11,    12,    13,    14,
      15,    38,   171,    40,   201,    42,    43,    44,    45,    46,
      47,    49,    49,    50,    49,    52,    27,    28,    29,    30,
      57,    58,    23,    38,    61,    37,    53,    24,    55,   153,
      53,    11,    55,   154,   158,   156,   205,    52,    53,    37,
      52,    53,    57,    58,    54,    53,    61,    55,   146,   147,
      62,   175,    64,    53,    52,    55,   177,   178,    31,    32,
      33,    34,    35,    53,    62,    55,    64,    53,   192,    55,
     194,   195,    53,   197,    55,    11,   200,    52,   199,    17,
      18,    19,    20,    56,    47,   209,    54,   211,   212,   187,
       3,     4,     5,     6,     7,     8,     9,    10,   222,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    80,    81,    82,    83,    57,
      58,    56,    59,    60,    38,    98,    40,    36,    42,    43,
      44,    45,    46,    47,    50,    49,    50,    51,    52,    78,
      79,    84,    85,    57,    58,    11,    11,    61,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      56,    49,    41,    49,    98,    16,    39,    29,    76,   150,
      77,   157,   187,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    38,    -1,    40,    -1,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    38,    52,    -1,    -1,    -1,
      -1,    57,    58,    38,    -1,    61,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    -1,    52,    61,    11,
      12,    13,    14,    15,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    38,    11,    12,    13,
      14,    15,    -1,    38,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    38,    49,    57,    58,    52,    -1,    61,
      -1,    -1,    57,    58,    38,    50,    61,    52,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    -1,    52,    53,
      -1,    -1,    -1,    57,    58,    -1,    -1,    61,    11,    12,
      13,    14,    15,    -1,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    38,    11,    12,    13,    14,
      15,    -1,    38,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    38,    -1,    57,    58,    52,    53,    61,    -1,
      -1,    57,    58,    38,    -1,    61,    52,    53,    -1,    -1,
      -1,    57,    58,    -1,    -1,    61,    -1,    52,    53,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    38,    40,    42,    43,    44,
      45,    46,    47,    49,    50,    52,    57,    58,    61,    66,
      67,    68,    69,    71,    72,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      92,    93,    94,    95,    96,    97,    98,    99,    11,    52,
      52,    52,    52,    49,    49,    49,    76,    51,    68,    70,
      99,    76,     0,    67,    49,    55,    23,    24,    25,    26,
      27,    28,    29,    30,    57,    58,    59,    60,    31,    32,
      33,    34,    35,    56,    78,    85,    37,    52,    62,    64,
      54,    11,   102,   103,   100,   101,   102,    76,    49,    76,
      11,    76,    49,    51,    68,   102,    53,    77,    80,    85,
      81,    82,    82,    83,    83,    83,    83,    84,    84,    85,
      85,    77,    17,    18,    19,    20,    90,    53,    77,    91,
      79,    11,    21,    22,    89,    88,    52,    54,    56,    49,
      55,    56,    71,    53,    49,    76,    49,    54,    53,    53,
      55,    63,    36,    53,    96,    99,   104,   105,    99,    71,
     101,    50,    77,   106,    68,    53,    76,    49,    49,    76,
      87,    68,    77,    88,    11,    11,    53,    55,    56,    49,
     106,   107,    41,    68,    53,    53,    76,    53,    76,    49,
      53,    39,   105,    71,    51,    55,    68,    68,    68,    53,
      68,    53,    53,    76,    68,    88,    49,    51,   106,    68,
      68,    68,    53,    68
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
      

/* Line 1455 of yacc.c  */
#line 1716 "y.tab.c"
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
#line 314 "Parser.y"


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

