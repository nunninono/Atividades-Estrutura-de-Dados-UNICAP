#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
    char titulo_da_musica[100];
    char artista[50];
    char duracao[20];
} Musica;

typedef struct ldecNode {
    struct ldecNode* ant;
    Musica* info;
    struct ldecNode* prox;
} LDECNode;

typedef struct ldec {
    LDECNode* inicio;
    LDECNode* fim;
    int qtd;
} LDEC;

void inicializar (LDEC* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
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

Musica* criarMusica (char* titulo_da_musica, char* artista, char* duracao) {
    Musica* novaMusica = (Musica*) malloc (sizeof(Musica));
    strcpy(novaMusica->titulo_da_musica, titulo_da_musica);
    strcpy(novaMusica->artista, artista);
    strcpy(novaMusica->duracao, duracao);
    return novaMusica;
}

LDECNode* criarNo (Musica* novaMusica) {
    LDECNode* novoNo = (LDECNode*) malloc (sizeof(LDECNode));
    novoNo->ant = NULL;
    novoNo->info = novaMusica;
    novoNo->prox = NULL;
    return novoNo;
}

void adicionarMusica (LDEC* lista, char* titulo_da_musica, char* artista, char* duracao) {
    Musica* novaMusica = criarMusica(titulo_da_musica, artista, duracao);
    LDECNode* novoNo = criarNo(novaMusica);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        lista->fim->prox = novoNo;
        novoNo->ant = lista->fim;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    lista->qtd++;
}
