#include <stdio.h>
#include <stdlib.h>

typedef struct dados {
    char nome[100];
    float media_final;
    int quantidade_faltas;
} Dados;

typedef struct ldecNode {
    struct ldecNode* ant;
    Dados* info;
    struct ldecNode* prox;
} LDECNode;

typedef struct ldec {
    LDECNode* inicio;
    LDECNode* fim;
    int qtd;
} LDEC;

void inicialize (LDEC* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty(LDEC* lista) {
    if (lista->fim == NULL && lista->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
