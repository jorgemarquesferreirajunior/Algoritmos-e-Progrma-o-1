#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
Dada uma lista contendo números inteiros positivos, escreva
uma função que calcule:
• Quantos números pares existem.
• A média da lista.
• O maior valor.
• O menor valor.
• A posição do maior valor.
• A posição do menor valor.
• O número de nós com valor maior do que x.
• A soma da lista.
• O número de nós da lista que possuem um número primo.
*/


int main(int argc, char const *argv[]){
    int num = 2;
    puts("Listas duplamente encadeadas...\n");

    DList *dlist01 = create_DList();
    for (int i = 1; i < 15; i++){
        add_end_DList(dlist01, i);
    }

    puts("\nLista01");
    print_DList(dlist01);

    printf("Quantos números pares existem?\nresp:%d\n", countEvenNumbersFromDList(dlist01));
    printf("A média da lista?\nresp:%.1f\n", meanDList(dlist01));
    printf("O maior valor?\nresp:%d\n", maxValueFromDList(dlist01));
    printf("O menor valor?\nresp:%d\n", minValueFromDList(dlist01));
    printf("A posição do maior valor?\nresp:%d\n", findIndexOfMaxValueInDList(dlist01));
    printf("A posição do menor valor?\nresp:%d\n", findIndexOfMinValueInDList(dlist01));
    printf("O número de nós com valor maior do que %d?\nresp:%d\n", num, countNodesAboveXInDList(dlist01, num));
    printf("A soma da lista?\nresp:%d\n", sumOfDList(dlist01));
    printf("O número de nós da lista que possuem um número primo?\nresp:%d\n", countPrimesInDList(dlist01));

    destroy_DList(&dlist01);

    puts("\n***************************************************************************");

    return EXIT_SUCCESS;
}
