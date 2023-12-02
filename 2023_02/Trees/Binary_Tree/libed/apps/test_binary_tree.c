#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    BinaryTree *arvore = createBinaryTree();

    arvore->root = append_v1(arvore->root, 50);
    arvore->root = append_v1(arvore->root, 25);
    arvore->root = append_v1(arvore->root, 100);
    arvore->root = append_v1(arvore->root, 9);


    printf("In-order traversal: ");
    printInOrder(arvore);

    destroyBinaryTree(&arvore);

    printf("Arvore é nula?[1:yes | 0:no]\n> %d\n", arvore == NULL);fflush(stdout);   

    return EXIT_SUCCESS;
}
