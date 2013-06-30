algoritmo "Negativo_ou_positivo"
// Função : Faça um Programa que peça um valor
//          e mostre na tela se o valor é positivo ou negativo.
// Autor : Iasmim Cunha
// Data : 5/8/2013
// Seção de Declarações 
var
  valor : real
  primeiro, segundo: inteiro
inicio
// Seção de Comandos
escreval("Entre com o primeiro valor...")
leia(primeiro)
escreval("Entre com o segundo valor...")
leia(segundo)

   se(primeiro > segundo) entao
       escreval("O maior valor entre os números é:",primeiro)
   senao
       escreval("O maior valor entre os números é:",segundo)
   fimse
fimalgoritmo
