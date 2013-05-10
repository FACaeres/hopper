algoritmo "Média de idade"
// Função : Calcula a média de notas
// Autor : Daniel Aquino
// Data : 8/5/2013
// Seção de Declarações
var
nota, total, soma, num, i: inteiro
media: real
inicio
      total <- 0
      soma <- 0
      //insere as notas a media que elas estiverem dentro da faixe entre 0 e 10 inclusive
      repita
            escreva("Escreva o numero total de notas: ")
            leia(num)
      ate (num > 0)

      para i de 1 ate num faca
            escreva("Escreva a nota ", i, ": ")
            leia(nota)
            //soma das notas
            soma <- soma + nota
            //total das notas
            total <- total + 1
      fimpara
      
      //calculo da média
      media <- soma / total
      //imprime média da turma
      escreval("Média da turma: ", media:1:2)

fimalgoritmo
