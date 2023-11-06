#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Cubo *cubo = create_Cubo();
    Cubo *cebolinha = create_Cubo();

    float x, y, z;

    printf_Cubo(cubo);
    printf("Digite três valores para as medidas do cubo.Ex: 2 5 4\nmedidas: ");

    if (scanf("%f %f %f", &x, &y, &z) != 3) {
        printf("Erro ao ler as medidas do cubo.\n");
        destroy_Cubo(&cubo);
        exit(EXIT_FAILURE);
    }



    add_vals_Cubo(cubo, x, y, z);
    add_vals_Cubo(cebolinha, x*10, y*10, z*10);

    printf_Cubo(cubo);
    printf_Cubo(cebolinha);
    
    destroy_Cubo(&cubo);
    destroy_Cubo(&cebolinha);
    
    printf("cubo is NULL? %d\n", cubo == NULL);


    return 0;
}
