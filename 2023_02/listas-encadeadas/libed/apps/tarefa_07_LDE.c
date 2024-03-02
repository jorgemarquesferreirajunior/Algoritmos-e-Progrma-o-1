#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
Dadas duas listas ordenadas, L1 e L2, escreva uma função que
faça a UNIÃO de ambas em uma terceira lista.
*/


int main(int argc, char const *argv[]){
    DList *lista1 = create_DList();
    DList *lista2 = create_DList();

    for (int i = 1; i <= 5; i++){
        add_end_DList(lista1, i);
        add_end_DList(lista2, i + 3);
    }
    
    puts("lista01");
    print_DList(lista1);

    puts("lista02");
    print_DList(lista2);

    

    puts("intersecção:");

    DList *interseccao = intersectionDList(lista1, lista2);

    print_DList(interseccao);

    destroy_DList(&lista1);
    destroy_DList(&lista2);
    destroy_DList(&interseccao);
















    return EXIT_SUCCESS;
}