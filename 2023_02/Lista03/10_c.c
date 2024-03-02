#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MINIMO 0
#define MAXIMO 99

void start_randomization();
int random_int(int min, int max);
int* random_list(int qtd, int min, int max);
void print_list(int* list, int size);
void copy_list_to_list(int list[], int new_list[], int size, int , int);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    start_randomization();
    int number;
    int len = random_int(2, 6);
    int new_len = len + 1;
    int pos;

    printf("Escreva um número inteiro positivo\npara adicionarmos no vetor: ");
    scanf("%d", &number);
    printf("Em qual posição do vetor você quer\nadicionar o número %d ? [ %d - %d ]: ",number, 0, len - 1);
    scanf("%d", &pos);
    printf("\n");

    int* vetor = random_list(len, MINIMO, MAXIMO);
    print_list(vetor,len);

    int new_vetor[new_len];// novo vetor
    copy_list_to_list(vetor, new_vetor, len, pos, number);

    print_list(new_vetor,new_len);

    system("pause");

    return 0;
}

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
    for(int i = 0; i < size; i++){printf("Posicao[%d] = %d\n", i, list[i]);}
    printf("\n");
}

void copy_list_to_list(int list[], int new_list[], int size, int pos_insert, int value)
{
    int c;
    for(c = 0; c < pos_insert; c++)
    {
        new_list[c] = list[c];
    }
    new_list[pos_insert] = value;
    if
    for(int d = pos_insert + 1; d < size + 1; d++, c++)
    {
        new_list[d] = list[c];
    }
}

