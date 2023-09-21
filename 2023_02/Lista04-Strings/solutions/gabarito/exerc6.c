/*
 f) Escreva uma função que receba uma string ASCII de 0s e 1s, interprete essa
 string como um número natural em notação binária e devolva o correspondente int.

 Por exemplo, a string "1111011" deve ser convertida no inteiro 123.
 (Se a string for longa demais, descarte os últimos dígitos.)
 */

#include<stdio.h>
#include<string.h>
#include<math.h>

int binToDec(char bin[100]) {
    unsigned long dec = 0;
    int i = 0;
    int s;
    
    s = strlen( bin );
    while( s-- ) {
        if (bin[s] == '0' || bin[s] == '1') {
            dec = dec + pow(2, i++) * (bin[s] - '0');
        }
    }
    return dec;
}

int main()
{
    char bin[100];
    unsigned long dec;

    printf("Informe um número binário(ex: 1111011):");
    fgets( bin, sizeof(bin), stdin);
    dec = binToDec(bin);
    printf("\nEquivalente em decimal: \t %u\n", dec);
    return 0;
}
