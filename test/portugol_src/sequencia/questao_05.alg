algoritmo "05_metros_centimetros"
// Fun��o :  Converte um valor em metros informado pelo usu�rio
//           para cent�metros.
// Autor :   Williams Ara�jo
// Data :    7/5/2013
var
   metro, centimetro : real
inicio
      escreval("Digite um valor em metros: ")
      leia(metro)
      
      //Calculo para a obten��o do valor equivalente em cent�metro
      centimetro <- metro * 100
      
      escreval("O valor em cent�metros �: ", centimetro)
fimalgoritmo
