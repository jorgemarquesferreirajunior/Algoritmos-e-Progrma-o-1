#include <stdio.h>
#include "linked_list.h"

void printComboCList(const CList *list){
    print_CList_v2(list);
    print_inverted_CList_v2(list);
}
int main(int argc, char const *argv[]){
    CList *c_list  =create_CList();


    if (CList_is_empty(c_list)){
        puts("empty list");
        printComboCList(c_list);
    }

    removel_CList(c_list, 99);
    printComboCList(c_list);

    puts("Adding 10, 2, 7, 4, 5, 7");
    add_end_CList(c_list, 10);
    add_end_CList(c_list, 2);
    add_end_CList(c_list, 7);
    add_end_CList(c_list, 4);
    add_end_CList(c_list, 5);
    add_end_CList(c_list, 7);
    puts("");
    print_CList_v2(c_list);
    // printComboCList(c_list);

    removel_CList(c_list, 10);
    print_CList_v2(c_list);
    // printComboCList(c_list);

    removel_CList(c_list, 7);
    print_CList_v2(c_list);
    // printComboCList(c_list);

    removel_CList(c_list, 7);
    print_CList_v2(c_list);
    // printComboCList(c_list);


    /*
    add_end_CList(c_list, 4);
    add_end_CList(c_list, 7);
    print_CList(c_list);

    add_begin_CList(c_list, 2);
    print_CList(c_list);
    add_end_CList(c_list, 8);
    print_CList(c_list);
    print_inverted_CList(c_list);
    */

    /*
    print_CList(c_list);
    print_CList_v2(c_list);
    add_begin_CList(c_list, 7);
    // print_CList(c_list);

    add_begin_CList(c_list, 5);
    // print_CList(c_list);

    add_begin_CList(c_list, 4);
    // print_CList(c_list);

    add_begin_CList(c_list, 2);
    // print_CList(c_list);

    add_begin_CList(c_list, 10);
    print_CList(c_list);
    print_inverted_CList(c_list);
    print_CList_v2(c_list);
    print_inverted_CList_v2(c_list);
    */


    destroy_CList(&c_list);


    /*
    DList *list_01 = create_DList();

    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 99");
    removel_DList(list_01, 99);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Adding 10, 7, 2, 4, 7");
    add_end_DList(list_01, 10);
    add_end_DList(list_01, 7);
    add_end_DList(list_01, 2);
    add_end_DList(list_01, 4);
    add_end_DList(list_01, 7);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 99");
    removel_DList(list_01, 99);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 7");
    removel_DList(list_01, 7);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 10");
    removel_DList(list_01, 10);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 4");
    removel_DList(list_01, 4);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 2");
    removel_DList(list_01, 2);
    print_DList(list_01);
    print_inverted_DList(list_01);

    puts("Remove 7");
    removel_DList(list_01, 7);
    print_DList(list_01);
    print_inverted_DList(list_01);
    */
    
    return 0;
}
