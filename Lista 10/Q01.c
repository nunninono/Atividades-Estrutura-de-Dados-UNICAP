// FALTA A MAIN

#include <stdio.h>
#include <stlib.h>

typedef struct info {
    int valor;
} Info;

typedef struct ldeNode {
    struct ldeNode* ant;
    Info* info;
    struct ldeNode* prox;
} LDENode;

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

Info* criarInfo (int valor) {
    novoInfo = (Info*) malloc (sizeof(Info));
    novoInfo->valor = valor;
    return novoInfo;
}

LDENode* criarNo (Info* novoInfo) {
    novoNo = (LDENode*) malloc (sizeof(LDENode*));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = noveInfo;
    return novoNo;
}

void inserirFinal (LDE* lista, int valor) {
    Info* novoInfo = criarInfo(valor);
    LDENode* novoNo = criarNo(novoInfo);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    }
    else {
        novoNo->ant = lista->fim;
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
    }
    lista->qtd++;
    printf("Valor foi inserido na lista!\n");
}

void remover (LDE* lista, int valor) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!\n");
        return;
    }
    for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
        int count_achados = 0;
        int count_nao_achados = 0;
        if (aux->info->valor == valor) {
            if (aux == lista->inicio) {
                lista->inicio = lista->inicio->prox;
                free(lista->inicio->ant);
                lista->inicio->ant = NULL;
                lista->qtd--;
                count++;
            }
            else if (aux == lista->fim) {
                lista->fim = lista->inicio->ant;
                free(lista->fim->prox);
                lista->fim->prox = NULL;
                lista->qtd--;
                count++;
            }
            else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
                lista->qtd--;
                count++;
            }
        }
        else {
            count_nao_achados++;
        }
    }
    if (count_nao_achados == lista->qtd) {
        printf("Nao foi encontrado nenhum %d na lista!\n", valor);
    }
    else {
        printf("Um total de %d valores foram removidos!!\n", count);
    }
}
