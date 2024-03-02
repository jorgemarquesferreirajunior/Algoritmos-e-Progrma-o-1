#include<stdio.h>
#include<locale.h>


int main(void)
{
    setlocale(LC_ALL , "Portuguese");
    int numero;
    int impar = 0;

    printf("Digite um número inteiro positivo diferente de zero: ");
    scanf("%d", &numero);
    printf("Os %d primeiros números ímpares são:\n", numero);

    for (int i = 1; i < numero * 2; i++){
        impar = i % 2;
        impar != 0 ? printf("%d ", i):printf("");
    }
    return 0;
}
