/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "hopper.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila/fila.c"
#include "var/var.c"
#include "hash/hash.h"

#define YYSTYPE char*
#define GLOBAL "__GLOBAL__"

fila_var fila_variavel;
filaError fila_erros;
filaTraducao fila_traducao;

int erros;
extern int yylineno;
extern char *yytext;

char *var_nome;
char *var_escopo;
char *var_tipo;
char *c;
char *tipo;
char leiaTipos[256];
char leiaVariaveis[256];

void cadastrar_variavel(char var_tipo[50])
{
	elementofila_var *elemento_fila_var;
	push_traducao(&fila_traducao,var_tipo);
	while(pop_var(&fila_variavel, &elemento_fila_var) == 1)
	{
		if(hash_consultar(elemento_fila_var->token, var_escopo) == 0)
		{
			hash_inserir(elemento_fila_var->token, var_escopo, var_tipo);
		}
		else
		{
			erros++;
			strcat(elemento_fila_var->token, " ");
			strcat(elemento_fila_var->token, var_escopo);				
			yyerror("Variável já declarada: ", yylineno, elemento_fila_var->token);		
		}
		push_traducao(&fila_traducao,elemento_fila_var->token);
		if(elemento_fila_var->prox!=NULL)
		  push_traducao(&fila_traducao,",");
	}
	push_traducao(&fila_traducao,";");
	
}

void verificar_variavel(char variavel[50])
{
	if (hash_consultar(variavel, var_escopo) == 0)
	{
		if (hash_consultar(variavel, GLOBAL) == 0)
		{
			erros++;
			strcat(variavel, " ");
			strcat(variavel, var_escopo);				
			yyerror("Variável não declarada: ", yylineno, variavel);
		}
	}	
}


/* Line 371 of yacc.c  */
#line 137 "hopper.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "hopper.tab.h".  */
#ifndef YY_YY_HOPPER_TAB_H_INCLUDED
# define YY_YY_HOPPER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
     NEG = 366
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

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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

#endif /* !YY_YY_HOPPER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 327 "hopper.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  112
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   366

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
     105,   106,   107,   108,   109,   110,   111
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    12,    16,    21,
      25,    29,    31,    33,    34,    38,    40,    41,    45,    50,
      56,    58,    60,    62,    66,    68,    70,    72,    74,    76,
      78,    80,    82,    85,    88,    89,   105,   106,   120,   124,
     130,   136,   138,   141,   144,   147,   150,   153,   156,   159,
     162,   165,   171,   175,   178,   180,   181,   182,   189,   190,
     193,   197,   198,   204,   207,   212,   213,   216,   221,   223,
     230,   240,   242,   244,   246,   248,   250,   251,   259,   261,
     264,   269,   270,   274,   285,   298,   305,   311,   312,   317,
     319,   321,   323,   325,   327,   331,   335,   339,   343,   347,
     351,   355,   359,   363,   367,   371,   375,   379,   383,   387,
     390,   393,   397,   402,   407,   412,   417,   422,   423,   428,
     430,   434,   436,   438
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     115,     0,    -1,    -1,   114,    -1,     5,    -1,   114,     5,
      -1,    -1,   113,   116,   117,    -1,   118,   120,   128,   134,
      -1,   118,   120,   134,    -1,   119,     4,   114,    -1,     3,
      -1,     1,    -1,    -1,   121,   113,   123,    -1,     6,    -1,
      -1,     1,   122,     5,    -1,   125,   124,   127,   114,    -1,
     123,   125,     8,   127,   114,    -1,     8,    -1,     1,    -1,
     163,    -1,   125,   126,   163,    -1,     9,    -1,     1,    -1,
      10,    -1,    11,    -1,    36,    -1,     1,    -1,   129,    -1,
     131,    -1,   128,   129,    -1,   128,   131,    -1,    -1,    60,
     163,   130,    16,   133,    15,   124,   127,   114,   120,    12,
     114,   135,    55,   114,    -1,    -1,    79,   163,   132,    16,
     133,    15,   114,   120,    12,   114,   135,    57,   114,    -1,
     125,   124,   127,    -1,   133,   126,   125,   124,   127,    -1,
      12,   114,   135,    25,   113,    -1,   136,    -1,   135,   136,
      -1,   137,   114,    -1,   142,   114,    -1,   158,   114,    -1,
     146,   114,    -1,   150,   114,    -1,   155,   114,    -1,   156,
     114,    -1,   157,   114,    -1,   163,    16,   162,    15,   114,
      -1,    85,   160,   114,    -1,    63,   114,    -1,     1,    -1,
      -1,    -1,    17,   138,    16,   139,   140,    15,    -1,    -1,
     163,   141,    -1,   140,   126,   163,    -1,    -1,   164,    16,
     143,   144,    15,    -1,   160,   145,    -1,   144,     9,   160,
     145,    -1,    -1,   124,   104,    -1,   124,   104,   124,   104,
      -1,     1,    -1,   147,   160,   149,   114,   135,   148,    -1,
     147,   160,   149,   114,   135,    88,   114,   135,   148,    -1,
      86,    -1,    59,    -1,     1,    -1,    48,    -1,     1,    -1,
      -1,    49,   163,   151,   114,   152,   154,    54,    -1,   153,
      -1,   152,   153,    -1,    37,   160,   114,   135,    -1,    -1,
      73,   114,   135,    -1,    74,   160,    43,   160,    31,   160,
      51,   114,   135,    56,    -1,    74,   160,    43,   160,    31,
     160,    75,   160,    51,   114,   135,    56,    -1,    47,   160,
      51,   114,   135,    53,    -1,    84,   114,   135,    31,   160,
      -1,    -1,   163,   159,    18,   160,    -1,   163,    -1,   104,
      -1,   105,    -1,    77,    -1,     4,    -1,    16,   160,    15,
      -1,   160,    94,   160,    -1,   160,    19,   160,    -1,   160,
      20,   160,    -1,   160,    21,   160,    -1,   160,    22,   160,
      -1,   160,   106,   160,    -1,   160,   109,   160,    -1,   160,
     107,   160,    -1,   160,    95,   160,    -1,   160,    96,   160,
      -1,   160,    97,   160,    -1,   160,    98,   160,    -1,   160,
      99,   160,    -1,   160,   100,   160,    -1,    20,   160,    -1,
     108,   160,    -1,   160,    23,   160,    -1,    24,    16,   160,
      15,    -1,    68,    16,   160,    15,    -1,    38,    16,   160,
      15,    -1,   163,    16,   162,    15,    -1,    39,    16,   162,
      15,    -1,    -1,    16,     1,   161,    15,    -1,   160,    -1,
     162,     9,   160,    -1,     7,    -1,    13,    -1,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   124,   128,   129,   136,   136,   140,   141,
     145,   149,   151,   154,   156,   160,   161,   161,   166,   167,
     171,   172,   176,   177,   181,   182,   187,   188,   189,   190,
     194,   195,   196,   197,   201,   201,   207,   207,   212,   213,
     217,   221,   222,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   241,   241,   241,   245,   245,
     246,   250,   250,   254,   255,   258,   260,   261,   262,   267,
     268,   272,   276,   277,   281,   282,   286,   286,   290,   291,
     295,   298,   300,   304,   305,   309,   313,   317,   317,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   349,   353,
     354,   358,   362,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "T_OP_LOGICO_NAO", "T_OP_LOGICO_OU", "T_INVALIDO", "NEG", "$accept",
  "QuebraComando", "FimComando", "Input", "$@1", "Algoritmo",
  "BlocoCabecalho", "T_Algoritmo", "BlocoDeclaracoes", "T_Var", "$@2",
  "ListaDeclaracoes", "T_Tipo_Atribuidor", "ListaVariaveis",
  "T_Ident_Separador", "TipoVariavel", "BlocoFuncoes", "BlocoFuncao",
  "$@3", "BlocoProcedimento", "$@4", "ListaParametros", "BlocoComando",
  "Comandos", "Comando", "Leia", "$@5", "$@6", "ListaLeia", "$@7",
  "Escreva", "$@8", "ConteudoEscreva", "OpcaoCasasDecimais", "BlocoSe",
  "T_Se", "T_FimSe", "T_Entao", "BlocoEscolha", "$@9", "ListaCasos",
  "Caso", "OutroCaso", "BlocoPara", "BlocoEnquanto", "BlocoRepita",
  "Atribuicao", "$@10", "Expr", "$@11", "List_Expr", "T_Identificador",
  "T_Escreva", YY_NULL
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
     365,   366
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   112,   113,   113,   114,   114,   116,   115,   117,   117,
     118,   119,   119,   120,   120,   121,   122,   121,   123,   123,
     124,   124,   125,   125,   126,   126,   127,   127,   127,   127,
     128,   128,   128,   128,   130,   129,   132,   131,   133,   133,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   138,   139,   137,   141,   140,
     140,   143,   142,   144,   144,   145,   145,   145,   145,   146,
     146,   147,   148,   148,   149,   149,   151,   150,   152,   152,
     153,   154,   154,   155,   155,   156,   157,   159,   158,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   160,   162,
     162,   163,   164,   164
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     0,     3,     4,     3,
       3,     1,     1,     0,     3,     1,     0,     3,     4,     5,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     0,    15,     0,    13,     3,     5,
       5,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     3,     2,     1,     0,     0,     6,     0,     2,
       3,     0,     5,     2,     4,     0,     2,     4,     1,     6,
       9,     1,     1,     1,     1,     1,     0,     7,     1,     2,
       4,     0,     3,    10,    12,     6,     5,     0,     4,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     4,     4,     4,     4,     4,     0,     4,     1,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     6,     3,     0,     0,     5,     1,    12,    11,
       7,     0,     0,    16,    15,     0,     2,     0,     0,     0,
       0,     0,     0,    30,    31,     9,     0,    10,    17,     0,
     121,    34,    36,    32,    33,     8,    14,     0,    22,    54,
     122,   123,    55,     0,     0,     0,     0,     0,     0,    71,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,    21,    20,    24,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,    92,
      90,    91,     0,     0,    89,    76,    53,     0,     0,     0,
       2,    42,    43,    44,    46,     0,    47,    48,    49,    50,
      45,     0,     0,    61,     0,     0,    25,     0,    29,    26,
      27,    28,     0,    23,    56,   117,     0,   109,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    40,    75,    74,     0,   119,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,    94,
       0,     0,     0,     0,    96,    97,    98,    99,   111,     0,
      95,   103,   104,   105,   106,   107,   108,   100,   102,   101,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,    19,     0,    58,   118,   112,   114,
     116,   113,     0,   115,     0,    81,    78,     0,    86,     0,
     120,    51,     0,    62,    68,     0,    63,    38,    21,     0,
       0,     0,    57,     0,    59,    85,     0,     0,    79,     0,
       0,    54,    72,     0,    69,     0,     0,     0,     0,     0,
      60,     0,     0,    77,     0,     0,     0,    64,     0,     0,
      39,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,    70,     0,     0,    83,     0,     0,     0,     0,
       0,    37,    84,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    10,    11,    12,    15,    16,
      18,    36,   215,   152,    70,   112,    22,    23,    63,    24,
      64,   153,    25,    50,    51,    52,    71,   157,   195,   224,
      53,   151,   188,   216,    54,    55,   234,   147,    56,   140,
     205,   206,   229,    57,    58,    59,    60,   102,   148,   158,
     149,    84,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -206
static const yytype_int16 yypact[] =
{
      24,  -206,  -206,    41,    54,    97,  -206,  -206,  -206,  -206,
    -206,     6,    67,  -206,  -206,    -4,    24,    24,    79,    24,
      84,    84,    -4,  -206,  -206,  -206,    84,    41,  -206,   757,
    -206,  -206,  -206,  -206,  -206,  -206,    84,   105,  -206,  -206,
    -206,  -206,  -206,   373,    84,    24,   373,    24,   373,  -206,
     802,  -206,    24,    24,    24,   373,    24,    24,    24,    24,
      24,    94,   104,   106,   108,   118,    96,  -206,  -206,    23,
      84,   109,  -206,    44,   373,   112,   113,   115,   116,  -206,
    -206,  -206,   373,   514,   119,  -206,    41,   531,   757,   310,
      24,  -206,    41,    41,    41,   339,    41,    41,    41,    41,
      41,   373,   126,  -206,    84,    84,  -206,    23,  -206,  -206,
    -206,  -206,    24,  -206,  -206,  -206,   363,   122,   373,   373,
     373,   373,   774,   373,   373,   373,   373,   373,    24,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
      24,   373,   831,    41,  -206,  -206,  -206,    24,   576,    48,
     373,   373,   105,    77,    87,    24,    41,    84,   121,  -206,
     403,   432,    52,   464,     4,     4,   122,   122,   122,   757,
     120,     0,     0,     0,     0,     0,     0,   774,   638,   613,
      65,    10,   556,   373,   757,   373,    24,   576,    72,   257,
      23,    30,    84,    24,    41,    92,  -206,  -206,  -206,  -206,
    -206,  -206,   846,  -206,   373,   -20,  -206,   373,   576,   714,
     576,    41,   373,  -206,    42,    43,  -206,  -206,  -206,    23,
     105,   103,  -206,    84,  -206,  -206,   310,    24,  -206,    99,
     494,   145,  -206,    24,  -206,   257,    61,    24,    23,   139,
    -206,   757,   757,  -206,    24,   373,   757,  -206,    50,   103,
    -206,    24,   738,   889,   757,   596,   897,  -206,   144,   757,
     940,    24,  -206,    24,   948,  -206,   757,   757,    24,   993,
    1034,    41,  -206,    24,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,   -13,   -17,  -206,  -206,  -206,  -206,  -206,  -205,  -206,
    -206,  -206,   -36,   -22,  -143,  -101,  -206,   136,  -206,   137,
    -206,    55,   143,   -79,   -45,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,   -74,  -206,  -206,   -90,  -206,  -206,  -206,
    -206,   -37,  -206,  -206,  -206,  -206,  -206,  -206,   187,  -206,
    -107,    29,  -206
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -83
static const yytype_int16 yytable[] =
{
      27,    69,    29,    26,    37,    91,   155,    13,    19,   142,
     192,   192,    14,   162,    65,     6,   239,   204,   -13,   123,
     124,   125,   126,   127,   108,   125,   126,   127,    86,     1,
      88,   218,   180,   109,   110,    92,    93,    94,    67,    96,
      97,    98,    99,   100,   258,   115,     6,   204,    72,    31,
      32,    30,   223,   227,     7,    38,    20,   185,    61,   111,
      73,   185,   218,   186,    74,    38,   -13,   200,    75,    67,
     -66,    17,   143,    85,   185,    21,   -66,   144,   106,    61,
     203,   212,    76,    77,    28,   -13,    68,   213,   106,   217,
     202,    30,   191,   106,   129,   156,    68,    91,     8,   113,
       9,    68,   193,   -25,    13,   209,    66,   222,     6,    14,
     101,   169,    78,    67,    68,   -13,   190,    61,   237,   106,
     103,    79,   104,   181,   105,   114,   107,    68,   118,   119,
     184,   120,   121,    38,    38,   139,   197,   250,   194,   123,
     124,   125,   126,   127,   150,   127,   -21,   236,    80,    81,
     -73,   251,    82,   243,   257,   219,   263,    91,    33,    34,
     154,   247,   252,   253,    91,    35,   262,   256,   228,   211,
     220,    61,     0,     0,     0,   260,   221,     0,     0,     0,
     264,     0,     0,     0,   238,     0,   196,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
     248,     0,     0,     0,     0,     0,     0,    91,    91,   241,
     242,    91,     0,    61,     0,    91,   246,     0,     0,    91,
     249,    38,     0,     0,    91,    91,     0,   254,     0,     0,
      83,    61,     0,    87,   259,    89,     0,     0,    61,     0,
       0,     0,    95,     0,   266,     0,   267,     0,     0,     0,
       0,   271,   240,     0,     0,     0,   274,     0,   214,     0,
     116,   117,     0,     0,     0,    67,   -65,     0,     0,   122,
      61,    61,   -65,     0,     0,    61,   123,   124,   125,   126,
     127,    61,    61,    61,     0,    61,     0,     0,    61,    61,
       0,     0,     0,    61,     0,    61,    61,     0,    61,    61,
       0,     0,     0,     0,     0,   160,   161,     0,   163,     0,
     164,   165,   166,   167,   168,     1,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,   182,   123,
     124,   125,   126,   127,     0,     0,     0,   187,   189,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,   134,   135,   123,   124,
     125,   126,   127,   136,   137,     0,   138,     0,     0,     0,
     208,     0,   210,     0,     0,     0,     0,    72,   159,     0,
      30,     0,   123,   124,   125,   126,   127,   146,     0,    73,
       0,   226,     0,    74,   230,     0,     0,    75,     0,   235,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,    76,    77,     0,     0,     0,   136,   137,   198,   138,
       0,     0,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,   255,   129,   130,   131,   132,   133,   134,   135,
       0,    78,     0,     0,     0,   136,   137,   199,   138,     0,
      79,   123,   124,   125,   126,   127,     0,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
     137,     0,   138,     0,     0,     0,     0,    80,    81,   201,
       0,    82,     0,   123,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
     137,     0,   138,   123,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
     133,   134,   135,   123,   124,   125,   126,   127,   136,   137,
       0,   138,     0,     0,     0,   244,     0,     0,     0,     0,
     123,   124,   125,   126,   127,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   135,   128,     0,     0,     0,   245,
     136,   137,     0,   138,   141,   123,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,     0,   207,   129,   130,
     131,   132,   133,   134,   135,   123,   124,   125,   126,   127,
     136,   137,     0,   138,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   135,   123,   124,   125,   126,   127,
     136,   137,     0,   138,     0,   129,   130,   131,   132,   133,
     134,   135,   123,   124,   125,   126,   127,   136,   137,     0,
     138,     0,     0,     0,     0,     0,     0,   261,     0,     0,
     129,   130,   131,   132,   133,   134,   135,   123,   124,   125,
     126,   127,   136,   137,     0,   138,     0,     0,     0,     0,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,   136,   137,     0,   138,     0,     0,     0,     0,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,   136,   137,     0,   138,     0,   129,   130,   131,
     132,   133,   134,   135,     0,   231,     0,     0,     0,   136,
     137,    30,     0,     0,     0,     0,     0,    40,    41,     0,
       0,    42,   129,   130,   131,   132,   133,   134,   135,    39,
       0,     0,     0,     0,   136,    30,     0,     0,     0,     0,
       0,    40,    41,     0,     0,    42,     0,     0,    39,     0,
       0,    43,     6,    44,    30,     0,     0,     0,     0,     0,
      40,    41,     0,   232,    42,   -80,     0,    45,     0,     0,
       0,     0,     0,     0,     0,    43,     0,    44,    46,     0,
       0,     0,   -80,   123,   124,   125,   126,   127,    47,    48,
      49,    45,   233,    39,    43,     0,    44,     0,     0,    30,
       0,   -80,    46,     0,     0,    40,    41,     0,     0,    42,
      45,     0,    47,    48,    49,     0,     0,    90,     0,     0,
       0,    46,    39,     0,     0,     0,     0,     0,    30,     0,
       0,    47,    48,    49,    40,    41,     0,    39,    42,    43,
       0,    44,     0,    30,     0,     0,     0,     0,     0,    40,
      41,     0,   183,    42,     0,    45,     0,     0,   129,   130,
     131,   132,   133,   134,   135,     0,    46,     0,    43,     0,
      44,     0,     0,     0,     0,     0,    47,    48,    49,     0,
      39,     0,     0,    43,    45,    44,    30,     0,   231,   225,
       0,     0,    40,    41,    30,    46,    42,     0,     0,    45,
      40,    41,     0,     0,    42,    47,    48,    49,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,     0,     0,     0,    43,     0,    44,     0,
       0,    39,     0,   -82,    43,     0,    44,    30,     0,    39,
       0,     0,    45,    40,    41,    30,   232,    42,     0,     0,
      45,    40,    41,    46,     0,    42,     0,     0,     0,     0,
       0,    46,     0,    47,    48,    49,     0,     0,     0,     0,
       0,    47,    48,    49,     0,     0,     0,    43,     0,    44,
       0,     0,     0,     0,    39,    43,   265,    44,     0,     0,
      30,     0,     0,    45,     0,   268,    40,    41,     0,     0,
      42,    45,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,    48,    49,     0,     0,     0,
       0,     0,    47,    48,    49,    39,     0,     0,     0,     0,
      43,    30,    44,     0,     0,     0,     0,    40,    41,   272,
       0,    42,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,    49,
       0,    43,     0,    44,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      49
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-206)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      17,    37,    19,    16,    26,    50,   107,     1,    12,    88,
     153,   154,     6,   120,    36,     5,   221,    37,    12,    19,
      20,    21,    22,    23,     1,    21,    22,    23,    45,     5,
      47,     1,   139,    10,    11,    52,    53,    54,     8,    56,
      57,    58,    59,    60,   249,     1,     5,    37,     4,    20,
      21,     7,   195,    73,     0,    26,    60,     9,    29,    36,
      16,     9,     1,    15,    20,    36,    60,    15,    24,     8,
       9,     4,    89,    44,     9,    79,    15,    90,     1,    50,
      15,     9,    38,    39,     5,    79,     9,    15,     1,   190,
     169,     7,    15,     1,    94,   112,     9,   142,     1,    70,
       3,     9,    15,     7,     1,   184,     1,    15,     5,     6,
      16,   128,    68,     8,     9,    12,   152,    88,   219,     1,
      16,    77,    16,   140,    16,    16,     8,     9,    16,    16,
     147,    16,    16,   104,   105,    16,    15,   238,   155,    19,
      20,    21,    22,    23,    18,    23,   104,   104,   104,   105,
       5,    12,   108,    54,   104,   191,    12,   202,    22,    22,
     105,   235,   241,   242,   209,    22,   256,   246,   205,   186,
     192,   142,    -1,    -1,    -1,   254,   193,    -1,    -1,    -1,
     259,    -1,    -1,    -1,   220,    -1,   157,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,   226,
     227,   256,    -1,   184,    -1,   260,   233,    -1,    -1,   264,
     237,   192,    -1,    -1,   269,   270,    -1,   244,    -1,    -1,
      43,   202,    -1,    46,   251,    48,    -1,    -1,   209,    -1,
      -1,    -1,    55,    -1,   261,    -1,   263,    -1,    -1,    -1,
      -1,   268,   223,    -1,    -1,    -1,   273,    -1,     1,    -1,
      73,    74,    -1,    -1,    -1,     8,     9,    -1,    -1,    82,
     241,   242,    15,    -1,    -1,   246,    19,    20,    21,    22,
      23,   252,   253,   254,    -1,   256,    -1,    -1,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,   267,    -1,   269,   270,
      -1,    -1,    -1,    -1,    -1,   118,   119,    -1,   121,    -1,
     123,   124,   125,   126,   127,     5,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,   141,    19,
      20,    21,    22,    23,    -1,    -1,    -1,   150,   151,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,    19,    20,
      21,    22,    23,   106,   107,    -1,   109,    -1,    -1,    -1,
     183,    -1,   185,    -1,    -1,    -1,    -1,     4,    15,    -1,
       7,    -1,    19,    20,    21,    22,    23,    48,    -1,    16,
      -1,   204,    -1,    20,   207,    -1,    -1,    24,    -1,   212,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,    38,    39,    -1,    -1,    -1,   106,   107,    15,   109,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,   245,    94,    95,    96,    97,    98,    99,   100,
      -1,    68,    -1,    -1,    -1,   106,   107,    15,   109,    -1,
      77,    19,    20,    21,    22,    23,    -1,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,   106,
     107,    -1,   109,    -1,    -1,    -1,    -1,   104,   105,    15,
      -1,   108,    -1,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,   106,
     107,    -1,   109,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,    19,    20,    21,    22,    23,   106,   107,
      -1,   109,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,    51,    -1,    -1,    -1,    75,
     106,   107,    -1,   109,    43,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    94,    95,
      96,    97,    98,    99,   100,    19,    20,    21,    22,    23,
     106,   107,    -1,   109,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,    19,    20,    21,    22,    23,
     106,   107,    -1,   109,    -1,    94,    95,    96,    97,    98,
      99,   100,    19,    20,    21,    22,    23,   106,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,    19,    20,    21,
      22,    23,   106,   107,    -1,   109,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,   106,   107,    -1,   109,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,   106,   107,    -1,   109,    -1,    94,    95,    96,
      97,    98,    99,   100,    -1,     1,    -1,    -1,    -1,   106,
     107,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    17,    94,    95,    96,    97,    98,    99,   100,     1,
      -1,    -1,    -1,    -1,   106,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    17,    -1,    -1,     1,    -1,
      -1,    47,     5,    49,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    59,    17,    37,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    74,    -1,
      -1,    -1,    54,    19,    20,    21,    22,    23,    84,    85,
      86,    63,    88,     1,    47,    -1,    49,    -1,    -1,     7,
      -1,    73,    74,    -1,    -1,    13,    14,    -1,    -1,    17,
      63,    -1,    84,    85,    86,    -1,    -1,    25,    -1,    -1,
      -1,    74,     1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    84,    85,    86,    13,    14,    -1,     1,    17,    47,
      -1,    49,    -1,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    31,    17,    -1,    63,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,    -1,    74,    -1,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,
       1,    -1,    -1,    47,    63,    49,     7,    -1,     1,    53,
      -1,    -1,    13,    14,     7,    74,    17,    -1,    -1,    63,
      13,    14,    -1,    -1,    17,    84,    85,    86,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    -1,    -1,    -1,    47,    -1,    49,    -1,
      -1,     1,    -1,    54,    47,    -1,    49,     7,    -1,     1,
      -1,    -1,    63,    13,    14,     7,    59,    17,    -1,    -1,
      63,    13,    14,    74,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    -1,    -1,    -1,    47,    -1,    49,
      -1,    -1,    -1,    -1,     1,    47,    56,    49,    -1,    -1,
       7,    -1,    -1,    63,    -1,    57,    13,    14,    -1,    -1,
      17,    63,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,     1,    -1,    -1,    -1,    -1,
      47,     7,    49,    -1,    -1,    -1,    -1,    13,    14,    56,
      -1,    17,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,   113,   114,   115,   116,     5,     0,     1,     3,
     117,   118,   119,     1,     6,   120,   121,     4,   122,    12,
      60,    79,   128,   129,   131,   134,   113,   114,     5,   114,
       7,   163,   163,   129,   131,   134,   123,   125,   163,     1,
      13,    14,    17,    47,    49,    63,    74,    84,    85,    86,
     135,   136,   137,   142,   146,   147,   150,   155,   156,   157,
     158,   163,   164,   130,   132,   125,     1,     8,     9,   124,
     126,   138,     4,    16,    20,    24,    38,    39,    68,    77,
     104,   105,   108,   160,   163,   163,   114,   160,   114,   160,
      25,   136,   114,   114,   114,   160,   114,   114,   114,   114,
     114,    16,   159,    16,    16,    16,     1,     8,     1,    10,
      11,    36,   127,   163,    16,     1,   160,   160,    16,    16,
      16,    16,   160,    19,    20,    21,    22,    23,    51,    94,
      95,    96,    97,    98,    99,   100,   106,   107,   109,    16,
     151,    43,   135,   114,   113,     1,    48,   149,   160,   162,
      18,   143,   125,   133,   133,   127,   114,   139,   161,    15,
     160,   160,   162,   160,   160,   160,   160,   160,   160,   114,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     162,   114,   160,    31,   114,     9,    15,   160,   144,   160,
     124,    15,   126,    15,   114,   140,   163,    15,    15,    15,
      15,    15,   135,    15,    37,   152,   153,    31,   160,   135,
     160,   114,     9,    15,     1,   124,   145,   127,     1,   124,
     125,   114,    15,   126,   141,    53,   160,    73,   153,   154,
     160,     1,    59,    88,   148,   160,   104,   127,   124,   120,
     163,   114,   114,    54,    51,    75,   114,   145,   124,   114,
     127,    12,   135,   135,   114,   160,   135,   104,   120,   114,
     135,    51,   148,    12,   135,    56,   114,   114,    57,   135,
     135,   114,    56,    55,   114
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
        case 4:
/* Line 1787 of yacc.c  */
#line 128 "hopper.y"
    {printf("\n");}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 136 "hopper.y"
    {var_escopo = GLOBAL;}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 149 "hopper.y"
    {push_traducao(&fila_traducao, "import sys\n");
		     push_traducao(&fila_traducao, "import math\n\n");}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 151 "hopper.y"
    {erros++; yyerror("Esperava ALGORITMO, encontrado: ", yylineno, yytext);}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 161 "hopper.y"
    {erros++; yyerror("Esperava VAR, encontrado: ", yylineno, yytext);}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 172 "hopper.y"
    {erros++; yyerror("Esperava ':', encontrado: ", yylineno, yytext);}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 176 "hopper.y"
    {push_var(&fila_variavel, (yyvsp[(1) - (1)]));}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 177 "hopper.y"
    {push_var(&fila_variavel, (yyvsp[(3) - (3)]));}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 182 "hopper.y"
    {erros++; yyerror("Esperava VIRGULA, encontrado: ", yylineno, yytext);}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 187 "hopper.y"
    {cadastrar_variavel("float");}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 188 "hopper.y"
    {cadastrar_variavel("int");}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 189 "hopper.y"
    {cadastrar_variavel("char *");}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 190 "hopper.y"
    {erros++; yyerror("Tipo de variavel desconhecido: ", yylineno, yytext);}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 201 "hopper.y"
    {var_escopo = (yyvsp[(2) - (2)]);}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 202 "hopper.y"
    {var_escopo = GLOBAL;}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 207 "hopper.y"
    {var_escopo = (yyvsp[(2) - (2)]);}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 208 "hopper.y"
    {var_escopo = GLOBAL;}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 237 "hopper.y"
    {erros++; yyerror("Comando inválido: ", yylineno, yytext);}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 241 "hopper.y"
    {push_traducao(&fila_traducao,"scanf");}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 241 "hopper.y"
    {push_traducao(&fila_traducao,"(");}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 241 "hopper.y"
    {push_traducao(&fila_traducao,")");}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 245 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(1) - (1)])));}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 245 "hopper.y"
    {push_traducao(&fila_traducao,strdup((yyvsp[(1) - (2)])));}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 246 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(3) - (3)])));}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 250 "hopper.y"
    {push_traducao(&fila_traducao,"(");}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 250 "hopper.y"
    {push_traducao(&fila_traducao,")");}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 262 "hopper.y"
    {erros++; yyerror("Formatacao de casas decimais inválidas", yylineno, yytext);}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 272 "hopper.y"
    {push_traducao(&fila_traducao,"if");}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 276 "hopper.y"
    {push_traducao(&fila_traducao,"}");}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 277 "hopper.y"
    {erros++; yyerror("Esperava FIMSE, encontrado: ", yylineno, yytext);}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 281 "hopper.y"
    {push_traducao(&fila_traducao,"{");}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 282 "hopper.y"
    {erros++; yyerror("Esperava ENTAO, encontrado: ", yylineno, yytext);}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 286 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(2) - (2)])));}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 317 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(1) - (1)])));}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 321 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(1) - (1)])));}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 322 "hopper.y"
    {push_traducao(&fila_traducao,"scanf");}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 325 "hopper.y"
    {(yyval) = strdup(yytext); push_traducao(&fila_traducao,(yyval));}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 326 "hopper.y"
    {push_traducao(&fila_traducao,"("); push_traducao(&fila_traducao,(yyvsp[(2) - (3)])); push_traducao(&fila_traducao,")"); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 349 "hopper.y"
    {erros++; yyerror("Expressao inválida", yylineno, yytext);}
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 358 "hopper.y"
    { (yyval) = strdup(yytext);}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 362 "hopper.y"
    {push_traducao(&fila_traducao,"print");}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 363 "hopper.y"
    {push_traducao(&fila_traducao,"print");}
    break;


/* Line 1787 of yacc.c  */
#line 2326 "hopper.tab.c"
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


/* Line 2050 of yacc.c  */
#line 366 "hopper.y"


int main(int ac, char **av) {
	FILE *file_traducao;
	extern FILE *yyin;
	
	

	cria_fila_var(&fila_variavel);
	cria_fila_error(&fila_erros);
	cria_fila_traducao(&fila_traducao);	
	  
		 
	if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
		perror(av[1]);
		exit(1);
	}

	
	yyparse();

	if(!erros){
		printf("\n\nO algoritmo é valido!\n");
		file_traducao= fopen ("traducao.py", "w+");
		cria_arquivo(&fila_traducao,file_traducao);	
	}
	else
	{
		printf("\n\nExistem erros no algoritmo.\n");
	}
}

int yyerror(char *msg, int line, char *token )
{
	printf ("ERRO -> Linha: %d. %s %s \n", yylineno, msg, token);
	return 0;
}

int yywrap(void)
{
	return 1;
}
