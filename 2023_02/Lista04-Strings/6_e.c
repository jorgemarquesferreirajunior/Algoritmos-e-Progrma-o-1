#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

void cont_str(char *word);

int main() {
    setlocale(LC_ALL, "Portuguese");
    char word[50];

    printf("Digite uma palavra: ");
    scanf(" %[^\n]", word);
    fflush(stdin);

    cont_str(word);
    return 0;
}

void cont_str(char *word) {
    size_t len_word = strlen(word);
    char uniques[50];  // Supondo que o número máximo de caracteres únicos seja 50
    int cont = 0;
    int pos = 0;
    int repeticoes[256];  // Um array para contar todas as possíveis letras (ASCII)

    for (int i = 0; i < 256; i++) {
        repeticoes[i] = 0;  // Inicialize o array de repetições com zeros
    }

    for (int letra = 0; letra < len_word; letra++) {
        char caractere = word[letra];
        printf("%c\n", caractere);
        if (repeticoes[caractere] == 0) {
            uniques[pos++] = caractere;  // Adicione o caractere único a 'uniques'
        }
        repeticoes[caractere]++;  // Atualize a contagem para o caractere

    }

    printf("\n");
    for (int u = 0; u < pos; u++) {
        char letra = uniques[u];
        int num_repeticoes = repeticoes[letra];
        printf("letra: %c -- repetições: %d\n", letra, num_repeticoes);
    }
}
