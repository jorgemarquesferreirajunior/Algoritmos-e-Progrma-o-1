/*
d) Escreva uma função que receba uma string ASCII e exiba uma tabela com
 o número de ocorrências de cada um dos caracteres do alfabeto ASCII na string.
 Escreva um programa para testar a função.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void procedure (char *palavra){
    int cont, x=0, cont2;
    char letra;

    for (cont=0; cont<strlen(palavra); cont++){
        letra=palavra[cont];
        for (cont2=0; cont2<strlen(palavra); cont2++){
            if(letra==palavra[cont2]){
                x++;
            }
        }
        printf ("\nocorrencias da letra %c = %d", letra, x);
        x=0;
    }
}

int main(){

    char word[20];
    char *p = word;

    printf ("Digite uma palavra: ");
    fflush(stdin);
    scanf("%[^\n]", p);
    procedure(p);
    return 0;
}
