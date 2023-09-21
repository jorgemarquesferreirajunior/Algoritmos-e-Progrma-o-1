/*
 b) Escreva uma função booleana que receba strings s e t e decida se
 s é um segmento de t. Escreva um programa que use a função para
 contar o número de ocorrências de uma string s em uma string.
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool ehSegmento(const char *s, const char *t) {
    int i = 0, j = 0;
    int sizeS = strlen(s), sizeT = strlen(t);

    if (sizeS > sizeT) {
        return false;
    }
    while (j < sizeT) {
        if (s[0] == t[j]) {
            i = 0;
            while (i < sizeS && s[i] == t[j]) {
                i++;
                j++;
            }
            if (i == sizeS) {
                return true;
            }
        }
        j++;
    }
    return false;
}

int main() {
    if (ehSegmento("teste", "eu sou um teste")) {
        printf("É segmento");
    } else {
        printf("Não é segmento");
    }

    return 0;
}
