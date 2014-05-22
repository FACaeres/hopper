algoritmo "nome_na_vertical"
// Função : Programa que solicita o nome do usuario e o imprime na vertical.
// Autor :  Darlisson Jesus
// Data : 6/6/2013

var

   // Declaracao de variaveis.
   letra,nome: caracter
   nome_tam,i: inteiro

inicio

      // Solicita o nome do usuario.
      
      escreva("Digite seu nome: ")
      leia(nome)

      // Transforma em maiusculo o nome do usuario.
      
      nome <-maiusc(nome)
      
      // Obtem o tamanho do nome do usuario.

      nome_tam <- compr(nome)

      // Usa um laco de repeticao para percorrer caracter
      // por caracter do nome do usuario e imprime um caracter por
      // linha no console.
      
      // Usa-se a funcao copia() para se obter um unico caracter
      // a cada laco de repeticao.
      
      i <- 1
      repita
           letra <- copia(nome,i,1)
           escreval(letra)
           i <- i+1
      ate i = nome_tam+1

fimalgoritmo
