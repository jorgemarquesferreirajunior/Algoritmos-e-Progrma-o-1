#include "BinaryTree.h"

typedef struct _node_binarytree {
    int value;
    struct _node_binarytree *left, *right;

}NodeBTree;


NodeBTree *createNodeBTree(int value){
    NodeBTree *node = (NodeBTree*)calloc(1, sizeof(NodeBTree));
    if (node == NULL) {
        fprintf(stderr, "Error in createNodeBTree(): Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->left = node->right = NULL;
    node->value = value;

    return node;
}

BinaryTree *createBinaryTree(){
    BinaryTree *tree = (BinaryTree*)calloc(1, sizeof(BinaryTree));
    if (tree == NULL) {
        fprintf(stderr, "Error in createBinaryTree(): Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;

    return tree;
}

NodeBTree *append_v1(NodeBTree *current, int value){
    if (current == NULL) {
        return createNodeBTree(value);
    }

    if (value < current->value) {
        current->left = append_v1(current->left, value);
    } else {
        current->right = append_v1(current->right, value);
    }

    return current;
}

void inOrderTraversal(NodeBTree *node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->value);
        inOrderTraversal(node->right);
    }
}

void printInOrder(BinaryTree *tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->root);
        printf("\n");
    }
}

void freeTree(NodeBTree *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

void destroyBinaryTree(BinaryTree **tree) {
    if (tree != NULL && *tree != NULL) {
        freeTree((*tree)->root);
        free(*tree);
        *tree = NULL;
    }
}