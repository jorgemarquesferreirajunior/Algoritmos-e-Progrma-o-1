/*
d) Escreva uma função que apague todos os # de um vetor c[0..n-1] de caracteres ASCII.
Exemplo: Se n vale 7 e o vetor contém   a b c # # d #   então o resultado deve ser   a b c d .
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

int main () {
   int cont = 0;
   int len;
   char str[100];

    setlocale(LC_ALL, "Portuguese");

    printf("Digite uma palavra que contenha #: ");
    scanf("%[^\n]", str);//nao usar & quando ler uma string em vetor;
    //%[^\n] le paravras com espaços até a tecla Enter ser pressionada...
    fflush(stdin);
    len = strlen(str);
    int str_n[len];

    char filter[len];

    for(int i = 0; i < len; i++){
        int str_int;

        str_int = (int)str[i];

        if(str_int != 35){
            filter[cont] = str[i];
            cont++;
        }
    }
    filter[cont] = '\0';
    printf("Palavra Original: %s\n", str);
    printf("Palavra Filtrada: %s\n", filter);

   return(0);
}
