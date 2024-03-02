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

void append_v2(NodeBTree **root, int value){
    if (*root == NULL) {
        *root = createNodeBTree(value);
        return;
    }

    if (value < (*root)->value) {
        append_v2(&((*root)->left), value);
    } else {
        append_v2(&((*root)->right), value);
    }
}

void append_v3(NodeBTree **root, int value) {
    NodeBTree *newNode = createNodeBTree(value);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    NodeBTree *current = *root;
    NodeBTree *parent = NULL;

    while (current != NULL) {
        parent = current;

        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
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

void inOrderLeftRight(NodeBTree *node){
    if (node != NULL){
        printf("%d ", node->value);
        inOrderLeftRight(node->left);
        inOrderLeftRight(node->right);
    }
}
void printBinaryTree_LR(BinaryTree *tree){
    if (tree != NULL){
        inOrderLeftRight(tree->root);
        puts("");
    }
    
    
}

void print_v3(NodeBTree *root, int level){
    int i;

    if (root){
        print_v3(root->right, level + 1);
        puts("\n");

        for (int i = 0; i < level; i++)
            printf("\t");
        
        printf("%d", root->value);
        print_v3(root->left, level + 1);
    }
}

NodeBTree *find_v1(NodeBTree *root, int value){
    if (root){
        if (value == root->value)
            return root;
        else if (value < root->left)
            return find_v1(root->left, value);
        else
            return find_v1(root->right, value);
    }
    
    return NULL;
}

NodeBTree *find_v2(NodeBTree *root, int value){
    while (root){
        if (value < root->value)
            root = root->left;
        else if (value > root->value)
            root = root->right;
        else
            return root;
    }
    
    return NULL;
}

NodeBTree *findMin(NodeBTree *root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

NodeBTree *findMax(NodeBTree *root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

int getMinValue(NodeBTree *root){
    if (qtdNodeBTree(root) == 0)
        return -111111;

    NodeBTree *node = findMin(root);
    return node->value;
}

int getMaxValue(NodeBTree *root){
    if (qtdNodeBTree(root) == 0)
        return -111111;

    NodeBTree *node = findMax(root);
    return node->value;
}

int heightBinaryTree(NodeBTree *root){
    if (root == NULL){
        return -1;
    }else{
        int left = heightBinaryTree(root->left), right = heightBinaryTree(root->right);
        if (left > right)
            return left + 1;
        else
            return
                right + 1;
    }
}


int qtdNodeBTree(NodeBTree *root){
    return (root == NULL) ? 0 : 1 + qtdNodeBTree(root->left) + qtdNodeBTree(root->right);
}

int qtdLeafsBTree(NodeBTree *root){
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return qtdLeafsBTree(root->left) + qtdLeafsBTree(root->right);    
}

NodeBTree *removeLeafsBTree(NodeBTree *root, int value){
    if (root == NULL){
        puts("Valor não encontrado!");
        return NULL;
    } else {
        // procurar o nó
        if (value == root->value){
            // remover o nó
            if (root->left == NULL && root->right == NULL){
                // caso 1: o nó é uma folha (sem filhos)
                free(root);
                return NULL;
            }else{
                if (root->left != NULL && root->right != NULL){
                    // caso 2: o nó tem dois filhos
                    NodeBTree * aux = root->left;

                    while (aux->right != NULL)
                        aux = aux->right;
                    root->value = aux->value;
                    aux->value = value;
                    root->left = removeLeafsBTree(root->left, value);
                    
                    return root;
                }else{
                    // caso 3: o nó tem nó filho apenas
                    NodeBTree *aux;
                    if (root->left != NULL)
                        aux = root->left;
                    else
                        aux = root->right;
                    free(root);
                    return aux;
                }
            }
        } else {
            if (value < root->value)
                root->left = removeLeafsBTree(root->left, value);
            else
                root->right = removeLeafsBTree(root->right, value);
            return root;
        }
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

void isNullBinaryTree(BinaryTree *tree){
    printf("Arvore destruída?: ");
    tree == NULL ? puts("Sim") : puts("Não");
}