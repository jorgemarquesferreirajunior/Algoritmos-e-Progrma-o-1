/*
Desenvolva um TAD que represente uma esfera. Inclua as
funções de inicializações necessárias e as operações que
retornem o seu raio, a sua área e o seu volume. 
*/
#include <cilindro.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159265358979323846

typedef struct _ci_esfera{
    float radius;
    float area;
    float volume;
}Esfera;

Esfera *createEsfera(){
    Esfera *sphere = (Esfera *) calloc(1, sizeof(Esfera));
    sphere->area = sphere->radius = sphere->volume = 0;

    return sphere;
}

void add_values_into_Esfera(Esfera *sphere, float radius){
    sphere->radius = radius;
    sphere->area = 4 * PI * radius * radius;
    sphere->volume = (4 * PI * radius * radius * radius) / 3;
}

void printf_all_Esfera(const Esfera * sphere){
    puts("\nshowing parameteres of the sphere[mm]");
    printf("sphere->radius = %.2f\n", sphere->radius);
    printf("sphere->area   = %.2f\n", sphere->area);
    printf("sphere->volume = %.2f\n\n", sphere->volume);

}

void destroy_Esfera(Esfera **sphere){
    free(*sphere);
    *sphere = NULL;
    puts("destruindo a esfera...");

}

float get_radius_Esfera(const Esfera *sphere){
    return sphere->radius;
}

float get_area_Esfera(const Esfera *sphere){
    return sphere->area;
}

float get_volume_Esfera(const Esfera *sphere){
    return sphere->volume;
}