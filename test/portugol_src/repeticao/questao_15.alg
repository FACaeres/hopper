algoritmo "AlgoritmoFibonacci"
// Função : Gera a sequencia de Fibonacci até a posicao informada pelo usuario
//          Consideremos a série como 1 1 2 3 5 8 13 21 34 ...
// Autor :  Leandro Bentes
var
   cont, n, num, atual, ant : inteiro
inicio
      cont <- 0
      escreval ("Quantos numeros da cadeia fibonacci deseja ver?")
      escreval ("Digite um numero maior que zero!")
      leia (n) //Lê o valor de entrada do usuário

      se n <=0 entao
         escreval ("Numero Inválido!!!")
      senao
           se (n=1) entao //Caso o usuário só queira a primeira posicao
              escreval ("")
              escreval ("O primeiro numero da cadeia Fibonacci: ")
              escreval ("1 ")
           senao //Caso o usuário deseja mais de uma posicao
                 escreval ("")
                 escreval ("Os",n," primeiros numeros da cadeia Fibonacci: ")
                 escreva ("1  ")//Primeiro elemento considerado como 1
                 atual <- 1
                 ant <- 0
                 //Este bloco aplica a definicao matematica da serie de
                 //Fibonacci, onde a o elemento da posicao N na sequencia é a
                 //soma dos dois anteriores N-1 + N-2
                 repita
                       num <- atual + ant //A saída é a soma dos dois valores anteriores
                       escreva ("- ", num, "  ")  // Exibe a saída N
                       ant <- atual  // N-2 receve o valor de N-1
                       atual <- num  // N-1 recebe o valor de N
                       cont <- cont + 1
                 ate (cont = n-1)  //termina a repeticao assim quando o laço
                                   // a posicao desejada -1, pois o primeiro
                                   //elemento ja foi impresso fora do laco
           fimse
      fimse
      escreval ("")
fimalgoritmo
