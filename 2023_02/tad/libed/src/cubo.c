#include "cubo.h"
#include <stdlib.h>
#include <stdio.h>

struct _cubo{
    float length;
    float width;
    float height;
    float area;
};

Cubo *create_Cubo(){
    Cubo *cubo = (Cubo *)calloc(1, sizeof(Cubo));// retorna a qtd de bits para armazenar a struct Cubo
    cubo->length = 0;
    cubo->width  = 0;
    cubo->height = 0;
    cubo->area   = 0;

    return cubo;
}

void destroy_Cubo(Cubo **cubo){
    free(*cubo);
    *cubo = NULL;
}

void add_vals_Cubo(Cubo *cubo, float length, float width, float height){
    cubo->length = length;
    cubo->width = width;
    cubo->height = height;
    cubo->area = cubo->length * cubo->width * cubo->height;
}

void printf_Cubo(const Cubo *cubo){
    puts("\nParamters of cube[mm]");
    printf("length: %.2f\nwidth:  %.2f\nheight: %.2f\narea:   %.2f\n\n",cubo->length, cubo->width, cubo->height, cubo->area);
}