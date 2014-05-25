algoritmo "AlgoritmoFibonacci"
var
cont, n, num, atual, ant : inteiro
inicio
cont <- 0
escreval ("Quantos numeros da cadeia fibonacci deseja ver?")
escreval ("Digite um numero maior que zero!")
leia (n)

se n <=0 entao
   escreval ("Numero Inválido!!!")
senao
   se (n=1) entao
      escreval ("")
      escreval ("O primeiro numero da cadeia Fibonacci: ")
      escreval ("1 ")
   senao
      escreval ("")
      escreval ("Os",n," primeiros numeros da cadeia Fibonacci: ")
      se n=1 entao
         escreval ("1 ")
      senao
         escreva ("1  ")
         atual <- 1
         ant <- 0
         repita
            num <- atual + ant
            escreva ("- ", num, "  ")
            ant <- atual
            atual <- num
            cont <- cont + 1
         ate (cont = n-1)
      fimse
   fimse
fimse
escreval ("")
fimalgoritmo
