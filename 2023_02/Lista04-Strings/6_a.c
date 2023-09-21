#include<stdio.h>
#include<locale.h>
#include<string.h>

void str_section(char palavra[], int tamanho, int inicio, int fim);

int main(){
    setlocale(LC_ALL, "Portuguese");
    char word[20];
    int len, init, end;

    printf("Digite uma palavra: ");
    scanf("%[^\n]", word);
    fflush(stdin);
    len = strlen(word);

    printf("digite dois valores inteiros entre 0 e %d: ", len - 1);
    scanf("%d %d", &init, &end);

    str_section(word, len, init, end);
return 0;
}

void str_section(char palavra[], int tamanho, int inicio, int fim){
    if(inicio < 0 || inicio >= tamanho || inicio >= tamanho || fim < 0|| fim >= tamanho){
        printf("intervalo inválido.\n");
        return;
    }

    for(int i = inicio; i < fim; i++){
        printf("%c", palavra[i]);
    }
    printf("\n");

}
