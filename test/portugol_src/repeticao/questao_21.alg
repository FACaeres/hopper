algoritmo "Numero primo"
// Função : Determinar se número é o não é primo
// Autor : Daniel
// Data : 7/5/2013
// Seção de Declarações 
var
   num, i, j: inteiro
inicio
   // Seção de Comandos
   repita
      escreva("Escreva um numero inteiro positivo: ")
      leia(num)
   ate (num > 0)
   
   j <- 0
   para i de 1 ate num faca
        //verifica se o número é divisível; se for divisivel por mais que 2 números, não é primo
		  se((num mod i) = 0) entao
                j <- j + 1
        fimse
        //interrompe se número não é primo
		  se j > 2 entao
           interrompa
        fimse
   fimpara
   //imprime se numero é primo ou não
   se j > 2 entao
        escreva("O número não é primo")
   senao
        escreva("O número é primo")
   fimse
fimalgoritmo
