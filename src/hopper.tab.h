/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

