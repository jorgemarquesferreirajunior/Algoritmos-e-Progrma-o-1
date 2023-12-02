#ifndef BinaryTree_H
#define BinaryTree_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _node_binarytree NodeBTree;

typedef struct _binarytree {
    NodeBTree *root;
} BinaryTree;

NodeBTree *createNodeBTree(int value);
BinaryTree *createBinaryTree();
NodeBTree *append_v1(NodeBTree *current, int value);
void printInOrder(BinaryTree *tree);
void destroyBinaryTree(BinaryTree **tree);

#endif
