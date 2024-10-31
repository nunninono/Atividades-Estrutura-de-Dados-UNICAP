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
    printf("Nova musica foi inserida!!\n");
}

LDECNode* buscar (LDEC lista, char* titulo_da_musica) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!\n");
        return NULL;
    }
    else {
        LDECNode* aux;
        do {
            if (strcmp(aux->info->titulo_da_musica, titulo_da_musica) == 0) {
                return aux;
            }
            else {
                aux = aux->prox;
            }
        } while (aux != lista.inicio);
        return NULL;
    }
}

void removerMusica (LDEC* lista, char* titulo_da_musica) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    else {
        LDECNode* aux = buscar(*lista, titulo_da_musica);
        if (buscar != NULL) {
            if (lista->inicio == aux && lista->fim == aux) {
                free(aux);
                lista->fim = NULL;
                lista->fim = NULL;
            }
            else if (lista->inicio == aux) {
                lista->inicio = lista->inicio->prox;
                free(aux);
                lista->fim->prox = lista->inicio;
                lista->inicio->ant = lista->fim;
            }
            else if (lista->fim == aux) {
                lista->fim = lista->fim->ant;
                free(aux);
                lista->fim->prox = lista->inicio;
                lista->inicio->ant = lista->fim;
            }
            else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
            }
            lista->qtd--;
            printf("Musica removida!!\n");
        }
        else {
            printf("Musica nao encontrada!!\n");
        }
    }
}

void listarMusicas (LDEC lista) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    else {
        int contador = 1;
        LDECNode* aux;
        do {
            printf("Musica %d: %s (%s)\n", contador, aux->info->titulo_da_musica, aux->info->duracao);
            printf("           %s\n\n", aux->info->duracao);
            aux = aux->prox;
        } while (aux != lista.inicio);
    }
}

void limparLista (LDEC* lista) {
    if (isEmpty(*lista) == 1) {
        printf("A lista ja esta vazia!\n");
    }
    else {
        
    }
}
