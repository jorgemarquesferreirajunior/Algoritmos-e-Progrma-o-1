//Escreva um programa em C que calcule o rendimento de uma aplicação. O programa
//deve receber o valor do capital inicial, da taxa de juros ao mês (porcentagem), e do
//tempo (meses) que o capital ficará aplicado, e retornar o //valor do montante. A
//fórmula para o cálculo é:

// M = P.(1 + i)^n
// M = montante [R$]
// P = Capital [R$]
// i = taxa de juros [%]
// n = tempo [meses]
#include<stdio.h>
#include<math.h>
int main()
{
int tempo;
float capitalInicial, taxaDeJuros, montante;

printf("\nCapital inicial R$ ");
scanf("\n%f", &capitalInicial);
printf("\nTempo [meses]: ");
scanf("\n%d", &tempo);
printf("\nTaxa de juros [a.m.] ");
scanf("\n%f", &taxaDeJuros);

montante = capitalInicial * pow((1 + taxaDeJuros / 100), tempo);
printf("\nMontante = R$%.2f", montante);

return 0;
}