algoritmo "MaiorMenorSoma"
var
      num, maior, menor, soma: inteiro
inicio
      num <- 0
      maior <- 0
      menor <- 9999
      soma <- 0

      enquanto num >= 0 faca
               escreva("Insira um número (numero negativo encerra): ")
               leia(num)

               se num < 0 entao
                  escreval("Encerrando!")
               senao
                    se num > maior entao
                       maior <- num
                    fimse
                    se num < menor entao
                       menor <- num
                    fimse
                    soma <- soma + num
               fimse
      fimenquanto

      escreval("Maior numero: ", maior)
      escreval("Menor numero: ", menor)
      escreval("Soma dos numeros: ", soma)

fimalgoritmo
