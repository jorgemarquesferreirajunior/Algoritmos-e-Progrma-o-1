#include <stdio.h>
#include <stdlib.h>

int main()
{

int inicio, fim, i, numero, divisor, divisoes;
printf("Descobrindo numeros primos...\n\n");
printf("Digite um numero\n");
scanf("%d", &inicio);
printf("Agora outro que seja maior que o anterior \n");
scanf("%d", &fim);

for (int i = inicio; i < fim + 1; i++)
{
    numero = i;
    divisoes = 0;
    divisor = 1;
    
    while (divisor < numero + 1)
    {

        if (numero % divisor == 0)
        {
            divisoes ++;
        }
        divisor++;
    }
    
    if (divisoes == 2 && i != 1)
    {
        printf("Numero primo: %d \n", i);
    }
}

system("pause");
return 0;
}