algoritmo "Numero primo"
// Função : Determinar se número é o não é primo.
//          Se não primo, mostrar todos os seus divisiveis.
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
        se((num mod i) = 0) entao
                j <- j + 1
        fimse
		  //o número não é primo
        se j > 2 entao
           interrompa
        fimse
   fimpara
	//imprime se número é primo ou não
   se j > 2 entao
        escreval("O número não é primo")
		  //se não primo, imprive os seus divisíveis        
		  para i de 1 ate num faca
           se((num mod i) = 0) entao
                   escreval(i)
           fimse
      fimpara
   senao
        escreval("O número é primo")
   fimse
fimalgoritmo
