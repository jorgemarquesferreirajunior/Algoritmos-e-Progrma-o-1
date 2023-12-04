#include "AVLTree.h"

typedef struct _node_avltree {
    int value, height;
    struct _node_avltree *left, *right;

}NodeAVLTree;

NodeAVLTree *createNodeAVLTree(int value){
    NodeAVLTree *node = (NodeAVLTree*)calloc(1, sizeof(NodeAVLTree));
    if (node == NULL) {
        fprintf(stderr, "Error in createNodeAVLTree(): Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->left = node->right = NULL;
    node->value = value;
    node->height = 0;
    return node;
}

AVLTree *createAVLTree(){
    AVLTree *tree = (AVLTree*)calloc(1, sizeof(AVLTree));
    if (tree == NULL) {
        fprintf(stderr, "Error in createAVLTree(): Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;

    return tree;
}

NodeAVLTree *append_v1(NodeAVLTree *current, int value){
    if (current == NULL)
        return createNodeAVLTree(value);

    else{
        if(value < current->value){
            current->left = append_v1(current->left, value);
        } else if (value > current->value)
            current->right = append_v1(current->right, value);
        else
            printf("\nInserção não realizada, o elemento %d já existe !\n", value);
    }

    current->height = bigger(heightNode(current->left), heightNode(current->right)) + 1;
    current = doBalance(current);

    return current;
}

void inOrderTraversal(NodeAVLTree *node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->value);
        inOrderTraversal(node->right);
    }
}

void printInOrder(AVLTree *tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->root);
        printf("\n");
    }
}

void inOrderLeftRight(NodeAVLTree *node){
    if (node != NULL){
        printf("%d ", node->value);
        inOrderLeftRight(node->left);
        inOrderLeftRight(node->right);
    }
}
void printAVLTree_LR(AVLTree *tree){
    if (tree != NULL){
        inOrderLeftRight(tree->root);
        puts("");
    }
}

void print_v3(NodeAVLTree *root, int level){
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

NodeAVLTree *find_v1(NodeAVLTree *root, int value){
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

NodeAVLTree *find_v2(NodeAVLTree *root, int value){
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

NodeAVLTree *findMin(NodeAVLTree *root) {
    if (root == NULL) 
        return NULL;
    while (root->left != NULL)
        root = root->left;

    return root;
}

NodeAVLTree *findMax(NodeAVLTree *root) {
    if (root == NULL) 
        return NULL;
    while (root->right != NULL)
        root = root->right;

    return root;
}

int getMinValue(NodeAVLTree *root){
    if (qtdNodeAVLTree(root) == 0)
        return -111111;
    
    NodeAVLTree *node = findMin(root);
    return node->value;
}

int getMaxValue(NodeAVLTree *root){
    if (qtdNodeAVLTree(root) == 0)
        return -111111;

    NodeAVLTree *node = findMax(root);
    return node->value;
}

int bigger(int a, int b){
    return (a > b) ? a : b;
}
int heightNode(NodeAVLTree *root){
    if (root == NULL){
        return -1;
    }else{
        return root->height;
    }
}

int heightAVLTree(NodeAVLTree *root){
    if (root == NULL){
        return -1;
    }else{
        int left = heightAVLTree(root->left), right = heightAVLTree(root->right);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

int balancefactor(NodeAVLTree *root){
    if (root)
        return (heightNode(root->left) - heightNode(root->right));
    else
        return 0;
}

int getBalanceFactor(NodeAVLTree *root){
    return balancefactor(root);
}

NodeAVLTree *rotateLeftAVL(NodeAVLTree *root){
    NodeAVLTree *newRoot, *son;
    
    newRoot = root->right;
    son = newRoot->left;

    newRoot->left = root;
    root->right = son;

    root->height = bigger(heightNode(root->left), heightNode(root->right)) + 1;
    newRoot->height = bigger(heightNode(newRoot->left), heightNode(newRoot->right)) + 1;

    return newRoot;
}

NodeAVLTree *rotateRightAVL(NodeAVLTree *root){
    NodeAVLTree *newRoot, *son;
    
    newRoot = root->left;
    son = newRoot->right;

    newRoot->right = root;
    root->left = son;

    root->height = bigger(heightNode(root->left), heightNode(root->right)) + 1;
    newRoot->height = bigger(heightNode(newRoot->left), heightNode(newRoot->right)) + 1;

    return newRoot;
}

NodeAVLTree *rotateRightLeftAVL(NodeAVLTree *root){
    root->right = rotateRightAVL(root->right);

    return rotateLeftAVL(root);
}

NodeAVLTree *rotateLeftRightAVL(NodeAVLTree *root){
    root->left = rotateLeftRightAVL(root->left);

    return rotateRightAVL(root);
}

NodeAVLTree *doBalance(NodeAVLTree *root){
    int fb = balancefactor(root);

    //Rotacao a esquerda
    if (fb < -1 && balancefactor(root->right) <= 0)
        root = rotateLeftAVL(root);

    //Rotacao a direita
    if (fb > 1 && balancefactor(root->left) >= 0)
        root = rotateRightAVL(root);

    //Rotacao dupla à esquerda
    if (fb > 1 && balancefactor(root->left) < 0)
        root = rotateLeftRightAVL(root);
    
    //Rotacao dupla à direita
    if (fb < -1 && balancefactor(root->right) > 0)
        root = rotateRightLeftAVL(root);

    return root;
}






int qtdNodeAVLTree(NodeAVLTree *root){
    return (root == NULL) ? 0 : 1 + qtdNodeAVLTree(root->left) + qtdNodeAVLTree(root->right);
}

int qtdLeafsAVLTree(NodeAVLTree *root){
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return qtdLeafsAVLTree(root->left) + qtdLeafsAVLTree(root->right);    
}

NodeAVLTree *removeLeafsBTree(NodeAVLTree *root, int value){
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
                printf("Elemento folha removido com sucesso!\n");
                return NULL;
            }else{
                if (root->left != NULL && root->right != NULL){
                    // caso 2: o nó tem dois filhos
                    NodeAVLTree * aux = root->left;

                    while (aux->right != NULL)
                        aux = aux->right;
                    root->value = aux->value;
                    aux->value = value;
                    root->left = removeLeafsBTree(root->left, value);
                    
                    return root;
                }else{
                    // caso 3: o nó tem nó filho apenas
                    NodeAVLTree *aux;
                    if (root->left != NULL)
                        aux = root->left;
                    else
                        aux = root->right;
                    free(root);
                    printf("Elemento com 1 filho removido com sucesso!\n");
                    return aux;
                }
            }
        } else {
            if (value < root->value)
                root->left = removeLeafsBTree(root->left, value);
            else
                root->right = removeLeafsBTree(root->right, value);
        }
    root->height = bigger(heightNode(root->left), heightNode(root->right)) + 1;
    root = doBalance(root);

    return root;

    }
}


void freeTree(NodeAVLTree *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

void destroyAVLTree(AVLTree **tree) {
    if (tree != NULL && *tree != NULL) {
        freeTree((*tree)->root);
        free(*tree);
        *tree = NULL;
    }
}

void isNullAVLTree(AVLTree *tree){
    printf("Arvore destruída?: ");
    tree == NULL ? puts("Sim") : puts("Não");
}