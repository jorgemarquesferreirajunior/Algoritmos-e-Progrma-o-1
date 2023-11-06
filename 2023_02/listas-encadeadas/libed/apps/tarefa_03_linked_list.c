#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#define MAX 5

/*
Faça uma função para remover os n últimos elementos de uma
lista. A função deve retornar se a operação foi possível ou não.
Faça a função para todos os tipos de listas: estática e dinâmica
(encadeada, circular e duplamente encadeada)
*/



int main(int argc, char const *argv[]){
    int n_items = 2;
    // REFAZER TUDO A PARTIR DAQUI...
    puts("");
    puts("Removendo os n primeiros elementos de uma lista estatica");
    ESList *estatic_list = create_ESList(MAX);

    for (int i = 1; i <= MAX; i++){
        append_in_ESList(estatic_list, i);
    }
    puts("\nESLista01");
    print_ESList(estatic_list);
    
    printf("Removendo os %d primeiros elementos da lista...\n",n_items);
    removen_ESList(estatic_list, n_items);

    puts("\nESLista01");
    print_ESList(estatic_list);
    puts("\n***************************************************************************");
    puts("Removendo os n primeiros elementos de uma lista simplesmente encadeada...\n");
    SList *singly_list = create_SList();

    for (int i = 1; i <= MAX; i++){
        add_end_SList(singly_list, i + 5);
    }

    n_items = 4;

    print_SList(singly_list);
    printf("Removendo os %d primeiros elementos da lista...\n",n_items);
    removen_SList(singly_list, n_items);
    print_SList(singly_list);

    puts("\n***************************************************************************");
    puts("Removendo os n primeiros elementos de uma lista duplamente encadeada...\n");

    DList *doubly_list = create_DList();

    for (int i = 1; i <= MAX + 5; i++){
        add_end_DList(doubly_list, i + 15);
    }

    n_items = 7;

    print_DList(doubly_list);
    printf("Removendo os %d primeiros elementos da lista...\n",n_items);
    removen_DList(doubly_list, n_items);
    print_DList(doubly_list);

    puts("\n***************************************************************************");
    puts("Removendo os n primeiros elementos de uma lista duplamente circular...\n");

    CList *circ_list = create_CList();

    for (int i = 1; i <= MAX + 10; i++){
        add_end_CList(circ_list, i + 20);
    }

    n_items = 12;

    print_CList(circ_list);
    printf("Removendo os %d primeiros elementos da lista...\n",n_items);
    removen_CList(circ_list, n_items);
    print_CList(circ_list);

    return EXIT_SUCCESS;
}
