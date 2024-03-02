#include "recursao.h"
#include <stdio.h>
#include <stdlib.h>
# include <string.h>

int main(int argc, char const *argv[]){


    /*
    int valor;

    printf("digite um número maior que zero: ");
    scanf("%d", &valor);fflush(stdin);

    //imprimir(valor);
    //printf("\n");

    puts("fibonacci iterativo");
    timer c = tic();
    printf("O %d° termo da sequencia de fibonacci vale: %lld\n", valor, Ifibonacci(valor));
    timer d = tac();
    printf("tempo de processamento: %.2f segundos\n", comptime(c, d));

    puts("fibonacci recursivo");
    timer a = tic();
    printf("O %d° termo da sequencia de fibonacci vale: %lld\n", valor, Rfibonacci(valor));
    timer b = tac();
    printf("tempo de processamento: %.2f segundos\n", comptime(a, b));  
    */


    //printf("O fatorial de %d vale %d\n", valor, fatorial(valor));



    /*
    int a, b;

    printf("digite dois: ");
    scanf("%d %d", &a, &b);fflush(stdin);

    printf("Resultado de %d elevado a %d: %d\n", a, b, potencia(a, b));
    */

    /*
    int valor;

    printf("digite um número maior que zero: ");
    scanf("%d", &valor);fflush(stdin);

    printf("somade 1 até %d é: %d\n", valor, somaSequencia(valor));
    */

    /*
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    puts("Dado o vetor 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");

    printf("A soma dele vale: %d\n", somaVetor(vetor, 10));
    */

    /*
    int vetor[10] = {11, 258, 13, 445, 58, 67, 7, 8, 9, 10};
    puts("Dado o vetor {11, 258, 13, 445, 58, 67, 7, 8, 9, 10}");

    printf("O Maior valor vale: %d\n", maxValue(vetor, 10, 0));
    */

    /*

    int vetor[10] = {11, 258, 13, 445, 58, 67, 7, 8, 9, 10};
    puts("Dado o vetor {11, 258, 13, 445, 58, 67, 7, 8, 9, 10}");

    puts("O Vetor invertido vale:");

    printInvertedVetor(vetor, 10);
    */

    /*

    int vetor[10] = {11, 258, 13, 445, 58, 67, 7, 8, 9, 10};

    printInvertedVetor(vetor, 10);
    reorderVetor(vetor, 0, 9);
    printInvertedVetor(vetor, 10);
    */




    /*
    int n;

    printf("digite um numero decimal: ");
    scanf("%d", &n);fflush(stdin);

    printf("%d em binário vale: ", n);
    converterDecToBi(n);
    puts("");
    */

    /*
    int vetor[10] = {11, 258, 13, 445, 58, 67, 7, 8, 9, 10};

    reorderVetor(vetor, 0, 9);
    printInvertedVetor(vetor, 10);

    printf("A media dos pares é: %.2f\n", meanEven(vetor, 10, 0, 0));
    */

    /*
    int vetor[10] = {11, 258, 13, 445, 58, 67, 7, 8, 9, 10};

    printVetor(vetor, 10, 0);
    */
    
    /*
    int len = 20;
    int n, vet[len];
    
    memset(vet, 0, sizeof(vet));

    printf("digite um número inteiro maior que zero: ");
    scanf("%d", &n);fflush(stdin);

    returnDecToBi(n, vet, len - 1);
    printVetor(vet, len, 0);
    */
    puts("**********fillVec**********");
    puts("Criando um vetor e preenchendo-o automaticamente");
    int size = 8, begin = 9, step = 1, vec[size];
    fillVec(vec, size, begin, step, 0);
    printVetor(vec, size, 0);
    puts("");
    
    puts("**********fillRandomVec**********");
    puts("Criando um vetor e preenchendo-o aleatóriamente");
    int min = 1, max = 100, vec2[size];

    initializeSeed();

    fillRandomVec(vec2, size, min, max, 0);
    printVetor(vec2, size, 0);
    puts("");

    puts("**********minValue**********");
    puts("Encontrando de forma recursiva, o menor valor de um vetor");
    int minvalue;
    minvalue = minValue(vec2, size, 0);
    printVetor(vec2, size, 0);
    printf("O menor é: %d\n", minvalue);
    puts("");

    puts("**********quickSort**********");
    puts("Ordenando um vetor através do quick sort");

    int size2 = 10, min2 = 1, max2 = 100, vec3[size2];

    printf("Vetor Original: ");
    fillRandomVec(vec3, size2, min2, max2, 0);
    printVetor(vec3, size2, 0);

    printf("Vetor Ordenado: ");
    quickSort(vec3, 0, size2 - 1);
    printVetor(vec3, size2, 0);
    puts("");

    puts("**********bubbleSort**********");
    puts("Ordenando um vetor através do bubble sort");
    int vec4[size2];

    printf("Vetor Original: ");
    fillRandomVec(vec4, size2, min2, max2, 0);
    printVetor(vec4, size2, 0);

    printf("Vetor Ordenado: ");
    bubbleSort(vec4, size2);
    printVetor(vec4, size2, 0);
    puts("\n");

    puts("**********selecionSort**********");
    puts("Ordenando um vetor através do selection sort");
    int vec5[size2];

    printf("Vetor Original: ");
    fillRandomVec(vec5, size2, min2, max2, 0);
    printVetor(vec5, size2, 0);

    printf("Vetor Ordenado: ");
    selecionSort(vec5, size2, 0);
    printVetor(vec5, size2, 0);
    puts("\n");



    return EXIT_SUCCESS;
}
