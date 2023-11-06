#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Faça uma função para remover os n primeiros elementos de uma
lista. A função deve retornar se a operação foi possível ou não.
Faça a função para todos os tipos de listas: estática e dinâmica
(encadeada, circular e duplamente encadeada).
*/


int main(int argc, char const *argv[]){

    // REFAZER TUDO A PARTIR DAQUI...
    puts("\nconcatenando listas estaticas...");
    ESList *eslist01 = create_ESList(5);
    ESList *eslist02 = create_ESList(5);
    for (int i = 0; i < 5; i++){
        append_in_ESList(eslist01, i);
        append_in_ESList(eslist02, i + 50);
    }
    puts("\nESLista01");
    print_ESList(eslist01);
    puts("\nESLista02");
    print_ESList(eslist02);

    ESList *eslist03 = concat_ESList(eslist01, eslist02);

    puts("\nLista concatenada");
    print_ESList(eslist03);

    puts("\n***************************************************************************");
    puts("\nconcatenando listas simplesmente encadeadas...\n");
    SList *slista01 = create_SList();
    SList *slista02 = create_SList();

    for (int i = 1; i < 6; i++){
        add_end_SList(slista01, i);
        add_end_SList(slista02, i * 10);
    }
    puts("\nLista01");
    print_SList(slista01);
    puts("\nLista02");
    print_SList(slista02);

    SList *slista03 = create_SList();

    slista03 = concat_SList(slista01, slista02);
    puts("\nLista concatenada");
    print_SList(slista03);
    
    puts("\n***************************************************************************");
    puts("\nconcatenando listas duplamente encadeadas...\n");

    DList *dlist01 = create_DList();
    DList *dlist02 = create_DList();

    for (int i = 5; i < 25; i = i + 5){
        add_end_DList(dlist01, i);
        add_end_DList(dlist02, i * 10);
    }

    puts("\nLista01");
    print_DList(dlist01);
    puts("\nLista02");
    print_DList(dlist02);

    DList *dlist03 = concat_DList(dlist01, dlist02);

    puts("\nLista concatenada");
    print_DList(dlist03);

    puts("\n***************************************************************************");
    puts("\nconcatenando listas circulares...");

    CList *clist01 = create_CList();
    CList *clist02 = create_CList();

    for (int i = 3; i < 30; i = i + 3){
        add_end_CList(clist01, i);
        add_end_CList(clist02, i * 2);
    }

    puts("\nLista01");
    print_CList(clist01);
    puts("\nLista02");
    print_CList(clist02);

    CList *clist03 = concat_CList(clist01, clist02);
    puts("\nLista concatenada");
    print_CList(clist03);

    return EXIT_SUCCESS;
}
