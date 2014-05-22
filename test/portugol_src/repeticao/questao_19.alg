algoritmo "MaiorMenorSomaLimited"
// Função : Dado um conjunto de N números, determina o menor valor, o 
//			maior valor e a soma dos valores.
//          Aceita como entrada números inteiros ENTRE  0 e 1000 (1 a 999)
// Autor :  Leandro Bentes
var
      num, maior, menor, soma: inteiro
inicio
      num <- 1 //Inicializa a variavel que armazena a leitura de dados
               //com 1 para entrar no laço abaixo. O valor será substituído
               //pela entrada do usuário
      maior <- 0 //Variavel que guardará o maior número, inicializada com
                 //o menor valor possível, que logo será substituído
      menor <- 9999 //Variavel que guardará o menor número, inicializada com
                    //valor alto para ser substituída pelo menor número assim
                    //que inserido
      soma <- 0 //Acumulador que guarda a soma dos números de entrada

      //Este bloco mantém a repetição enquanto o usuário inserir números válidos
      enquanto ((num > 0) e (num < 1000)) faca
               escreva("Insira um número (<=0 ou >=1000 encerra): ")
               leia(num)
               se (num <= 0) ou (num >=1000) entao
                  escreval("Encerrando!")
               senao
                    //Verifica se a entrada supera o maior numero ate o momento
                    se num > maior entao
                       maior <- num
                    fimse
                    //Vê se a entrada é inferior ao menor numero registrado
                    se num < menor entao
                       menor <- num
                    fimse
                    //Acumula os valores inseridos
                    soma <- soma + num
               fimse
      fimenquanto

      escreval("Maior numero: ", maior)
      escreval("Menor numero: ", menor)
      escreval("Soma dos numeros: ", soma)

fimalgoritmo
