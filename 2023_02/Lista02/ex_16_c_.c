#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

/*
c) Escreva um algoritmo que leia o número de identificação, as 3 notas obtidas por um aluno nas 3 verificaçõe
 e a média dos exercícios que fazem parte da avaliação, e calcule a média de aproveitamento,
 usando a fórmula: MA := (nota1 + nota 2 * 2 + nota 3 * 3 + ME)/7
 A atribuição dos conceitos obedece a tabela abaixo.
 O algoritmo deve escrever o número do aluno, suas notas, a média dos exercícios, a média de aproveitamento,
 o conceito correspondente e a mensagem 'Aprovado' se o conceito for A, B ou C,
 e 'Reprovado' se o conceito for D ou E.
 Média de aproveitamento Conceito  >= 90 A >= 75 e < 90 B >= 60 e < 75 C >= 40 e < 60 D < 40 E
*/

#define NOTAS  4

void print_list(float* list, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Nota[%d] = %.2f\n", i + 1, list[i]);
    }
    printf("\n");
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    char id[10] = "";
    char conceito[2] = "";
    float notas[NOTAS];
    float media_aprov;

    printf("Identificação do aluno: [ex: 05180334] ");
    scanf("%s", &id);
    printf("Aluno identificado: %s\n", id);
    for(int c = 0; c < NOTAS; c++)
    {
       (c < 3) ?  printf("Nota %d: ", c + 1) : printf("Media dos Exercicios: ");
       scanf("%f", &notas[c]);
    }
    printf("\n");
    media_aprov = (notas[0] + (notas[1] * 2) + (notas[2] * 3) + notas[3]) / 7;
    print_list(notas, NOTAS);
    printf("media %.2f\n", media_aprov);

    if(media_aprov < 40)
    {
        strcpy(conceito[1],"E");
    }
    if(media_aprov >= 40 && media_aprov < 60)
    {
        strcpy(conceito[1],"D");
    }
    if(media_aprov >= 60 && media_aprov < 75)
    {
        strcpy(conceito[1],"C");
    }
    if(media_aprov >= 75 && media_aprov < 90)
    {
        strcpy(conceito[1],"B");
    }
    if(media_aprov <= 90)
    {
        strcpy(conceito[1],"A");
    }
    printf("%s", conceito[1]);
    system("pause");
    return 0;
}
