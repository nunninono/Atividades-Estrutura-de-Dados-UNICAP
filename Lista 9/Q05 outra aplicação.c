#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa {
    char descricao [100];
    int prioridade;
} Tarefa;

typedef struct ldeNode {
    struct ldeNode* ant;
    Tarefa* info;
    struct ldeNode* prox;
} LDENode;

typedef struct lde {
    LDENode* inicio;
    LDENode* fim;
    int qtd;
} LDE;

void inicializar (LDE* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty (LDE lista) {
    if (lista->inicio == NULL && lista->fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

