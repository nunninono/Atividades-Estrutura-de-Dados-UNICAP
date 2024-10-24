#include <stdio.h>
#include <stdlib.h>

typedef struct lsecNode {
    int info;
    struct lsecNode* prox;
} LSECNode;

typedef struct lsec {
    LSECNode* inicio;
    LSECNode* fim;
    int qtd;
} LSEC;

void inicializar (LSEC* lista) {
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->qtd = 0;
}

int isEmpty (LSEC lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

LSECNode* criarNo (int valor) {
    LSECNode* novoNo = (LSECNode*) malloc (sizeof(LSECNode));
    novoNo->prox = NULL;
    novoNo->info = valor;
    return novoNo;
}

int buscaSimples (LSEC lista, int valor) {
    if (isEmpty(lista) == 1) {
        return 0;
    }
    else {
        LSECNode* aux = lista.inicio;
        do {
            if (aux->info = valor) {
                return 1;
            }
            aux = aux->prox;
        } while (aux != lista.fim);
        return 0;
    }
}

void inserirInicio (LSEC* lista, int valor) {
    LSECNode* novoNo = criarNo(valor);
    if (isEmpty(*lista) == 1) {
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio; 
    }
    else {
        if (buscaSimples(*lista, valor) != 1) {
            novoNo->prox = lista->inicio;
            lista->inicio = novoNo;
            lista->fim->prox = lista->inicio;
        }
        else {
            printf("Valor ja presente na lista!!\n");
            free(novoNo);
            return;
        }
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void inserirFinal (LSEC* lista, int valor) {
    LSECNode* novoNo = criarNo(valor);
    if (isEmpty(*lista) == 1) {
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio;
    }
    else {
        if (buscaSimples(*lista, valor) != 1) {
            lista->fim->prox = novoNo;
            lista->fim = novoNo;
            lista->fim->prox = lista->inicio;
        }
        else {
            printf("Valor ja presente na lista!!\n");
            free(novoNo);
            return;
        }
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void removerInicio (LSEC* lista) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    else if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    else {
        LSECNode* aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(aux);
        lista->fim->prox = lista->inicio;
    }
    lista->qtd--;
    printf("Remocao efetuada!!\n");
}

void removerFim (LSEC* lista) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    else if (lista->fim == lista->inicio) {
        free(lista->fim);
        lista->fim = NULL;
        lista->inicio = NULL;
    }
    else {
        for (LSECNode* aux = lista->inicio; aux->prox != lista->fim; aux = aux->prox);
        free(lista->fim);
        lista->fim = aux;
        lista->fim->prox = lista->inicio;
    }
    lista->qtd--;
    printf("R emocao efetuada!!\n");
}

void removerEspecifico (LSEC* lista, int valor) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    else if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    else {
        LSECnode* aux = lista->inicio;
        do {
            if (aux->info == valor) {
                
            }
            else {
                aux = aux->prox;
            }
        } while (aux != lista->inicio);
    }
}
