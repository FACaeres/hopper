algoritmo "questao_05"

// Descricao : Programa faz a leitura de duas notas parciais de um aluno e
//             calcula e mostra a média alcançada pelo aluno.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    media, nota_parcial1, nota_parcial2:real
inicio
	// Faz a leitura das duas notas reais do aluno.
    escreva("informe sua primeira nota parcial: ")
    leia(nota_parcial1)
    escreva("informe sua segunda nota parcial: ")
    leia(nota_parcial2)
	
	// Faz o calculo da media aritmetica, consulte http://pt.wikipedia.org/wiki/M%C3%A9dia_aritm%C3%A9tica.
	 
    media <- (nota_parcial1 + nota_parcial2)/2
    
	// Realiza a comparacao do valor da media e exibe a mensagem correspondente.
	se media = 10.0 entao
        escreva("Aprovado com Distincao com a media de: ", media:2:2)
    senao
        se media >= 7.0 entao
            escreva("Aprovado com a media de: ", media:2:2)
        senao
            se media < 7.0 entao
                escreva("Reprovado com a media de: ", media:2:2)
            fimse
       fimse
   fimse
  
fimalgoritmo
