#ifndef recursao_H
#define recursao_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/time.h>

void initializeSeed();
void imprimir(int x);                               //imprimir numero
int fatorial(int x);                                //fatorial
long long int Rfibonacci(int n);                    //fibonacci recursivo
long long int Ifibonacci(int n);                    //fibonacci interativo
int potencia(int x, int n);                         // potenciação
int somaSequencia(int x);                           //soma de 1 até n elementos
int somaVetor(int *v, int size);                    // somar todos os elementos de um vetor
int minValue(int *vec, int size, int index);        // buscar o menor elemento de um vetor
int maxValue(int *v, int size, int index);          // buscar o maior elemento de um vetor
void printVetor(int *v, int size, int c);                  // printar o vetor 
void printInvertedVetor(int *v, int size);          // printar o vetor invertido
void reorderVetor(int *v, int begin, int end);      // inverter o vetor
void converterDecToBi(int n);                       //conveter decimal para binario
void returnDecToBi(int n, int *vet, int idx);       //conveter decimal para binario e salvar em uma variavel
float meanEven(int *v, int size, int sum, int qtd); //calcula a mediados numeros pares de um vetor
void fillVec(int *vec, int size, int begin, int step, int idx);
void fillRandomVec(int *vec, int size, int min, int max, int idx);
int part(int *v, int begin, int end);
void quickSort(int *vec, int begin, int end);
void bubbleSort(int *vec, int size);
void selecionSort(int *vec, int size, int begin);

typedef struct timeval timer; 
timer tic();
timer tac();
float comptime(timer tic, timer tac);

#endif