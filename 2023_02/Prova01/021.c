Aqui está um programa em C que permite cadastrar alunos, calcular suas médias finais e pesquisar por matrículas:

```c
#include <stdio.h>
#include <string.h>

// Estrutura para representar um aluno
struct Aluno {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
    float notaRecuperacao; // Nota de recuperação, caso seja necessária
    float mediaFinal;
};

int main() {
    struct Aluno turma[30]; // Array para armazenar os alunos
    int numAlunos = 0; // Contador de alunos cadastrados

    // Menu principal
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Calcular média final\n");
        printf("3. Pesquisar aluno por matrícula\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numAlunos < 30) {
                    // Cadastrar um novo aluno
                    struct Aluno novoAluno;
                    printf("Nome do aluno: ");
                    scanf("%s", novoAluno.nome);
                    printf("Matrícula do aluno: ");
                    scanf("%d", &novoAluno.matricula);
                    printf("Nota 1 do aluno: ");
                    scanf("%f", &novoAluno.nota1);
                    printf("Nota 2 do aluno: ");
                    scanf("%f", &novoAluno.nota2);
                    printf("Nota de recuperação do aluno (0 se não houver): ");
                    scanf("%f", &novoAluno.notaRecuperacao);

                    // Calcular a média final
                    if (novoAluno.notaRecuperacao == 0) {
                        novoAluno.mediaFinal = (novoAluno.nota1 + novoAluno.nota2) / 2.0;
                    } else {
                        novoAluno.mediaFinal = (novoAluno.nota1 + novoAluno.nota2 + novoAluno.notaRecuperacao) / 3.0;
                    }

                    // Adicionar o aluno à turma
                    turma[numAlunos] = novoAluno;
                    numAlunos++;

                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("A turma está cheia (limite de 30 alunos).\n");
                }
                break;

            case 2:
                // Calcular a média final de um aluno
                if (numAlunos > 0) {
                    int matricula;
                    printf("Digite a matrícula do aluno: ");
                    scanf("%d", &matricula);

                    int encontrado = 0;
                    for (int i = 0; i < numAlunos; i++) {
                        if (turma[i].matricula == matricula) {
                            printf("Média final do aluno %s: %.2f\n", turma[i].nome, turma[i].mediaFinal);
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("Aluno não encontrado.\n");
                    }
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;

            case 3:
                // Pesquisar aluno por matrícula
                if (numAlunos > 0) {
                    int matricula;
                    printf("Digite a matrícula do aluno: ");
                    scanf("%d", &matricula);

                    int encontrado = 0;
                    for (int i = 0; i < numAlunos; i++) {
                        if (turma[i].matricula == matricula) {
                            printf("Aluno encontrado:\n");
                            printf("Nome: %s\n", turma[i].nome);
                            printf("Matrícula: %d\n", turma[i].matricula);
                            printf("Nota 1: %.2f\n", turma[i].nota1);
                            printf("Nota 2: %.2f\n", turma[i].nota2);
                            printf("Nota de recuperação: %.2f\n", turma[i].notaRecuperacao);
                            printf("Média final: %.2f\n", turma[i].mediaFinal);
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("Aluno não encontrado.\n");
                    }
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;

            case 4:
                printf("Encerrando o programa. Até mais!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
```

Neste programa, você pode escolher entre cadastrar alunos, calcular a média final de um aluno ou pesquisar um aluno por matrícula. O programa permite cadastrar até 30 alunos na turma e calcula a média final levando em consideração as notas e, se necessário, a nota de recuperação. Certifique-se de que esteja utilizando um compilador C para testar o código.
