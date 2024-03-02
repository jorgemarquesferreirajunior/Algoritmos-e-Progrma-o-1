#include "esfera.h"
#include <stdio.h>

int main()
{
    Esfera *esfera = createEsfera();
    printf_all_Esfera(esfera);
    printf("\nEsfera destruida? yes[1]/no[0]: %d\n", esfera == NULL);
    
    add_values_into_Esfera(esfera, 1);
    printf("raio: %.2f\n", get_radius_Esfera(esfera));
    printf("area: %.2f\n", get_area_Esfera(esfera));
    printf("volume: %.2f\n", get_volume_Esfera(esfera));

    destroy_Esfera(&esfera);
    printf("\nEsfera destruida? yes[1]/no[0]: %d\n", esfera == NULL);
    
    return 0;
}
