/*
h) Familiarize-se com a função strstr da biblioteca string que localiza a
 primeira ocorrência de uma string em outra. Procure descobrir o algoritmo
 que strstr implementa.
 */

#include<stdio.h>
#include<string.h>

int main() {
    const char *resp = strstr("o abacate é verde", "é");

    if (resp != NULL) {
        printf("%s encontrada!", resp);
    } else {
        printf("Não encontrada.");
    }
    return 0;
}
