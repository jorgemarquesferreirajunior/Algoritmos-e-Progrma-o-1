#include <stdio.h>
#include <stdlib.h>

int main()
{

int i, numero, divisor, divisoes, soma;
printf("Somando os numeros primos de 1 ate 100...\n\n");

soma = 0;

for (int i = 1; i <= 100; i++)
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
        soma += i;
    }
}
printf("Resultado: %d \n\n", soma);

system("pause");
return 0;
}