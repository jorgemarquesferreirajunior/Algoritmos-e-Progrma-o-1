#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Escreva uma função que receba a posição de dois elementos da
lista e os troque de lugar. A função deve retornar se a operação
foi possível ou não. Faça a função para todos os tipos de
listas: estática e dinâmica (encadeada)
*/

struct produto{
    int codido;
    char nome[30];
    float preco;
    int qtd;
};

// Lista Sequencial Estatica
typedef struct _estatic_list{
    int size;
    int capacity;
    struct produto *data;

} Elist;

bool Elist_is_empty(const Elist * list){
    return list->size == 0;
}

Elist *createElist(int capacity){
    Elist *l = (Elist*)calloc(1, sizeof(Elist));
    l->capacity = capacity;
    l->size = 0;
    l->data = (struct produto*)calloc(capacity, sizeof(struct produto));

    return l;
}

void addproduct(Elist *list, int code, char *name, float price, int qtd){
    struct produto product;

    product.codido = code;
    strcpy(product.nome, name);
    product.preco = price;
    product.qtd = qtd;

    if (Elist_is_empty(list)){
        list->data[0] = product;
        
    }
    else{
        // Encontrando a posição correta para inserção ordenada
        int i = list->size - 1;

        while (i >= 0 && list->data[i].preco > product.preco) {
            list->data[i + 1] = list->data[i];
            i--;
        }
        list->data[i + 1] = product;
    }
    list->size++;
}

struct produto price_product(const Elist *list){
    struct produto product;

    if (Elist_is_empty(list)){
        fprintf(stderr, "ERROR in price_product\n");
        fprintf(stderr , "List is empty'\n");
    }
    else if (list->size == 1){
        product = list->data[0];
    }
    else{
        int loops = list->size;
        product = list->data[0];

        for (size_t i = 0; i < loops; i++){
            if (list->data[i].preco < product.preco){
                product = list->data[i];
            }
            
        }
        
    }
    
    return product;
}

void printf_list(const Elist *lista){
    puts("Lista de Produtos:");
    for (int i = 0; i < lista->size; i++) { 
        printf("Nome:   %s\nCódigo: %d\nPreço:  %.2f\nQtd:    %d\n",
               lista->data[i].nome, lista->data[i].codido,
               lista->data[i].preco, lista->data[i].qtd);
        printf("*************************************\n");
    }
}

void printf_product(const struct produto product){
    puts("Produto:");
    printf("Nome:   %s\nCódigo: %d\nPreço:  %.2f\nQtd:    %d\n",
               product.nome, product.codido,
               product.preco, product.qtd);
    printf("#####################################\n");

}
void destroyElist(Elist **list_ref){
    Elist *l = *list_ref;
    free(l->data);
    free(*list_ref);
    *list_ref = NULL;
}

bool change_pos_Elist(Elist *list, int pos1, int pos2) {
    if (Elist_is_empty(list)){
        fprintf(stderr, "ERROR in change_pos_Elist\n");
        fprintf(stderr, "List is empty\n");

        return false;
    }
    
    else if (pos1 < 0 || pos1 >= list->size || pos2 < 0 || pos2 >= list->size) {
        fprintf(stderr, "ERROR in change_pos_Elist\n");
        fprintf(stderr, "Invalid Positions\n");

        return false;
    }
    else{
        struct produto temp = list->data[pos1];

        list->data[pos1] = list->data[pos2];
        list->data[pos2] = temp;

        return true;
    }
    
}

//LISTA SEQUENCIAL DINÂMICA
typedef struct _doubly_node {
    struct produto val;
    struct _doubly_node *prev;
    struct _doubly_node *next;
}DoublyNode, Dnode;

typedef struct _doubly_list{
    int size;
    Dnode *begin;
    Dnode *end;
    
}Dlist;

Dnode *createDnode() {
    Dnode *node = (Dnode *)calloc(1, sizeof(Dnode));
    
    if (node) {
        node->prev = node->next = NULL;
        node->val.codido = 0;
        strcpy(node->val.nome, "");
        node->val.preco = 0.0;
        node->val.qtd = 0;

        return node;
    }
    return NULL;
}

Dlist *createDlist(){
    Dlist *list = (Dlist *)calloc(1, sizeof(Dlist));
    if (list) {
        list->size = 0;
        list->begin = list->end = NULL;
        
        return list;
    }
    return NULL;    
}


void destroyDList(Dlist **list_ref) {
    if (*list_ref == NULL) {
        return;
    }

    Dlist *l = *list_ref;
    Dnode *current = l->begin;

    while (current) {
        Dnode *next = current->next;

        free(current);
        current = next;
    }

    free(*list_ref);
    *list_ref = NULL;
}

bool DList_is_empty(const Dlist * list){
    return list->size == 0;
}

void addToDList(Dlist *list, int code, char *name, float price, int qtd) {
    Dnode *node = createDnode();
    
    if (!node) {
        fprintf(stderr, "Error creating node\n");
        return;
    }

    node->val.codido = code;
    strcpy(node->val.nome, name);
    node->val.preco = price;
    node->val.qtd = qtd;

    if (DList_is_empty(list)) {
        list->begin = list->end = node;
    } else {
        list->end->next = node;
        node->prev = list->end;
        list->end = node;
    }

    list->size++;
}

struct produto price_product_DList(const Dlist *list) {
    if (DList_is_empty(list)) {
        fprintf(stderr, "Error in price_product_DList\n");
        fprintf(stderr, "List is empty\n");
        
        struct produto invalid_product = { .codido = -1, .nome = "", .preco = -1.0, .qtd = -1 };
        return invalid_product;
    }

    struct produto product = list->begin->val; 
    Dnode *current = list->begin->next;

    while (current != NULL) {
        if (current->val.preco < product.preco) {
            product = current->val;
        }
        current = current->next;
    }

    return product;
}

bool change_pos_Dlist(Dlist *list, int pos1, int pos2) {
    if (DList_is_empty(list)){
        fprintf(stderr, "Error in change_pos_Dlist\n");
        fprintf(stderr, "List is empty\n");

        return false;
    }
    else if (pos1 < 0 || pos1 >= list->size || pos2 < 0 || pos2 > list->size){
        fprintf(stderr, "Error in change_pos_Dlist\n");
        fprintf(stderr, "Invalid Positions\n");
        
        return false;
    }
    else{
        Dnode *current = list->begin;
        Dnode *node1 = NULL, *node2 = NULL;
        int count = 0;

        while (current != NULL){
            if(count == pos1){
                node1 = current;
            }
            if(count == pos2){
                node2 = current;
            }

            if(node1 != NULL && node2 != NULL){
                break;
            }
            current = current->next;
            count++;
        }

        if (node1 == NULL || node2 == NULL) {
            return false;
        }
        else{
            struct produto temp = node1->val;
            node1->val = node2->val;
            node2->val = temp;

            return true;
        }
    }
    
}

void printf_DList(const Dlist *list) {
    if (DList_is_empty(list)) {
        printf("Lista dinâmica encadeada vazia.\n");
        return;
    }

    Dnode *current = list->begin;

    while (current != NULL) {
        printf_product(current->val);
        current = current->next;
    }
}

//*********************************************MAIN*********************************************//
int main(int argc, char const *argv[]){
    puts("LISTA ESTATICA");

    Elist *lista = createElist(10);

    addproduct(lista, 1, "Produto1", 7.8, 20);
    addproduct(lista, 2, "Produto2", 9.5, 15);
    addproduct(lista, 3, "Produto3", 1.2, 30);

    printf_list(lista);
    change_pos_Elist(lista, 0, 2);
    printf_list(lista);

    destroyElist(&lista);
    puts("********************************************************************");
    puts("LISTA DINÂMICA...");

    Dlist *dlista = createDlist();

    addToDList(dlista, 1, "Produto1", 10.5, 20);
    addToDList(dlista, 2, "Produto2", 25.5, 15);
    addToDList(dlista, 3, "Produto3", 81.0, 30);
    addToDList(dlista, 4, "Produto4", 69.0, 9);
    addToDList(dlista, 5, "Produto5", 34.0, 17);

    printf_DList(dlista);
    change_pos_Dlist(dlista, 0, 4);
    printf_DList(dlista);

    destroyDList(&dlista);

    puts("LISTA CIRCULAR...");

    return EXIT_SUCCESS;
}