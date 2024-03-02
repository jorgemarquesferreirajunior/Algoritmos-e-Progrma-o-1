/*
a) Construa uma função encaixa que dados dois inteiros positivos
 a e b verifica se b corresponde aos últimos dígitos de a.

Ex.:


 */
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool estaContido(char *, char *, int, int);
void converteNumeroParaTexto(int, char *);
int lerNumero();

int main(){
    setlocale(LC_ALL, "Portuguese");
    int a, b;
    char va[10], vb[10];

    a = lerNumero();
    converteNumeroParaTexto(a, va);
    b = lerNumero();
    converteNumeroParaTexto(b, vb);
    bool contido = estaContido(va, vb, strlen(va), strlen(vb));

    if (contido) {
        printf("O número %d está contido em %d", b, a);
    } else {
        printf("Não foi encontrada uma correspondência.");
    }
    return EXIT_SUCCESS;
}

bool estaContido(char *va, char *vb, int tamanhoA, int tamanhoB) {
    int j = tamanhoB - 1;
    int i = tamanhoA - 1;

    while (j >= 0 && i >= 0 && vb[j] == va[i]) {
        i--;
        j--;
    }
    return (j == -1);
}

void converteNumeroParaTexto(int a, char *va) {
    sprintf(va,"%d", a);
}

int lerNumero() {
    int a = 0;
    
    printf("Informe um número:\n");
    scanf("%d", &a);
    fflush(stdin);
    return a;
}
