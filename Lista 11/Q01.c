#include <stdio.h>
#include <stdlib.h>

typedef struct dados {
    char nome[100];
    float media_final;
    int quantidade_faltas;
} Dados;

typedef struct ldeNode {
    struct ldeNode* ant;
    Dados* info;
    struct ldeNode* prox;
} LDENode;

typedef struct lde {
    LDENode* inicio;
    LDENode* fim;
    int qtd;
} LDE;

void inicialize (LDE* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty(LDE* lista) {
    if (lista->fim == NULL && lista->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
