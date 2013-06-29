/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "hopper.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash/hash.c"
#define YYSTYPE char*
int erros;
extern yylineno, yytext;

char *var_nome;
char *var_escopo;
char *var_tipo;

typedef struct elementofila
{
    char token[50];
    struct elementofila *prox;
}elementofila;

typedef struct fila
{
    elementofila *inicio;
    elementofila *final;
} fila;

fila *Fila;

void cria_fila(fila *_fila)
{
    _fila->inicio = _fila->final = NULL;
}

int fila_vazia(fila *_fila)
{
    if(_fila->inicio == NULL && _fila->final == NULL)
        return 1;
    else
        return 0;
}

int push(fila *_fila, char *_token)
{
    elementofila *novoElemento;
    novoElemento = (elementofila*) malloc(sizeof(elementofila));
    if (novoElemento == NULL)
        return 0;
    strcpy(novoElemento->token,_token);
    novoElemento->prox = NULL;
    if (fila_vazia(_fila))
        _fila->inicio = novoElemento;
    else
        (_fila->final)->prox = novoElemento;
    _fila->final = novoElemento;
   return 1;
}

int pop(fila *_fila, struct elementofila **_elemento)
{
    if (fila_vazia(_fila))
        return 0;
    *_elemento = (_fila->inicio);
    if (_fila->inicio == _fila->final)
      _fila->final = NULL;
    _fila->inicio = (_fila->inicio)->prox;
    return 1;
}

void pop_all(fila *_fila)
{
    while(!fila_vazia(_fila))
  {
        elementofila *ret;
        pop(_fila, &ret);
        free(ret);
  }
}



/* Line 268 of yacc.c  */
#line 152 "hopper.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     T_ALGORITMO = 258,
     T_STRING = 259,
     T_FIM_COMANDO = 260,
     T_VAR = 261,
     T_IDENTIFICADOR = 262,
     T_TIPO_ATRIBUIDOR = 263,
     T_IDENT_SEPARADOR = 264,
     T_REAL = 265,
     T_INTEIRO = 266,
     T_INICIO = 267,
     T_ESCREVA = 268,
     T_ESCREVAL = 269,
     T_PARENTESE_DIR = 270,
     T_PARENTESE_ESQ = 271,
     T_LEIA = 272,
     T_OPERADOR_ATRIBUICAO = 273,
     T_OPERADOR_SOMA = 274,
     T_OPERADOR_SUBTRACAO = 275,
     T_OPERADOR_MULTIPLICACAO = 276,
     T_OPERADOR_DIVISAO = 277,
     T_OPERADOR_EXPONENCIACAO = 278,
     T_RAIZQ = 279,
     T_FIMALGORITMO = 280,
     T_ABS = 281,
     T_ALEATORIO = 282,
     T_ARCCOS = 283,
     T_ARCSEN = 284,
     T_ARCTAN = 285,
     T_ATE = 286,
     T_ASC = 287,
     T_ARQUIVO = 288,
     T_CARAC = 289,
     T_CARACPNUM = 290,
     T_CARACTERE = 291,
     T_CASO = 292,
     T_COMPR = 293,
     T_COPIA = 294,
     T_COS = 295,
     T_COTAN = 296,
     T_CRONOMETRO = 297,
     T_DE = 298,
     T_DEBUG = 299,
     T_DECLARE = 300,
     T_ECO = 301,
     T_ENQUANTO = 302,
     T_ENTAO = 303,
     T_ESCOLHA = 304,
     T_EXP = 305,
     T_FACA = 306,
     T_FALSO = 307,
     T_FIMENQUANTO = 308,
     T_FIMESCOLHA = 309,
     T_FIMFUNCAO = 310,
     T_FIMPARA = 311,
     T_FIMPROCEDIMENTO = 312,
     T_FIMREPITA = 313,
     T_FIMSE = 314,
     T_FUNCAO = 315,
     T_GRAUPRAD = 316,
     T_INT = 317,
     T_INTERROMPA = 318,
     T_LIMPATELA = 319,
     T_LITERAL = 320,
     T_LOG = 321,
     T_LOGICO = 322,
     T_MAIUSC = 323,
     T_MENSAGEM = 324,
     T_MINUSC = 325,
     T_NUMPCARAC = 326,
     T_NUMERICO = 327,
     T_OUTROCASO = 328,
     T_PARA = 329,
     T_PASSO = 330,
     T_PAUSA = 331,
     T_PI = 332,
     T_POS = 333,
     T_PROCEDIMENTO = 334,
     T_QUAD = 335,
     T_RADPGRAU = 336,
     T_RAND = 337,
     T_RANDI = 338,
     T_REPITA = 339,
     T_RETORNE = 340,
     T_SE = 341,
     T_SEN = 342,
     T_SENAO = 343,
     T_TAN = 344,
     T_TIMER = 345,
     T_VETOR = 346,
     T_VERDADEIRO = 347,
     T_OPERADOR_DIVISAO_INT = 348,
     T_OPERADOR_DIVISAO_RESTO = 349,
     T_OPERADOR_IGUAL = 350,
     T_OPERADOR_DIFERENTE = 351,
     T_OPERADOR_MENOR = 352,
     T_OPERADOR_MAIOR = 353,
     T_OPERADOR_MENOR_IGUAL = 354,
     T_OPERADOR_MAIOR_IGUAL = 355,
     T_COLCHETE_ESQ = 356,
     T_COLCHETE_DIR = 357,
     T_VETOR_INTERVALO = 358,
     T_NUMERO_INTEIRO = 359,
     T_NUMERO_REAL = 360,
     T_OP_LOGICO_E = 361,
     T_OP_LOGICO_XOU = 362,
     T_OP_LOGICO_NAO = 363,
     T_OP_LOGICO_OU = 364,
     T_INVALIDO = 365,
     MAIOR_IGUAL = 366,
     MAIOR = 367,
     MENOR_IGUAL = 368,
     MENOR = 369,
     DIFERENTE = 370,
     IGUAL = 371,
     NEG = 372
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 324 "hopper.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1714

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNRULES -- Number of states.  */
#define YYNSTATES  353

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    21,
      22,    26,    30,    31,    35,    36,    40,    45,    51,    52,
      56,    58,    62,    63,    67,    69,    71,    73,    74,    78,
      79,    81,    83,    86,    89,    90,    94,    95,   111,   112,
     116,   117,   131,   135,   141,   147,   149,   152,   153,   157,
     160,   163,   166,   169,   172,   175,   178,   181,   187,   191,
     194,   195,   199,   204,   206,   210,   211,   215,   220,   223,
     228,   229,   233,   234,   237,   242,   243,   247,   254,   264,
     270,   277,   279,   282,   287,   288,   292,   296,   307,   320,
     327,   333,   337,   339,   341,   343,   345,   347,   351,   355,
     359,   363,   367,   371,   374,   377,   381,   386,   391,   396,
     401,   406,   407,   412,   414,   418,   419,   423,   425,   427,
     428,   432,   434,   436,   438,   440,   442,   444,   446,   448,
     450,   452,   454,   456,   458,   459,   463,   465,   467,   468,
     472,   474,   475,   479,   481,   482,   486,   488,   490,   491,
     495,   497,   498,   502,   504,   505,   509,   511,   513,   515,
     517,   519,   521,   523,   525,   527,   529,   531,   533,   535,
     537,   539,   540,   544,   546,   548,   550,   552,   554,   556,
     558,   560,   562,   564,   566
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     121,     0,    -1,    -1,   120,    -1,     5,    -1,   120,     5,
      -1,     1,    -1,   119,   122,    -1,   124,   125,   133,   141,
      -1,    -1,     1,   123,   120,    -1,   173,   174,   120,    -1,
      -1,   176,   119,   127,    -1,    -1,     1,   126,   120,    -1,
     129,   177,   131,   120,    -1,   127,   129,   177,   131,   120,
      -1,    -1,     1,   128,   120,    -1,   179,    -1,   129,   181,
     179,    -1,    -1,     1,   130,   120,    -1,    10,    -1,    11,
      -1,    36,    -1,    -1,     1,   132,   120,    -1,    -1,   135,
      -1,   138,    -1,   133,   135,    -1,   133,   138,    -1,    -1,
       1,   134,   120,    -1,    -1,   183,   179,   136,   184,   140,
     186,   177,   131,   120,   125,   188,   120,   142,   190,   120,
      -1,    -1,     1,   137,   120,    -1,    -1,   191,   179,   139,
     184,   140,   186,   120,   125,   188,   120,   142,   192,   120,
      -1,   129,   177,   131,    -1,   140,   181,   129,   177,   131,
      -1,   188,   120,   142,   193,   119,    -1,   144,    -1,   142,
     144,    -1,    -1,     1,   143,   120,    -1,   146,   120,    -1,
     149,   120,    -1,   163,   120,    -1,   154,   120,    -1,   155,
     120,    -1,   160,   120,    -1,   161,   120,    -1,   162,   120,
      -1,   179,   184,   166,   186,   120,    -1,   194,   164,   120,
      -1,   195,   120,    -1,    -1,     1,   145,   120,    -1,   196,
     184,   147,   186,    -1,   179,    -1,   147,   181,   179,    -1,
      -1,     1,   148,   120,    -1,   197,   184,   150,   186,    -1,
     164,   152,    -1,   150,   181,   164,   152,    -1,    -1,     1,
     151,   120,    -1,    -1,   177,   104,    -1,   177,   104,   177,
     104,    -1,    -1,     1,   153,   120,    -1,   198,   164,   199,
     120,   142,   200,    -1,   198,   164,   199,   120,   142,   201,
     120,   142,   200,    -1,   202,   179,   120,   156,   203,    -1,
     202,   179,   120,   156,   159,   203,    -1,   157,    -1,   156,
     157,    -1,   205,   164,   120,   142,    -1,    -1,     1,   158,
     120,    -1,   206,   120,   142,    -1,   207,   164,   209,   164,
     208,   164,   210,   120,   142,   211,    -1,   207,   164,   209,
     164,   208,   164,   212,   164,   210,   120,   142,   211,    -1,
     213,   164,   210,   120,   142,   214,    -1,   215,   120,   142,
     208,   164,    -1,   179,   216,   164,    -1,   179,    -1,   104,
      -1,   105,    -1,    77,    -1,   174,    -1,   184,   164,   186,
      -1,   164,    94,   164,    -1,   164,   168,   164,    -1,   164,
     170,   164,    -1,   164,   171,   164,    -1,   164,   172,   164,
      -1,    20,   164,    -1,   108,   164,    -1,   164,    23,   164,
      -1,    24,   184,   164,   186,    -1,    68,   184,   164,   186,
      -1,    38,   184,   164,   186,    -1,   179,   184,   166,   186,
      -1,    39,   184,   166,   186,    -1,    -1,   184,     1,   165,
     186,    -1,   164,    -1,   166,   181,   164,    -1,    -1,     1,
     167,   120,    -1,    19,    -1,    20,    -1,    -1,     1,   169,
     120,    -1,    21,    -1,    22,    -1,   106,    -1,   109,    -1,
     107,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,     3,    -1,     4,    -1,    -1,     1,
     175,   120,    -1,     6,    -1,     8,    -1,    -1,     1,   178,
     120,    -1,     7,    -1,    -1,     1,   180,   120,    -1,     9,
      -1,    -1,     1,   182,   120,    -1,    60,    -1,    16,    -1,
      -1,     1,   185,   120,    -1,    15,    -1,    -1,     1,   187,
     120,    -1,    12,    -1,    -1,     1,   189,   120,    -1,    55,
      -1,    79,    -1,    57,    -1,    25,    -1,    85,    -1,    63,
      -1,    17,    -1,    13,    -1,    14,    -1,    86,    -1,    48,
      -1,    59,    -1,    88,    -1,    49,    -1,    54,    -1,    -1,
       1,   204,   120,    -1,    37,    -1,    73,    -1,    74,    -1,
      31,    -1,    43,    -1,    51,    -1,    56,    -1,    75,    -1,
      47,    -1,    53,    -1,    84,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   134,   138,   139,   140,   147,   151,   152,
     152,   156,   160,   162,   163,   163,   168,   169,   170,   170,
     174,   175,   176,   176,   180,   190,   191,   192,   192,   195,
     197,   198,   199,   200,   201,   201,   205,   205,   207,   207,
     211,   211,   216,   217,   221,   225,   226,   227,   227,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   242,   246,   250,   251,   252,   252,   256,   260,   261,
     262,   262,   265,   267,   268,   269,   269,   273,   274,   278,
     279,   283,   284,   288,   289,   289,   293,   297,   298,   302,
     306,   310,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   333,   337,   338,   339,   339,   350,   351,   352,
     352,   356,   357,   361,   362,   363,   367,   368,   369,   370,
     371,   372,   377,   381,   382,   382,   387,   392,   393,   393,
     397,   398,   398,   402,   403,   403,   407,   411,   412,   412,
     416,   417,   417,   421,   422,   422,   426,   430,   434,   438,
     442,   447,   451,   455,   456,   460,   464,   468,   472,   476,
     480,   481,   481,   485,   489,   493,   497,   501,   505,   509,
     513,   517,   521,   525,   529
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ALGORITMO", "T_STRING",
  "T_FIM_COMANDO", "T_VAR", "T_IDENTIFICADOR", "T_TIPO_ATRIBUIDOR",
  "T_IDENT_SEPARADOR", "T_REAL", "T_INTEIRO", "T_INICIO", "T_ESCREVA",
  "T_ESCREVAL", "T_PARENTESE_DIR", "T_PARENTESE_ESQ", "T_LEIA",
  "T_OPERADOR_ATRIBUICAO", "T_OPERADOR_SOMA", "T_OPERADOR_SUBTRACAO",
  "T_OPERADOR_MULTIPLICACAO", "T_OPERADOR_DIVISAO",
  "T_OPERADOR_EXPONENCIACAO", "T_RAIZQ", "T_FIMALGORITMO", "T_ABS",
  "T_ALEATORIO", "T_ARCCOS", "T_ARCSEN", "T_ARCTAN", "T_ATE", "T_ASC",
  "T_ARQUIVO", "T_CARAC", "T_CARACPNUM", "T_CARACTERE", "T_CASO",
  "T_COMPR", "T_COPIA", "T_COS", "T_COTAN", "T_CRONOMETRO", "T_DE",
  "T_DEBUG", "T_DECLARE", "T_ECO", "T_ENQUANTO", "T_ENTAO", "T_ESCOLHA",
  "T_EXP", "T_FACA", "T_FALSO", "T_FIMENQUANTO", "T_FIMESCOLHA",
  "T_FIMFUNCAO", "T_FIMPARA", "T_FIMPROCEDIMENTO", "T_FIMREPITA",
  "T_FIMSE", "T_FUNCAO", "T_GRAUPRAD", "T_INT", "T_INTERROMPA",
  "T_LIMPATELA", "T_LITERAL", "T_LOG", "T_LOGICO", "T_MAIUSC",
  "T_MENSAGEM", "T_MINUSC", "T_NUMPCARAC", "T_NUMERICO", "T_OUTROCASO",
  "T_PARA", "T_PASSO", "T_PAUSA", "T_PI", "T_POS", "T_PROCEDIMENTO",
  "T_QUAD", "T_RADPGRAU", "T_RAND", "T_RANDI", "T_REPITA", "T_RETORNE",
  "T_SE", "T_SEN", "T_SENAO", "T_TAN", "T_TIMER", "T_VETOR",
  "T_VERDADEIRO", "T_OPERADOR_DIVISAO_INT", "T_OPERADOR_DIVISAO_RESTO",
  "T_OPERADOR_IGUAL", "T_OPERADOR_DIFERENTE", "T_OPERADOR_MENOR",
  "T_OPERADOR_MAIOR", "T_OPERADOR_MENOR_IGUAL", "T_OPERADOR_MAIOR_IGUAL",
  "T_COLCHETE_ESQ", "T_COLCHETE_DIR", "T_VETOR_INTERVALO",
  "T_NUMERO_INTEIRO", "T_NUMERO_REAL", "T_OP_LOGICO_E", "T_OP_LOGICO_XOU",
  "T_OP_LOGICO_NAO", "T_OP_LOGICO_OU", "T_INVALIDO", "MAIOR_IGUAL",
  "MAIOR", "MENOR_IGUAL", "MENOR", "DIFERENTE", "IGUAL", "NEG", "$accept",
  "QuebraComando", "FimComando", "Input", "Algoritmo", "$@1",
  "BlocoCabecalho", "BlocoDeclaracoes", "$@2", "ListaDeclaracoes", "$@3",
  "ListaVariaveis", "$@4", "TipoVariavel", "$@5", "BlocoFuncoes", "$@6",
  "BlocoFuncao", "$@7", "$@8", "BlocoProcedimento", "$@9",
  "ListaParametros", "BlocoComando", "Comandos", "$@10", "Comando", "$@11",
  "Leia", "ListaLeia", "$@12", "Escreva", "ConteudoEscreva", "$@13",
  "OpcaoCasasDecimais", "$@14", "BlocoSe", "BlocoEscolha", "ListaCasos",
  "Caso", "$@15", "OutroCaso", "BlocoPara", "BlocoEnquanto", "BlocoRepita",
  "Atribuicao", "Expr", "$@16", "List_Expr", "$@17", "Add_op", "$@18",
  "Mult_op", "Bool_op", "Comp_op", "T_Algoritmo", "T_String", "$@19",
  "T_Var", "T_Tipo_Atribuidor", "$@20", "T_Identificador", "$@21",
  "T_Ident_Separador", "$@22", "T_Funcao", "T_Parentese_Esq", "$@23",
  "T_Parentese_Dir", "$@24", "T_Inicio", "$@25", "T_FimFuncao",
  "T_Procedimento", "T_FimProcedimento", "T_FimAlgoritmo", "T_Retorne",
  "T_Interrompa", "T_Leia", "T_Escreva", "T_Se", "T_Entao", "T_FimSe",
  "T_Senao", "T_Escolha", "T_Fimescolha", "$@26", "T_Caso", "T_OutroCaso",
  "T_Para", "T_Ate", "T_De", "T_Faca", "T_FimPara", "T_Passo",
  "T_Enquanto", "T_FimEnquanto", "T_Repita", "T_Operador_Atribuicao", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   119,   120,   120,   120,   121,   122,   123,
     122,   124,   125,   125,   126,   125,   127,   127,   128,   127,
     129,   129,   130,   129,   131,   131,   131,   132,   131,   133,
     133,   133,   133,   133,   134,   133,   136,   135,   137,   135,
     139,   138,   140,   140,   141,   142,   142,   143,   142,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   144,   146,   147,   147,   148,   147,   149,   150,   150,
     151,   150,   152,   152,   152,   153,   152,   154,   154,   155,
     155,   156,   156,   157,   158,   157,   159,   160,   160,   161,
     162,   163,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   165,   164,   166,   166,   167,   166,   168,   168,   169,
     168,   170,   170,   171,   171,   171,   172,   172,   172,   172,
     172,   172,   173,   174,   175,   174,   176,   177,   178,   177,
     179,   180,   179,   181,   182,   181,   183,   184,   185,   184,
     186,   187,   186,   188,   189,   188,   190,   191,   192,   193,
     194,   195,   196,   197,   197,   198,   199,   200,   201,   202,
     203,   204,   203,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     4,     0,
       3,     3,     0,     3,     0,     3,     4,     5,     0,     3,
       1,     3,     0,     3,     1,     1,     1,     0,     3,     0,
       1,     1,     2,     2,     0,     3,     0,    15,     0,     3,
       0,    13,     3,     5,     5,     1,     2,     0,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     5,     3,     2,
       0,     3,     4,     1,     3,     0,     3,     4,     2,     4,
       0,     3,     0,     2,     4,     0,     3,     6,     9,     5,
       6,     1,     2,     4,     0,     3,     3,    10,    12,     6,
       5,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     4,     4,     4,     4,
       4,     0,     4,     1,     3,     0,     3,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     1,     0,     3,
       1,     0,     3,     1,     0,     3,     1,     1,     0,     3,
       1,     0,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     4,     0,     3,     0,     9,   132,     7,     0,
       0,     5,     1,     0,    14,   136,     0,     0,   134,   133,
       0,    10,     0,    34,   146,   157,     0,    30,    31,     0,
       0,     0,     0,    11,    15,     0,     0,    38,   153,    32,
      33,     8,     0,   141,   140,    36,    40,    18,     0,     0,
      20,   135,    35,    39,     0,     0,     0,     0,     0,     0,
       0,    22,     0,   138,   137,   143,     0,     0,   155,    47,
     163,   164,   162,   181,   169,   161,   175,   183,   160,   165,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   148,   147,     0,     0,    19,    23,     0,     0,     0,
      27,    24,    25,    26,     0,    21,     0,     0,    60,   159,
      46,     0,    49,    50,    52,    53,    54,    55,    56,    51,
     184,     0,     0,   134,     0,     0,     0,     0,     0,    95,
      93,    94,     0,     0,    96,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,   145,     0,    16,    48,    61,    44,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,   117,   118,
     121,   122,     0,     0,   126,   127,   128,   129,   130,   131,
     123,   125,   124,    58,     0,     0,     0,     0,     0,   111,
       0,    65,     0,    63,    70,     0,     0,   119,   166,     0,
       0,   177,     0,   178,     0,     0,   149,     0,   144,   150,
       0,     0,     0,    17,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,    97,     0,     0,    62,     0,     0,    67,    75,
      68,     0,     0,    84,   173,     0,    81,     0,     0,     0,
     176,     0,    42,     0,     0,   138,     0,     0,   116,     0,
      57,   106,   108,   110,   107,   120,   109,   151,   112,    66,
      64,    71,     0,     0,     0,     0,     0,    84,   170,   174,
      82,     0,    79,     0,     0,     0,     0,     0,   152,     0,
       0,     0,    69,    76,     0,   167,   168,    77,     0,    85,
       0,   171,    80,     0,     0,     0,   182,    89,    43,     0,
     154,     0,    74,     0,   172,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,   158,     0,   179,    87,     0,     0,    41,     0,   156,
       0,    88,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     8,    13,     9,    16,    22,    48,
      59,   156,    60,   114,   162,    26,    35,    27,    57,    36,
      28,    58,   157,    41,    80,   116,    81,   117,    82,   202,
     243,    83,   205,   246,   250,   283,    84,    85,   255,   256,
     286,   291,    86,    87,    88,    89,   168,   240,   169,   225,
     194,   232,   195,   196,   197,    10,   144,    32,    17,   251,
     108,   145,    56,    67,   109,    29,   146,   155,   221,   263,
      42,    54,   350,    30,   342,   121,    91,    92,    93,    94,
      95,   209,   307,   308,    96,   292,   310,   257,   293,    97,
     261,   212,   214,   344,   329,    98,   317,    99,   132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -301
static const yytype_int16 yypact[] =
{
     155,  -301,  -301,   117,    51,    59,  -301,  -301,  -301,     5,
      27,  -301,  -301,   143,  -301,  -301,    23,    93,  -301,  -301,
     143,    51,   143,  -301,  -301,  -301,   139,  -301,  -301,    47,
      47,   138,   143,    51,    51,   143,   143,  -301,  -301,  -301,
    -301,  -301,   143,  -301,  -301,  -301,  -301,  -301,   104,   114,
    -301,    51,    51,    51,   143,  1388,   143,    50,    50,   143,
     143,  -301,   114,  -301,  -301,  -301,   142,    47,    51,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    1396,  -301,   143,   143,   143,   143,   143,   143,   143,   143,
      24,    29,   143,    50,    50,    29,    47,    29,    29,   143,
      51,  -301,  -301,   140,   140,    51,    51,   142,   143,   143,
    -301,  -301,  -301,  -301,   143,  -301,   143,   143,  -301,  -301,
    -301,   187,    51,    51,    51,    51,    51,    51,    51,    51,
    -301,   201,    29,  -301,    29,    50,    50,    50,    50,  -301,
    -301,  -301,    29,  1025,  -301,   425,  1065,    51,   154,  1283,
    1057,   143,  1092,  1117,  1388,   143,   114,    17,    17,   143,
      51,    51,   143,    51,    51,    51,  -301,  -301,   899,    17,
    1157,   532,    29,    29,   201,    29,   573,  -301,  -301,  -301,
    -301,  -301,    29,    29,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,    51,    29,    29,    29,    29,   201,    85,
    1217,  -301,    17,  -301,  -301,    17,   383,  -301,  -301,   143,
      15,  -301,    29,  -301,   143,  1440,    51,   142,  -301,  -301,
     140,    84,   143,    51,    51,   143,    29,   143,  1217,  1217,
      17,  1217,   143,   635,   676,   738,   779,   841,   882,    17,
      76,  -301,  -301,   143,    47,  -301,   143,    29,  -301,  -301,
    -301,     3,  1388,  -301,  -301,    77,  -301,    29,  1174,  1388,
    -301,    29,  -301,   143,   114,  -301,   142,   222,    51,   943,
      51,  -301,  -301,  -301,  -301,    51,  -301,  -301,  -301,    51,
    -301,    51,   383,   143,    49,  1291,   143,  -301,  -301,  -301,
    -301,     1,  -301,   143,  1025,    29,  1483,  1274,    51,   142,
     143,    26,  -301,    51,    28,  -301,  -301,  -301,   143,    51,
     143,  -301,  -301,  1388,  1388,  1000,  -301,  -301,  -301,   222,
    -301,   143,  -301,  1388,    51,  1491,  1345,  -301,   143,    29,
      26,  1388,  1534,  1388,  1117,   143,  1542,  -301,  1587,   143,
    1388,  -301,   143,  -301,  -301,  1388,  1628,    51,  1587,  -301,
     143,  -301,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -301,   -12,   -13,  -301,  -301,  -301,  -301,  -259,  -301,  -301,
    -301,   -27,  -301,  -104,  -301,  -301,  -301,   101,  -301,  -301,
     131,  -301,    55,  -301,  -142,  -301,   -36,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -163,  -301,  -301,  -301,  -301,   -90,
    -301,  -301,  -301,  -301,  -301,  -301,   241,  -301,  -161,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,   160,  -301,  -301,   -48,
    -301,    32,  -301,   -76,  -301,  -301,    31,  -301,   785,  -301,
    -291,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -158,  -301,  -301,  -116,  -301,  -301,  -301,  -301,
     -81,  -301,  -300,  -166,  -301,  -301,  -301,  -301,  -301
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -135
static const yytype_int16 yytable[] =
{
      21,    66,   311,   159,    49,    31,    14,    33,   301,    34,
     321,    15,   215,   230,   107,   328,   253,   -12,   218,    51,
      11,    62,    52,    53,    23,   101,    65,   320,    18,    55,
     133,    19,   219,    19,   339,   -29,    44,   239,    38,   335,
     102,    68,   130,   100,   120,   102,   105,   106,    43,   134,
     265,   101,   254,   135,    44,   288,    11,    64,   -73,    12,
     330,    45,    46,    50,   -73,   -12,   102,   136,   137,   122,
     123,   124,   125,   126,   127,   128,   129,   277,   287,   147,
      50,   220,   220,    24,   -12,   265,   154,    90,   103,   104,
    -134,   219,    64,   226,     1,   160,   161,   138,     2,   115,
      -2,   163,    25,   164,   165,    61,   139,   284,   217,   166,
     285,    44,    90,   262,   254,    63,   -13,   296,     6,   302,
       7,   131,    64,    65,   148,   149,   244,    39,   151,   247,
     193,   288,   322,   140,   141,    50,    50,   142,   210,    47,
      37,    61,   216,   110,     1,    44,   223,    44,     2,   224,
     289,    38,   111,   112,   226,   201,     1,    40,    -2,   158,
       2,    44,   300,   226,   -13,   290,   172,   173,   174,   175,
      20,   325,   326,   266,   337,   312,   198,   295,   113,   120,
     203,   332,   351,   -13,     0,     0,    90,    -2,     1,   336,
       0,   338,     2,   264,     0,   318,   252,     0,   346,    24,
       0,   259,   167,   348,     0,    19,     0,     0,    44,   267,
       0,     0,   268,     0,   270,     0,   299,   102,    25,   275,
       0,   134,     0,    14,     0,   135,     0,    11,    15,     0,
     279,     0,     0,   281,   -12,     0,   304,     0,     0,   136,
     137,     0,     0,     0,     0,     0,     0,    90,     0,   120,
     298,     0,    50,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     303,     0,     0,   309,     0,     0,   280,     0,   139,     0,
     313,   314,     0,     0,    90,     0,     0,   319,     0,   120,
     120,    90,     0,     0,     0,   323,   120,   324,     0,     0,
     120,     0,   120,     0,     0,   140,   141,     0,   331,   142,
     120,     0,   120,     0,     0,   333,     0,    90,     0,     0,
       0,     0,   340,     0,     0,     0,   345,     0,    90,   347,
       0,     0,   143,     0,     0,     0,   150,   352,   152,   153,
       0,     0,     0,     0,     0,    90,    90,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,    90,    90,     0,
       0,     0,     0,    90,    90,    90,     0,     0,    90,     0,
      90,     0,    90,   170,     0,   171,     0,    90,    90,     0,
      90,     0,     0,   176,   249,     0,     0,   200,     0,     0,
     206,    64,   -72,     0,     0,     0,     0,     0,   -72,     0,
       0,     0,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,     0,   228,   229,     0,   231,     0,     0,     0,
       0,     0,     0,   233,   234,     0,   101,     0,     0,     0,
     -92,     0,     0,   -92,   -92,   235,   236,   237,   238,     0,
     -92,   102,     0,     0,   -92,   -92,   -92,   -92,   -92,     0,
       0,     0,     0,   258,     0,     0,   -92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   -92,     0,
       0,     0,     0,   -92,     0,     0,   -92,   183,   184,   185,
     186,   187,   188,   189,     0,     0,     0,     0,   282,   190,
     191,     0,   192,     0,     0,     0,     0,     0,   294,     0,
     -92,     0,   297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,
       0,   -92,   -92,   207,   -92,     0,   315,  -103,     0,     0,
    -103,  -103,     0,     0,     0,     0,     0,  -103,     0,     0,
       0,  -103,  -103,  -103,  -103,   182,     0,     0,     0,     0,
       0,     0,     0,  -103,     0,     0,     0,     0,     0,     0,
     334,     0,     0,     0,   207,  -103,     0,     0,  -104,     0,
    -103,  -104,  -104,  -103,     0,     0,     0,     0,  -104,     0,
       0,     0,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,     0,     0,  -104,     0,     0,  -103,     0,     0,
       0,     0,     0,     0,     0,     0,  -104,     0,     0,     0,
       0,  -104,     0,     0,  -104,     0,  -103,   184,   185,   186,
     187,   188,   189,     0,     0,     0,   207,     0,  -103,  -103,
    -105,  -103,     0,  -105,  -105,     0,     0,     0,  -104,     0,
    -105,     0,     0,     0,  -105,  -105,  -105,  -105,   182,     0,
       0,     0,     0,     0,     0,     0,  -105,   183,   184,   185,
     186,   187,   188,   189,     0,     0,     0,   207,  -105,  -104,
    -104,   -98,  -104,  -105,   -98,   -98,  -105,     0,     0,     0,
       0,   -98,     0,     0,     0,   178,   179,   180,   181,   182,
       0,     0,     0,     0,     0,     0,     0,   -98,     0,     0,
    -105,     0,     0,     0,     0,     0,     0,     0,     0,   -98,
       0,     0,     0,     0,   -98,     0,     0,   -98,     0,  -105,
     184,   185,   186,   187,   188,   189,     0,     0,     0,   207,
       0,  -105,  -105,   -99,  -105,     0,   -99,   -99,     0,     0,
       0,   -98,     0,   -99,     0,     0,     0,   178,   179,   180,
     181,   182,     0,     0,     0,     0,     0,     0,     0,   -99,
     -98,   184,   185,   186,   187,   188,   189,     0,     0,     0,
     207,   -99,   -98,   -98,  -100,   -98,   -99,  -100,  -100,   -99,
       0,     0,     0,     0,  -100,     0,     0,     0,   178,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     0,
    -100,     0,     0,   -99,     0,     0,     0,     0,     0,     0,
       0,     0,  -100,     0,     0,     0,     0,  -100,     0,     0,
    -100,     0,   183,   184,   185,   186,   187,   188,   189,     0,
       0,     0,   207,     0,   190,   191,  -101,   192,     0,  -101,
    -101,     0,     0,     0,  -100,     0,  -101,     0,     0,     0,
     178,   179,   180,   181,   182,     0,     0,     0,     0,     0,
       0,     0,  -101,   183,   184,   185,   186,   187,   188,   189,
       0,     0,     0,   207,  -101,   190,   191,  -102,   192,  -101,
    -102,  -102,  -101,     0,     0,     0,     0,  -102,     0,     0,
     207,   178,   179,   180,   181,   182,     0,     0,  -113,     0,
       0,     0,     0,  -102,  -113,     0,  -101,     0,   178,   179,
     180,   181,   182,     0,     0,  -102,     0,     0,     0,     0,
    -102,     0,     0,  -102,     0,   183,   184,   185,   186,   187,
     188,   189,     0,   222,   207,     0,     0,   190,   191,     0,
     192,     0,  -114,     0,   227,     0,     0,  -102,  -114,     0,
       0,     0,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,   186,
     187,   188,   189,     0,     0,   242,     0,   245,   190,   191,
     248,   192,     0,   183,   184,   185,   186,   187,   188,   189,
       0,   207,     0,     0,     0,   190,   191,     0,   192,     0,
       0,     0,     0,   271,   272,   273,   274,     0,     0,   178,
     179,   180,   181,   182,   276,   278,   177,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   178,   179,   180,   181,   182,   190,
     191,   213,   192,     0,     0,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,    19,
       0,     0,    44,     0,     0,   327,   178,   179,   180,   181,
     182,   102,     0,     0,     0,   134,     0,     0,     0,   135,
       0,     0,     0,   207,   183,   184,   185,   186,   187,   188,
     189,     0,     0,   136,   137,   208,   190,   191,     0,   192,
       0,   178,   179,   180,   181,   182,     0,     0,   207,   183,
     184,   185,   186,   187,   188,   189,     0,     0,     0,     0,
       0,   190,   191,   138,   192,   211,   178,   179,   180,   181,
     182,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   207,     0,
       0,     0,   -91,   190,   191,     0,   192,     0,   213,   140,
     141,     0,     0,   142,     0,   207,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,   183,   184,   185,   186,
     187,   188,   189,   178,   179,   180,   181,   182,   190,   191,
       0,   192,     0,     0,     0,   260,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   241,     0,
       0,     0,     0,   190,   191,     0,   192,     0,     0,     0,
       0,     0,   219,     0,     0,     0,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,     0,     0,   190,   191,     0,   192,     0,   183,   184,
     185,   186,   187,   188,   189,   207,     0,     0,     0,   -90,
     190,   191,     0,   192,   204,     0,     0,    19,     0,     0,
      44,     0,   118,   178,   179,   180,   181,   182,    44,   102,
       0,     0,     0,   134,    70,    71,     0,   135,    72,     0,
       0,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,   136,   137,   190,   191,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
      74,     0,     0,     0,     0,     0,   118,     0,     0,     0,
     305,   138,    44,     0,    75,     0,     0,     0,    70,    71,
     139,     0,    72,     0,     0,    76,     0,     0,   183,   184,
     185,   186,   187,   188,   189,    77,    78,    79,     0,   306,
     190,   191,   -83,   192,     0,     0,     0,   140,   141,    69,
       0,   142,    73,    11,    74,    44,     0,   118,     0,   -83,
       0,    70,    71,    44,     0,    72,     0,     0,    75,    70,
      71,     0,     0,    72,     0,     0,     0,     0,   -83,    76,
       0,   119,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,     0,     0,     0,    73,     0,    74,     0,     0,
       0,   118,     0,    73,     0,    74,     0,    44,     0,     0,
       0,    75,     0,    70,    71,     0,     0,    72,     0,    75,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
      76,   260,    77,    78,    79,     0,     0,     0,     0,     0,
      77,    78,    79,     0,   118,     0,     0,    73,     0,    74,
      44,     0,   118,     0,     0,     0,    70,    71,    44,     0,
      72,     0,     0,    75,    70,    71,     0,     0,    72,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,     0,     0,     0,
      73,     0,    74,     0,     0,   118,   316,     0,    73,     0,
      74,    44,     0,   118,     0,   -86,    75,    70,    71,    44,
       0,    72,     0,     0,    75,    70,    71,    76,     0,    72,
       0,     0,     0,     0,     0,    76,     0,    77,    78,    79,
       0,     0,     0,     0,     0,    77,    78,    79,     0,     0,
       0,    73,     0,    74,     0,     0,     0,     0,   118,    73,
       0,    74,     0,   305,    44,     0,     0,    75,     0,   341,
      70,    71,     0,     0,    72,    75,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    76,     0,    77,    78,
      79,     0,     0,     0,     0,     0,    77,    78,    79,   118,
       0,     0,     0,     0,    73,    44,    74,     0,     0,     0,
       0,    70,    71,   343,     0,    72,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,     0,    73,     0,    74,     0,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-301))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      13,    49,     1,   107,    31,    17,     1,    20,   267,    22,
     301,     6,   154,   174,    62,   315,     1,    12,     1,    32,
       5,    48,    35,    36,     1,     1,     9,     1,     1,    42,
       1,     4,    15,     4,   334,    12,     7,   198,    12,   330,
      16,    54,    18,    56,    80,    16,    59,    60,     1,    20,
       1,     1,    37,    24,     7,    54,     5,     8,     9,     0,
     319,    29,    30,    31,    15,    60,    16,    38,    39,    82,
      83,    84,    85,    86,    87,    88,    89,     1,     1,    92,
      48,   157,   158,    60,    79,     1,    99,    55,    57,    58,
       5,    15,     8,   169,     1,   108,   109,    68,     5,    67,
       7,   114,    79,   116,   117,     1,    77,   104,   156,   121,
     252,     7,    80,   217,    37,     1,    12,   259,     1,   282,
       3,    90,     8,     9,    93,    94,   202,    26,    96,   205,
     143,    54,   104,   104,   105,   103,   104,   108,   151,     1,
       1,     1,   155,     1,     1,     7,   159,     7,     5,   162,
      73,    12,    10,    11,   230,     1,     1,    26,     3,   104,
       5,     7,   266,   239,    60,   255,   135,   136,   137,   138,
      10,   313,   314,   221,   332,   291,   145,   258,    36,   215,
     148,   323,   348,    79,    -1,    -1,   154,     0,     1,   331,
      -1,   333,     5,   220,    -1,   299,   209,    -1,   340,    60,
      -1,   214,     1,   345,    -1,     4,    -1,    -1,     7,   222,
      -1,    -1,   225,    -1,   227,    -1,   264,    16,    79,   232,
      -1,    20,    -1,     1,    -1,    24,    -1,     5,     6,    -1,
     243,    -1,    -1,   246,    12,    -1,   284,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,   285,
     263,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
     283,    -1,    -1,   286,    -1,    -1,   244,    -1,    77,    -1,
     293,   294,    -1,    -1,   252,    -1,    -1,   300,    -1,   325,
     326,   259,    -1,    -1,    -1,   308,   332,   310,    -1,    -1,
     336,    -1,   338,    -1,    -1,   104,   105,    -1,   321,   108,
     346,    -1,   348,    -1,    -1,   328,    -1,   285,    -1,    -1,
      -1,    -1,   335,    -1,    -1,    -1,   339,    -1,   296,   342,
      -1,    -1,    91,    -1,    -1,    -1,    95,   350,    97,    98,
      -1,    -1,    -1,    -1,    -1,   313,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,   325,   326,    -1,
      -1,    -1,    -1,   331,   332,   333,    -1,    -1,   336,    -1,
     338,    -1,   340,   132,    -1,   134,    -1,   345,   346,    -1,
     348,    -1,    -1,   142,     1,    -1,    -1,   146,    -1,    -1,
     149,     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,    -1,     1,    -1,    -1,    -1,
       5,    -1,    -1,     8,     9,   194,   195,   196,   197,    -1,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,   247,   106,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      75,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,   106,   107,     1,   109,    -1,   295,     5,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     329,    -1,    -1,    -1,     1,    43,    -1,    -1,     5,    -1,
      48,     8,     9,    51,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,     1,    -1,   106,   107,
       5,   109,    -1,     8,     9,    -1,    -1,    -1,    75,    -1,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,     1,    43,   106,
     107,     5,   109,    48,     8,     9,    51,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,     1,
      -1,   106,   107,     5,   109,    -1,     8,     9,    -1,    -1,
      -1,    75,    -1,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
       1,    43,   106,   107,     5,   109,    48,     8,     9,    51,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,     1,    -1,   106,   107,     5,   109,    -1,     8,
       9,    -1,    -1,    -1,    75,    -1,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,     1,    43,   106,   107,     5,   109,    48,
       8,     9,    51,    -1,    -1,    -1,    -1,    15,    -1,    -1,
       1,    19,    20,    21,    22,    23,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    31,    15,    -1,    75,    -1,    19,    20,
      21,    22,    23,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    94,    95,    96,    97,    98,
      99,   100,    -1,   158,     1,    -1,    -1,   106,   107,    -1,
     109,    -1,     9,    -1,   169,    -1,    -1,    75,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   200,    -1,   202,   106,   107,
     205,   109,    -1,    94,    95,    96,    97,    98,    99,   100,
      -1,     1,    -1,    -1,    -1,   106,   107,    -1,   109,    -1,
      -1,    -1,    -1,   228,   229,   230,   231,    -1,    -1,    19,
      20,    21,    22,    23,   239,   240,     1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,    19,    20,    21,    22,    23,   106,
     107,    51,   109,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,     4,
      -1,    -1,     7,    -1,    -1,    75,    19,    20,    21,    22,
      23,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,     1,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    38,    39,    48,   106,   107,    -1,   109,
      -1,    19,    20,    21,    22,    23,    -1,    -1,     1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,   106,   107,    68,   109,    43,    19,    20,    21,    22,
      23,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,     1,    -1,
      -1,    -1,     5,   106,   107,    -1,   109,    -1,    51,   104,
     105,    -1,    -1,   108,    -1,     1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,    19,    20,    21,    22,    23,   106,   107,
      -1,   109,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,     1,    -1,
      -1,    -1,    -1,   106,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,   106,   107,    -1,   109,    -1,    94,    95,
      96,    97,    98,    99,   100,     1,    -1,    -1,    -1,     5,
     106,   107,    -1,   109,     1,    -1,    -1,     4,    -1,    -1,
       7,    -1,     1,    19,    20,    21,    22,    23,     7,    16,
      -1,    -1,    -1,    20,    13,    14,    -1,    24,    17,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    38,    39,   106,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      59,    68,     7,    -1,    63,    -1,    -1,    -1,    13,    14,
      77,    -1,    17,    -1,    -1,    74,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,    84,    85,    86,    -1,    88,
     106,   107,    37,   109,    -1,    -1,    -1,   104,   105,     1,
      -1,   108,    47,     5,    49,     7,    -1,     1,    -1,    54,
      -1,    13,    14,     7,    -1,    17,    -1,    -1,    63,    13,
      14,    -1,    -1,    17,    -1,    -1,    -1,    -1,    73,    74,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,
      -1,     1,    -1,    47,    -1,    49,    -1,     7,    -1,    -1,
      -1,    63,    -1,    13,    14,    -1,    -1,    17,    -1,    63,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    31,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    -1,     1,    -1,    -1,    47,    -1,    49,
       7,    -1,     1,    -1,    -1,    -1,    13,    14,     7,    -1,
      17,    -1,    -1,    63,    13,    14,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    -1,    -1,    -1,
      47,    -1,    49,    -1,    -1,     1,    53,    -1,    47,    -1,
      49,     7,    -1,     1,    -1,    54,    63,    13,    14,     7,
      -1,    17,    -1,    -1,    63,    13,    14,    74,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,    -1,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,     1,    47,
      -1,    49,    -1,    59,     7,    -1,    -1,    63,    -1,    57,
      13,    14,    -1,    -1,    17,    63,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,     1,
      -1,    -1,    -1,    -1,    47,     7,    49,    -1,    -1,    -1,
      -1,    13,    14,    56,    -1,    17,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    -1,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,   119,   120,   121,     1,     3,   122,   124,
     173,     5,     0,   123,     1,     6,   125,   176,     1,     4,
     174,   120,   126,     1,    60,    79,   133,   135,   138,   183,
     191,   119,   175,   120,   120,   134,   137,     1,    12,   135,
     138,   141,   188,     1,     7,   179,   179,     1,   127,   129,
     179,   120,   120,   120,   189,   120,   180,   136,   139,   128,
     130,     1,   129,     1,     8,     9,   177,   181,   120,     1,
      13,    14,    17,    47,    49,    63,    74,    84,    85,    86,
     142,   144,   146,   149,   154,   155,   160,   161,   162,   163,
     179,   194,   195,   196,   197,   198,   202,   207,   213,   215,
     120,     1,    16,   184,   184,   120,   120,   177,   178,   182,
       1,    10,    11,    36,   131,   179,   143,   145,     1,    25,
     144,   193,   120,   120,   120,   120,   120,   120,   120,   120,
      18,   184,   216,     1,    20,    24,    38,    39,    68,    77,
     104,   105,   108,   164,   174,   179,   184,   120,   184,   184,
     164,   179,   164,   164,   120,   185,   129,   140,   140,   131,
     120,   120,   132,   120,   120,   120,   119,     1,   164,   166,
     164,   164,   184,   184,   184,   184,   164,     1,    19,    20,
      21,    22,    23,    94,    95,    96,    97,    98,    99,   100,
     106,   107,   109,   120,   168,   170,   171,   172,   184,     1,
     164,     1,   147,   179,     1,   150,   164,     1,    48,   199,
     120,    43,   209,    51,   210,   142,   120,   177,     1,    15,
     181,   186,   186,   120,   120,   167,   181,   186,   164,   164,
     166,   164,   169,   164,   164,   164,   164,   164,   164,   166,
     165,     1,   186,   148,   181,   186,   151,   181,   186,     1,
     152,   177,   120,     1,    37,   156,   157,   205,   164,   120,
      31,   208,   131,   187,   129,     1,   177,   120,   120,   164,
     120,   186,   186,   186,   186,   120,   186,     1,   186,   120,
     179,   120,   164,   153,   104,   142,   158,     1,    54,    73,
     157,   159,   203,   206,   164,   208,   142,   164,   120,   177,
     131,   125,   152,   120,   177,    59,    88,   200,   201,   120,
     204,     1,   203,   120,   120,   164,    53,   214,   131,   120,
       1,   188,   104,   120,   120,   142,   142,    75,   210,   212,
     125,   120,   142,   120,   164,   188,   142,   200,   142,   210,
     120,    57,   192,    56,   211,   120,   142,   120,   142,    55,
     190,   211,   120
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1806 of yacc.c  */
#line 140 "hopper.y"
    {erros++; yyerror("Esperava quebra de linha, encontrou: ", yylineno, yytext);}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 147 "hopper.y"
    {var_escopo = "__GLOBAL__";}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 152 "hopper.y"
    {erros++; yyerror("Ordem inválida dos blocos, encontrou: ", yylineno, yytext);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 163 "hopper.y"
    {erros++; yyerror("Variável Inválida ", yylineno, yytext);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 170 "hopper.y"
    {erros++; yyerror("Declaracao de variável inválida: ", yylineno, yytext);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 175 "hopper.y"
    {/*push(Fila, $3);*/}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 176 "hopper.y"
    {erros++; yyerror("Nome de variavel Inválido: ", yylineno, yytext);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 181 "hopper.y"
    {
		var_tipo = "real";		
		elementofila **elemento_fila;
		
		/*while(pop(Fila, elemento_fila) == 1)
		{
		
		}*/
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 190 "hopper.y"
    {var_tipo = "inteiro";}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 191 "hopper.y"
    {var_tipo = "caractere";}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 192 "hopper.y"
    {erros++; yyerror("Tipo de dados Inválido: ", yylineno, yytext);}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 201 "hopper.y"
    {erros++; yyerror("Subprograma mal-estruturado, token nao esperado: ", yylineno, yytext);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 205 "hopper.y"
    {var_escopo = (yyvsp[(2) - (2)]);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 206 "hopper.y"
    {var_escopo = "__GLOBAL__";}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 207 "hopper.y"
    {erros++; yyerror("Estrutura da funcão inválida, token nao esperado: ", yylineno, yytext);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 211 "hopper.y"
    {var_escopo = (yyvsp[(2) - (2)]);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 212 "hopper.y"
    {var_escopo = "__GLOBAL__";}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 227 "hopper.y"
    {erros++; yyerror("Comando não esperado: ", yylineno, yytext);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 242 "hopper.y"
    {erros++; yyerror("Comando inválido: ", yylineno, yytext);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 252 "hopper.y"
    {erros++; yyerror("Parâmetro inválido no LEIA, token nao esperado: ", yylineno, yytext);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 262 "hopper.y"
    {erros++; yyerror("Parâmetros inválidos no ESCREVA, token invalido: ", yylineno, yytext);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 269 "hopper.y"
    {erros++; yyerror("Formatacao de casas decimais inválidas", yylineno, yytext);}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 289 "hopper.y"
    {erros++; yyerror("Estrutura Caso invalida, token desconhecido: ", yylineno, yytext);}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 333 "hopper.y"
    {erros++; yyerror("Expressao inválida", yylineno, yytext);}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 339 "hopper.y"
    {erros++; yyerror("Expressao invalida: ", yylineno, yytext);}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 352 "hopper.y"
    {erros++; yyerror("Esperava + ou -, encontrado: ", yylineno, yytext);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 382 "hopper.y"
    {erros++; yyerror("Formato de String inválido ", yylineno, yytext);}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 393 "hopper.y"
    {erros++; yyerror("Esperava ':', encontrou: ", yylineno, yytext);}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 398 "hopper.y"
    {erros++; yyerror("Nome nao segue as regras de criacao, consulte as referencias: ", yylineno, yytext);}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 403 "hopper.y"
    {erros++; yyerror("Esperava ',' encontrou: ", yylineno, yytext);}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 412 "hopper.y"
    {erros++; yyerror("Esperava '(', encontrou: ", yylineno, yytext);}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 417 "hopper.y"
    {erros++; yyerror("Esperava ')', encontrou: ", yylineno, yytext);}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 422 "hopper.y"
    {erros++; yyerror("Esperava INICIO, encontrou: ", yylineno, yytext);}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 481 "hopper.y"
    {erros++; yyerror("Esperava FIMESCOLHA, encontrado: ", yylineno, yytext);}
    break;



/* Line 1806 of yacc.c  */
#line 2483 "hopper.tab.c"
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 2067 of yacc.c  */
#line 532 "hopper.y"


int main(int ac, char **av) {
		
	extern FILE *yyin;
	
	//cria_fila(Fila);
		
	if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
		perror(av[1]);
		exit(1);
	}
	
	yyparse();

	if(!erros)
		printf("O algoritmo é valido!\n");
	else
	{
		printf("\n\nExistem erros no algoritmo.\n");		
	}	
}

int yyerror(char *s, int line, char *msg )
{
  printf ("ERRO->%d %s %s\n", line, s, msg ); 
  return 0;
}

int yywrap(void)
{
  return 1;
}

