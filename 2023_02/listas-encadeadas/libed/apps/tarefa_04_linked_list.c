#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

/*
Dada uma lista que armazena a struct produto, escreva a
função que busca o produto de menor preço. Faça a função para a
lista sequencial estática e dinâmica encadeada.

struct produto{
    int codido;
    char nome[30];
    float preco;
    int qtd;
};

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
int main(int argc, char const *argv[]){
    puts("LISTA ESTATICA...");

    Elist *lista = createElist(10);

    addproduct(lista, 1, "Produto1", 10.5, 20);
    addproduct(lista, 2, "Produto2", 5.5, 15);
    addproduct(lista, 3, "Produto3", 8.0, 30);

    // Imprimir a lista de produtos ordenada por preço
    printf_list(lista);

    puts("qual é o pruduto de menor valor?");

    struct produto menor_produto = price_product(lista);
    printf_product(menor_produto);

    destroyElist(&lista);
    
    puts("LISTA DINÂMICA...");

    return EXIT_SUCCESS;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct produto {
    int codigo;
    char nome[30];
    float preco;
    int qtd;
};

// Lista Sequencial Estática
struct lista_sequencial {
    struct produto dados[100]; // Tamanho arbitrário, ajuste conforme necessário
    int tamanho;
};

struct produto *menor_preco_sequencial(const struct lista_sequencial *lista) {
    if (lista->tamanho == 0) {
        return NULL; // Lista vazia
    }

    struct produto *menor = &lista->dados[0];
    
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->dados[i].preco < menor->preco) {
            menor = &lista->dados[i];
        }
    }

    return menor;
}

// Lista Dinâmica Encadeada
struct no {
    struct produto dados;
    struct no *prox;
};

struct lista_encadeada {
    struct no *inicio;
};

struct produto *menor_preco_encadeada(const struct lista_encadeada *lista) {
    if (lista->inicio == NULL) {
        return NULL; // Lista vazia
    }

    struct no *atual = lista->inicio;
    struct produto *menor = &atual->dados;

    while (atual != NULL) {
        if (atual->dados.preco < menor->preco) {
            menor = &atual->dados;
        }
        atual = atual->prox;
    }

    return menor;
}

int main() {
    // Exemplo de uso com lista sequencial estática
    struct lista_sequencial lista_seq = {
        .dados = {
            {1, "Produto A", 10.5, 5},
            {2, "Produto B", 8.0, 8},
            {3, "Produto C", 12.3, 3},
            // ... outros produtos ...
        },
        .tamanho = 3 // Número real de produtos na lista
    };

    struct produto *menor_seq = menor_preco_sequencial(&lista_seq);

    if (menor_seq != NULL) {
        printf("Menor preço (Sequencial): %s - R$%.2f\n", menor_seq->nome, menor_seq->preco);
    } else {
        printf("Lista sequencial vazia.\n");
    }

    // Exemplo de uso com lista dinâmica encadeada
    struct lista_encadeada lista_enc = {
        .inicio = NULL
        // Adicione produtos à lista dinâmica aqui
    };

    struct produto *menor_enc = menor_preco_encadeada(&lista_enc);

    if (menor_enc != NULL) {
        printf("Menor preço (Encadeada): %s - R$%.2f\n", menor_enc->nome, menor_enc->preco);
    } else {
        printf("Lista encadeada vazia.\n");
    }

    return 0;
}

*/