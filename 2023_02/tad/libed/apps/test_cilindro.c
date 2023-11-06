#include "cilindro.h"
#include <stdio.h>

int main()
{
    Cilindro *cil = createCilindro();
    printf_all_Cilindro(cil);

    add_values_into_Cilindro(cil, 1, 1);
    printf_all_Cilindro(cil);

    destroy_Cilindro(&cil);
    printf("\nCilindro destruido? yes[1]/no[0]: %d\n", cil == NULL);

    return 0;
}
