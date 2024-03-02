#include "recursao.h"
#include <time.h>

void imprimir(int x){
    if (x == 0){
        printf("%d ", x);   
    }
    else{
        imprimir(x - 1);
        printf("%d ", x);
    }
}

int fatorial(int x){
    if (x == 1 || x == 0){
        return 1;
    }
    else{
        int result;
        result = x * fatorial(x - 1);
        return result;
    }
}

//fibonacci por recursao não é eficiente!
long long int Rfibonacci(int n){
    if (n == 1){
        return 0;
    }
    else if (n == 2){
        return 1;
    }
    else{
        return Rfibonacci(n - 1) + Rfibonacci(n - 2);
    }
}

long long int Ifibonacci(int n){
    long long int a = 0, b = 1, c;
    int i = 2;

    if (n == 1){
        return a;
    }
    else{
        if (n == 2){
            return b;
        }
        else{
            while (i < n){
                c = a + b;
                a = b;
                b = c;
                i++;
            }
            return c;
        }   
    } 
}

int potencia(int x, int n){

    if (x == 0 || x == 1 || n == 0){
        return 1;
    }
    else{
        return x * potencia(x, n - 1);
    }

}

int somaSequencia(int x){
    if (x == 0){
        return 0;
    }
    else{
        return x + somaSequencia(x - 1);
    }
    
}

int somaVetor(int *v, int size){
    if (size == 0){
        return 0;
    }
    else{
        return v[size - 1] + somaVetor(v, size -1);
    }
}

int minValue(int *vec, int size, int index){
    if (size == 0){
        return vec[index];
    }
    else if (vec[size - 1] < vec[index]){
        return minValue(vec, size - 1, size - 1);
    }else{
        return minValue(vec, size - 1, index);
    }
}

int maxValue(int *v, int size, int index){
    if (size == 0){
        return v[index];
    }
    else{
        if (v[size -1 ] > v[index]){
            return maxValue(v, size - 1, size - 1);
        }
        else{
            return maxValue(v, size - 1, index);
        }
    }
}

void printVetor(int *v, int size, int c){
    if (size <= 0) {
        printf("Vetor vazio.\n");
        return;
    }

    else if (c == size - 1){
        printf("%d\n", v[c]);
    }
    else{
        printf("%d ", v[c]);
        printVetor(v, size, c + 1);
    }
}

void printInvertedVetor(int *v, int size){
    if (size == 1){
        printf("%d\n", v[size -1]);
    }
    else{
        printf("%d ", v[size - 1]);
        printInvertedVetor(v, size - 1);
    }
    
}

void reorderVetor(int *v, int begin, int end){
    int aux;

    if (begin < end){
        aux = v[begin];
        v[begin] = v[end];
        v[end] = aux;

        reorderVetor(v, begin + 1, end - 1);
    }
    
}

void converterDecToBi(int n){
    if (n == 0){
        printf("%d", n);
    }
    else{
        converterDecToBi(n / 2);
        printf("%d", n % 2);
    }
}

void returnDecToBi(int n, int *vet, int idx){
    if(n == 0){
        //printf("%d ", n);
        vet[idx] = n;
    }else{
        returnDecToBi(n / 2, vet, idx - 1);
        //printf("%d ", n % 2);
        vet[idx] = n % 2;
    }
}
typedef struct timeval timer; 

timer tic() {
    timer tic_;
    gettimeofday(&tic_, NULL); // "marca" o tempo atual
    return tic_;
}

timer tac() {
    return tic();
}

float comptime(timer tic, timer tac) {
  float t = ((tac.tv_sec  - tic.tv_sec) * 1000.0) +
            ((tac.tv_usec - tic.tv_usec) * 0.001);
  
  return t / 1000;
}

float meanEven(int *v, int size, int sum, int qtd){
    if (size == 0){
        return (sum * 1.0) / qtd;
    }
    else{
        if (v[size - 1] % 2 == 0){
            return meanEven(v, size - 1, sum + v[size - 1], qtd = qtd + 1);
        }
        else{
            return meanEven(v, size - 1, sum, qtd);
        }
        
    }
    
}

void fillVec(int *vec, int size, int begin, int step, int idx){
    if (idx == size -1){
        vec[idx] = begin;
        return;
    }
    vec[idx] = begin;
    fillVec(vec, size, begin = begin + step, step, idx = idx + 1);
}

void initializeSeed(){
    srand(time(NULL));
}

void fillRandomVec(int *vec, int size, int min, int max, int idx){
    /*
    if (idx == 0) {
        initializeSeed();
    }
    */
    if (idx == size - 1){
        vec[idx] = (rand() % (max - min + 1)) + min;

        return;
    }
    vec[idx] = (rand() % (max - min + 1)) + min;
    fillRandomVec(vec, size, min, max, idx = idx + 1);
}

int part(int *v, int begin, int end){
    //identificar o pivô
    int pivo = (v[begin] + v[end] + v[(begin  + end) / 2]) / 3;

    while (begin < end){
        //percorrendo o vetor da esquerda para a direita
        while (begin < end && v[begin] <= pivo){
            begin++;
        }
        //perorrendo o vetor da direita para a esquerda
        while (begin < end && v[end] > pivo){
            end--;
        }
        //troca os valores dos vetores
        int aux = v[begin];
        v[begin] = v[end];
        v[end] = aux;    
    }
    return begin;
}

void quickSort(int *vec, int begin, int end){
    if (begin < end){
        int pos = part(vec, begin, end);
        quickSort(vec, begin, pos - 1);
        quickSort(vec, pos, end);
    }
    
}

void bubbleSort(int *vec, int size){
    if (size <= 1)return;
    
    for (int i = 0; i < size - 1; i++){
        if (vec[i] > vec[i + 1]){
            int aux = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = aux;
        }
    }
    bubbleSort(vec, size - 1);
}

void selecionSort(int *vec, int size, int begin){
    if (begin == size - 1)return;

    int minus = begin; 

    for (int i = begin + 1; i < size; i++){
        if (vec[i] < vec[minus])minus = i;
    }
    int aux = vec[begin];
    vec[begin] = vec[minus];
    vec[minus] = aux;
    
    selecionSort(vec, size, begin + 1);
        
}