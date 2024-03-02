#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <stdbool.h>
bool ispalindromo(char *word);


int main() {
    setlocale(LC_ALL, "Portuguese");
    char word[20];

    printf("Digite uma palavra: ");
    scanf("%[^\n]", word);
    fflush(stdin);

    if(ispalindromo(word)){
        printf("\n%s É um palíndromo.\n");
    }else{
        printf("\n%s Não é um palíndromo.\n");
    }

    return 0;
}

bool ispalindromo(char *word){
    size_t len = strlen(word);
    int pos_i = 0, pos_j = len - 1;

    while(pos_i < len){

        if(word[pos_i] != word[pos_j]){
            return false;
        }
        pos_i++;
        pos_j--;
    }

    return true;
}
