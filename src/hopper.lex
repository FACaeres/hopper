%option yylineno
%{
#include <stdio.h>
#include <string.h>

#define ERRO -1
struct par_linha_token
{
  char *token;
  int linha;
}par_linha_token;

struct par_linha_token	*linhas_erro;	//Armazena o número das linhas que tiverem tokens inválidos
int	indice=1;	//Índice atual do array "linhas_erro"
int 	qtd_linhas;	//Quantidade de linhas do arquivo .alg
%}

T_ABS			(A|a)(B|b)(S|s)
T_ALEATORIO		(A|a)(L|l)(E|e)(A|a)(T|t)(O|o)(R|r)(I|i)(O|o)
T_ALGORITMO		(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(M|m)(O|o)
T_ARCCOS		(A|a)(R|r)(C|c)(C|c)(O|o)(S|s)
T_ARCSEN		(A|a)(R|r)(C|c)(S|s)(E|e)(N|n)
T_ARCTAN		(A|a)(R|r)(C|c)(T|t)(A|a)(N|n)
T_ARQUIVO		(A|a)(R|r)(Q|q)(U|u)(I|i)(V|v)(O|o)
T_ASC			(A|a)(S|s)(C|c)
T_ATE			(A|a)(T|t)(E|e)
T_CARAC			(C|c)(A|a)(R|r)(A|a)(C|c)
T_CARACPNUM		(C|c)(A|a)(R|r)(A|a)(C|c)(P|p)(N|n)(U|u)(M|m)
T_CARACTERE		(C|c)(A|a)(R|r)(A|a)(C|c)(T|t)(E|e)(R|r)(E|e)
T_CASO			(C|c)(A|a)(S|s)(O|o)
T_COMPR			(C|c)(O|o)(M|m)(P|p)(R|r)
T_COPIA			(C|c)(O|o)(P|p)(I|i)(A|a)
T_COS			(C|c)(O|o)(S|s)
T_COTAN			(C|c)(O|o)(T|t)(A|a)(N|n)
T_CRONOMETRO		(C|c)(R|r)(O|o)(N|n)(O|o)(M|m)(E|e)(T|t)(R|r)(O|o)
T_DE			(D|d)(E|e)
T_DEBUG			(D|d)(E|e)(B|b)(U|u)(G|g)
T_DECLARE		(D|d)(E|e)(C|c)(L|l)(A|a)(R|r)(E|e)
T_E			(E|e)
T_ECO			(E|e)(C|c)(O|o)
T_ENQUANTO		(E|e)(N|n)(Q|q)(U|u)(A|a)(N|n)(T|t)(O|o)
T_ENTAO			(E|e)(N|n)(T|t)(A|a)(O|o)
T_ESCOLHA		(E|e)(S|s)(C|c)(O|o)(L|l)(H|h)(A|a)
T_ESCREVA		(E|e)(S|s)(C|c)(R|r)(E|e)(V|v)(A|a)
T_ESCREVAL		(E|e)(S|s)(C|c)(R|r)(E|e)(V|v)(A|a)(L|l)
T_EXP			(E|e)(X|x)(P|p)
T_FACA			(F|f)(A|a)(C|c)(A|a)
T_FALSO			(F|f)(A|a)(L|l)(S|s)(O|o)
T_FIMALGORITMO		(F|f)(I|i)(M|m)(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(M|m)(O|o)
T_FIMENQUANTO		(F|f)(I|i)(M|m)(E|e)(N|n)(Q|q)(U|u)(A|a)(N|n)(T|t)(O|o)
T_FIMESCOLHA		(F|f)(I|i)(M|m)(E|e)(S|s)(C|c)(O|o)(L|l)(H|h)(A|a)
T_FIMFUNCAO		(F|f)(I|i)(M|m)(F|f)(U|u)(N|n)(C|c)(A|a)(O|o)
T_FIMPARA		(F|f)(I|i)(M|m)(P|p)(A|a)(R|r)(A|a)
T_FIMPROCEDIMENTO	(F|f)(I|i)(M|m)(P|p)(R|r)(O|o)(C|c)(E|e)(D|d)(I|i)(M|m)(E|e)(N|n)(T|t)(O|o)
T_FIMREPITA		(F|f)(I|i)(M|m)(R|r)(E|e)(P|p)(I|i)(T|t)(A|a)
T_FIMSE			(F|f)(I|i)(M|m)(S|s)(E|e)
T_FUNCAO		(F|f)(U|u)(N|n)(C|c)(A|a)(O|o)
T_GRAUPRAD		(G|g)(R|r)(A|a)(U|u)(P|p)(R|r)(A|a)(D|d)
T_INICIO		(I|i)(N|n)(I|i)(C|c)(I|i)(O|o)
T_INT			(I|i)(N|n)(T|t)
T_INTEIRO		(I|i)(N|n)(T|t)(E|e)(I|i)(R|r)(O|o)
T_INTERROMPA		(I|i)(N|n)(T|t)(E|e)(R|r)(R|r)(O|o)(M|m)(P|p)(A|a)
T_LEIA			(L|l)(E|e)(I|i)(A|a)
T_LIMPATELA		(L|l)(I|i)(M|m)(P|p)(A|a)(T|t)(E|e)(L|l)(A|a)
T_LITERAL		(L|l)(I|i)(T|t)(E|e)(R|r)(A|a)(L|l)
T_LOG			(L|l)(O|o)(G|g)
T_LOGICO		(L|l)(O|o)(G|g)(I|i)(C|c)(O|o)
T_MAIUSC		(M|m)(A|a)(I|i)(U|u)(S|s)(C|c)
T_MENSAGEM		(M|m)(E|e)(N|n)(S|s)(A|a)(G|g)(E|e)(M|m)
T_MINUSC		(M|m)(I|i)(N|n)(U|u)(S|s)(C|c)
T_MOD			(M|m)(O|o)(D|d)
T_NAO			(N|n)(A|a)(O|o)
T_NUMERICO		(N|n)(U|u)(M|m)(E|e)(R|r)(I|i)(C|c)(O|o)
T_NUMPCARAC		(N|n)(U|u)(M|m)(P|p)(C|c)(A|a)(R|r)(A|a)(C|c)
T_OU			(O|o)(U|u)
T_OUTROCASO		(O|o)(U|u)(T|t)(R|r)(O|o)(C|c)(A|a)(S|s)(O|o)
T_PARA			(P|p)(A|a)(R|r)(A|a)
T_PASSO			(P|p)(A|a)(S|s)(S|s)(O|o)
T_PAUSA			(P|p)(A|a)(U|u)(S|s)(A|a)
T_PI			(P|p)(I|i)
T_POS			(P|p)(O|o)(S|s)
T_PROCEDIMENTO		(P|p)(R|r)(O|o)(C|c)(E|e)(D|d)(I|i)(M|m)(E|e)(N|n)(T|t)(O|o)
T_QUAD			(Q|q)(U|u)(A|a)(D|d)
T_RADPGRAU		(R|r)(A|a)(D|d)(P|p)(G|g)(R|r)(A|a)(U|u)
T_RAIZQ			(R|r)(A|a)(I|i)(Z|z)(Q|q)
T_RAND			(R|r)(A|a)(N|n)(D|d)
T_RANDI			(R|r)(A|a)(N|n)(D|d)(I|i)
T_REAL			(R|r)(E|e)(A|a)(L|l)
T_REPITA		(R|r)(E|e)(P|p)(I|i)(T|t)(A|a)
T_RETONRE		(R|r)(E|e)(T|t)(O|o)(R|r)(N|n)(E|e)
T_SE			(S|s)(E|e)
T_SEN			(S|s)(E|e)(N|n)
T_SENAO			(S|s)(E|e)(N|n)(A|a)(O|o)
T_TAN			(T|t)(A|a)(N|n)
T_TIMER			(T|t)(I|i)(M|m)(E|e)(R|r)
T_VAR			(V|v)(A|a)(R|r)
T_VETOR			(V|v)(E|e)(T|t)(O|o)(R|r)
T_VERDADEIRO		(V|v)(E|e)(R|r)(D|d)(A|a)(D|e)(I|i)(R|r)(O|o)
T_XOU			(X|x)(O|o)(U|u)
T_COMENTARIO_UL 	"//".*(\n)?
T_COMENTARIO_ML 	\{(.*|\n)[^\}]*\}
T_NUMERO_INTEIRO	[0-9]+
T_NUMERO_REAL		[0-9]+\.[0-9]+
T_IDENTIFICADOR		[aA-zZ][aA-zZ0-9]*
T_INVALIDO		[0-9][aA-zZ0-9]*
T_STRING		\".*\"
T_BRANCO		[ \t\r]*


%%

{T_STRING}		{printf("T_STRING:\t%s\n", yytext);}
{T_ABS}			{printf("T_ABS:\t%s\n", yytext);}
{T_ALEATORIO}		{printf("T_ALEATORIO:\t%s\n", yytext);}
{T_ARCCOS}		{printf("T_ARCCOS:\t%s\n", yytext);}
{T_ARCSEN}		{printf("T_ARCSEN:\t%s\n", yytext);}
{T_ARCTAN}		{printf("T_ARCTAN:\t%s\n", yytext);}
{T_ATE}			{printf("T_ATE:\t%s\n", yytext);}
{T_ASC}			{printf("T_ASC:\t%s\n", yytext);}
{T_ARQUIVO}		{printf("T_ARQUIVO:\t%s\n", yytext);}
{T_ALGORITMO}		{printf("T_ALGORITMO:\t%s\n", yytext);}
{T_CARAC}		{printf("T_CARAC:\t%s\n", yytext);}
{T_CARACPNUM}		{printf("T_CARACPNUM:\t%s\n", yytext);}
{T_CARACTERE}		{printf("T_CARACTERE:\t%s\n", yytext);}
{T_CASO}		{printf("T_CASO:\t%s\n", yytext);}
{T_COMPR}		{printf("T_COMPR:\t%s\n", yytext);}
{T_COPIA}		{printf("T_COPIA:\t%s\n", yytext);}
{T_COS}			{printf("T_COS:\t%s\n", yytext);}
{T_COTAN}		{printf("T_COTAN:\t%s\n", yytext);}
{T_CRONOMETRO}		{printf("T_CRONOMETRO:\t%s\n", yytext);}
{T_DE}			{printf("T_DE:\t%s\n", yytext);}
{T_DEBUG}		{printf("T_DEBUG:\t%s\n", yytext);}
{T_DECLARE}		{printf("T_DECLARE:\t%s\n", yytext);}
{T_ECO}			{printf("T_ECO:\t%s\n", yytext);}
{T_ENQUANTO}		{printf("T_ENQUANTO:\t%s\n", yytext);}
{T_ENTAO}		{printf("T_ENTAO:\t%s\n", yytext);}
{T_ESCOLHA}		{printf("T_ESCOLHA:\t%s\n", yytext);}
{T_ESCREVA}		{printf("T_ESCREVA:\t%s\n", yytext);}
{T_ESCREVAL}		{printf("T_ESCREVAL:\t%s\n", yytext);}
{T_EXP}			{printf("T_EXP:\t%s\n", yytext);}
{T_FACA}		{printf("T_FACA:\t%s\n", yytext);}
{T_FALSO}		{printf("T_FALSO:\t%s\n", yytext);}
{T_FIMALGORITMO}	{printf("T_FIMALGORITMO:\t%s\n", yytext);}
{T_FIMENQUANTO}		{printf("T_FIMENQUANTO:\t%s\n", yytext);}
{T_FIMESCOLHA}		{printf("T_FIMESCOLHA:\t%s\n", yytext);}
{T_FIMFUNCAO}		{printf("T_FIMFUNCAO:\t%s\n", yytext);}
{T_FIMPARA}		{printf("T_FIMPARA:\t%s\n", yytext);}
{T_FIMPROCEDIMENTO}	{printf("T_FIMPROCEDIMENTO:\t%s\n", yytext);}
{T_FIMREPITA}		{printf("T_FIMREPITA:\t%s\n", yytext);}
{T_FIMSE}		{printf("T_FIMSE:\t%s\n", yytext);}
{T_FUNCAO}		{printf("T_FUNCAO:\t%s\n", yytext);}
{T_GRAUPRAD}		{printf("T_GRAUPRAD\t%s\n", yytext);}
{T_INICIO}		{printf("T_INICIO:\t%s\n", yytext);}
{T_INT}			{printf("T_INT:\t%s\n", yytext);}
{T_INTEIRO}		{printf("T_INTEIRO:\t%s\n", yytext);}
{T_INTERROMPA}		{printf("T_INTERROMPA:\t%s\n", yytext);}
{T_LEIA}		{printf("T_LEIA:\t%s\n", yytext);}
{T_LIMPATELA}		{printf("T_LIMPATELA:\t%s\n", yytext);}
{T_LITERAL}		{printf("T_LITERAL:\t%s\n", yytext);}
{T_LOG}			{printf("T_LOG:\t%s\n", yytext);}
{T_LOGICO}		{printf("T_LOGICO:\t%s\n", yytext);}
{T_MAIUSC}		{printf("T_MAIUSC:\t%s\n", yytext);}
{T_MENSAGEM}		{printf("T_MENSAGEM:\t%s\n", yytext);}
{T_MINUSC}		{printf("T_MINUSC:\t%s\n", yytext);}
{T_NUMPCARAC}		{printf("T_NUMPCARAC:\t%s\n", yytext);}
{T_NUMERICO}		{printf("T_NUMERICO:\t%s\n", yytext);}
{T_OUTROCASO}		{printf("T_OUTROCASO:\t%s\n", yytext);}
{T_PARA}		{printf("T_PARA:\t%s\n", yytext);}
{T_PASSO}		{printf("T_PASSO:\t%s\n", yytext);}
{T_PAUSA}		{printf("T_PAUSA:\t%s\n", yytext);}
{T_PI}			{printf("T_PI:\t%s\n", yytext);}
{T_POS}			{printf("T_POS:\t%s\n", yytext);}
{T_PROCEDIMENTO}	{printf("T_PROCEDIMENTO:\t%s\n", yytext);}
{T_QUAD}		{printf("T_QUAD:\t%s\n", yytext);}
{T_RADPGRAU}		{printf("T_RADPGRAU:\t%s\n", yytext);}
{T_RAIZQ}		{printf("T_RAIZQ:\t%s\n", yytext);}
{T_RAND}		{printf("T_RAND:\t%s\n", yytext);}
{T_RANDI}		{printf("T_RANDI:\t%s\n", yytext);}
{T_REAL}		{printf("T_REAL:\t%s\n", yytext);}
{T_REPITA}		{printf("T_REPITA:\t%s\n", yytext);}
{T_RETONRE}		{printf("T_RETORNE:\t%s\n", yytext);}
{T_SE}			{printf("T_SE:\t%s\n", yytext);}
{T_SEN}			{printf("T_SEN:\t%s\n", yytext);}
{T_SENAO}		{printf("T_SENAO:\t%s\n", yytext);}
{T_TAN}			{printf("T_TAN:\t%s\n", yytext);}
{T_TIMER}		{printf("T_TIMER:\t%s\n", yytext);}
{T_VAR}			{printf("T_VAR:\t%s\n", yytext);}
{T_VETOR}		{printf("T_VETOR:\t%s\n", yytext);}
{T_VERDADEIRO}		{printf("T_VERDADEIRO:\t%s\n", yytext);}
{T_COMENTARIO_UL}	{printf("T_COMENTARIO_UL:\t%s\n",yytext);} 
{T_COMENTARIO_ML}	{printf("T_COMENTARIO_ML:\t%s\n",yytext);} 
"+"                 	{printf("T_OPERADOR_SOMA:\t%s\n", yytext);}
"-"                 	{printf("T_OPERADOR_SUBTRACAO:\t%s\n", yytext);}
"*"                 	{printf("T_OPERADOR_MULTIPLICACAO:\t%s\n", yytext);}
"/"                 	{printf("T_OPERADOR_DIVISAO:\t%s\n", yytext);}
"\\"                	{printf("T_OPERADOR_DIVISAO_INT:\t%s\n", yytext);}
"\^"                	{printf("T_OPERADOR_EXPONENCIACAO:\t%s\n", yytext);}
"%"                 	{printf("T_OPERADOR_DIVISAO_RESTO:\t%s\n", yytext);}
{T_MOD}			{printf("T_OPERADOR_DIVISAO_RESTO:\t%s\n", yytext);}
"="                 	{printf("T_OPERADOR_IGUAL:\t%s\n", yytext);}
"<>"                	{printf("T_OPERADOR_DIFERENTE:\t%s\n", yytext);}
"<"                 	{printf("T_OPERADOR_MENOR:\t%s\n", yytext);}
">"                 	{printf("T_OPERADOR_MAIOR:\t%s\n", yytext);}
"<="               	{printf("T_OPERADOR_MENOR_IGUAL:\t%s\n", yytext);}
">="                	{printf("T_OPERADOR_MAIOR_IGUAL:\t%s\n", yytext);}
"("                 	{printf("T_PARENTESE_ESQ:\t%s\n", yytext);}
")"                 	{printf("T_PARENTESE_DIR:\t%s\n", yytext);}
"<-"                	{printf("T_OPERADOR_ATRIBUICAO:\t%s\n", yytext);}
","			{printf("T_IDENT_SEPARADOR:\t%s\n", yytext);}
":"			{printf("T_TIPO_ATRIBUIDOR:\t%s\n", yytext);}
{T_NUMERO_INTEIRO}	{printf("T_NUMERO_INTEIRO:\t%s\n", yytext);}
{T_NUMERO_REAL}		{printf("T_NUMERO_REAL:\t%s\n", yytext);}
{T_E}			{printf("T_OP_LOGICO_E:\t%s\n", yytext);}
{T_XOU}			{printf("T_OP_LOGICO_XOU:\t%s\n", yytext);}
{T_NAO}			{printf("T_OP_LOGICO_NAO:\t%s\n", yytext);}
{T_OU}			{printf("T_OP_LOGICO_OU:\t%s\n", yytext);}

{T_IDENTIFICADOR}	{printf("T_IDENTIFICADOR:\t%s\n", yytext);}
{T_BRANCO}		{}
\n			{}
{T_INVALIDO}		{
			  struct par_linha_token token_invalido;
			  token_invalido.token=malloc(sizeof(yytext));
			  memcpy(token_invalido.token, yytext, sizeof(yytext));
			  memcpy(&token_invalido.linha, &yylineno, sizeof(int));
			  linhas_erro[indice]=token_invalido; 
			  indice++;
			}
.			{
			  struct par_linha_token token_invalido;
			  token_invalido.token=malloc(sizeof(yytext));
			  memcpy(token_invalido.token, yytext, sizeof(yytext));
			  memcpy(&token_invalido.linha, &yylineno, sizeof(int));
			  linhas_erro[indice]=token_invalido; 
			  indice++;
			}
%%

main(int argc, char *argv[])
{
	int i;	//Indice que irá percorrer o vetor de linhas inválidas
	int c; 	//Guarda o caracter lido do arquivo

	if (argc < 2)
	{
		printf ("Missing input file\n");exit(ERRO);
	}

	//Extrai a quantidade de linhas do algoritmo para que seja alocada memória para o vetor de linhas inválidas
	yyin = fopen(argv[1], "r" );
	while ( (c=fgetc(yyin)) != EOF ) {
		if ( c == '\n' )
			qtd_linhas++;
		}

	//Aloca a quantidade de memória suficiente para gravar as linha inválidas do algoritmo
	linhas_erro = malloc(qtd_linhas*sizeof (par_linha_token));

	yyin = fopen(argv[1], "r" );
	if(!yylex())
	{
		printf("\n---------------------------------------------------------------\n");
		if (indice > 1)
		{
			for(i=1;i<=indice-1;i++)
				printf("Token desconhecido [%s] na linha: %d\n", linhas_erro[i].token, linhas_erro[i].linha);
			free(linhas_erro);
		} 
		else
		{
			printf("***Sucesso: todos os tokens do algoritmo foram reconhecidos!\n");
			free(linhas_erro);
		}
	}
}

