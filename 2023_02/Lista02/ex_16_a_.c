#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
/*
a) O IMC – Indice de Massa Corporal é um critério da Organização Mundial de Saúde para dar uma indicação sobre
a condição de peso de uma pessoa adulta. A fórmula é IMC = peso / ( altura )2 Elabore um algoritmo que leia
o peso e a altura de um adulto e mostre sua condição de acordo com a tabela abaixo.
IMC em adultos Condição:
Abaixo de 18,5 Abaixo do peso
Entre 18,5 e 25 Peso normal
Entre 25 e 30  Acima do peso
Acima de 30 obeso
*/

int main()
{
    float altura, peso;
    printf("Qual sua altura? [ex: 1.75] ");
    scanf("%f", &altura);
    printf("Qual seu peso? [ex: 70.5] ");
    scanf("%f", &peso);
    float imc = peso / (altura * altura);
    setlocale(LC_ALL, "Portuguese");
    printf("Seu IMC é de: %.2f - ", imc);
    if(imc < 18.5)
    {
        printf("Abaixo do peso\n\n");
    }
    if(18.5 < imc && imc < 25)
    {
        printf("Peso normal\n\n");
    }
    if(25 < imc && imc < 30)
    {
        printf("Acima do peso\n\n");
    }
    if(imc > 30)
    {
        printf("Obeso\n");
    }

    system("pause");
    return 0;
}
