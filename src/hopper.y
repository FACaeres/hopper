%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila/fila.c"	
int erros;
extern yylineno, yytext;
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
	| error {erros++; yyerror("Esperava quebra de linha, encontrou: ", yylineno, yytext);}
;

//Inicio da análise sintática
//-----------------------------------------------

Input:
	QuebraComando Algoritmo
	| error {erros++; yyerror("Esperava ALGORITMO, encontrou: ", yylineno, yytext);} FimComando
;

Algoritmo:
	BlocoCabecalho BlocoDeclaracoes BlocoFuncoes BlocoComando
	| error {erros++; yyerror("Ordem inválida dos blocos, encontrou: ", yylineno, yytext);} FimComando
;

BlocoCabecalho:
	T_Algoritmo T_String FimComando
	| error {erros++; yyerror("Formato do nome do algoritmo inválido, encontrou: ", yylineno, yytext);} FimComando
;


BlocoDeclaracoes:

	| T_Var QuebraComando ListaDeclaracoes
	| error {erros++; yyerror("Variável Inválida ", yylineno, yytext);} FimComando
;


ListaDeclaracoes:
	ListaVariaveis T_Tipo_Atribuidor TipoVariavel FimComando
	| ListaDeclaracoes ListaVariaveis T_Tipo_Atribuidor TipoVariavel FimComando
	| error {erros++; yyerror("Declaracao de variável inválida: ", yylineno, yytext);} FimComando
;



ListaVariaveis:
	T_Identificador
	| ListaVariaveis T_Ident_Separador T_Identificador
	| error {erros++; yyerror("Nome de variavel Inválido: ", yylineno, yytext);} FimComando
;

TipoVariavel:
	T_REAL
	| T_INTEIRO
	| T_CARACTERE
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
	T_Funcao T_Identificador T_Parentese_Esq ListaParametros T_Parentese_Dir T_Tipo_Atribuidor TipoVariavel FimComando BlocoDeclaracoes T_Inicio FimComando Comandos T_FimFuncao FimComando
	| error {erros++; yyerror("Estrutura da funcão inválida, token nao esperado: ", yylineno, yytext);} FimComando
;

BlocoProcedimento:
	T_Procedimento T_Identificador T_Parentese_Esq ListaParametros T_Parentese_Dir FimComando BlocoDeclaracoes T_Inicio FimComando Comandos T_FimProcedimento FimComando
	| error {erros++; yyerror("Estrutura do procedimento inválida, token nao esperado: ", yylineno, yytext);} FimComando
;

ListaParametros:
	ListaVariaveis T_Tipo_Atribuidor TipoVariavel
	| ListaParametros T_Ident_Separador ListaVariaveis T_Tipo_Atribuidor TipoVariavel
	| error {erros++; yyerror("Parâmetros inválidos ", yylineno, yytext);} FimComando
;

BlocoComando:
	T_Inicio FimComando Comandos T_FimAlgoritmo QuebraComando
	| error {erros++; yyerror("Bloco principal mal-formado, token inválido: ", yylineno, yytext);} FimComando
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
	| T_Identificador T_Parentese_Esq List_Expr T_Parentese_Dir FimComando
	| T_Retorne Expr FimComando
	| T_Interrompa FimComando
	| error {erros++; yyerror("Comando inválido: ", yylineno, yytext);} FimComando
;

Leia:
	T_Leia T_Parentese_Esq ListaLeia T_Parentese_Dir
	| error {erros++; yyerror("Instrucao leia invalida, token nao esperado: ", yylineno, yytext);} FimComando
;

ListaLeia:
	T_Identificador
	| ListaLeia T_Ident_Separador T_Identificador
	| error {erros++; yyerror("Parâmetro inválido no LEIA, token nao esperado: ", yylineno, yytext);} FimComando
;

Escreva:
	T_Escreva T_Parentese_Esq ConteudoEscreva T_Parentese_Dir
	| error {erros++; yyerror("Parâmetro inválido no ESCREVA, token nao esperado: ", yylineno, yytext);} FimComando
;

ConteudoEscreva:
	Expr OpcaoCasasDecimais
	| ConteudoEscreva T_Ident_Separador Expr OpcaoCasasDecimais
	| error {erros++; yyerror("Parâmetros inválidos no ESCREVA, token invalido: ", yylineno, yytext);} FimComando
;

OpcaoCasasDecimais:
	
	| T_Tipo_Atribuidor T_NUMERO_INTEIRO
	| T_Tipo_Atribuidor T_NUMERO_INTEIRO T_Tipo_Atribuidor T_NUMERO_INTEIRO
	| error {erros++; yyerror("Formatacao de casas decimais inválidas", yylineno, yytext);} FimComando
;

BlocoSe:
	T_Se Expr T_Entao FimComando Comandos T_FimSe
	| T_Se Expr T_Entao FimComando Comandos T_Senao FimComando Comandos T_FimSe
	| error {erros++; yyerror("Bloco SE invalido, token nao esperado: ", yylineno, yytext);} FimComando
;

BlocoEscolha:
	T_Escolha T_Identificador FimComando ListaCasos T_Fimescolha
	| T_Escolha T_Identificador FimComando ListaCasos OutroCaso T_Fimescolha
	| error {erros++; yyerror("Bloco escolha inválido, token desconhecido: ", yylineno, yytext);} FimComando
;

ListaCasos:
	Caso
	| ListaCasos Caso
	| error {erros++; yyerror("Bloco Caso inválido, token desconhecido: ", yylineno, yytext);} FimComando
;

Caso:
	T_Caso Expr FimComando Comandos
	| error {erros++; yyerror("Estrutura Caso invalida, token desconhecido: ", yylineno, yytext);} FimComando
;

OutroCaso:
	T_OutroCaso FimComando Comandos
	| error {erros++; yyerror("Estrutura Outrocaso invalida, token desconhecido: ", yylineno, yytext);} FimComando
;

BlocoPara:
	T_Para Expr T_De Expr T_Ate Expr T_Faca FimComando Comandos T_FimPara
	| T_Para Expr T_De Expr T_Ate Expr T_Passo Expr T_Faca FimComando Comandos T_FimPara
	| error {erros++; yyerror("Bloco para inválido, token desconhecido: ", yylineno, yytext);} FimComando
;

BlocoEnquanto:
	T_Enquanto Expr T_Faca FimComando Comandos T_FimEnquanto
	| error {erros++; yyerror("Bloco enquanto inválido, token desconhecido: ", yylineno, yytext);} FimComando
;


BlocoRepita:
	T_Repita FimComando Comandos T_Ate Expr
	| error {erros++; yyerror("Bloco repita invalido, token desconhecido: ", yylineno, yytext);} FimComando
;

Atribuicao:
	T_Identificador T_Operador_Atribuicao Expr
	| error {erros++; yyerror("Atribuicao invalida, token desconhecido: ", yylineno, yytext);} FimComando
;

Expr:
	T_Identificador
	| T_NUMERO_INTEIRO		
	| T_NUMERO_REAL
	| T_PI
	| T_String
	| T_Parentese_Esq Expr T_Parentese_Dir
	| Expr T_OPERADOR_DIVISAO_RESTO Expr
	| Expr Add_op Expr
	| Expr Mult_op Expr
	| Expr Bool_op Expr
	| Expr Comp_op Expr
	| T_OPERADOR_SUBTRACAO Expr %prec NEG
	| T_OP_LOGICO_NAO Expr
	| Expr T_OPERADOR_EXPONENCIACAO Expr
	| T_RAIZQ T_Parentese_Esq Expr T_Parentese_Dir
	| T_MAIUSC T_Parentese_Esq Expr T_Parentese_Dir
	| T_COMPR T_Parentese_Esq Expr T_Parentese_Dir
	| T_Identificador T_Parentese_Esq List_Expr T_Parentese_Dir
	| T_COPIA T_Parentese_Esq List_Expr T_Parentese_Dir
	| T_Parentese_Esq error {erros++; yyerror("Expressao inválida", yylineno, yytext);} T_Parentese_Dir
;

List_Expr:
	Expr
	| List_Expr T_Ident_Separador Expr
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
	| error {erros++; yyerror("Esperava * ou /, encontrado: ", yylineno, yytext);} FimComando
;

Bool_op:
	T_OP_LOGICO_E
	| T_OP_LOGICO_OU
	| T_OP_LOGICO_XOU
	| error {erros++; yyerror("Esperava 'ou' 'e' 'xou', encontrado: ", yylineno, yytext);} FimComando
;

Comp_op:
	T_OPERADOR_IGUAL
	| T_OPERADOR_DIFERENTE
	| T_OPERADOR_MENOR
	| T_OPERADOR_MAIOR
	| T_OPERADOR_MENOR_IGUAL
	| T_OPERADOR_MAIOR_IGUAL
	| error {erros++; yyerror("Esperava operador comparacao, encontrado: ", yylineno, yytext);} FimComando
;


T_Algoritmo:
	T_ALGORITMO
	| error {erros++; yyerror("Esperava ALGORITMO ", yylineno, yytext);} FimComando
;	

T_String:
	T_STRING
	| error {erros++; yyerror("Formato de String inválido ", yylineno, yytext);} FimComando
;


T_Var:
	T_VAR
	| error {erros++; yyerror("Esperava VAR, encontrou: ", yylineno, yytext);} FimComando
;


T_Tipo_Atribuidor:
	T_TIPO_ATRIBUIDOR
	| error {erros++; yyerror("Esperava ':', encontrou: ", yylineno, yytext);} FimComando
;

T_Identificador:
	T_IDENTIFICADOR
	| error {erros++; yyerror("Nome nao segue as regras de criacao, consulte as referencias: ", yylineno, yytext);} FimComando
;

T_Ident_Separador:
	T_IDENT_SEPARADOR
	| error {erros++; yyerror("Esperava ',' encontrou: ", yylineno, yytext);} FimComando
;

T_Funcao:
	T_FUNCAO
	| error {erros++; yyerror("Esperava FUNCAO, encontrou: ", yylineno, yytext);} FimComando
;

T_Parentese_Esq:
	T_PARENTESE_ESQ
	| error {erros++; yyerror("Esperava '(', encontrou: ", yylineno, yytext);} FimComando
;

T_Parentese_Dir:
	T_PARENTESE_DIR
	| error {erros++; yyerror("Esperava ')', encontrou: ", yylineno, yytext);} FimComando
;

T_Inicio:
	T_INICIO
	| error {erros++; yyerror("Esperava INICIO, encontrou: ", yylineno, yytext);} FimComando
;

T_FimFuncao:
	T_FIMFUNCAO
	| error {erros++; yyerror("Esperava FIMFUNCAO, encontrou: ", yylineno, yytext);} FimComando
;

T_Procedimento:
	T_PROCEDIMENTO
	| error {erros++; yyerror("Esperava PROCEDIMENTO, encontrou: ", yylineno, yytext);} FimComando
;

T_FimProcedimento:
	T_FIMPROCEDIMENTO
	| error {erros++; yyerror("Esperava FIMPROCEDIMENTO, encontrou: ", yylineno, yytext);} FimComando
;

T_Inicio:
	T_INICIO
	| error {erros++; yyerror("Esperava INICIO, encontrou: ", yylineno, yytext);} FimComando
;

T_FimAlgoritmo:
	T_FIMALGORITMO
	| error {erros++; yyerror("Esperava FIMALGORITMO, encontrou: ", yylineno, yytext);} FimComando
;

T_Retorne:
	T_RETORNE
	| error {erros++; yyerror("Esperava RETORNE, encontrou: ", yylineno, yytext);} FimComando
;


T_Interrompa:
	T_INTERROMPA
	| error {erros++; yyerror("Esperava INTERROMPA, encontrou: ", yylineno, yytext);} FimComando
;

T_Leia:
	T_LEIA
	| error {erros++; yyerror("Esperava LEIA, encontrou: ", yylineno, yytext);} FimComando
;

T_Escreva:
	T_ESCREVA
	| T_ESCREVAL
	| error {erros++; yyerror("Esperava ESCREVA ou ESCREVAL, encontrado: ", yylineno, yytext);} FimComando
;

T_Se:
	T_SE
	| error {erros++; yyerror("Esperava SE, encontrado: ", yylineno, yytext);} FimComando
;

T_Entao:
	T_ENTAO
	| error {erros++; yyerror("Esperava ENTAO, encontrado: ", yylineno, yytext);} FimComando
;

T_FimSe:
	T_FIMSE
	| error {erros++; yyerror("Esperava FIMSE, encontrado: ", yylineno, yytext);} FimComando
;

T_Senao:
	T_SENAO
	| error {erros++; yyerror("Esperava SENAO, encontrado: ", yylineno, yytext);} FimComando
;

T_Escolha:
	T_ESCOLHA
	| error {erros++; yyerror("Esperava ESCOLHA, encontrado: ", yylineno, yytext);} FimComando
;

T_Fimescolha:
	T_FIMESCOLHA
	| error {erros++; yyerror("Esperava FIMESCOLHA, encontrado: ", yylineno, yytext);} FimComando
;

T_Caso:
	T_CASO
	| error {erros++; yyerror("Esperava CASO, encontrado: ", yylineno, yytext);} FimComando
;

T_OutroCaso:
	T_OUTROCASO
	| error {erros++; yyerror("Esperava OUTROCASO, encontrado: ", yylineno, yytext);} FimComando
;

T_Para:
	T_PARA
	| error {erros++; yyerror("Esperava PARA, encontrado: ", yylineno, yytext);} FimComando
;

T_Ate:
	T_ATE
	| error {erros++; yyerror("Esperava ATE, encontrado: ", yylineno, yytext);} FimComando
;

T_De:
	T_DE
	| error {erros++; yyerror("Esperava DE, encontrado: ", yylineno, yytext);} FimComando
;

T_Faca:
	T_FACA
	| error {erros++; yyerror("Esperava FACA, encontrado: ", yylineno, yytext);} FimComando
;

T_FimPara:
	T_FIMPARA
	| error {erros++; yyerror("Esperava FIMPARA, encontrado: ", yylineno, yytext);} FimComando
;

T_Passo:
	T_PASSO
	| error {erros++; yyerror("Esperava PASSO, encontrado: ", yylineno, yytext);} FimComando
;

T_Enquanto:
	T_ENQUANTO
	| error {erros++; yyerror("Esperava ENQUANTO, encontrado: ", yylineno, yytext);} FimComando
;

T_FimEnquanto:
	T_FIMENQUANTO
	| error {erros++; yyerror("Esperava FIMENQUANTO, encontrado: ", yylineno, yytext);} FimComando
;

T_Repita:
	T_REPITA
	| error {erros++; yyerror("Esperava REPITA, encontrado: ", yylineno, yytext);} FimComando
;

T_Operador_Atribuicao:
	T_OPERADOR_ATRIBUICAO
	| error {erros++; yyerror("Esperava ':=', encontrado: ", yylineno, yytext);} FimComando
;

%%

int main(int ac, char **av) {
		
	extern FILE *yyin;

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
