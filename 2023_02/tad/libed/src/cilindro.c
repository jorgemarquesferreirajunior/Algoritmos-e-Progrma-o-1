#include <cilindro.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159265358979323846

typedef struct _cilindro{
    float radius;
    float heigth;
    float area;
    float volume;
}Cilindro;

Cilindro *createCilindro(){
    Cilindro *cilinder = (Cilindro *) calloc(1, sizeof(Cilindro));
    cilinder->area = cilinder->heigth = cilinder->radius = cilinder->volume = 0;

    return cilinder;
}

void add_values_into_Cilindro(Cilindro *cilinder, float radius, float heigth){
    cilinder->radius = radius;
    cilinder->heigth = heigth;
    cilinder->area = PI * radius * radius;
    cilinder->volume = cilinder->area * heigth;
}
void printf_all_Cilindro(const Cilindro * cilinder){
    puts("\nshowing parameteres of the cilinder");
    printf("cilinder->radius = %.2f\n", cilinder->radius);
    printf("cilinder->heigth = %.2f\n", cilinder->heigth);
    printf("cilinder->area   = %.2f\n", cilinder->area);
    printf("cilinder->volume = %.2f\n\n", cilinder->volume);

}

void destroy_Cilindro(Cilindro **cilinder){
    free(*cilinder);
    *cilinder = NULL;
    puts("destruindo o cilindro...");

}

float get_radius_Cilindro(const Cilindro *cilinder){
    return cilinder->radius;
}

float get_heigth_Cilindro(const Cilindro *cilinder){
    return cilinder->heigth;
}

float get_area_Cilindro(const Cilindro *cilinder){
    return cilinder->area;
}

float get_volume_Cilindro(const Cilindro *cilinder){
    return cilinder->volume;
}