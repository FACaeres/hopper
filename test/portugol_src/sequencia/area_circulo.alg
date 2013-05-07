algoritmo "06_area_circulo"
// Função :  Recebe o raio do círculo informada pelo usuário,calcula
//           e mostra sua área.
// Autor :   Equipe Hooper
// Data :    7/5/2013
var
   raio, area: real
inicio
      escreval("Informe o raio do círculo: ")
      leia(raio)
      
      //O portugol já possui uma constante chamada pi
      area <- pi*(raio^2)
      
      escreval("A área do círculo é: ", area)

fimalgoritmo
