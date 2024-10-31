#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
    char[100] titulo_da_musica;
    char[50] artista;
    float duracao;
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

Musica* novaMusica (char* titulo_da_musica, char* artista, float duracao) {}
    novaMusica = (Musica*) malloc (sizeof(Musica));
    novaMusica->
LDECNode*

void adicionarMusica (LDEC* lista)
