#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
Escreva uma função para verificar se uma lista de inteiros
está ordenada ou não. A ordenação pode ser crescente ou
decrescente. 
*/


int main(int argc, char const *argv[]){
    int num = 5;
    DList *dlist01 = create_DList();
    DList *dlist02 = create_DList();

    for (int i = 1; i < num; i++){
        add_end_DList(dlist01, i);
    }

    for (int i = num; i > 0; i--){
        add_end_DList(dlist02, i);
    }

    puts("****************************************");
    puts("Lista01");
    print_DList(dlist01);

    if (sortedDList(dlist01)){
        puts("Lista01 is sorted");
    }
    if (!sortedDList(dlist01)){
        puts("Lista01 is unsorted");
    }
    puts("****************************************");
    puts("\nLista02");
    print_DList(dlist02);

    if (sortedDList(dlist02)){
        puts("Lista02 is sorted");
    }
    if (!sortedDList(dlist02)){
        puts("Lista02 is unsorted");
    }
    puts("****************************************");
    puts("adding value 99 in the lista01...");
    add_begin_DList(dlist01, 99);


    if (sortedDList(dlist01)){
        puts("Lista01 is sorted");
    }
    if (!sortedDList(dlist01)){
        puts("Lista01 is unsorted");
    }

    puts("\nLista01");
    print_DList(dlist01);
    puts("****************************************");

    puts("adding value 1 in the lista02...");
    add_begin_DList(dlist02, 1);
    
    if (sortedDList(dlist02)){
        puts("Lista02 is sorted");
    }
    if (!sortedDList(dlist02)){
        puts("Lista02 is unsorted");
    }

    puts("\nLista02");
    print_DList(dlist02);
    puts("****************************************");
    removel_DList(dlist01, 99);
    if (sortedDList(dlist01)){
        puts("Lista01 is sorted");
    }
    if (!sortedDList(dlist01)){
        puts("Lista01 is unsorted");
    }

    puts("\nLista01");
    print_DList(dlist01);
    
    destroy_DList(&dlist01);
    destroy_DList(&dlist02);

    return EXIT_SUCCESS;
}
