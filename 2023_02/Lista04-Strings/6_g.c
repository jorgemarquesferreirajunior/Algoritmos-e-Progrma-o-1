#include <stdio.h>

void decimalParaBinario(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binario[32];
    int i = 0;

    while (n > 0) {
        binario[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}

int main() {
    int numero;
    printf("Digite um numero inteiro qualquer: ");
    scanf("%d", &numero);
    printf("\nEm decimal, %d vale: ",numero);
    decimalParaBinario(numero);
    printf("\n");

    return 0;
}
