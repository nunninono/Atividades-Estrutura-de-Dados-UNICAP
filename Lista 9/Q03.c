// AINDA PRECISA TERMINAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode {
    char descricao[50];
    int prioridade;
    struct listNode* prox;
    struct listNode* ant;
} ListNode;

typedef struct lde {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LDE;

void inicializar (LDE* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty (LDE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void inserirTarefa (LDE* lista, int valor, char* descricao) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode*));
    novo->prioridade = valor;
    strcpy(novo->descricao, descricao);
    novo->ant = NULL;
    novo->prox = NULL;

    if (isEmpty(*lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
        return;
    }

    for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
        if (strcmp(novo->descricao, aux->descricao) == 0) { // 2 descrições iguais
            printf("Ja existe uma tarefa com essa mesma descricao!!\n");
            free(novo);
            return;
        }
    }

    if (novo->prioridade > lista->inicio->prioridade) {    // inseir inicio
        lista->inicio->ant = novo;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
        return;
    }
    else if (novo->prioridade <= lista->fim->prioridade) {   // inserir fim
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;        
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
        return;
    }
    else {
        ListNode* aux = lista->inicio;
        while (aux != NULL && aux->prioridade >= novo->prioridade) {    // vai par ao nó onde deve ser adicionado
            aux = aux->prox;
        }
        // Insere o nó entre 'aux->ant' e 'aux' (antes do aux)
        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
    }
}

void buscaDescricao (LDE lista, char* descricao) {
    
}



