algoritmo "Média de idade"
// Função : Calcula a média de idade
// Autor : Daniel Aquino
// Data : 8/5/2013
// Seção de Declarações
var
idade, total, soma, num, i: inteiro
media: real
inicio
      total <- 0
      soma <- 0
      //insere as notas a media que elas estiverem dentro da faixe entre 0 e 10 inclusive
      repita
            escreva("Escreva o numero total de pessoas: ")
            leia(num)
      ate (num > 0)

      para i de 1 ate num faca
            escreva("Informa a idade da pessoa ", i, ": ")
            leia(idade)
            //soma das notas
            soma <- soma + idade
            //total das notas
            total <- total + 1
      fimpara

      //calculo da média
      media <- soma / total
      //imprime se a turma é jovem, adulta ou idosa
      se (media < 26) entao
         escreval("A turma é jovem")
      senao
         se (media < 61) entao
               escreval("A turma é adulta")
         senao
           escreval("A turma é idosa")
         fimse
      fimse
fimalgoritmo
