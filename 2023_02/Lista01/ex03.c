#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int main(void)
{
    setlocale(LC_ALL , "Portuguese");
    int numero;
    printf("Digite um número inteiro positivo não-nulo: ");
    scanf("%d", &numero);
    if (numero == 0)
    {
        printf("Digite um número diferente de zero.\n");
    }

    while (numero != 0)
    {
        printf("\nO quadrado de %d vale %d", numero, numero * numero);
        printf("\nDigite outro número [0] - SAIR: ");
        scanf("%d", &numero);
    }
    
    printf("\nVolte Sempre!");

    return 0;
}