algoritmo "questao_06"

// Descricao : Programa que le três números inteiros e mostra o maior deles.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    num1, num2, num3, maior:inteiro

inicio
	// Faz a leitura dos 3 numeros inteiros.
    escreva("Informe o primeiro numero: ")
    leia(num1)
    escreva("Informe o segundo numero: ")
    leia(num2)
    escreva("Informe o terceiro numero: ")
    leia(num3)
    
	// Faz a comparacao um a um para descobrir o maior valor informado
	// e atribuir se valor para a variavel 'maior'.
	
    se num1 > num2 entao
        se num1 > num3 entao
           maior <- num1
        senao
           maior <- num3
        fimse
   senao
        se num2 > num3  entao
            maior <- num2
        senao
             maior <- num3
        fimse
    fimse
	
	// Exibe na tela maior valor informado.	
    escreva("O maior valor digitado foi: <", maior, ">")
   
fimalgoritmo
