algoritmo "Numero primo"
// Fun��o : Determinar se n�mero � o n�o � primo
// Autor : Daniel
// Data : 7/5/2013
// Se��o de Declara��es 
var
   num, i, j: inteiro
inicio
   // Se��o de Comandos
   repita
      escreva("Escreva um numero inteiro positivo: ")
      leia(num)
   ate (num > 0)
   
   j <- 0
   para i de 1 ate num faca
        //verifica se o n�mero � divis�vel; se for divisivel por mais que 2 n�meros, n�o � primo
		  se((num mod i) = 0) entao
                j <- j + 1
        fimse
        //interrompe se n�mero n�o � primo
		  se j > 2 entao
           interrompa
        fimse
   fimpara
   //imprime se numero � primo ou n�o
   se j > 2 entao
        escreva("O n�mero n�o � primo")
   senao
        escreva("O n�mero � primo")
   fimse
fimalgoritmo
