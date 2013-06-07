algoritmo "imprime_nesima_02"

var
   n : inteiro

procedimento imprime(n : inteiro)
var
   i, j : inteiro
inicio
      para i de 1 ate n faca
       para j de 1 ate i faca
           escreva(j)
       fimpara
       escreval(" ")
      fimpara
fimprocedimento

inicio
      escreva("Informe o valor de n: ")
      leia(n)
      imprime(n)
fimalgoritmo
