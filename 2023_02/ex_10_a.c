#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MINIMO 0
#define MAXIMO 99

void start_randomization(){
    srand(time(NULL));
}

int random_int(int min, int max)
{
    int n;
    max = max - min + 1;
    n = min + (rand() % max);
    return n;
}

int* random_list(int qtd, int min, int max)
{
    int* list = (int*)malloc(qtd * sizeof(int));
    start_randomization();
    for(int c = 0; c < qtd; c++){list[c] = random_int(min, max);}
    return list;
}

void print_list(int* list, int size)
{
    for(int i = 0; i < size; i++){printf("Valor[%d] = %d\n", i + 1, list[i]);}
    printf("\n");
}

void find_int_list(int* list, int size, int value)
{
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        if(value == list[i])
        {
            result = 1;
        }
    }
    if(result == 1)
    {
        printf("\n%d - Esta na lista", result);
    }
    else
    {
        printf("\n%d - Não esta na lista", result);
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    start_randomization();
    int number;
    int len;
    printf("Escreva um número inteiro positivo\npara procurarmos no vetor: ");
    scanf("%d", &number);
    printf("\nAgora, digite um número inteiro positivo\npara o tamanho do vetor: ");
    scanf("%d", &len);
    printf("\n");

    int* v = random_list(len, MINIMO, MAXIMO);

    print_list(v,len);

    find_int_list(v, len, number);

    return 0;
}



