algoritmo "funcao_positivo_negativo"

var
   a : inteiro
   resultado : caracter

funcao verifica(a : inteiro) : caracter
inicio
      se (a > 0) entao
         retorne "P"
      senao
         retorne "N"
      fimse

fimfuncao

inicio
      escreva("Informe o valor a ser verificado: ")
      leia(a)
      resultado <- verifica(a)
      escreval(resultado)

fimalgoritmo
