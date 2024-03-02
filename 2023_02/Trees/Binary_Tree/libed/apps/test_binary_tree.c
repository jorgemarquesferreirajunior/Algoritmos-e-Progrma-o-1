#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    BinaryTree *arvore = createBinaryTree();
    int opcao, valor;
    char sep[100] = "-=-=-=-=--=--=-=-=-=-=-=-=-=-=-=--=--=-=-=-=-=-=";
    
    do {
        printf("%s\n\n", sep);
        printf("\t0 - Sair\t\t1 - Inserir\n\t2 - Imprimir\t\t3 - Buscar\n\t4 - Altura\t\t5 - Qtd. de nós\n\t6 - Remover\t\t7 - Qtd. de Folhas\n\t8 - Menor\t\t9 - Maior\n>:");
        scanf("%d", &opcao); fflush(stdin);

        switch (opcao){
            case 0:
                printf("%s\n\n", sep);
                puts("Saindo...");
                destroyBinaryTree(&arvore);
                isNullBinaryTree(arvore);
                puts("");
                break;
            case 1:
                printf("%s\n", sep);
                printf("Digite um número inteiro: ");
                scanf("%d", &valor);
                append_v3(&(arvore->root), valor);
                break;
            case 2:
                printf("%s\n", sep);
                print_v3(arvore->root, 1);
                puts("\n\n");
                break;
            case 3:
                printf("%s\n\n", sep);
                print_v3(arvore->root, 1);
                printf("\nDigite um número inteiro: ");
                scanf("%d", &valor);
                NodeBTree *retorno = find_v1(arvore->root, valor);

                if (retorno)
                    printf("O valor %d foi encontrado!\n", valor);
                else
                    printf("Valor %d não está presente na árvore!\n", valor);
                puts("");
                break;
            case 4:
                printf("%s\n\n", sep);
                printf("Altura da árvore: %d\n", heightBinaryTree(arvore->root));
                puts("");
                break;
            case 5:
                printf("%s\n\n", sep);
                printf("Quantidade de Nós na árvore: %d\n", qtdNodeBTree(arvore->root));
                puts("");
                break;
            case 6:
                printf("%s\n", sep);
                print_v3(arvore->root, 1);
                printf("\nDigite o valor a ser removido: ");
                scanf("%d", &valor);
                arvore->root = removeLeafsBTree(arvore->root, valor);
                printBinaryTree_LR(arvore);
                puts("");
                break;
            case 7:
                printf("%s\n\n", sep);
                printf("Quantidade de Folhas na árvore: %d\n", qtdLeafsBTree(arvore->root));
                puts("");
                break;
            case 8:
                printf("%s\n\n", sep);
                if (getMinValue(arvore->root) != NULL)
                    if (getMinValue(arvore->root) == -111111)
                        puts("Árvore Vazia\n");
                    else 
                        printf("Menor valor: %d\n\n", getMinValue(arvore->root));
                else
                    puts("Árvore Vazia\n");
                break;
            case 9:
                printf("%s\n\n", sep);
                if (getMaxValue(arvore->root) != NULL)
                    if (getMaxValue(arvore->root) == -111111)
                        puts("Árvore Vazia\n");
                    else 
                        printf("Maior valor: %d\n\n", getMaxValue(arvore->root));
                else
                    puts("Árvore Vazia\n");
                break;
            default:
				puts("*******************************************************\n");
                printf("Opção inválida!\n\n");
        }
    } while (opcao != 0);

    puts("");
    
    return EXIT_SUCCESS;
}
