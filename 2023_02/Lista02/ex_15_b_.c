#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Sabe-se que um número da forma n3 é igual a soma de n ímpares consecutivos.
Exemplo: 13= 1, 23= 3+5, 33= 7+9+11,  43= 13+15+17+19,... Dado m,
determine os ímpares consecutivos cuja soma é igual a n3 para n assumindo valores de 1 a m.
*/
int main()
{
int numero;
int somatorio = 0;
int passo = 1;
printf("Digite qualquer numero inteiro positivo: ");
scanf("%d", &numero);
for(int a = 1; a <= numero; a++)
{
    somatorio = somatorio + a;
}
int impares[somatorio];
printf("%d ao cubo vale %d\nOu entao:\n", numero, numero *numero *numero);
for(int c = 1; c <= somatorio; c++)
{
    impares[c] = passo;
    passo = passo + 2;
}
for(int k = somatorio - numero; k <= somatorio; k++)
{
    printf("%d ", impares[k]);
}
system("pause");
return 0;
}
