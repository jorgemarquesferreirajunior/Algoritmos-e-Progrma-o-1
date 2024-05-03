#ifndef STRUCTS_H
#define STRUCTS_H

// Definição da struct
typedef struct _Numeros {
    int valor1;
    int valor2;
    
    // Ponteiro de função para somar os valores
    int (*somar)(struct _Numeros *);
}Numeros;

// Protótipo da função para somar os valores da struct
void init_Numeros(Numeros *nums);
int somar_valores(Numeros *nums);

#endif // STRUCTS_H
