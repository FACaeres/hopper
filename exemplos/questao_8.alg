algoritmo "Retorna_Salario"
// Função :Faça um Programa que pergunte quanto você
//         ganha por hora e o número de horas trabalhadas no mês
//         Calcule e mostre o total do seu salário no referido mês.
// Autor : Iasmim Cunha
// Data : 5/8/2013
// Seção de Declarações 
var
salario_hora : real
horas_mes :real
salario_base : real
inicio
// Seção de Comandos 
escreval("Quanto você ganha por hora?")
leia(salario_hora)
escreval("Quantas horas você trabalho em um mês?")
leia(horas_mes)

salario_base <- salario_hora*horas_mes

escreval("Você ganha em torno de :",salario_base," por mês")
fimalgoritmo
