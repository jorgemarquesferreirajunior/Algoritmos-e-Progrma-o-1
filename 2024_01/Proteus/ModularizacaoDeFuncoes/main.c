#include <stdio.h>
#include "structs.h"

int main() {
    // Criando uma instância da struct Numeros
    Numeros nums;
    init_Numeros(&nums);

    // Inicializando os valores
    nums.valor1 = 5;
    nums.valor2 = 3;
    
    // Chamando a função para somar os valores da struct
    int resultado = nums.somar(&nums);
    
    printf("Resultado da soma: %d\n", resultado);
    
    return 0;
}
