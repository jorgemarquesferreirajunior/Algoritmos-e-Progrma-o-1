#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINIMO 2
#define MAXIMO 6

//funcoes secundarias

void start_randomization()
{
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
    for(int c = 0; c < qtd; c++)
    {
        list[c] = random_int(min, max);
    }
    return list;
}

void copy_list_to_matriz(int list[], int matriz[][20], int size)
{
    for(int c = 0; c < size; c++)
    {
        matriz[0][c] = list[c];
    }
}

void print_list(int* list, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("lista[%d] = %d\n", i, list[i]);
    }
    printf("\n");
}

int cont_divisor(int divisor, int matriz[][20], int max)
{
    int lin =   0;
    int resto = 0;
    int cont =  0;
    int numero;
    int resultado_resto;
    int resultado_divisao;
    int soma_resto = 0;

    while(soma_resto != max)
    {
        printf("\n");
        for(int c = 0; c < max; c++)
        {
            numero = matriz[lin][c];
            resultado_resto = numero % divisor;
            resultado_divisao = numero / divisor;
            if(resultado_resto == 0)
            {
                matriz[lin + 1][c] = resultado_divisao;
            }
            else
            {
                matriz[lin + 1][c] = numero;
                soma_resto++;
            }
            //printf("%d / %d= %d resto %d soma resto = %d\n",numero,divisor, resultado_divisao, resultado_resto, soma_resto);
        }

        if(soma_resto != max)
        {
            cont++;
            soma_resto = 0;
        }
        lin++;
    }
    //printf("divisor = %d\n", divisor);
    cont = cont * divisor;
    if(cont == 0){
        cont = 1;
    }
    //printf("cont = %d [1]= nenhum\n", cont);
    return cont;
}

//funcao principal ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main()
{
    start_randomization();
    int max = random_int(MINIMO, MAXIMO);
    int* numeros = random_list(max, MINIMO, MAXIMO);
    int divididos2[20][max];
    int divididos3[20][max];
    int divididos5[20][max];
    int cont2, cont3, cont5;
    int max_divisor;

    print_list(numeros, max);

    copy_list_to_matriz(numeros, divididos2, max);
    copy_list_to_matriz(numeros, divididos3, max);
    copy_list_to_matriz(numeros, divididos5, max);

    cont2 = cont_divisor(2,divididos2, max);
    cont3 = cont_divisor(3,divididos3, max);
    cont5 = cont_divisor(5,divididos5, max);
    max_divisor = cont2 * cont3 * cont5;
    printf("Maximo divisor comum = %d\n", max_divisor);
    free(numeros);

    system("pause");
    return 0;
}
