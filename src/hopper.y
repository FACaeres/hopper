%{
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
int tab = 0;
int cont_caso = 0;
int erros;
char variavel_escolha[50];
extern int yylineno;
extern char *yytext;

char *var_nome;
char *var_escopo;
char *var_tipo;
char *c;
char *tipo;
char leiaTipos[256];
char leiaVariaveis[256];

int flag_escreval = 0;
item *temp;
void tabear(){
	int i;
	for(i=0;i<tab;i++)
		push_traducao(&fila_traducao, "    ");
}

void tabear_especial(){ //serve para tabear o palavras como o "else" por exemplo
	int i;
        for(i=0;i<tab-1;i++)
                push_traducao(&fila_traducao, "    ");
}

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
%left 	T_OPERADOR_IGUAL T_OPERADOR_DIFERENTE T_OPERADOR_MENOR T_OPERADOR_MENOR_IGUAL T_OPERADOR_MAIOR T_OPERADOR_MAIOR_IGUAL
%left 	T_OPERADOR_DIVISAO_RESTO
%left 	T_OPERADOR_SOMA T_OPERADOR_SUBTRACAO
%left 	T_OPERADOR_MULTIPLICACAO T_OPERADOR_DIVISAO
%left 	NEG
%right 	T_OPERADOR_EXPONENCIACAO
%nonassoc T_INVALIDO

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
	|BlocoCabecalho BlocoDeclaracoes BlocoComando
;

BlocoCabecalho:
	T_Algoritmo T_STRING FimComando 
;

T_Algoritmo:
	T_ALGORITMO {push_traducao(&fila_traducao,"# -*- coding: utf-8 -*-\n");
		     push_traducao(&fila_traducao, "import sys\n");
		     push_traducao(&fila_traducao, "import math\ndef frange(start, stop, step):\n    i=start\n    if(step > 0):\n        while i <= stop:\n            yield i\n            i += step\n    else:\n        while i >= stop:\n            yield i\n            i += step\n\n");}
	| error {erros++; yyerror("Esperava ALGORITMO, encontrado: ", yylineno, yytext);}
;

BlocoDeclaracoes:

	| T_Var QuebraComando ListaDeclaracoes
;

T_Var:
	T_VAR
	| error {erros++; yyerror("Esperava VAR, encontrado: ", yylineno, yytext);} T_FIM_COMANDO
;


ListaDeclaracoes:
	ListaVariaveis T_Tipo_Atribuidor TipoVariavel FimComando
	| ListaDeclaracoes ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel FimComando
;

T_Tipo_Atribuidor:
	T_TIPO_ATRIBUIDOR 
	| error {erros++; yyerror("Esperava ':', encontrado: ", yylineno, yytext);} 
;

ListaVariaveis:
	T_Identificador {push_var(&fila_variavel, $1);}
	| ListaVariaveis T_Ident_Separador T_Identificador {push_var(&fila_variavel, $3);}
;

T_Ident_Separador:
	T_IDENT_SEPARADOR 
	| error {erros++; yyerror("Esperava VIRGULA, encontrado: ", yylineno, yytext);}
;

//falta operador logico
TipoVariavel:
	T_REAL {cadastrar_variavel("float");}
	| T_INTEIRO {cadastrar_variavel("int");}
	| T_CARACTERE {cadastrar_variavel("string");}
	| error {erros++; yyerror("Tipo de variavel desconhecido: ", yylineno, yytext);}
;

BlocoFuncoes:	
	BlocoFuncao
	| BlocoProcedimento
	| BlocoFuncoes BlocoFuncao
	| BlocoFuncoes BlocoProcedimento
;

BlocoFuncao:
	T_FUNCAO T_Identificador {var_escopo = $2;} T_PARENTESE_ESQ ListaParametros T_PARENTESE_DIR T_Tipo_Atribuidor TipoVariavel FimComando
	BlocoDeclaracoes T_INICIO FimComando Comandos T_FIMFUNCAO FimComando {var_escopo = GLOBAL;}
;


BlocoProcedimento:
	T_PROCEDIMENTO T_Identificador {var_escopo = $2;} T_PARENTESE_ESQ ListaParametros T_PARENTESE_DIR FimComando 
	BlocoDeclaracoes T_INICIO FimComando Comandos T_FIMPROCEDIMENTO FimComando {var_escopo = GLOBAL;}
;

ListaParametros:
	ListaVariaveis T_Tipo_Atribuidor TipoVariavel
	| ListaParametros T_Ident_Separador ListaVariaveis T_Tipo_Atribuidor TipoVariavel
;

BlocoComando:
	T_INICIO FimComando Comandos T_FIMALGORITMO  QuebraComando
;

Comandos:
	Comando
	| Comandos Comando
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
	| T_INTERROMPA FimComando {tabear();push_traducao(&fila_traducao,"break\n");}
	| error {erros++; yyerror("Comando inválido: ", yylineno, yytext);}
;

Leia:
	T_LEIA T_PARENTESE_ESQ ListaLeia T_PARENTESE_DIR
;

ListaLeia:
	T_Identificador {
		verificar_variavel(strdup($1));
		hash_consultar2(strdup($1),var_escopo,&temp);
		char *tipo_string;
		char s[250];
		tipo_string = temp->tipo;
		printf(": %s %s %s\n",temp->key.nome, temp->key.escopo, tipo_string);
		if(strcmp(tipo_string,"string")==0){
			sprintf(s,"%s = input()\n",strdup($1));
		}else{
			sprintf(s,"%s = %s(input())\n",strdup($1),tipo_string);
		}
		tabear();
		push_traducao(&fila_traducao,s);
	}
	| ListaLeia T_Ident_Separador T_Identificador {
		verificar_variavel(strdup($3));
		hash_consultar2(strdup($3),var_escopo,&temp);
		char *tipo_string;
		char s[250];
		tipo_string = temp->tipo;
		printf(": %s %s %s\n",temp->key.nome, temp->key.escopo, tipo_string);
		if(strcmp(tipo_string,"string")==0){
			sprintf(s,"%s = input()\n",strdup($3));
		}else{
			sprintf(s,"%s = %s(input())\n",strdup($3),tipo_string);
		}
		tabear();
		push_traducao(&fila_traducao,s);
	} 
	//falta fazer o leia para varias variaveis.
;

Escreva:
	T_Escreva T_PARENTESE_ESQ ConteudoEscreva T_PARENTESE_DIR {
			if(flag_escreval == 1){
				push_traducao(&fila_traducao,",end='\\n')\n");
				flag_escreval = 0;
			}else{
			push_traducao(&fila_traducao,",end='')\n");}}
;

ConteudoEscreva:
	Expr OpcaoCasasDecimais
	| Expr T_IDENT_SEPARADOR {push_traducao(&fila_traducao,", ");} Expr OpcaoCasasDecimais
;

OpcaoCasasDecimais:
	
	| T_Tipo_Atribuidor T_NUMERO_INTEIRO
	| T_Tipo_Atribuidor T_NUMERO_INTEIRO T_Tipo_Atribuidor T_NUMERO_INTEIRO
	| error {erros++; yyerror("Formatacao de casas decimais inválidas", yylineno, yytext);}

;

BlocoSe:
	T_Se Expr T_Entao FimComando Comandos T_FimSe
	| T_Se Expr T_Entao FimComando Comandos T_Senao FimComando Comandos T_FimSe
;

T_Se:
      T_SE {tabear();push_traducao(&fila_traducao,"if ");}
;

T_FimSe:
	T_FIMSE {tab--;}
	| error {erros++; yyerror("Esperava FIMSE encontrado: ", yylineno, yytext);}
;

T_Entao:
	T_ENTAO {push_traducao(&fila_traducao,":\n");tab++;}
	| error {erros++; yyerror("Esperava ENTAO, encontrado: ", yylineno, yytext);}
;

T_Senao:
	T_SENAO {tabear_especial();push_traducao(&fila_traducao, "else:\n");}
;
BlocoEscolha:
	T_ESCOLHA T_Identificador {verificar_variavel(strdup($2));sprintf(variavel_escolha, "if %s.lower() == ",$2);tab++;} FimComando ListaCasos OutroCaso T_FIMESCOLHA {tab--;cont_caso = 0;}
;

ListaCasos:
	Caso
	| ListaCasos Caso
;

Caso:
	T_CASO {tabear_especial();if(cont_caso>0){push_traducao(&fila_traducao, "el");}push_traducao(&fila_traducao, variavel_escolha);cont_caso++;} Expr {push_traducao(&fila_traducao, ".lower():\n");} FimComando Comandos
;

OutroCaso:
	
	| T_OUTROCASO {tabear_especial();push_traducao(&fila_traducao, "else:\n");}FimComando Comandos	
;

InicioPara:
	T_PARA{tabear();push_traducao(&fila_traducao, "for ");tab++;} Expr T_DE {push_traducao(&fila_traducao, " in frange(");} Expr {push_traducao(&fila_traducao, ",");} T_ATE Expr 
;

MeioPara:
	T_PASSO{push_traducao(&fila_traducao, ",");} Expr T_FACA{push_traducao(&fila_traducao, "):\n");} FimComando
	| T_FACA{push_traducao(&fila_traducao, ",1):\n");} FimComando
;

BlocoPara:
	InicioPara MeioPara Comandos T_FIMPARA {tab--;}
;

BlocoEnquanto:
	T_ENQUANTO {tabear();push_traducao(&fila_traducao, "while ");tab++;} Expr{push_traducao(&fila_traducao, ":\n");} T_FACA FimComando Comandos T_FIMENQUANTO{tab--;} 
;

BlocoRepita:
	T_REPITA {tabear();push_traducao(&fila_traducao, "while True:\n");tab++;} FimComando Comandos T_ATE{tabear();push_traducao(&fila_traducao, "if ");tab++;} Expr {push_traducao(&fila_traducao, ":\n");tabear();push_traducao(&fila_traducao, "break\n");tab = tab - 2;}
;

Atribuicao:
	T_Identificador {verificar_variavel(strdup($1));tabear();push_traducao(&fila_traducao, $1);} T_OPERADOR_ATRIBUICAO {push_traducao(&fila_traducao, " = ");}Expr {push_traducao(&fila_traducao, "\n");}
;

Expr:
	T_Identificador {verificar_variavel(strdup($1));char s[50];sprintf(s,"%s", $1);push_traducao(&fila_traducao, s);}
	| T_NUMERO_INTEIRO {char s[50];sprintf(s,"%i", atoi(yylval));push_traducao(&fila_traducao, s);}
	| T_NUMERO_REAL {char s[50];sprintf(s,"%f", atof(yylval));push_traducao(&fila_traducao, s);}
	| T_PI {push_traducao(&fila_traducao, "math.pi");}
	| T_STRING {$$ = strdup(yytext); push_traducao(&fila_traducao,$$);}
	| T_PARENTESE_ESQ {push_traducao(&fila_traducao,"(");} Expr T_PARENTESE_DIR {push_traducao(&fila_traducao,")"); }
	| Expr T_OPERADOR_DIVISAO_RESTO {push_traducao(&fila_traducao, " % ");}Expr
	| Expr T_OPERADOR_SOMA {push_traducao(&fila_traducao, " + ");}Expr 
	| Expr T_OPERADOR_SUBTRACAO {push_traducao(&fila_traducao, " - ");}Expr 
	| Expr T_OPERADOR_MULTIPLICACAO {push_traducao(&fila_traducao, " * ");}Expr
	| Expr T_OPERADOR_DIVISAO {push_traducao(&fila_traducao, " / ");} Expr
	| Expr T_OP_LOGICO_E {push_traducao(&fila_traducao, " and ");} Expr
	| Expr T_OP_LOGICO_OU {push_traducao(&fila_traducao, " or ");} Expr
	| Expr T_OP_LOGICO_XOU Expr
	| Expr T_OPERADOR_IGUAL {push_traducao(&fila_traducao, " == ");}Expr
	| Expr T_OPERADOR_DIFERENTE {push_traducao(&fila_traducao, " != ");}Expr 
	| Expr T_OPERADOR_MENOR {push_traducao(&fila_traducao, " < ");}Expr 
	| Expr T_OPERADOR_MAIOR {push_traducao(&fila_traducao, " > ");}Expr
	| Expr T_OPERADOR_MENOR_IGUAL {push_traducao(&fila_traducao, " <= ");}Expr
	| Expr T_OPERADOR_MAIOR_IGUAL {push_traducao(&fila_traducao, " >= ");}Expr
	| T_OPERADOR_SUBTRACAO{push_traducao(&fila_traducao, " -");} Expr %prec NEG 
	| T_OP_LOGICO_NAO {push_traducao(&fila_traducao, " not");}Expr
	
	| Expr T_OPERADOR_EXPONENCIACAO {push_traducao(&fila_traducao, " ** ");}Expr
	
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
;

T_Identificador:
	T_IDENTIFICADOR { $$ = strdup(yytext);}
;

T_Escreva:
	T_ESCREVA {tabear();push_traducao(&fila_traducao,"print(");}
	| T_ESCREVAL {tabear();flag_escreval=1;push_traducao(&fila_traducao,"print(");}
;

%%

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
