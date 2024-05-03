#include "structs.h"

// Implementação da função para somar os valores da struct
int somar_valores(Numeros *nums) {
    return nums->valor1 + nums->valor2;
}

// funcao inicializacao da funcao soma
void init_Numeros(Numeros *nums) {
    nums->somar = somar_valores;
}
