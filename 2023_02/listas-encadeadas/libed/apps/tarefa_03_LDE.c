#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
Escreva uma função que, dada uma lista L1, crie uma cópia
dela em L2 eliminando os valores repetidos.
*/


int main(int argc, char const *argv[]){
    int num = 10;
    DList *dlist01 = create_DList();


    for (int i = 1; i < num; i++){
        add_end_DList(dlist01, i);
    }

    for (int i = 11; i < num + 10; i++){
        add_end_DList(dlist01, i);
        add_end_DList(dlist01, i);
    }

    puts("\nLista01");
    print_DList(dlist01);    

    puts("\nLista02-copiada(sem valores repetidos) da Lista01");
    DList *dlist02 = copyUniquesDList(dlist01);
    print_DList(dlist02);

    destroy_DList(&dlist01);
    destroy_DList(&dlist02);

    return EXIT_SUCCESS;
}
