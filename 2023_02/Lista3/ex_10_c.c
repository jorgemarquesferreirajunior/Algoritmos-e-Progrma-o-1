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

void copy_list_to_list(int list[], int new_list[], int size)
{
    for(int c = 0; c < size; c++)
    {
        new_list[c] = list[c];
    }
}

void add_value_list(int list[], int size, int pos, int value)
{
    for(int c = 0; c <= size; c++)
    {
        if(pos == c)
        {
            list[c] = value;
        }
        if(pos < c)
        {
            list[c] = list[c - 1];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    start_randomization();
    int number;
    int len = random_int(1, 10);
    int pos;
    printf("Escreva um número inteiro positivo\npara adicionarmos no vetor: ");
    scanf("%d", &number);
    printf("Em qual posição do vetor você quer\nadicionar o número %d ? [ %d - %d ]: ",number, 0, len - 1);
    scanf("%d", &number);
    printf("\n");
    int nvetor[len + 1];

    int* vetor = random_list(len, MINIMO, MAXIMO);

    copy_list_to_list(vetor, nvetor, len);

    add_value_list(nvetor, len, pos, number);

    print_list(nvetor,len + 1);

    system("pause");

    return 0;
}



