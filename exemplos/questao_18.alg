algoritmo "questao_08"

// Descrição : Programa que pergunta o preço de três produtos e
//             informe qual produto você deve comprar, sabendo
//             que a decisão é sempre pelo mais barato.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    preco_prod1, preco_prod2, preco_prod3:real

inicio
    // Faz a leitura dos 3 valores reais de cada produto.
    escreva("Informe o preco do primeiro produto R$: ")
    leia(preco_prod1)
    escreva("Informe o preco do segundo produto R$: ")
    leia(preco_prod2)
    escreva("Informe o preco do terceiro produto R$: ")
    leia(preco_prod3)

	// Faz a comparacao um a um para descobrir o menor valor informado
	// e exibe na tela qual e o produto mais barato.
	
    se preco_prod1 > preco_prod2 entao
        se preco_prod2 > preco_prod3 entao
            escreva("Recomendamos o terceiro produto, com o preco de R$: ", preco_prod3)
        senao
            escreva("Recomendamos o segundo produto, com o preco de R$: ", preco_prod2)
        fimse
    senao
        se preco_prod3 > preco_prod1 entao
            escreva("Recomendamos o primeiro produto, com o preco de R$: ", preco_prod1)
        senao
            escreva("Recomendamos o terceiro produto, com o preco de R$: ", preco_prod3)
        fimse
    fimse

fimalgoritmo