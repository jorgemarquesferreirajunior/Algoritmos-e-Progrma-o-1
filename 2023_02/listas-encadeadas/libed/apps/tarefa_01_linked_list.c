#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
Escreva uma função que receba duas listas e retorne uma
terceira contendo as duas primeiras concatenadas. Faça a função
para todos os tipos de listas: estática e dinâmica (encadeada,
duplamente encadeada e circular)
*/


int main(int argc, char const *argv[]){

    puts("\ntratando listas simplesmente encadeadas...");
    SList *slista01 = create_SList();
    SList *slista02 = create_SList();

    for (int i = 1; i < 6; i++){
        add_end_SList(slista01, i);
        add_end_SList(slista02, i * 10);
    }
    print_SList(slista01);
    print_SList(slista02);

    SList *slista03 = create_SList();

    print_SList(slista03);
    slista03 = concat_SList(slista01, slista02);
    print_SList(slista03);

    add_end_SList(slista03, 99);
    print_SList(slista03);

    puts("\ntratando listas duplamente encadeadas...");

    DList *dlist01 = create_DList();
    DList *dlist02 = create_DList();

    for (int i = 5; i < 25; i = i + 5){
        add_end_DList(dlist01, i);
        add_end_DList(dlist02, i * 10);
    }
    print_DList(dlist01);
    print_DList(dlist02);

    DList *dlist03 = concat_DList(dlist01, dlist02);
    print_DList(dlist03);

    puts("\ntratando listas circulares...");

    CList *clist01 = create_CList();
    CList *clist02 = create_CList();

    for (int i = 3; i < 30; i = i + 3){
        add_end_CList(clist01, i);
        add_end_CList(clist02, i * 2);
    }
    print_CList(clist01);
    print_CList(clist02);

    CList *clist03 = concat_CList(clist01, clist02);
    print_CList(clist03);

    return EXIT_SUCCESS;
}
