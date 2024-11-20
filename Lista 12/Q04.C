#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacoes {
    char nome[50];
    int matricula;
    float media;
    int quantidadeFaltas;
} Informacoes;

typedef struct listNode {
    struct listNode* ant;
    Informacoes* info;
    struct listNode* prox;
} ListNode;

typedef struct ldec {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LDEC;

void inicializar (LDEC* lista) {
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->qtd = 0;
}

int isEmpty (LDEC lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Informacoes* criarInfo (char* nome, int matricula, float media, int quantidadeFaltas) {
    Informacoes* novaInfo = (Informacoes*) malloc (sizeof(Informacoes));
    strcpy(novaInfo->nome, nome);
    novaInfo->matricula = matricula;
    novaInfo->media = media;
    novaInfo->quantidadeFaltas = quantidadeFaltas;
    return novaInfo;
}

ListNode* criarNo (Informacoes* novaInfo) {
    ListNode* novoNo = (ListNode*) malloc (sizeof(ListNode));
    novoNo->info = novaInfo;
    return novoNo;
}

void inserirFinal (LDEC* lista, char* nome, int matricula, float media, int quantidadeFaltas) {
    Informacoes* novaInfo = criarInfo(nome, matricula, media, quantidadeFaltas);
    ListNode* novoNo = criarNo(novaInfo);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->inicio->ant = lista->fim;
        lista->fim->prox = lista->inicio;
    }
    else {
        lista->fim->prox = novoNo;
        novoNo->ant = lista->fim;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    lista->qtd++;
    printf("No inserido!!\n");
}

void classificar() {

}
