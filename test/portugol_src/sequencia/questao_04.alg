algoritmo "04_media"
// Função : Calcula a Média de 4 notas bimestrais informadas pelo usuario
// Autor : Equipe Hooper
// Data : 7/5/2013
// Seção de Declarações 
var
   n1, n2, n3, n4, media : real
inicio
      //Efetua a leitura das 4 notas bimestrais
      escreval("Digite a nota do 1 bimestre: ")
      leia(n1)
      escreval("Digite a nota do 2 bimestre: ")
      leia(n2)
      escreval("Digite a nota do 3 bimestre: ")
      leia(n3)
      escreval("Digite a nota do 4 bimestre: ")
      leia(n4)
      
      //Calculo para obtenção da média
      media <- (n1+n2+n3+n4)/4
      
      escreval("Média do aluno: ", media)

fimalgoritmo
