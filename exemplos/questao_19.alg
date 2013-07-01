algoritmo "decrescente"

var num1, num2, num3, aux: inteiro
    maior, menor, meio: inteiro

inicio
      escreval("Entre com tres numeros: ")
      leia(num1, num2, num3)
      
      escreva("Numeros em ordem decrescente: ")
      
      Se (num1>=num2) e (num1>=num3) entao
   maior <- num1
   se (num2>=num3) entao
       meio <- num2
       menor <- num3
   senao
       se (num3>=num2) entao
           meio <- num3
           menor <- num2
       fimse
   fimse
   senao
        se (num2>=num1) e (num2>=num3) entao
           maior <- num2
        se (num1>=num3) entao
           meio <- num1
           menor <- num3
        senao
          se (num3>=num1) entao
            meio <- num3
            menor <- num1
          fimse
        fimse        
   senao
       se (num3>=num2) e (num3>=num1) entao
           maior <- num3
           se (num2>=num1) entao
               meio <- num2
               menor <- num1
           senao
               se (num1>=num2) entao
                   meio <- num1
                   menor <- num2
               fimse
           fimse
      fimse
   fimse
fimse

escreva(maior)
escreva(", ")
escreva(meio)
escreva(", ")
escreva(menor)

fimalgoritmo
