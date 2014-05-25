algoritmo "nome_na_vertical_escada_inv"
// Função : Programa que solicita o nome do usuario e o imprime na vertical
//          em forma de escada invertida.
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

      // Usa-se um laco de repeticao para decrementar a quantidade de caracteres do
      // nome do usuario que sera impressa por linha do console a cada iteracao.
      
      // Usa-se a funcao copia() para se obter o conjunto de caracteres
      // de um tamanho 'i'.
      
      para i de nome_tam ate 1 passo -1 faca
           letra <- copia(nome,1,i)
           escreval(letra)
      fimpara
      
fimalgoritmo
