algoritmo "questao_04"

// Descricao: Programa que verifica se uma letra digitada é vogal ou consoante.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    letra_digitada:caracter

inicio
	// Faz a leitura da letra.
    escreva("Digite uma letra do alfabeto: ")
    leia(letra_digitada)
	
	// Faz a decisao da mensagem a ser mostrada. 
    escolha letra_digitada
	
   // Se a letra digitada nao se encaixa nos casos de vogal('a','e','i','o','u')
   // entao trata-se de um outro caso, uma consoante.
   
    caso "a"
        escreva("A letra <" ,letra_digitada,"> eh uma vogal")
    caso "e"
        escreva("A letra <" ,letra_digitada,"> eh uma vogal")
    caso "i"
        escreva("A letra <" ,letra_digitada,"> eh uma vogal")
	caso "o"
        escreva("A letra <" ,letra_digitada,"> eh uma vogal")
	caso "u"
        escreva("A letra <" ,letra_digitada,"> eh uma vogal")
    outrocaso
        escreva("A letra <" ,letra_digitada,"> eh uma consoante")
    fimescolha

fimalgoritmo
