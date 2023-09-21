/*
 e) O exemplo abaixo conta o número de vogais em uma string.
 Faça uma função que conte o número de consoantes,
 excluindo caracteres especiais ('/n', '/t', '.', ‘,’, etc.)
 */

#include <stdio.h>
#include <stdbool.h>

int contaConsoantes(char s[]) {
    char *outros;
    outros = "aeiouAEIOU\n\t.,;[]()*^%$#@!+-<>?/\\&:{}|~`\"\' ";
    int numConsoantes = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        char ch = s[i];
        bool achou = false;

        for (int j = 0; outros[j] != '\0'; ++j) {
            if (outros[j] == ch) {
                achou = true;
                break;
            }
        }
        if (!achou) {
            numConsoantes++;
        }
    }
    return numConsoantes;
}

int main() {
    printf("Total de consoantes: %d", contaConsoantes("Eu, Rafael, programa em c!"));
    return 0;
}
