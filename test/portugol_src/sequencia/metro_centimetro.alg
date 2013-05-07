algoritmo "05_metros_centimetros"
// Função :  Converte um valor em metros informado pelo usuário
//           para centímetros.
// Autor :   Equipe Hooper
// Data :    7/5/2013
var
   metro, centimetro : real
inicio
      escreval("Digite um valor em metros: ")
      leia(metro)
      
      //Calculo para a obtenção do valor equivalente em centímetro
      centimetro <- metro * 100
      
      escreval("O valor em centímetros é: ", centimetro)
fimalgoritmo
