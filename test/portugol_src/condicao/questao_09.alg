algoritmo "decrescente"
// Função : Lê três números e os mostra em ordem decrescente
// Autor :  Leandro Bentes
var
   num1, num2, num3: inteiro
inicio
      escreval("Entre com tres numeros: ")
      leia(num1, num2, num3)//Faz a leitura dos tres numeros
      
      escreva("Numeros em ordem decrescente: ")
      
      //Este bloco testa todas as possibilidades de ordem para os tres numeros
      //primeiro encontrando o maior, depois definindo a ordem do dois restantes\
      //imprimindo na tela conforme a ordem eh encontrada
      se (num1>=num2) e (num1>=num3) entao  //Numero 1 eh maior que todos
         escreva(num1, ", ") //Exibe na tela acompanhada de uma virgula
         se (num2>=num3) entao //Numero 2 eh maior que Num3
            escreva(num2, ", ")
            escreva(num3) //Apenas exibe na tela
         senao//Num 3 eh maior que num 2
            escreva(num3, ", ")
            escreva(num2)
         fimse
      senao
         se (num2>=num1) e (num2>=num3) entao //Numero 2 eh o maior de todos
           escreva(num2, ", ")
           se (num1>=num3) entao //Numero 1 eh maior que o numero 3
              escreva(num1, ", ")
              escreva(num3)
           senao //Numero 3 eh maior que o numero 1
                escreva(num3, ", ")
                escreva(num1)
           fimse
         senao
              se (num3>=num2) e (num3>=num1) entao //Numero 3 eh o maior de todos
                 escreva(num3, ", ")
                 se (num2>=num1) entao //Numero 2 eh maior que o numero 1
                    escreva(num2, ", ")
                    escreva(num1)
                 senao //Numero 1 eh maior que o numero 2
                    escreva(num1, ", ")
                    escreva(num2)
                 fimse
              fimse
         fimse
      fimse
fimalgoritmo
