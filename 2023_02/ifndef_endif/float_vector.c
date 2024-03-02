#include"float_vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//*********************** INTERFACE PRIVADA ***********************//
struct float_vector
{
    int capacity;//num máx de elementos
    int size;//qtd de elementos ja armazenados
    float *data;// vetor de floats
};

bool _FloatVector_isFull(const FloatVector *vec){
    return vec->size == vec->capacity;
}
//*********************** INTERFACE PUBLICA ***********************//

/**
 * @brief cria um vetor de floats
 * @param capacity tamanho máximo do vetro
 * @return FloatVector*
 * 
*/
FloatVector *FloatVector_create(int capacity){
    FloatVector *vec = (FloatVector *) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float *) calloc(capacity, sizeof(float));

    return vec;
}

void FloatVector_destroy(FloatVector **vec_ref){
    free((*vec_ref)->data);
    free(*vec_ref);
    *vec_ref = NULL;
}
void FloatVector_append(FloatVector *vec, float val){
    if(_FloatVector_isFull(vec)){
        fprintf(stderr,"ERROR in 'append'\n");
        fprintf(stderr,"Vector is full\n");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size] = val;
    vec->size++;

}
void FloatVector_print_vec(const FloatVector *vec){
    puts("--------------");
    printf("Capacity: %d\n", vec->capacity);
    printf("Size: %d\n", vec->size);
    puts("----");
    for (int i = 0; i < vec->size; i++)
    {
        printf("vector[%d]= %.2f\n", i, vec->data[i]);
    }
    
    puts("--------------\n");
}
int FloatVector_capacity(const FloatVector *vec){
    return vec->capacity;
}
int FloatVector_size(const FloatVector *vec){
    return vec->size;
}
float FloatVector_at(const FloatVector *vec, int index){
    if (index < 0 || index >= vec->size){
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index [%d] out of bounds: [0:%d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}
float FloatVector_get(const FloatVector *vec, int index){
    return vec->data[index];
}
void FloatVector_set(FloatVector *vec, int index, float val){
    if (index < 0 || index >= vec->size){
        fprintf(stderr, "ERROR in 'set'\n");
        fprintf(stderr, "Index [%d] out of bounds: [0:%d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }
    vec->data[index] = val;
}
