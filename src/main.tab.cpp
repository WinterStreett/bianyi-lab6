/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/main.y" /* yacc.c:339  */

    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );

#line 75 "src/main.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "main.tab.h".  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_VOID = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    BREAK = 266,
    CONTINUE = 267,
    RETURN = 268,
    FOR = 269,
    CONST = 270,
    SCANF = 271,
    PRINTF = 272,
    SEMICOLON = 273,
    LBRACKET = 274,
    RBRACKET = 275,
    LBRACE = 276,
    RBRACE = 277,
    COMMA = 278,
    LSB = 279,
    RSB = 280,
    IDENTIFIER = 281,
    INTEGER = 282,
    CHAR = 283,
    BOOL = 284,
    STRING = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    LOP_EQ = 291,
    LOP_NQ = 292,
    OR = 293,
    AND = 294,
    LT = 295,
    BT = 296,
    LTEQ = 297,
    BTEQ = 298,
    ADDR = 299,
    INC = 300,
    DEC = 301,
    NOT = 302,
    LOP_ASSIGN = 303,
    ADD_ASSIGN = 304,
    SUB_ASSIGN = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 177 "src/main.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    31,    32,    33,    39,    48,    58,    70,
      74,    78,    82,    88,    96,   103,   110,   111,   115,   116,
     117,   118,   126,   134,   142,   147,   148,   154,   161,   167,
     171,   175,   180,   188,   192,   193,   201,   205,   206,   211,
     217,   226,   230,   237,   241,   250,   257,   264,   270,   280,
     287,   294,   304,   326,   327,   328,   329,   333,   334,   335,
     342,   349,   359,   360,   371,   372,   383,   384,   392,   403,
     404,   412,   420,   428,   440,   441,   449,   460,   461,   469,
     477,   488,   489,   496,   503,   510,   520,   521,   524,   531,
     532,   535,   542,   549,   556,   563,   566,   569,   575
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "T_VOID", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN", "FOR",
  "CONST", "SCANF", "PRINTF", "SEMICOLON", "LBRACKET", "RBRACKET",
  "LBRACE", "RBRACE", "COMMA", "LSB", "RSB", "IDENTIFIER", "INTEGER",
  "CHAR", "BOOL", "STRING", "ADD", "SUB", "MUL", "DIV", "MOD", "LOP_EQ",
  "LOP_NQ", "OR", "AND", "LT", "BT", "LTEQ", "BTEQ", "ADDR", "INC", "DEC",
  "NOT", "LOP_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "$accept", "program",
  "compUnit", "funcDef", "funcParams", "funcParam", "statements",
  "statement", "forExpr12", "forExpr3", "IOFunc", "scanfParams", "block",
  "declaration", "varDef", "constDeclaration", "constDef", "initVal", "T",
  "expr", "lOrExp", "lAndExp", "eqExp", "relExp", "addExp", "mulExp",
  "unaryExp", "funcRParams", "primaryExp", "LVal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     270,   -33,   -33,   -33,   -33,   -10,    -2,     8,    14,    85,
      30,    90,    40,    65,   -33,    85,   180,    -9,   -33,   -33,
     -33,   135,   135,    63,    84,   135,   122,   270,   -33,   -33,
      96,   -33,   -17,    34,    98,   117,   109,   -18,   -32,    78,
     287,   105,   -33,   -33,   107,   135,   135,   -33,   -33,   131,
     -33,   -33,    16,   125,   123,   129,   140,   -33,   225,   -33,
     125,    85,   -33,   -33,    85,    85,    85,     5,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   125,   -33,
     125,   149,   -33,   121,   -33,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,    85,    85,
      85,    -5,    68,    18,   -33,   155,   148,   -33,   -33,   -33,
     130,   154,   156,   -33,   -33,   -33,   -33,    75,   -33,   -33,
     -33,   -33,   -33,    90,    85,   -18,   -32,    78,    78,    68,
      68,    68,    68,   105,   105,   -33,   -33,   -33,   182,   185,
     186,   270,   270,    16,   157,    85,   165,    85,   -33,    85,
     103,   189,   188,   -33,   -33,   -33,   -33,   -33,   206,   -33,
     198,    85,   -33,   191,   113,   114,   -33,     7,    90,    85,
     194,   270,    85,   -33,   -33,   -33,   175,   -33,   -33,   -33,
     189,   195,    60,   -33,   201,   196,   -33,   -33,   199,   270,
     -33,   -33,   -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    54,    53,    55,    56,     0,     0,     0,     0,    38,
       0,     0,     0,     0,    18,     0,     0,    98,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       0,    25,     0,     0,     0,     0,    58,    62,    64,    66,
      69,    74,    77,    81,    90,     0,     0,    29,    30,     0,
      37,    90,    36,     0,     0,     0,     0,    43,     0,    16,
       0,    86,    93,    94,     0,     0,     0,    98,    82,    83,
      91,    92,    84,     1,     5,     6,    33,    19,     0,    20,
       0,    98,    45,    47,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    31,     0,     0,    34,    98,    49,
       0,     0,     0,    89,    44,    17,    87,     0,    59,    60,
      61,    46,    50,    11,     0,    63,    65,    67,    68,    70,
      71,    72,    73,    75,    76,    78,    79,    80,     0,     0,
       0,     0,     0,    36,     0,     0,     0,    86,    85,     0,
       0,     9,     0,    48,    52,    21,    22,    23,    26,    28,
       0,     0,    51,     0,     0,     0,    88,     0,     0,     0,
      12,     0,    38,    35,    41,    39,     0,    40,     8,     7,
      10,     0,     0,    27,     0,     0,    15,    13,     0,     0,
      42,    14,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -33,   -33,   203,   -33,    55,   -33,   -13,    91,    73,
     -33,   -33,    81,   -33,   171,   -33,   170,   115,     2,     3,
      20,   169,   172,    21,   -15,    50,   -14,   112,   -33,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,   150,   151,    58,    29,   105,    49,
      30,   164,    31,    32,    82,    33,   109,   153,    60,    35,
      36,    37,    38,    39,    40,    41,    42,   117,    43,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    77,    34,    59,    87,    88,    78,    68,    69,    45,
      61,    72,    50,    53,    75,   141,    44,    46,    56,     1,
       2,    86,     3,     4,    61,   178,    47,    44,    16,    34,
     102,   102,    48,    85,    83,    15,    62,    63,   142,    64,
      65,    66,    17,    18,    19,   115,    20,    21,    22,    52,
      62,    63,    79,   110,   106,   107,    85,    80,    44,    54,
      83,    23,    24,    25,   116,   101,   103,   118,   119,   120,
     102,   102,   102,   102,   129,   130,   131,   132,    83,    15,
     110,   135,   136,   137,    55,   187,    17,    18,    19,    70,
      20,    21,    22,     1,     2,   148,     3,     4,   149,    93,
      94,   138,   139,   140,    15,    23,    24,    25,   127,   128,
      71,    17,    18,    19,    76,    20,    21,    22,    89,    90,
      91,    92,    73,   167,    81,   152,   168,   154,   158,   159,
      23,    24,    25,   175,   177,    84,   176,   149,    95,    96,
      97,    44,    44,   133,   134,   106,   107,    85,   154,   104,
     116,   108,   166,   111,    15,    98,    99,   100,   183,   112,
     113,    67,    18,    19,   173,    20,    21,    22,   123,   124,
     152,    44,   181,   143,   144,    50,   192,   146,   145,   147,
      23,    24,    25,     1,     2,   188,     3,     4,     5,    44,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
     155,    16,    57,   156,   157,   161,    17,    18,    19,   163,
      20,    21,    22,   169,   170,   171,   172,   174,   182,   185,
     186,   189,   190,   180,   191,    23,    24,    25,     1,     2,
      74,     3,     4,     5,   160,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   184,    16,   114,   179,   121,
     122,    17,    18,    19,   125,    20,    21,    22,   126,   165,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,     1,     2,     0,     3,     4,     5,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,     0,     0,     0,    17,    18,    19,     0,
      20,    21,    22,     0,     0,   -57,     0,   -57,     0,     0,
     -57,     0,   -57,     0,     0,    23,    24,    25,    93,    94
};

static const yytype_int16 yycheck[] =
{
       0,    18,     0,    16,    36,    37,    23,    21,    22,    19,
      19,    25,     9,    11,    27,    20,    16,    19,    15,     3,
       4,    39,     6,     7,    19,    18,    18,    27,    21,    27,
      45,    46,    18,    38,    34,    19,    45,    46,    20,    48,
      49,    50,    26,    27,    28,    58,    30,    31,    32,    19,
      45,    46,    18,    53,    52,    52,    38,    23,    58,    19,
      60,    45,    46,    47,    61,    45,    46,    64,    65,    66,
      85,    86,    87,    88,    89,    90,    91,    92,    78,    19,
      80,    95,    96,    97,    19,    25,    26,    27,    28,    26,
      30,    31,    32,     3,     4,    20,     6,     7,    23,    31,
      32,    98,    99,   100,    19,    45,    46,    47,    87,    88,
      26,    26,    27,    28,    18,    30,    31,    32,    40,    41,
      42,    43,     0,    20,    26,   123,    23,   124,   141,   142,
      45,    46,    47,    20,    20,    18,    23,    23,    33,    34,
      35,   141,   142,    93,    94,   143,   143,    38,   145,    18,
     147,    26,   149,    30,    19,    48,    49,    50,   171,    30,
      20,    26,    27,    28,   161,    30,    31,    32,    19,    48,
     168,   171,   169,    18,    26,   172,   189,    23,    48,    23,
      45,    46,    47,     3,     4,   182,     6,     7,     8,   189,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      18,    21,    22,    18,    18,    48,    26,    27,    28,    44,
      30,    31,    32,    24,    26,     9,    18,    26,    24,    44,
      25,    20,    26,   168,    25,    45,    46,    47,     3,     4,
      27,     6,     7,     8,   143,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   172,    21,    22,   167,    78,
      80,    26,    27,    28,    85,    30,    31,    32,    86,   147,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,     3,     4,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    32,    -1,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    25,    -1,    -1,    45,    46,    47,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    26,    27,    28,
      30,    31,    32,    45,    46,    47,    52,    53,    54,    58,
      61,    63,    64,    66,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    79,    80,    19,    19,    18,    18,    60,
      70,    80,    19,    69,    19,    19,    70,    22,    57,    58,
      69,    19,    45,    46,    48,    49,    50,    26,    77,    77,
      26,    26,    77,     0,    54,    58,    18,    18,    23,    18,
      23,    26,    65,    80,    18,    38,    39,    36,    37,    40,
      41,    42,    43,    31,    32,    33,    34,    35,    48,    49,
      50,    71,    75,    71,    18,    59,    69,    70,    26,    67,
      80,    30,    30,    20,    22,    58,    70,    78,    70,    70,
      70,    65,    67,    19,    48,    72,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    70,    70,
      70,    20,    20,    18,    26,    48,    23,    23,    20,    23,
      55,    56,    69,    68,    70,    18,    18,    18,    58,    58,
      59,    48,    68,    44,    62,    78,    70,    20,    23,    24,
      26,     9,    18,    70,    26,    20,    23,    20,    18,    63,
      56,    70,    24,    58,    60,    44,    25,    25,    70,    20,
      26,    25,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     6,     6,     1,
       3,     0,     2,     4,     5,     4,     1,     2,     1,     2,
       2,     4,     4,     4,     2,     1,     5,     7,     5,     2,
       2,     3,     9,     2,     1,     4,     0,     1,     0,     6,
       6,     2,     4,     2,     3,     2,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     4,     0,     1,     3,     3,
       1,     2,     2,     2,     2,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 27 "src/main.y" /* yacc.c:1646  */
    {root = new TreeNode(0, NODE_PROG); root->addChild((yyvsp[0]));}
#line 1412 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 31 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode((yyvsp[0])->lineno, NODE_COMP);(yyval)->addChild((yyvsp[0]));}
#line 1418 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 32 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode((yyvsp[0])->lineno, NODE_COMP);(yyval)->addChild((yyvsp[0]));}
#line 1424 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 33 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_COMP);
    node->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
    (yyval)->addSibling(node);
}
#line 1435 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 39 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_COMP);
    node->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
    (yyval)->addSibling(node);
}
#line 1446 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 48 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-5])->lineno, NODE_FUNC);
    (yyval)->var_name = (yyvsp[-4])->var_name;
    (yyval)->type = (yyvsp[-5])->type;
    (yyvsp[-4])->type = (yyvsp[-5])->type;
    (yyval)->addChild((yyvsp[-5]));
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1461 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-5])->lineno, NODE_FUNC);
    (yyval)->var_name = (yyvsp[-4])->var_name;
    (yyvsp[-4])->type = (yyvsp[-5])->type;
    (yyval)->type = (yyvsp[-5])->type;
    (yyval)->addChild((yyvsp[-5]));
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
}
#line 1475 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_FUNCPARAMS);
    (yyval)->addChild((yyvsp[0]));
}
#line 1484 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 74 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1493 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 1499 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_FUNCPARAM);
    (yyval)->addChild((yyvsp[-1]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[0])->isdecl=true;
}
#line 1510 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_FUNCPARAM);
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));  
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EMPTY);
    (yyval)->addChild(node);
    (yyvsp[-2])->isdecl=true;
}
#line 1523 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 96 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_FUNCPARAM);
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-3]));  
    (yyval)->addChild((yyvsp[-1]));
    (yyvsp[-3])->isdecl = true;  
}
#line 1535 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 103 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-3]);
    (yyval)->addChild((yyvsp[-1]));
}
#line 1544 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1550 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 111 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); (yyval)->addSibling((yyvsp[0]));}
#line 1556 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 115 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1562 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 116 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1568 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 117 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1574 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 118 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_ASSG;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1587 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 126 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_ADD_ASSG;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1600 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 134 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_SUB_ASSG;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1613 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 142 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT); 
    (yyval)->stype = STMT_EXPR;
    (yyval)->addChild((yyvsp[-1]));
}
#line 1623 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 147 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1629 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IF;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1640 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IFELSE;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1652 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 161 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
    (yyval)->stype = STMT_WHILE;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));    
}
#line 1663 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_BREAK;
}
#line 1672 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_CONTI;   
}
#line 1681 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 175 "src/main.y" /* yacc.c:1646  */
    {//return语句的返回值应该是可以不写的，这里借用for第三个表达式的形式
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_RETURN;  
    (yyval)->addChild((yyvsp[-1]));     
}
#line 1691 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 180 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
    (yyval)->stype = STMT_FOR;
    (yyval)->addChild((yyvsp[-6]));  
    (yyval)->addChild((yyvsp[-4]));  
    (yyval)->addChild((yyvsp[-2]));  
    (yyval)->addChild((yyvsp[0]));  
}
#line 1704 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1710 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 192 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1716 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 193 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    (yyval)->stype = STMT_FOR_DECL;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[-2])->isdecl = true;
}
#line 1729 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 201 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 1735 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 205 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1741 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 1747 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 211 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IOFUNC;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1758 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 217 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IOFUNC;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1769 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 226 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_FUNCRPARAMS);
    (yyval)->addChild((yyvsp[0]));
}
#line 1778 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 230 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-3]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1787 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 237 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_BLOK;     
}
#line 1796 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 241 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    (yyval)->stype = STMT_BLOK;     
    (yyval)->addChild((yyvsp[-1])); 
}
#line 1806 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 250 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-1]));   
    node->addChild((yyvsp[0]));   
    (yyval) = node;
}
#line 1818 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 257 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1827 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 264 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[0])->lineno,NODE_VARDEF);
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[0])->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
#line 1838 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 270 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno,NODE_VARDEF);
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[-2])->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
#line 1850 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 280 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_DECL_CONST;
    node->addChild((yyvsp[-1]));   
    node->addChild((yyvsp[0]));   
    (yyval) = node;   
}
#line 1862 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 287 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1871 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 294 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno,NODE_VARDEF);
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[-2])->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
#line 1883 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 304 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1889 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 326 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 1895 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 327 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 1901 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 328 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 1907 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 329 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_VOID;}
#line 1913 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 333 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1919 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 334 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1925 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 335 "src/main.y" /* yacc.c:1646  */
    {//赋值式也有返回值，也可以是表达式
    (yyval) = new TreeNode((yyvsp[-2])->lineno,   NODE_EXPR);
    (yyval)->optype = OP_ASSG;
    (yyval)->type = (yyvsp[0])->type;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1937 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 342 "src/main.y" /* yacc.c:1646  */
    {//赋值式也有返回值，也可以是表达式
    (yyval) = new TreeNode((yyvsp[-2])->lineno,   NODE_EXPR);
    (yyval)->optype = OP_ADD_ASSG;
    (yyval)->type = (yyvsp[0])->type;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1949 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 349 "src/main.y" /* yacc.c:1646  */
    {//赋值式也有返回值，也可以是表达式
    (yyval) = new TreeNode((yyvsp[-2])->lineno,   NODE_EXPR);
    (yyval)->optype = OP_SUB_ASSG;
    (yyval)->type = (yyvsp[0])->type;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1961 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 359 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1967 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 360 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_OR;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1980 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 371 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1986 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 372 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_AND;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 1999 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 383 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2005 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 384 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_EQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;       
}
#line 2018 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 392 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_NQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;         
}
#line 2031 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 403 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2037 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 404 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_LT;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2050 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 412 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_BT;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2063 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 420 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_LTEQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2076 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 428 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_BTEQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2089 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 440 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2095 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 441 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_ADD;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2108 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 449 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_SUB;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2121 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 460 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2127 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 461 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_MUL;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2140 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 469 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_DIV;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;    
}
#line 2153 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 477 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_MOD;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2166 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 488 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2172 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 489 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_OPT;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2184 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 496 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_NEG;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2196 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 503 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_NOT;
    node->type = TYPE_BOOL; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2208 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 510 "src/main.y" /* yacc.c:1646  */
    {//函数调用语句
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    (yyval)->optype = OP_FUNC;
    (yyval)->type = (yyvsp[-3])->type;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 2220 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 520 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 2226 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 521 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode((yyvsp[0])->lineno,NODE_FUNCRPARAMS);
    (yyval)->addChild((yyvsp[0]));
}
#line 2234 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 524 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 2243 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 531 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2249 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 532 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2257 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 535 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_INC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2269 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 542 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_DEC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2281 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 549 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->optype = OP_INC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2293 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 556 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->optype = OP_DEC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2305 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 563 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]); 
}
#line 2313 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 566 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]); 
}
#line 2321 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 569 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]); 
}
#line 2329 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 575 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2335 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2339 "src/main.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 590 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
