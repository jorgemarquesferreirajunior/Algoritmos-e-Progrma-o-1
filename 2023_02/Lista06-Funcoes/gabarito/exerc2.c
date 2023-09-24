/*
b) Escreva uma função que recebe como parâmetro um inteiro positivo
 ano e devolve 1 se ano for bissexto, 0 em caso contrário.
(Um ano é bissexto se (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)).)

 */
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ehBissexto(int);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int ano;

    printf("Informe um ano:\n");
    scanf("%d", &ano);
    if (ehBissexto(ano))
        printf("É bissexto!");
    else
        printf("Não é bissexto!");
    return EXIT_SUCCESS;
}


bool ehBissexto(int ano) {
    return ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0);
}
