algoritmo "AlgoritmoFibonacci"
var
cont, n, num, atual, ant : inteiro
inicio
      cont <- 0
      escreval ("Gerando série Fibonacci até valor maior que 500...")
      escreval ("")
      escreva ("0 1")
      atual <- 1
      ant <- 0
      repita
            num <- atual + ant
            escreva (num)
            ant <- atual
            atual <- num
            cont <- cont + 1
      ate (atual > 500)
      escreval ("")
      escreval ("")
      escreval ("Maior número foi", atual)
fimalgoritmo
