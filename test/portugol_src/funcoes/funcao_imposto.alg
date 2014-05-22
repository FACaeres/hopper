algoritmo "funcao_imposto"

var
   taxa, custo : real

procedimento somaImposto(ptaxa, pcusto : real)
inicio
      custo <- pcusto + (taxa/100)*pcusto
fimprocedimento

inicio
      escreva("Informe o valor da taxa de imposto (%): ")
      leia(taxa)
      escreva("Informa o valor do custo da compra: ")
      leia(custo)
      somaImposto(taxa, custo)
      escreva("O valor de custo da sua compra + impostos é: ", custo)

fimalgoritmo
