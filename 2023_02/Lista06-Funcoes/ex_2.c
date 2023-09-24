#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool ehAnoBissexto(int);
int main(){
    setlocale(LC_ALL, "Portuguese");
    int ano;
    char frases[2][50];
    strcpy(frases[0], "É ano bissexto\n");
    strcpy(frases[1],"Não é ano bissexto\n");

    printf("Digite um ano qualquer [ex:2023]: ");
    scanf("%d", &ano);fflush(stdin);
    printf("%d: ", ehAnoBissexto(ano));
    if(ehAnoBissexto(ano)){
        printf(frases[0]);
    }else{
        printf(frases[1]);
    }
    return 0;
}

bool ehAnoBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}









