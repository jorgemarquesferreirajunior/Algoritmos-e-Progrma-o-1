//Um concurso público possui provas de Português (peso 2,5), Inglês (peso 2,5),
//Conhecimentos Específicos (peso 3), Legislação (peso 2). Escreva um programa em C
//que receba as notas (0 a 10) de um candidato em cada uma das provas e calcule e
//mostre a média ponderada das notas do aluno

#include <stdio.h>
#include <string.h>

#define MAXIMO 20

int main()
{
    float x, mediap;
    float notas[MAXIMO];
    double pesos[MAXIMO];
    char disciplinas[4][MAXIMO];
    float dividendo = 0;
    float divisor = 0;
    
    pesos[0] = 2.5;
    pesos[1] = 2.5;
    pesos[2] = 3;
    pesos[3] = 2;

    strcpy(disciplinas[0], "Portugues");
    strcpy(disciplinas[1], "Ingles");
    strcpy(disciplinas[2], "Conhecimentos Especificos");
    strcpy(disciplinas[3], "Legislacao");
 
    for (int i = 0; i < 4; i++)
    {
        printf("\nQual sua nota na prova de %s ", disciplinas[i]);
        scanf("\n %f", &notas[i]);
        mediap = mediap + (notas[i] * pesos[i]);
        divisor += pesos[i];
        
    }

    mediap = mediap / divisor;
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\nMedia Ponderada = %.2f", mediap);

    return 0;
}