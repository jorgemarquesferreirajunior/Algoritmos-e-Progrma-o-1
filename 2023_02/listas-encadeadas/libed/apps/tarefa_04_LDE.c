#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
Escreva uma função que, dada uma lista L1, inverta a lista e
a armazene em L2.
*/


int main(int argc, char const *argv[]){
    int num = 10;
    DList *dlist01 = create_DList();


    for (int i = 1; i < num; i++){
        add_end_DList(dlist01, i);
    }

    puts("\nLista01");
    print_DList(dlist01);

    DList *dlist02 = copyInvertedDList(dlist01);

    puts("\nLista02-copiada(valores invertidos) da Lista01");
    print_DList(dlist02);

    destroy_DList(&dlist01);
    destroy_DList(&dlist02);

    return EXIT_SUCCESS;
}
