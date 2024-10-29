#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Dados* criarDados (char* nome, float media_final, int quantidade_faltas) {
    Dados* novosDados = (Dados*) malloc (sizeof(Dados*));
    strcpy(novosDados->nome, nome);
    novosDados->media_final = media_final;
    novosDados->quantidade_faltas = quantidade_faltas;
    return novosDados;
}

LDECNode* criarNo (Dados* novosDados) {
    LDECNode* novoNo = (LDECNode*) malloc (sizeof(LDECNode*));
    novoNo->info = novosDados;
    return novoNo;
}

void cadastrar (LDEC* lista, char* nome, float media_final, int quantidade_faltas) {
    Dados* novosDados = criarDados(nome, media_final, quantidade_faltas);
    LDECNode* novoNo = criarNo(novosDados);

    if (isEmpty(lista) == 1) {
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        lista->qtd++;
    }
    else {
        
    }
}
