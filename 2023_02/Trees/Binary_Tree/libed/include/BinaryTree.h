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
void append_v2(NodeBTree **root, int value);
void append_v3(NodeBTree **root, int value);
void printInOrder(BinaryTree *tree);
void print_v3(NodeBTree *root, int level);
NodeBTree *find_v1(NodeBTree *root, int value);
NodeBTree *find_v2(NodeBTree *root, int value);
NodeBTree *findMin(NodeBTree *root);
NodeBTree *findMax(NodeBTree *root);
int getMinValue(NodeBTree *root);
int getMaxValue(NodeBTree *root);

int heightBinaryTree(NodeBTree *root);
int qtdNodeBTree(NodeBTree *root);
int qtdLeafsBTree(NodeBTree *root);
NodeBTree *removeLeafsBTree(NodeBTree *root, int value);

void destroyBinaryTree(BinaryTree **tree);
void isNullBinaryTree(BinaryTree *tree);
void inOrderLeftRight(NodeBTree *node);
void printBinaryTree_LR(BinaryTree *tree);



#endif
