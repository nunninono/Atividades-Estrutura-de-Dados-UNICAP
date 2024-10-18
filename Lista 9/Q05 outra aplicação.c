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

Tarefa* criarTarefa (int prioridade, char* descricao) {
    Tarefa* novaTarefa = (Tarefa*) malloc (sizeof(Tarefa));
    srcpy(novaTarefa->descricao, descricao);
    novaTarefa->prioridade = prioridade;
    return novaTarefa;
}

LDENode* criarNo (Tarefa* novaTarefa) {
    LDENode* novoNo = (LDENode*) malloc (sizeof(LDENode));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = novaTarefa;
    return novoNo;
}

int buscaSimples(LDE lista, char* descricao) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
        return 0;
    }
    else {
        for (List)
    }
}

// Pode passar como parametro o proprio Tarefa* criarTarefa e pedir os dados na main
void inserirTarefa (LDE* lista, int prioridade, char* descricao) {
    Tarefa* novaTarefa = criarTarefa(prioridade, descricao);
    LDENode* novoNo = criarNo(novaTarefa);
    
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    }
    else {
        if (buscaSimples(lista, busca) == 1) {
            printf("Tarefa repetida. Insira outra!\n");
            free(novaTarefa);
            free(novoNo);
            return;
        }
        else {
            if (prioridade > lista->inicio->info->prioridade) {
                novoNo->prox = lista->inicio;
                lista->inicio->ant = novoNo;
                lista->inicio = novoNo;
            }
            else if (prioridade <= lista->fim->info->prioridade) {
                lista->fim->prox = novoNo;
                novoNo->ant = lista->fim;
                lista->fim = novoNo;
            }
            else {
                
            }
        }
    }
    lista->qtd++;
    printf("insercao efetuada!\n");
}
