
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//**********strucst**********//
typedef struct _product{
    int serial;
    char name[64];
    float price;
}Product;

typedef struct _node
{
    struct _node *prev;
    struct _node *next;
    int count;
    Product *product;
}Node;

typedef struct _list
{
    Node *begin;
    Node *end;
    int size;
    int total_cost;
}List;

//**********creating**********//
Product *createProduct(int serial, const char *name, float price){
    Product *product = (Product *)calloc(1, sizeof(Product));

    if (product != NULL) {
        product->serial = serial;
        strncpy(product->name, name, sizeof(product->name) - 1); 
        product->name[sizeof(product->name) - 1] = '\0'; 
        product->price = price;
    }

    return product;
}

Node *createNode(int serial, const char *name, float price){
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->prev = node->next = NULL;
    node->count = 0;
    node->product = createProduct(serial, name, price);

    return node;
}
List *createList(){
    List *L = (List *)calloc(1, sizeof(List));
    L->begin = L->end = NULL;
    L->size = L->total_cost = 0;

    return L;
}
//**********checking**********//
bool ListIsEmpty(const List *L){return L->size == 0;}
bool productNotExist(const Product *product){return product == NULL;}
//**********destroying**********//
void destroyProduct(Product **product_ref){
    free(*product_ref);
    *product_ref = NULL;
}

void destroyNode(Node **node_ref){
    Node *node = *node_ref;
    destroyProduct(&node->product);
    free(node);
    *node_ref = NULL;
}

void destroyList(List **list_ref){
    List *L = *list_ref;
    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL){   
        aux = p;
        p = p->next;
        destroyNode(&aux);
    }

    free(L);
    *list_ref = NULL;   

}

//*******************adding to lists*****************//
void addEndList(List *L, int serial, const char *name, float price){
    Node *p = createNode(serial, name, price);
    p->prev = L->end;

    ListIsEmpty(L) ? (L->begin = p) : (L->end->next = p);

    L->end = p;
    L->size++;
}

//*********************print lists*******************//
void printList(const List *L){
    Node *node = L->begin;

    printf("L-> ");
    while (node != NULL)
    {
        printf("%d (%d)-> ", node->product->serial, node->count);
        node = node->next;
    }
    printf("NULL\nL->end = ");
    (L->end == NULL) ? (printf("NULL\n")) : (printf("%d (%d)-> ", L->end->product->serial, L->end->count));
    printf("Size = %d\n", L->size);
    puts("");
}   
void printInvertedList(const List *L){
    Node *node = L->end;

    printf("DL-> end -> ");
    while (node != NULL)
    {
        printf("%d (%d)-> ", node->product->serial, node->count);
        node = node->prev;
    }
    printf("NULL\nL->begin = ");
    (L->end == NULL) ? (printf("NULL\n")) : (printf("%d (%d)-> ", L->begin->product->serial, L->begin->count));

    printf("Size = %d\n", L->size);
    puts("");
}

void printSerialList(const List *L){
    Node *p = L->begin;
    printf("\nL = ( ");
    if (ListIsEmpty(L)){
        printf("NULL");
    }
    else{
        while (p != NULL){
            printf("%d", p->product->serial);
            if (p != L->end){
                printf(", ");
            }
            p = p->next;
        }
        
    }
    
    printf(")\n");

    printf("Custo total = %d\n", L->total_cost);
}

//FUNCAO_TENEBROSA

const Product *accessProduct(List *L, int serial){
    Product *product = NULL;
    
    if (!ListIsEmpty(L)){
        Node *p = L->begin;
        int call = 1;

        while (p != NULL && p->product->serial != serial){
            call++;
            p = p->next;
        }

        if (p != NULL){
            L->total_cost += call;
            p->count++;
            product = p->product;

            //reorganizing
            if (p != L->begin){
                Node *q = p->prev;

                while (q !=NULL && q->count <= p->count){
                    p->prev = q->prev;
                    q->prev = p;
                    q->next = p->next;
                    p->next = q;

                    p->prev == NULL ? (L->begin = p) : (p->prev->next = p);
                    q->next == NULL ? (L->end = q) : (q->next->prev = q);
                    
                    q = p->prev;
                    
                }
                
            }
            
        }

    }

    return product;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////gcc main.c -o main
int main() {
    List *L = createList();

    char cmd[12];

    scanf("%s", cmd);

    while (strcmp(cmd, "para") != 0) {
      
        if (strcmp(cmd, "add") == 0) {
            int serial;
            char name[64];
            float price;

            scanf("%d %s %f", &serial, name, &price);
            addEndList(L, serial, name, price);
            
        }
       
        else if (strcmp(cmd, "acessa") == 0) {
            int serial;
            scanf("%d", &serial);

            const Product *product = accessProduct(L, serial);

            if (product == NULL) {
                printf("Produto %d inexistente\n", serial);
            }
            else {
               // puts("");
                printf("%d, %s, %.2f\n", product->serial, product->name, product->price);
            }
            // printList(L);
        }

        scanf("%s", cmd);
    }
    
    printSerialList(L);

    destroyList(&L);

    return 0;
}
