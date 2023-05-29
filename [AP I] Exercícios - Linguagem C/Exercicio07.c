//Escreva um programa em C que imprime a média de todos os valores ímpares de 1
//até 500
#include<stdio.h>
int main()
{

int impares = 0 ;
int soma = 0;
float media;

for (int i = 1; i < 500; i++)
{
    if (i % 2 != 0)
    {
        soma += i;
        impares += 1;

    }
}
 
media = soma / impares;
printf("\nMedia = %.2f", media);

return 0;
}
