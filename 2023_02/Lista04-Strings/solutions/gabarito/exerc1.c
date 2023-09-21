/*
 a) Escreva uma função que receba uma string str e inteiros positivos i e j
 e devolva uma string com o mesmo conteúdo que o segmento str[i..j].
 */
#include <stdio.h>
#include <string.h>

int main() {
    char s[20];
    int i, j;

    printf("digite um nome : ");
    scanf("%[^\n]", s);
    printf("digite dois valores inteiros : ");
    scanf("%d %d", &i, &j);
    int ax, t = strlen(s);

    i--;                     //  apontar para a posição inicial certa
    if (i < 0)
        i = 0;               //  validar a posição inicial
    else if (i > t)
        i = t;          //  validar a posição inicial
    if (j < 0)
        j = 0;               //  validar a posição final
    else if (j > t)
        j = t;          //  validar a posição final
    if (i > j)                     //  acertar a posição inicial o menor primeiro
    {
        ax = i;                    //  guarda esse calor em ax
        i = j;                     //  coloca o valor de j em i
        j = ax;                    //  coloca o valor de i anterior em j
    }
    for (i - 1; i < j; i++)          //  Loop para percorrer o espaço na string
        printf("%c", s[i]);        //  escreve os caracteres do intervalo da string
    return 0;
}
