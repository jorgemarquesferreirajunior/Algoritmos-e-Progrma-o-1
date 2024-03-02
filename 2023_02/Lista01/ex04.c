#include<stdio.h>
#include<locale.h>


int main(void)
{
    setlocale(LC_ALL , "Portuguese");
    int numero;
    int soma = 0;

    printf("Digite um número inteiro positivo diferente de zero: ");
    scanf("%d", &numero);
    printf("A soma de ");

    for (int i = 1; i <= numero; i++){
        printf("%d", i);
        i < numero ? printf(" + "):printf(" = ");
        soma += i;
    }
    printf("%d", soma);
    return 0;
}
