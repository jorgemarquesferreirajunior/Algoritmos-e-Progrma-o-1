#ifndef AVLTree_H
#define AVLTree_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _node_avltree NodeAVLTree;

typedef struct _AVLTree {
    NodeAVLTree *root;
} AVLTree;

NodeAVLTree *createNodeAVLTree(int value);
AVLTree *createAVLTree();
NodeAVLTree *append_v1(NodeAVLTree *current, int value);
void printInOrder(AVLTree *tree);
NodeAVLTree *find_v1(NodeAVLTree *root, int value);
NodeAVLTree *find_v2(NodeAVLTree *root, int value);
NodeAVLTree *findMin(NodeAVLTree *root);
NodeAVLTree *findMax(NodeAVLTree *root);
int getMinValue(NodeAVLTree *root);
int getMaxValue(NodeAVLTree *root);

int bigger(int a, int b);
int heightNode(NodeAVLTree *root);
int heightAVLTree(NodeAVLTree *root);
NodeAVLTree *rotateRightAVL(NodeAVLTree *root);
NodeAVLTree *rotateLeftAVL(NodeAVLTree *root);
NodeAVLTree *rotateRightLeftAVL(NodeAVLTree *root);
NodeAVLTree *rotateLeftRightAVL(NodeAVLTree *root);
NodeAVLTree *doBalance(NodeAVLTree *root);
int getBalanceFactor(NodeAVLTree *root);
void print_v3 (NodeAVLTree *root, int level);

int qtdNodeAVLTree(NodeAVLTree *root);
int qtdLeafsAVLTree(NodeAVLTree *root);
NodeAVLTree *removeLeafsBTree(NodeAVLTree *root, int value);

void destroyAVLTree(AVLTree **tree);
void isNullAVLTree(AVLTree *tree);
void inOrderLeftRight(NodeAVLTree *node);
void printAVLTree_LR(AVLTree *tree);



#endif
