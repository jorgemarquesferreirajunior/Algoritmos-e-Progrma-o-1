#include <stdio.h>
#include<string.h>
#include<locale.h>

#define MAX_RESPOSTAS 10

struct lista{
    char dados[MAX_RESPOSTAS];
};
int main() {
    int n, acertos, res;
    struct lista solucoes, respostas;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite o numero de alunos [MÁX:%d]: ", MAX_RESPOSTAS);
    scanf("%d", &n);fflush(stdin);
    printf("Digite o numero de questoes [MÁX:%d]: ", MAX_RESPOSTAS);
    scanf("%d", &res);fflush(stdin);

    printf("Digite o gabarito da prova [A,B,C,D,E]:\n");
    for(int x = 0; x < res; x++){
        printf("Questão %.2d:", x + 1);
        scanf("%c", &solucoes.dados[x]);fflush(stdin);
    }
    for(int n_alunos = 0; n_alunos < n; n_alunos++){
        printf("\nDigite as respostas do aluno %d\n", n_alunos + 1);
        acertos = 0;
        for(int r = 0; r < res; r++){
            printf("Resp %.2d: ", r + 1);
            scanf("%c", &respostas.dados[r]);fflush(stdin);
            if(solucoes.dados[r]==respostas.dados[r]){
                acertos++;
            }
        }
        printf("Acertos: %d\n", acertos);
    }
    return 0;
}

