<<<<<<< HEAD
/*
 Dados n e n seq��ncias de n�meros inteiros n�o-nulos, cada qual seguida por um 0,
 calcular a soma dos n�meros pares de cada seq��ncia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int cols, lins;
int cont = 1;
srand(time(NULL));
lins = 1 + (rand() % 6);
cols = 1 + (rand() % 6);
int sequecias[lins][cols];
int pares[cont];
int unico = 1;

printf("Matriz aletaoria: \n");
//gerando a matriz aletoria
for(int lin = 0; lin < lins; lin++)
{
    for(int col = 0; col < cols; col++)
    {
        sequecias[lin][col] = 1 + (rand() % 10);
    }
}

// armazenando todos os valores unicos pares presentes na matriz gerada
for(int i = 0; i < lins; i++)
{
    for(int c = 0; c < cols; c++)
    {
        if(sequecias[i][c] % 2 == 0)
        {
            for(int teste = 0; teste < cont; teste++)
            {
                if(sequecias[i][c] == pares[teste])
                {
                    unico = 0;
                }
            }
            if(unico == 1)
            {
                pares[cont - 1] = sequecias[i][c];
                cont ++;
            }
            unico = 1;
        }
    }
}

//printando a matriz gerada
for(int i = 0; i < lins; i++)
{
    for(int c = 0; c < cols; c++)
    {
        printf("%d ", sequecias[i][c]);
    }
    printf("\n");
}

//printando os numeros pares nao repetidos encotrados
printf("Numeros pares dessa matriz: \n");
for(int p = 0; p < cont - 1; p++)
{
    printf("%d ", pares[p]);
}

printf("\n");
system("pause");
return 0;
}
=======
/*
 Dados n e n seq��ncias de n�meros inteiros n�o-nulos, cada qual seguida por um 0,
 calcular a soma dos n�meros pares de cada seq��ncia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int cols, lins;
int cont = 1;
srand(time(NULL));
lins = 1 + (rand() % 6);
cols = 1 + (rand() % 6);
int sequecias[lins][cols];
int pares[cont];
int unico = 1;

printf("Matriz aletaoria: \n");
//gerando a matriz aletoria
for(int lin = 0; lin < lins; lin++)
{
    for(int col = 0; col < cols; col++)
    {
        sequecias[lin][col] = 1 + (rand() % 10);
    }
}

// armazenando todos os valores unicos pares presentes na matriz gerada
for(int i = 0; i < lins; i++)
{
    for(int c = 0; c < cols; c++)
    {
        if(sequecias[i][c] % 2 == 0)
        {
            for(int teste = 0; teste < cont; teste++)
            {
                if(sequecias[i][c] == pares[teste])
                {
                    unico = 0;
                }
            }
            if(unico == 1)
            {
                pares[cont - 1] = sequecias[i][c];
                cont ++;
            }
            unico = 1;
        }
    }
}

//printando a matriz gerada
for(int i = 0; i < lins; i++)
{
    for(int c = 0; c < cols; c++)
    {
        printf("%d ", sequecias[i][c]);
    }
    printf("\n");
}

//printando os numeros pares nao repetidos encotrados
printf("Numeros pares dessa matriz: \n");
for(int p = 0; p < cont - 1; p++)
{
    printf("%d ", pares[p]);
}

printf("\n");
system("pause");
return 0;
}
>>>>>>> origin/main
