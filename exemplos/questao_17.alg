algoritmo "questao_07"

// Descricao : Programa que le três números e mostra o maior e o menor deles.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    num1, num2, num3, menor, maior:inteiro

inicio
	// Faz a leitura dos 3 numeros inteiros.
    escreva("Informe o primeiro numero: ")
    leia(num1)
    escreva("Informe o segundo numero: ")
    leia(num2)
    escreva("Informe o terceiro numero: ")
    leia(num3)
	
	// Faz a comparacao um a um para descobrir o maior e o menor valor informado
	// e atribuir se valor para a variavel 'maior' e 'menor', respectivamente.
	
    se num1 > num2 entao
        se num1 > num3 entao
            maior <- num1
            se num2 > num3 entao
                menor <- num3
            senao
                menor <- num2
            fimse
        senao
            maior <- num3
            menor <- num2
        fimse
    senao
        se num2 > num3  entao
            maior <- num2
            se num1 > num3 entao
                menor <- num3
            senao
                menor <- num1
            fimse
        senao
            maior <- num3
            menor <- num1
        fimse
    fimse
	
	// Exibe na tela maior e o menor valor informado.
    escreva("O maior valor digitado foi: <", maior)
    escreva("> e o menor valor digitado foi: <", menor,">")
    
fimalgoritmo
