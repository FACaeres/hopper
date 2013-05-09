%{

%}

T_ALEATORIO			(A|a)(L|l)(E|e)(A|a)(T|t)(O|o)(R|r)(I|i)(O|o)
T_ATE				(A|a)(T|t)(E|e)
T_ASC				(A|a)(S|s)(C|c)
T_ARQUIVO			(A|a)(R|r)(Q|q)(U|u)(I|i)(V|v)(O|o)
T_ALGORITMO			(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(M|m)(O|o)
T_CARAC				(C|c)(A|a)(R|r)(A|a)(C|c)
T_CARACPNUM			(C|c)(A|a)(R|r)(A|a)(C|c)(P|p)(N|n)(U|u)(M|m)
T_CARACTERE			(C|c)(A|a)(R|r)(A|a)(C|c)(T|t)(E|e)(R|r)(E|e)
T_CASO				(C|c)(A|a)(S|s)(O|o)
T_COMPR				(C|c)(O|o)(M|m)(P|p)(R|r)
T_COPIA				(C|c)(O|o)(P|p)(I|i)(A|a)
T_CRONOMETRO			(C|c)(R|r)(O|o)(N|n)(O|o)(M|m)(E|e)(T|t)(R|r)(O|o)
T_DE				(D|d)(E|e)
T_DEBUG				(D|d)(E|e)(B|b)(U|u)(G|g)
T_E				(E|e)
T_ECO				(E|e)(C|c)(O|o)
T_ENQUANTO			(E|e)(N|n)(Q|q)(U|u)(A|a)(N|n)(T|t)(O|o)
T_ENTAO				(E|e)(N|n)(T|t)(A|a)(O|o)
T_ESCOLHA			(E|e)(S|s)(C|c)(O|o)(L|l)(H|h)(A|a)
T_ESCREVA			(E|e)(S|s)(C|c)(R|r)(E|e)(V|v)(A|a)
T_ESCREVAL			(E|e)(S|s)(C|c)(R|r)(E|e)(V|v)(A|a)(L|l)
T_FACA				(F|f)(A|a)(C|c)(A|a)
T_FALSO				(F|f)(A|a)(L|l)(S|s)(O|o)
T_FIMALGORITMO			(F|f)(I|i)(M|m)(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(M|m)(O|o)
T_FIMENQUANTO			(F|f)(I|i)(M|m)(E|e)(N|n)(Q|q)(U|u)(A|a)(N|n)(T|t)(O|o)
T_FIMESCOLHA			(F|f)(I|i)(M|m)(E|e)(S|s)(C|c)(O|o)(L|l)(H|h)(A|a)
T_FIMFUNCAO			(F|f)(I|i)(M|m)(F|f)(U|u)(N|n)(C|c)(A|a)(O|o)
T_FIMPARA			(F|f)(I|i)(M|m)(P|p)(A|a)(R|r)(A|a)
T_FIMPROCEDIMENTO		(F|f)(I|i)(M|m)(P|p)(R|r)(O|o)(C|c)(E|e)(D|d)(I|i)(M|m)(E|e)(N|n)(T|t)(O|o)
T_FIMREPITA			(F|f)(I|i)(M|m)(R|r)(E|e)(P|p)(I|i)(T|t)(A|a)
T_FIMSE				(F|f)(I|i)(M|m)(S|s)(E|e)
T_FUNCAO			(F|f)(U|u)(N|n)(C|c)(A|a)(O|o)
T_INICIO			(I|i)(N|n)(I|i)(C|c)(I|i)(O|o)
T_INT				(I|i)(N|n)(T|t)
T_INTEIRO			(I|i)(N|n)(T|t)(E|e)(I|i)(R|r)(O|o)
T_INTERROMPA			(I|i)(N|n)(T|t)(E|e)(R|r)(R|r)(O|o)(M|m)(P|p)(A|a)
T_LEIA				(L|l)(E|e)(I|i)(A|a)
T_LIMPATELA			(L|l)(I|i)(M|m)(P|p)(A|a)(T|t)(E|e)(L|l)(A|a)
T_LOGICO			(L|l)(O|o)(G|g)(I|i)(C|c)(O|o)
T_MAIUSC			(M|m)(A|a)(I|i)(U|u)(S|s)(C|c)
T_MINUSC			(M|m)(I|i)(N|n)(U|u)(S|s)(C|c)
T_MOD				(M|m)(O|o)(D|d)
T_NAO				(N|n)(A|a)(O|o)
T_NUMPCARAC			(N|n)(U|u)(M|m)(P|p)(C|c)(A|a)(R|r)(A|a)(C|c)
T_OU				(O|o)(U|u)
T_OUTROCASO			(O|o)(U|u)(T|t)(R|r)(O|o)(C|c)(A|a)(S|s)(O|o)
T_PARA				(P|p)(A|a)(R|r)(A|a)
T_PASSO				(P|p)(A|a)(S|s)(S|s)(O|o)
T_PAUSA				(P|p)(A|a)(U|u)(S|s)(A|a)
T_POS				(P|p)(O|o)(S|s)
T_PROCEDIMENTO			(P|p)(R|r)(O|o)(C|c)(E|e)(D|d)(I|i)(M|m)(E|e)(N|n)(T|t)(O|o)
T_REAL				(R|r)(E|e)(A|a)(L|l)
T_REPITA			(R|r)(E|e)(P|p)(I|i)(T|t)(A|a)
T_RETONRE			(R|r)(E|e)(T|t)(O|o)(R|r)(N|n)(E|e)
T_SE				(S|s)(E|e)
T_SENAO				(S|s)(E|e)(N|n)(A|a)(O|o)
T_TIMER				(T|t)(I|i)(M|m)(E|e)(R|r)
T_VAR				(V|v)(A|a)(R|r)
T_VETOR				(V|v)(E|e)(T|t)(O|o)(R|r)
T_VERDADEIRO			(V|v)(E|e)(R|r)(D|d)(A|a)(D|e)(I|i)(R|r)(O|o)
T_XOU				(X|x)(O|o)(U|u)
T_COMENTARIO_UL 		"//".*(\n)?
T_COMENTARIO_ML 		\{(.*|\n)[^\}]*\}
T_IDENTIFICADOR			[aA-zZ][aA-zZ0-9]*
T_STRING			\".*\"
T_BRANCO			[ \t\r]*


%%

{T_STRING}			{printf("T_STRING:\t%s\n", yytext);}
{T_ALEATORIO}			{printf("T_ALEATORIO:\t%s\n", yytext);}
{T_ATE}				{printf("T_ATE:\t%s\n", yytext);}
{T_ASC}				{printf("T_ASC:\t%s\n", yytext);}
{T_ARQUIVO}			{printf("T_ARQUIVO:\t%s\n", yytext);}
{T_ALGORITMO}			{printf("T_ALGORITMO:\t%s\n", yytext);}
{T_CARAC}			{printf("T_CARAC:\t%s\n", yytext);}
{T_CARACPNUM}			{printf("T_CARACPNUM:\t%s\n", yytext);}
{T_CARACTERE}			{printf("T_CARACTERE:\t%s\n", yytext);}
{T_CASO}			{printf("T_CASO:\t%s\n", yytext);}
{T_COMPR}			{printf("T_COMPR:\t%s\n", yytext);}
{T_COPIA}			{printf("T_COPIA:\t%s\n", yytext);}
{T_CRONOMETRO}			{printf("T_CRONOMETRO:\t%s\n", yytext);}
{T_DE}				{printf("T_DE:\t%s\n", yytext);}
{T_DEBUG}			{printf("T_DEBUG:\t%s\n", yytext);}
{T_E}				{printf("T_E:\t%s\n", yytext);}
{T_ECO}				{printf("T_ECO:\t%s\n", yytext);}
{T_ENQUANTO}			{printf("T_ENQUANTO:\t%s\n", yytext);}
{T_ENTAO}			{printf("T_ENTAO:\t%s\n", yytext);}
{T_ESCOLHA}			{printf("T_ESCOLHA:\t%s\n", yytext);}
{T_ESCREVA}			{printf("T_ESCREVA:\t%s\n", yytext);}
{T_ESCREVAL}			{printf("T_ESCREVAL:\t%s\n", yytext);}
{T_FACA}			{printf("T_FACA:\t%s\n", yytext);}
{T_FALSO}			{printf("T_FALSO:\t%s\n", yytext);}
{T_FIMALGORITMO}		{printf("T_FIMALGORITMO:\t%s\n", yytext);}
{T_FIMENQUANTO}			{printf("T_FIMENQUANTO:\t%s\n", yytext);}
{T_FIMESCOLHA}			{printf("T_FIMESCOLHA:\t%s\n", yytext);}
{T_FIMFUNCAO}			{printf("T_FIMFUNCAO:\t%s\n", yytext);}
{T_FIMPARA}			{printf("T_FIMPARA:\t%s\n", yytext);}
{T_FIMPROCEDIMENTO}		{printf("T_FIMPROCEDIMENTO:\t%s\n", yytext);}
{T_FIMREPITA}			{printf("T_FIMREPITA:\t%s\n", yytext);}
{T_FIMSE}			{printf("T_FIMSE:\t%s\n", yytext);}
{T_FUNCAO}			{printf("T_FUNCAO:\t%s\n", yytext);}
{T_INICIO}			{printf("T_INICIO:\t%s\n", yytext);}
{T_INT}				{printf("T_INT:\t%s\n", yytext);}
{T_INTEIRO}			{printf("T_INTEIRO:\t%s\n", yytext);}
{T_INTERROMPA}			{printf("T_INTERROMPA:\t%s\n", yytext);}
{T_LEIA}			{printf("T_LEIA:\t%s\n", yytext);}
{T_LIMPATELA}			{printf("T_LIMPATELA:\t%s\n", yytext);}
{T_LOGICO}			{printf("T_LOGICO:\t%s\n", yytext);}
{T_MAIUSC}			{printf("T_MAIUSC:\t%s\n", yytext);}
{T_MINUSC}			{printf("T_MINUSC:\t%s\n", yytext);}
{T_MOD}				{printf("T_MOD:\t%s\n", yytext);}
{T_NAO}				{printf("T_NAO:\t%s\n", yytext);}
{T_NUMPCARAC}			{printf("T_NUMPCARAC:\t%s\n", yytext);}
{T_OU}				{printf("T_OU:\t%s\n", yytext);}
{T_OUTROCASO}			{printf("T_OUTROCASO:\t%s\n", yytext);}
{T_PARA}			{printf("T_PARA:\t%s\n", yytext);}
{T_PASSO}			{printf("T_PASSO:\t%s\n", yytext);}
{T_PAUSA}			{printf("T_PAUSA:\t%s\n", yytext);}
{T_POS}				{printf("T_POS:\t%s\n", yytext);}
{T_PROCEDIMENTO}		{printf("T_PROCEDIMENTO:\t%s\n", yytext);}
{T_REAL}			{printf("T_REAL:\t%s\n", yytext);}
{T_REPITA}			{printf("T_REPITA:\t%s\n", yytext);}
{T_RETONRE}			{printf("T_RETORNE:\t%s\n", yytext);}
{T_SE}				{printf("T_SE:\t%s\n", yytext);}
{T_SENAO}			{printf("T_SENAO:\t%s\n", yytext);}
{T_TIMER}			{printf("T_TIMER:\t%s\n", yytext);}
{T_VAR}				{printf("T_VAR:\t%s\n", yytext);}
{T_VETOR}			{printf("T_VETOR:\t%s\n", yytext);}
{T_VERDADEIRO}			{printf("T_VERDADEIRO:\t%s\n", yytext);}
{T_XOU}				{printf("T_XOU:\t%s\n", yytext);}
{T_COMENTARIO_UL}               {printf("T_COMENTARIO_UL:\t%s\n",yytext);} 
{T_COMENTARIO_ML}               {printf("T_COMENTARIO_ML:\t%s\n",yytext);} 

{T_IDENTIFICADOR}		{printf("T_IDENTIFICADOR:\t%s\n", yytext);}

{T_BRANCO}			{}
.				{printf("Token inválido:\t%s\n", yytext);}
%%

main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf ("Missing input file\n");exit(-1);
	}
	yyin = fopen(argv[1], "r" );
	yylex();
}
