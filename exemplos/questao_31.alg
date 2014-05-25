algoritmo "nome_maiusc"
// Função : Programa que permita ao usuario digitar
//          o seu nome e em seguida mostra o nome do usuario
//          de tras para frente utilizando somente letras
//          maiusculas.
// Autor : Darlisson Jesus
// Data : 6/6/2013

var

   // Declaracao de variaveis.
   
   letra,nome: caracter
   nome_tam,i:inteiro
   
inicio

   // Solicita que o usuario informe seu nome.

   escreva("Digite seu nome: ")
   leia(nome)
   
   // Usa a funcao maiusc() para transformar o nome do usuario
   // para maiusculo.
   // maiusc() recebe uma cadeia de caracteres e retorna essa cadeia
   // em maiusculo.
   
   nome <-maiusc(nome)

   // Usa a funcao compr()para obter o tamanho do nome do usuario
   // compr() recebe uma cadeia de caracteres e retorna um seu tamanho
   nome_tam<- compr(nome)
   
   // Inicio a impressao do nome do usuario em maiusculo e
   // invertido.
   
   escreva("Seu nome em Maiusculo invertido: ")
   
   // Nesse trecho usa-se um laco de repeticao para obter caracter por caracter
   // do nome do usuario, de tras para frente que eh armazenado na variavel letra,
   // usando a funcao copia().

   // Usa-se a funcao copia(str,posicao_inicial,qtd) que retorna uma quantidade
   // especifica de caracateres a partir de uma posicao da string.
   // onde str - eh uma cadeia de caracteres
   // posicao_inicial -  representa a posicao na string para iniciar a copia
   // qtd representa a quantidade de caracteres que se deseja copiar.

   // A variavel letra recebe um caracter de tras pra frente do nome
   // em cada iteracao do laco.
   
   para i de nome_tam ate 1 passo -1 faca
      letra <- copia(nome,i,1)
      escreva(letra)
   fimpara

fimalgoritmo
