/*
 c) Escreva uma função booleana que decida se uma string ASCII dada é um
 palíndromo (ou seja, se o inverso da string é igual a ela).
 Escreva um programa para testar a função.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ehpalindromo(const char *string) {
    int i = 0, j = strlen(string) - 1;

    while (i < j) {
        if (string[i] != string[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    if (ehpalindromo("abba")) {
        printf("É palíndromo");
    } else {
        printf("Não é palíndromo");
    }
    return 0;
}
