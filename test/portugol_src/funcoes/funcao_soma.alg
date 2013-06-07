algoritmo "funcao_soma"

var
   a,b,c,resultado_soma : inteiro

funcao soma(a, b, c : inteiro) : inteiro
inicio
      retorne a+b+c
fimfuncao

inicio
      escreva("Informe o valor de a: ")
      leia(a)
      escreva("Informe o valor de b: ")
      leia(b)
      escreva("Informe o valor de c: ")
      leia(c)

      resultado_soma <- soma(a,b,c)
      escreval("O Resultado da soma e: ",resultado_soma)
      
fimalgoritmo
