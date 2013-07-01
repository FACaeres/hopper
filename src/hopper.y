%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var/var.c"
#include "hash/hash.h"

#define YYSTYPE char*
#define GLOBAL "__GLOBAL__"

fila_var fila_variavel;

int erros;
extern int yylineno;
extern char *yytext;

char *var_nome;
char *var_escopo;
char *var_tipo;

void cadastrar_variavel(char var_tipo[50])
{
	elementofila_var *elemento_fila_var;
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
	}
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

%}

%locations
%error-verbose

%token 	T_ALGORITMO T_STRING T_FIM_COMANDO 
%token 	T_VAR T_IDENTIFICADOR T_TIPO_ATRIBUIDOR T_IDENT_SEPARADOR T_REAL T_INTEIRO
%token 	T_INICIO T_ESCREVA T_ESCREVAL T_PARENTESE_DIR T_PARENTESE_ESQ
%token 	T_LEIA T_OPERADOR_ATRIBUICAO

%token 	T_OPERADOR_SOMA
%token 	T_OPERADOR_SUBTRACAO
%token 	T_OPERADOR_MULTIPLICACAO
%token 	T_OPERADOR_DIVISAO
%token 	T_OPERADOR_EXPONENCIACAO
%token  T_RAIZQ

%token 	T_FIMALGORITMO

%token 	T_ABS T_ALEATORIO T_ARCCOS T_ARCSEN T_ARCTAN T_ATE T_ASC T_ARQUIVO T_CARAC     
%token 	T_CARACPNUM T_CARACTERE T_CASO T_COMPR T_COPIA T_COS T_COTAN T_CRONOMETRO     
%token 	T_DE T_DEBUG

%token 	T_DECLARE T_ECO T_ENQUANTO T_ENTAO T_ESCOLHA T_EXP T_FACA  
%token 	T_FALSO T_FIMENQUANTO T_FIMESCOLHA T_FIMFUNCAO T_FIMPARA  
%token 	T_FIMPROCEDIMENTO T_FIMREPITA T_FIMSE T_FUNCAO T_GRAUPRAD  
%token 	T_INT T_INTERROMPA T_LIMPATELA T_LITERAL T_LOG T_LOGICO  
%token 	T_MAIUSC T_MENSAGEM T_MINUSC T_NUMPCARAC T_NUMERICO  
%token 	T_OUTROCASO T_PARA T_PASSO T_PAUSA T_PI T_POS T_PROCEDIMENTO  
%token 	T_QUAD T_RADPGRAU T_RAND T_RANDI T_REPITA T_RETORNE 
%token 	T_SE T_SEN T_SENAO T_TAN T_TIMER T_VETOR T_VERDADEIRO  
%token 	T_OPERADOR_DIVISAO_INT T_OPERADOR_DIVISAO_RESTO T_OPERADOR_IGUAL  
%token 	T_OPERADOR_DIFERENTE T_OPERADOR_MENOR T_OPERADOR_MAIOR T_OPERADOR_MENOR_IGUAL  
%token 	T_OPERADOR_MAIOR_IGUAL T_COLCHETE_ESQ T_COLCHETE_DIR T_VETOR_INTERVALO  
%token 	T_NUMERO_INTEIRO T_NUMERO_REAL T_OP_LOGICO_E T_OP_LOGICO_XOU  
%token 	T_OP_LOGICO_NAO T_OP_LOGICO_OU T_INVALIDO

%left 	T_OP_LOGICO_OU
%left 	T_OP_LOGICO_XOU
%left 	T_OP_LOGICO_E
%left 	T_OP_LOGICO_NAO
%left 	IGUAL DIFERENTE MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL
%left 	T_OPERADOR_DIVISAO_RESTO
%left 	T_OPERADOR_SOMA T_OPERADOR_SUBTRACAO
%left 	T_OPERADOR_MULTIPLICACAO T_OPERADOR_DIVISAO
%left 	NEG
%right 	T_OPERADOR_EXPONENCIACAO

%start 	Input
%%

//Definição de Quebra de linha
//-----------------------------------------------
QuebraComando:
	
	| FimComando
;

FimComando:
	T_FIM_COMANDO
	| FimComando T_FIM_COMANDO
;

//Inicio da análise sintática
//-----------------------------------------------

Input:
	QuebraComando {var_escopo = GLOBAL;} Algoritmo 
;

Algoritmo:
	BlocoCabecalho BlocoDeclaracoes BlocoFuncoes BlocoComando
	| error {erros++; yyerror("Ordem inválida dos blocos, encontrou: ", yylineno, yytext);} FimComando
;

BlocoCabecalho:
	T_ALGORITMO T_STRING FimComando
;


BlocoDeclaracoes:

	| T_VAR QuebraComando ListaDeclaracoes
	| error {erros++; yyerror("Variável Inválida ", yylineno, yytext);} FimComando
;


ListaDeclaracoes:
	ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel FimComando
	| ListaDeclaracoes ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel FimComando
	| error {erros++; yyerror("Declaracao de variável inválida: ", yylineno, yytext);} FimComando
;

ListaVariaveis:
	T_Identificador {push_var(&fila_variavel, $1);}
	| ListaVariaveis T_IDENT_SEPARADOR T_Identificador {push_var(&fila_variavel, $3);}
	| error {erros++; yyerror("Nome de variavel Inválido: ", yylineno, yytext);} FimComando
;

TipoVariavel:
	T_REAL {cadastrar_variavel("real");}
	| T_INTEIRO {cadastrar_variavel("inteiro");}
	| T_CARACTERE {cadastrar_variavel("caractere");}
	| error {erros++; yyerror("Tipo de dados Inválido: ", yylineno, yytext);} FimComando
;

BlocoFuncoes:
	
	| BlocoFuncao
	| BlocoProcedimento
	| BlocoFuncoes BlocoFuncao
	| BlocoFuncoes BlocoProcedimento
	| error {erros++; yyerror("Subprograma mal-estruturado, token nao esperado: ", yylineno, yytext);} FimComando
;

BlocoFuncao:
	T_FUNCAO T_Identificador {var_escopo = $2;} T_PARENTESE_ESQ ListaParametros T_PARENTESE_DIR T_TIPO_ATRIBUIDOR TipoVariavel FimComando
	BlocoDeclaracoes T_INICIO FimComando Comandos T_FIMFUNCAO FimComando {var_escopo = GLOBAL;}
	| error {erros++; yyerror("Estrutura da funcão inválida, token nao esperado: ", yylineno, yytext);} FimComando
;

BlocoProcedimento:
	T_PROCEDIMENTO T_Identificador {var_escopo = $2;} T_PARENTESE_ESQ ListaParametros T_PARENTESE_DIR FimComando 
	BlocoDeclaracoes T_INICIO FimComando Comandos T_FIMPROCEDIMENTO FimComando {var_escopo = GLOBAL;}
;

ListaParametros:
	ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel
	| ListaParametros T_IDENT_SEPARADOR ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel
;

BlocoComando:
	T_INICIO FimComando Comandos T_FIMALGORITMO QuebraComando
;

Comandos:
	Comando
	| Comandos Comando
	| error {erros++; yyerror("Comando não esperado: ", yylineno, yytext);} FimComando
;

Comando:
	Leia FimComando
	| Escreva FimComando
	| Atribuicao FimComando
	| BlocoSe FimComando
	| BlocoEscolha FimComando
	| BlocoPara FimComando
	| BlocoEnquanto FimComando
	| BlocoRepita FimComando
	| T_Identificador T_PARENTESE_ESQ List_Expr T_PARENTESE_DIR FimComando
	| T_RETORNE Expr FimComando
	| T_INTERROMPA FimComando
	| error {erros++; yyerror("Comando inválido: ", yylineno, yytext);} FimComando
;

Leia:
	T_LEIA T_PARENTESE_ESQ ListaLeia T_PARENTESE_DIR
;

ListaLeia:
	T_Identificador {verificar_variavel(strdup($1));}
	| ListaLeia T_IDENT_SEPARADOR T_Identificador {verificar_variavel(strdup($3));} 
	| error {erros++; yyerror("Parâmetro inválido no LEIA, token nao esperado: ", yylineno, yytext);} FimComando
;

Escreva:
	T_Escreva T_PARENTESE_ESQ ConteudoEscreva T_PARENTESE_DIR
;

ConteudoEscreva:
	Expr OpcaoCasasDecimais
	| ConteudoEscreva T_IDENT_SEPARADOR Expr OpcaoCasasDecimais
	| error {erros++; yyerror("Parâmetros inválidos no ESCREVA, token invalido: ", yylineno, yytext);} FimComando
;

OpcaoCasasDecimais:
	
	| T_TIPO_ATRIBUIDOR T_NUMERO_INTEIRO
	| T_TIPO_ATRIBUIDOR T_NUMERO_INTEIRO T_TIPO_ATRIBUIDOR T_NUMERO_INTEIRO
	| error {erros++; yyerror("Formatacao de casas decimais inválidas", yylineno, yytext);} FimComando
;

BlocoSe:
	T_SE Expr T_ENTAO FimComando Comandos T_FIMSE
	| T_SE Expr T_ENTAO FimComando Comandos T_SENAO FimComando Comandos T_FIMSE
;

BlocoEscolha:
	T_ESCOLHA T_Identificador {verificar_variavel(strdup($2));} FimComando ListaCasos OutroCaso T_FIMESCOLHA
;

ListaCasos:
	Caso
	| ListaCasos Caso
;

Caso:
	T_CASO Expr FimComando Comandos
	| error {erros++; yyerror("Estrutura Caso invalida, token desconhecido: ", yylineno, yytext);} FimComando
;

OutroCaso:
	
	| T_OUTROCASO FimComando Comandos	
;

BlocoPara:
	T_PARA Expr T_DE Expr T_ATE Expr T_FACA FimComando Comandos T_FIMPARA
	| T_PARA Expr T_DE Expr T_ATE Expr T_PASSO Expr T_FACA FimComando Comandos T_FIMPARA
;

BlocoEnquanto:
	T_ENQUANTO Expr T_FACA FimComando Comandos T_FIMENQUANTO
;

BlocoRepita:
	T_REPITA FimComando Comandos T_ATE Expr
;

Atribuicao:
	T_Identificador {verificar_variavel(strdup($1));} T_OPERADOR_ATRIBUICAO Expr
;

Expr:
	T_Identificador {verificar_variavel(strdup($1));}
	| T_NUMERO_INTEIRO
	| T_NUMERO_REAL
	| T_PI
	| T_STRING
	| T_PARENTESE_ESQ Expr T_PARENTESE_DIR
	| Expr T_OPERADOR_DIVISAO_RESTO Expr
	| Expr Add_op Expr
	| Expr Mult_op Expr
	| Expr Bool_op Expr
	| Expr Comp_op Expr
	| T_OPERADOR_SUBTRACAO Expr %prec NEG
	| T_OP_LOGICO_NAO Expr
	| Expr T_OPERADOR_EXPONENCIACAO Expr
	| T_RAIZQ T_PARENTESE_ESQ Expr T_PARENTESE_DIR
	| T_MAIUSC T_PARENTESE_ESQ Expr T_PARENTESE_DIR
	| T_COMPR T_PARENTESE_ESQ Expr T_PARENTESE_DIR
	| T_Identificador T_PARENTESE_ESQ List_Expr T_PARENTESE_DIR
	| T_COPIA T_PARENTESE_ESQ List_Expr T_PARENTESE_DIR
	| T_PARENTESE_ESQ error {erros++; yyerror("Expressao inválida", yylineno, yytext);} T_PARENTESE_DIR
;

List_Expr:
	Expr
	| List_Expr T_IDENT_SEPARADOR Expr
	| error {erros++; yyerror("Expressao invalida: ", yylineno, yytext);} FimComando
;


/**
***
***	Simbolos terminais
***
**/

Add_op:
	T_OPERADOR_SOMA
	| T_OPERADOR_SUBTRACAO
	| error {erros++; yyerror("Esperava + ou -, encontrado: ", yylineno, yytext);} FimComando
;

Mult_op:
	T_OPERADOR_MULTIPLICACAO
	| T_OPERADOR_DIVISAO
;

Bool_op:
	T_OP_LOGICO_E
	| T_OP_LOGICO_OU
	| T_OP_LOGICO_XOU
;

Comp_op:
	T_OPERADOR_IGUAL
	| T_OPERADOR_DIFERENTE
	| T_OPERADOR_MENOR
	| T_OPERADOR_MAIOR
	| T_OPERADOR_MENOR_IGUAL
	| T_OPERADOR_MAIOR_IGUAL
;

T_Identificador:
	T_IDENTIFICADOR { $$ = strdup(yytext);}
	| error {erros++; yyerror("Nome nao segue as regras de criacao, consulte as referencias: ", yylineno, yytext);} FimComando
;

T_Escreva:
	T_ESCREVA
	| T_ESCREVAL
;

%%

int main(int ac, char **av) {
		
	extern FILE *yyin;
	
	cria_fila_var(&fila_variavel);
		
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
	printf ("ERRO -> Linha: %d. %s %s \n", line, s, msg);
	return 0;
}

int yywrap(void)
{
	return 1;
}
