#include <stdio.h>
#include <stdlib.h>

int main()
{

int i;

printf("Esses sao os 100 primeiros numeros pares:\n");

for (int i = 1; i < 100; i++)
{
    if (i % 2 == 0)
    {
        printf("%d \n", i);
    }
    
    else
    {
        continue;
    }
}




system("pause");
return 0;
}