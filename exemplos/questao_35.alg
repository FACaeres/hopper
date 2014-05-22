algoritmo "compara_strings"

// Função : Programa que ler 2 strings e informa o
//          conteudo delas seguido do seu comprimento.
//          Informa tambem se as duas strings possuem o
//          mesmo comprimento e se sao iguais ou diferentes no conteudo.
// Autor : Darlisson Jesus
// Data : 6/6/2013

var
   // Declaracao de variaveis
   str1, str2:caracter
   str1_tam, str2_tam:inteiro
   
inicio

      // Solicita que o usuario informe as strings.
      
      escreva("Digite a primeira string: ")
      leia(str1)
      escreva("Digite a segunda string: ")
      leia(str2)
      
      // Imprime para o usuario informacoes
      // sobre as strings.
      
      escreval("Compara duas strings")
      escreval("string 1: ", str1 )
      escreval("string 2: ", str2 )

      // Atribui as variaveis inteiro tam1 e tam2
      // o tamanho das respectivas strings ( str1 e str2)
      // Usa-se a funcao da linguagem compr() que recebe uma
      // cadeia de caracter e retorna tamanho dessa cadeia.
      
      str1_tam <- compr(str1)
      str2_tam <- compr(str2)

      // Informa ao usuario o tamanho das strings.
      
      escreval("Tamanho de '", str1,"' :",str1_tam," caracteres.")
      escreval("Tamanho de '", str2,"' :",str2_tam, " caracteres.")
      
      // Informa ao usuario se as strings possuem o mesmo
      // tamanho e mesmo conteudo.
      
      se(str1_tam = str2_tam)entao
          escreval("As duas strings sao de tamanhos iguais.")

          se (str1 = str2) entao
             escreval("As duas strings possuem conteudos iguais.")
          fimse
      senao
          escreval("As duas strings sao de tamanhos diferentes.")
          escreval("As duas strings possuem conteudos diferentes.")
      fimse

fimalgoritmo
