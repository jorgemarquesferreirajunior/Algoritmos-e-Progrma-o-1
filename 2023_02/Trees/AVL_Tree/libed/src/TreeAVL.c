#include "TreeAVL.h"


typedef struct _node_avltree {
    int info;
    int height;
    struct _node_avltree *left;
    struct _node_avltree *right;

}NodeAVL;

int calcHeight(NodeAVL *node){return (node == NULL ? -1 : node->height);}

int calcBalanceFactor(NodeAVL *node){return labs(calcHeight(node->left) - calcHeight(node->right));}

int calcMax(int x, int y){return (x > y ? x: y);}

//******ROTATIONS*******//
void rotationLL(NodeAVL *node){
    NodeAVL *aux = node->left;

    node->left = aux->right;
    aux->right = node;
    node->height = calcMax(calcHeight(node->left), calcHeight(node->right));
    aux->height = calcMax(calcHeight(aux->left), node->height + 1);

    *node = *aux;
}
