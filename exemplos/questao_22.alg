algoritmo "Fatorial"
var
      cont, num, mult: inteiro
inicio
   escreva ("Informe um número para calcular o fatorial:  ")
   leia (num)
   se (num = 0) ou (num = 1) entao
      escreval ("")
      escreval ("O fatorial de ", num, " é: 1")
   senao
        mult <- num * (num-1)
        para cont de num ate 2 passo -1 faca
             se (cont < num) e (cont <> 1)  entao
                mult <- mult * (cont - 1)
             fimse
        fimpara
        escreval ("")
        escreval ("O fatorial de ", num, " é: ", mult)
   fimse
fimalgoritmo
