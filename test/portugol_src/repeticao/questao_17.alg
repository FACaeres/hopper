algoritmo "Fatorial"
// Função : Calcula o fatorial de um número inteiro fornecido pelo usuário
// Autor :  Leandro Bentes
var
      cont, num, mult: inteiro
inicio
   mult <- 1
   escreva ("Informe um número para calcular o fatorial:  ")
   leia (num) //Faz a leitura da entrada do usuario
   se (num <0) entao //Valida numero negativos
      escreval ("")
      escreval ("Numero invalido para calculo!")
   senao
        se (num = 0) ou (num = 1) entao //Retorna fatorial 1 para entradas 0 e 1
           escreval ("")
           escreval ("O fatorial de ", num, " é: 1")
        senao
            //Este bloco aplica o principio matematico do fatorial, realiza a
            //multiplicacao do numero com seu anterior até 2, usando um contador
            //decrementa (passo -1), ignorando a
            //multiplicacao por 1 que nao altera o resultado. Ex:
            //5 * 4 * 3 * 2 = , fatorial de 5
            para cont de num ate 2 passo -1 faca
                   mult <- mult * (cont)
            fimpara
            
            escreval ("")
            escreval ("O fatorial de ", num, " é: ", mult)
        fimse
   fimse
fimalgoritmo
