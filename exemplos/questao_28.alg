algoritmo "Numero primo"
// Função : Determinar se número é o não é primo.
//          Se não primo, mostrar todos os seus divisiveis.
// Autor : Daniel
// Data : 7/5/2013
// Seção de Declarações
var
   num, i, j, k, total: inteiro
   ic: real
inicio
   // Seção de Comandos
   repita
      escreva("Escreva um numero inteiro positivo: ")
      leia(num)
   ate (num > 0)

	//variável que conta o número total de divisões   
	total <- 0
	// Verifica os Num primeiros números e verifica quais são primos
   para i de 1 ate num faca
        k <- 0
			
		  //verifica até que ponto devo fazer as divisões para saber se um número é primo
        ic <- (i / 2)
        j <- 1
        //verifica se o número i é primo ou não
		  enquanto (j <= ic) faca
           total <- total + 1
           se((i mod j) = 0) entao
                 k <- k + 1
           fimse
			  //se k for maior que 1, o número não é primo
           se k > 1 entao
              interrompa
           fimse
           j <- j + 1
        fimenquanto
		  //imprime se número i for primo
        se k <= 1 entao
           escreval(i)
        fimse
   fimpara
   //imprime o número total de divisões realizadas
   escreval("Total de divisões realizadas: ", total)
fimalgoritmo
