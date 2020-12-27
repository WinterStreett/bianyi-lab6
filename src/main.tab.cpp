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
    extern bool is_use_stack;
    int yylex();
    int yyerror( char const * );

#line 76 "src/main.tab.cpp" /* yacc.c:339  */

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

#line 178 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

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
       0,    28,    28,    32,    33,    34,    40,    49,    59,    71,
      75,    79,    83,    89,    97,   104,   111,   112,   116,   117,
     118,   119,   127,   135,   143,   148,   149,   155,   162,   168,
     172,   176,   181,   189,   193,   194,   202,   206,   207,   212,
     220,   231,   235,   242,   246,   254,   255,   259,   266,   273,
     279,   289,   296,   303,   313,   335,   336,   337,   338,   342,
     343,   344,   351,   358,   368,   369,   380,   381,   392,   393,
     401,   412,   413,   421,   429,   437,   449,   450,   458,   469,
     470,   478,   486,   497,   498,   505,   512,   519,   529,   530,
     533,   540,   541,   544,   551,   558,   565,   572,   575,   578,
     584
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
  "decl", "declaration", "varDef", "constDeclaration", "constDef",
  "initVal", "T", "expr", "lOrExp", "lAndExp", "eqExp", "relExp", "addExp",
  "mulExp", "unaryExp", "funcRParams", "primaryExp", "LVal", YY_NULLPTR
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

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,  -115,  -115,  -115,  -115,    62,     4,    89,  -115,    -4,
      11,    17,     0,    20,  -115,  -115,    49,  -115,    20,    20,
      31,  -115,    27,  -115,  -115,    41,  -115,  -115,  -115,    62,
     113,   113,    33,    99,    65,   113,    38,  -115,  -115,  -115,
     273,   273,    88,   116,   273,  -115,  -115,   123,   112,    61,
     107,   106,   130,  -115,  -115,  -115,  -115,   -16,    62,   113,
     142,   151,   113,  -115,  -115,   113,   113,   113,    -3,  -115,
    -115,  -115,  -115,  -115,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,  -115,   173,  -115,
      99,   149,    75,  -115,  -115,    92,  -115,  -115,  -115,   112,
      78,    61,   107,   107,    78,    78,    78,    78,   130,   130,
    -115,  -115,  -115,   156,   159,   175,   180,   113,   183,   187,
     188,  -115,  -115,   218,  -115,   190,  -115,    67,    90,    20,
     191,   120,  -115,  -115,   185,  -115,   113,   273,   273,  -115,
    -115,   193,  -115,    32,   182,   184,  -115,  -115,  -115,  -115,
    -115,  -115,   113,   113,   113,  -115,  -115,    -9,    -5,  -115,
     195,   189,  -115,   194,   200,   198,   209,   220,   263,   263,
      32,   199,   197,   113,  -115,  -115,  -115,   233,  -115,   225,
     113,   226,    96,   110,   263,   113,  -115,  -115,  -115,   207,
    -115,  -115,   234,   227,   263,  -115,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    56,    55,    57,    58,     0,     0,     2,     3,     0,
      45,    46,     0,     0,     1,     5,     0,     4,     0,     0,
     100,    47,    49,   100,    51,     0,     6,    48,    52,    11,
       0,     0,     0,     9,     0,     0,   100,    97,    98,    99,
       0,     0,     0,     0,     0,    50,    54,    60,    64,    66,
      68,    71,    76,    79,    83,    92,    53,     0,     0,     0,
      12,     0,    88,    95,    96,     0,     0,     0,   100,    84,
      85,    93,    94,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     7,
      10,     0,     0,    91,    89,     0,    61,    62,    63,    65,
      71,    67,    69,    70,    72,    73,    74,    75,    77,    78,
      80,    81,    82,     0,     0,     0,     0,    38,     0,     0,
       0,    18,    43,     0,    16,     0,    25,     0,     0,     0,
       0,    92,    15,    13,     0,    87,     0,     0,     0,    29,
      30,     0,    37,    36,     0,     0,    44,    17,    33,    19,
      20,    24,     0,     0,     0,    14,    90,     0,     0,    31,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,    88,    21,    22,    23,    26,    28,     0,
       0,     0,     0,     0,     0,    38,    35,    41,    39,     0,
      40,    27,     0,     0,     0,    42,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,   248,  -115,   201,  -115,  -114,    86,    72,
    -115,  -115,   203,   251,    30,   243,    45,   249,   231,     3,
     -18,   -10,   211,   208,    77,   -56,   114,   -13,   115,  -115,
     -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    32,    33,   123,   124,   160,   141,
     125,   182,   126,     9,   127,    21,   128,    24,    45,   129,
     130,    47,    48,    49,    50,    51,    52,    53,    95,    54,
      55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    25,    87,    12,    14,    88,    22,    25,    13,   147,
      12,   168,    46,    46,    17,   169,    62,    61,   100,   100,
     100,   100,   104,   105,   106,   107,    20,    69,    70,    74,
      10,    73,    34,    74,    18,     1,     2,    10,     3,     4,
      19,    91,    63,    64,    94,    11,    23,    96,    97,    98,
      29,    35,    11,    57,   177,   178,    58,    62,    36,    37,
      38,    34,    39,    40,    41,     1,     2,    26,     3,     4,
     191,   110,   111,   112,   134,    30,   131,    42,    43,    44,
     196,   100,   100,    63,    64,   149,    65,    66,    67,    31,
      18,    60,     1,     2,    35,     3,     4,    76,    77,   142,
     133,    36,    37,    38,     5,    39,    40,    41,   150,    82,
      83,   131,   135,    19,    71,   136,   188,    22,   156,   189,
      42,    43,    44,    59,   -59,   162,   -59,   157,   158,   -59,
     190,   -59,    35,   136,   165,   166,   167,    82,    83,    36,
      37,    38,    72,    39,    40,    41,   161,    78,    79,    80,
      81,    75,   162,   102,   103,    94,   131,   131,    42,    43,
      44,    74,   186,    84,    85,    86,    92,   142,   152,   153,
     154,    93,   131,   161,   132,   137,     1,     2,   138,     3,
       4,   113,   131,   114,   115,   116,   117,   118,     5,   119,
     120,   121,    35,   139,    88,   122,   108,   109,   140,    36,
      37,    38,   143,    39,    40,    41,   144,   145,   148,   151,
     155,   159,   163,   170,   164,   171,   174,   172,    42,    43,
      44,     1,     2,   173,     3,     4,   113,   175,   114,   115,
     116,   117,   118,     5,   119,   120,   121,    35,   176,    88,
     146,   181,   184,   185,    36,    37,    38,   180,    39,    40,
      41,   193,   187,   195,   194,    15,   179,   192,    16,    90,
      89,    27,    56,    42,    43,    44,     1,     2,    28,     3,
       4,   113,     0,   114,   115,   116,   117,   118,     5,   119,
     120,   121,    35,   101,    88,    99,     0,     0,   183,    36,
      37,    38,    35,    39,    40,    41,     0,     0,     0,    68,
      37,    38,     0,    39,    40,    41,     0,     0,    42,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      44
};

static const yytype_int16 yycheck[] =
{
      12,    13,    18,     0,     0,    21,    18,    19,     5,   123,
       7,    20,    30,    31,    18,    20,    19,    35,    74,    75,
      76,    77,    78,    79,    80,    81,    26,    40,    41,    38,
       0,    44,    29,    38,    23,     3,     4,     7,     6,     7,
      23,    59,    45,    46,    62,     0,    26,    65,    66,    67,
      19,    19,     7,    20,   168,   169,    23,    19,    26,    27,
      28,    58,    30,    31,    32,     3,     4,    18,     6,     7,
     184,    84,    85,    86,    92,    48,    88,    45,    46,    47,
     194,   137,   138,    45,    46,    18,    48,    49,    50,    48,
      23,    26,     3,     4,    19,     6,     7,    36,    37,   117,
      25,    26,    27,    28,    15,    30,    31,    32,    18,    31,
      32,   123,    20,    23,    26,    23,    20,   129,   136,    23,
      45,    46,    47,    24,    18,   143,    20,   137,   138,    23,
      20,    25,    19,    23,   152,   153,   154,    31,    32,    26,
      27,    28,    26,    30,    31,    32,   143,    40,    41,    42,
      43,    39,   170,    76,    77,   173,   168,   169,    45,    46,
      47,    38,   180,    33,    34,    35,    24,   185,    48,    49,
      50,    20,   184,   170,    25,    19,     3,     4,    19,     6,
       7,     8,   194,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    18,    21,    22,    82,    83,    18,    26,
      27,    28,    19,    30,    31,    32,    19,    19,    18,    18,
      25,    18,    30,    18,    30,    26,    18,    23,    45,    46,
      47,     3,     4,    23,     6,     7,     8,    18,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    18,    21,
      22,    44,     9,    18,    26,    27,    28,    48,    30,    31,
      32,    44,    26,    26,    20,     7,   170,   185,     7,    58,
      57,    18,    31,    45,    46,    47,     3,     4,    19,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    75,    21,    74,    -1,    -1,   173,    26,
      27,    28,    19,    30,    31,    32,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,    15,    52,    53,    54,    64,
      65,    67,    70,    70,     0,    54,    64,    18,    23,    23,
      26,    66,    81,    26,    68,    81,    18,    66,    68,    19,
      48,    48,    55,    56,    70,    19,    26,    27,    28,    30,
      31,    32,    45,    46,    47,    69,    71,    72,    73,    74,
      75,    76,    77,    78,    80,    81,    69,    20,    23,    24,
      26,    71,    19,    45,    46,    48,    49,    50,    26,    78,
      78,    26,    26,    78,    38,    39,    36,    37,    40,    41,
      42,    43,    31,    32,    33,    34,    35,    18,    21,    63,
      56,    71,    24,    20,    71,    79,    71,    71,    71,    73,
      76,    74,    75,    75,    76,    76,    76,    76,    77,    77,
      78,    78,    78,     8,    10,    11,    12,    13,    14,    16,
      17,    18,    22,    57,    58,    61,    63,    65,    67,    70,
      71,    81,    25,    25,    71,    20,    23,    19,    19,    18,
      18,    60,    71,    19,    19,    19,    22,    58,    18,    18,
      18,    18,    48,    49,    50,    25,    71,    72,    72,    18,
      59,    70,    71,    30,    30,    71,    71,    71,    20,    20,
      18,    26,    23,    23,    18,    18,    18,    58,    58,    59,
      48,    44,    62,    79,     9,    18,    71,    26,    20,    23,
      20,    58,    60,    44,    20,    26,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     6,     6,     1,
       3,     0,     2,     4,     5,     4,     1,     2,     1,     2,
       2,     4,     4,     4,     2,     1,     5,     7,     5,     2,
       2,     3,     9,     2,     1,     4,     0,     1,     0,     6,
       6,     2,     4,     2,     3,     1,     1,     2,     3,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     4,     0,     1,
       3,     3,     1,     2,     2,     2,     2,     1,     1,     1,
       1
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
#line 28 "src/main.y" /* yacc.c:1646  */
    {root = new TreeNode(0, NODE_PROG); root->addChild((yyvsp[0]));}
#line 1420 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 32 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode((yyvsp[0])->lineno, NODE_COMP);(yyval)->addChild((yyvsp[0]));}
#line 1426 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 33 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_COMP);(yyval)->addChild((yyvsp[-1]));}
#line 1432 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 34 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_COMP);
    node->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
    (yyval)->addSibling(node);
}
#line 1443 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 40 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_COMP);
    node->addChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
    (yyval)->addSibling(node);
}
#line 1454 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "src/main.y" /* yacc.c:1646  */
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
#line 1469 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 59 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-5])->lineno, NODE_FUNC);
    (yyval)->var_name = (yyvsp[-4])->var_name;
    (yyvsp[-4])->type = (yyvsp[-5])->type;
    (yyval)->type = (yyvsp[-5])->type;
    (yyval)->addChild((yyvsp[-5]));
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
}
#line 1483 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 71 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_FUNCPARAMS);
    (yyval)->addChild((yyvsp[0]));
}
#line 1492 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 75 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1501 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 79 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 1507 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 83 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_FUNCPARAM);
    (yyval)->addChild((yyvsp[-1]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[0])->isdecl=true;
}
#line 1518 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_FUNCPARAM);
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));  
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EMPTY);
    (yyval)->addChild(node);
    (yyvsp[-2])->isdecl=true;
}
#line 1531 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_FUNCPARAM);
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-3]));  
    (yyval)->addChild((yyvsp[-1]));
    (yyvsp[-3])->isdecl = true;  
}
#line 1543 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-3]);
    (yyval)->addChild((yyvsp[-1]));
}
#line 1552 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 111 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1558 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 112 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); (yyval)->addSibling((yyvsp[0]));}
#line 1564 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 116 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1570 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 117 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1576 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1582 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_ASSG;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1595 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_ADD_ASSG;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1608 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_SUB_ASSG;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1621 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT); 
    (yyval)->stype = STMT_EXPR;
    (yyval)->addChild((yyvsp[-1]));
}
#line 1631 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 148 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1637 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 149 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IF;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1648 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 155 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IFELSE;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1660 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 162 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
    (yyval)->stype = STMT_WHILE;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));    
}
#line 1671 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_BREAK;
}
#line 1680 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 172 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_CONTI;   
}
#line 1689 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 176 "src/main.y" /* yacc.c:1646  */
    {//return语句的返回值应该是可以不写的，这里借用for第三个表达式的形式
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_RETURN;  
    (yyval)->addChild((yyvsp[-1]));     
}
#line 1699 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
    (yyval)->stype = STMT_FOR;
    (yyval)->addChild((yyvsp[-6]));  
    (yyval)->addChild((yyvsp[-4]));  
    (yyval)->addChild((yyvsp[-2]));  
    (yyval)->addChild((yyvsp[0]));  
}
#line 1712 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 189 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1718 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 193 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1724 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 194 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    (yyval)->stype = STMT_FOR_DECL;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[-2])->isdecl = true;
}
#line 1737 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 202 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 1743 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 206 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1749 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 207 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 1755 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 212 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IOFUNC;
    (yyval)->var_name = "scanf";
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
    is_use_stack = true;
}
#line 1768 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 220 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    (yyval)->stype = STMT_IOFUNC;
    (yyval)->var_name = "printf";
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));
    is_use_stack = true;
}
#line 1781 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 231 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_FUNCRPARAMS);
    (yyval)->addChild((yyvsp[0]));
}
#line 1790 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 235 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-3]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1799 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 242 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_BLOK;     
}
#line 1808 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 246 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    (yyval)->stype = STMT_BLOK;     
    (yyval)->addChild((yyvsp[-1])); 
}
#line 1818 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1824 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1830 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 259 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-1]));   
    node->addChild((yyvsp[0]));   
    (yyval) = node;
}
#line 1842 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 266 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1851 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[0])->lineno,NODE_VARDEF);
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[0])->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
#line 1862 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 279 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno,NODE_VARDEF);
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[-2])->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
#line 1874 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 289 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_DECL_CONST;
    node->addChild((yyvsp[-1]));   
    node->addChild((yyvsp[0]));   
    (yyval) = node;   
}
#line 1886 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 296 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 1895 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 303 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode((yyvsp[-2])->lineno,NODE_VARDEF);
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
    (yyvsp[-2])->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
#line 1907 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 313 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1913 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 335 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 1919 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 336 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 1925 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 337 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 1931 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 338 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_VOID;}
#line 1937 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 342 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1943 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 343 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1949 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 344 "src/main.y" /* yacc.c:1646  */
    {//赋值式也有返回值，也可以是表达式
    (yyval) = new TreeNode((yyvsp[-2])->lineno,   NODE_EXPR);
    (yyval)->optype = OP_ASSG;
    (yyval)->type = (yyvsp[0])->type;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1961 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 351 "src/main.y" /* yacc.c:1646  */
    {//赋值式也有返回值，也可以是表达式
    (yyval) = new TreeNode((yyvsp[-2])->lineno,   NODE_EXPR);
    (yyval)->optype = OP_ADD_ASSG;
    (yyval)->type = (yyvsp[0])->type;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1973 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 358 "src/main.y" /* yacc.c:1646  */
    {//赋值式也有返回值，也可以是表达式
    (yyval) = new TreeNode((yyvsp[-2])->lineno,   NODE_EXPR);
    (yyval)->optype = OP_SUB_ASSG;
    (yyval)->type = (yyvsp[0])->type;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1985 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 368 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1991 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 369 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_OR;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2004 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 380 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2010 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 381 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_AND;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2023 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 392 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2029 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 393 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_EQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;       
}
#line 2042 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 401 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_NQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;         
}
#line 2055 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 412 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2061 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 413 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_LT;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2074 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 421 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_BT;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2087 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 429 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_LTEQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2100 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 437 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_BTEQ;
    node->type = TYPE_BOOL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;          
}
#line 2113 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 449 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2119 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 450 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_ADD;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2132 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 458 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_SUB;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2145 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 469 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2151 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 470 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_MUL;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2164 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 478 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_DIV;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;    
}
#line 2177 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 486 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->optype = OP_MOD;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 2190 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 497 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2196 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 498 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_OPT;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2208 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 505 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_NEG;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2220 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 512 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_NOT;
    node->type = TYPE_BOOL; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2232 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 519 "src/main.y" /* yacc.c:1646  */
    {//函数调用语句
    (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    (yyval)->optype = OP_FUNC;
    (yyval)->type = (yyvsp[-3])->type;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 2244 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 529 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_EMPTY);}
#line 2250 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 530 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode((yyvsp[0])->lineno,NODE_FUNCRPARAMS);
    (yyval)->addChild((yyvsp[0]));
}
#line 2258 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 533 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2]);
    (yyval)->addChild((yyvsp[0]));
}
#line 2267 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 540 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2273 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 541 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2281 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 544 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_INC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2293 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 551 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->optype = OP_DEC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2305 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 558 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->optype = OP_INC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2317 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 565 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->optype = OP_DEC;
    node->type = TYPE_INT; 
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2329 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 572 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]); 
}
#line 2337 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 575 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]); 
}
#line 2345 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 578 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]); 
}
#line 2353 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 584 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2359 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2363 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 599 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
