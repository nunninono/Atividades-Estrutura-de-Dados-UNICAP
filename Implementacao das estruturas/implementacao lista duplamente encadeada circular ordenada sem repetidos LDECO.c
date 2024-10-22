#include <stdio.h>
#include <stdlib.h>

typedef struct ldeocNode {
    struct ldecoNode* ant;
    int info;
    struct ldecoNode* prox;
} LDECONode;

typedef struct ldeco {
    LDECONode* inicio;
    LDECONode* fim;
    int qtd;
} LDECO;

void inicializar (LDECO* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty (LDECO lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void inserir (LDECO* lista, int valor) {
    LDECONode* novo = (LDEONode*) malloc (sizeof(LDEONode)); 
    novo->info = valor;
    if (isEmpty(*lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else if (valor < lista->inicio) {
        lista->inicio->ant = novo;
        novo->prox = lista->inicio;
        lista->inicio = lista->inicio->ant;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else if (valor > lista->fim) {
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = lista->fim->prox;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        do {
            LDECONode* aux = lista->inicio;
            if (valor == aux->info) {
                printf("Valor ja presente na lista!!!\n");
                free(novo);
                return;
            }
            else if (aux->info < valor && aux->prox->info > valor){
                novo->prox = aux->prox;
                novo->ant = aux;
                aux->prox->ant = novo;
                aux->prox = novo;
            }
            aux = aux->prox;
        } while (aux != lista->inicio);
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void listar (LDECO lista) {
    if (isEmpty(lista) == 1) {
        pritnf("Lista vazia!!\n");
    }
    else {
        printf("Valores listados: ");
        do {
            LDECONode* aux = lista.inicio;
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != lista->inicio);
    }
}
