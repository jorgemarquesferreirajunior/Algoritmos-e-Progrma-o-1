#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <stdbool.h>

void cont_str(char *word);

int main() {
    setlocale(LC_ALL, "Portuguese");
    char word[50];

    printf("Digite uma palavra: ");
    scanf("%[^\n]", word);
    fflush(stdin);

    cont_str(word);
    return 0;
}

void cont_str(char *word){
    size_t len_word = strlen(word);
    char word_copy[len_word];
    strcpy(word_copy, word);

    char uniques[2];
    uniques[0] = '#';
    uniques[1] = '\0';
    size_t len_uniques = strlen(uniques);

    int cont = 0;
    int pos = 0;
    int repeticoes[len_word];

    for(int letra = 0; letra < len_word; letra++){
        for(int rept = 0; rept < len_uniques; rept++){
            if(word[letra]==word_copy[rept]){
                cont++;
            }
        }
        if(cont == 1){
            uniques[pos] = word[letra];
            uniques[pos+1] = '\0';
            pos++;
        }
        len_uniques++;
        cont = 0;

    }
    for(int u = 0; u < strlen(uniques); u++){
        for(int v = 0; v < len_word; v++){
            if(uniques[u] == word[v]){
                cont++;
            }
        }
        printf("letra: %c -- repetições: %d\n",uniques[u], cont);
        cont = 0;
    }
}
