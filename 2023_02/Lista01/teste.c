/*
Sabe-se que um número da forma n3 é igual a soma de n ímpares consecutivos.
Exemplo: 13= 1, 23= 3+5, 33= 7+9+11,  43= 13+15+17+19,... Dado m,
determine os ímpares consecutivos cuja soma é igual a n3 para n assumindo valores de 1 a m.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int n;
int m = 0;
int passo = 1;
printf("Digite qualquer numero inteiro positivo: ");
scanf("%d", &n);

for(int a = 1; a <= n; a++)
{
    m = m + a;
}
int impares[m];
printf("m: %d\n", m);
for(int c = 1; c <= m; c++)
{
    printf("%d ", c);
    impares[c] = passo;
    passo = passo + 2;
}

for(int k = m - n; k <= m; k++)
{
    printf("%d\n", impares[k]);
}

system("pause");
return 0;
}
