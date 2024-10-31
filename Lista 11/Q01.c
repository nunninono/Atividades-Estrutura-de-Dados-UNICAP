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

int isEmpty(LDEC lista) {
    if (lista.fim == NULL && lista.inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Dados* criarDados (char* nome, float media_final, int quantidade_faltas) {
    Dados* novosDados = (Dados*) malloc (sizeof(Dados));
    strcpy(novosDados->nome, nome);
    novosDados->media_final = media_final;
    novosDados->quantidade_faltas = quantidade_faltas;
    return novosDados;
}

LDECNode* criarNo (Dados* novosDados) {
    LDECNode* novoNo = (LDECNode*) malloc (sizeof(LDECNode));
    novoNo->info = novosDados;
    return novoNo;
}

void cadastrar (LDEC* lista, char* nome, float media_final, int quantidade_faltas) {
    Dados* novosDados = criarDados(nome, media_final, quantidade_faltas);
    LDECNode* novoNo = criarNo(novosDados);

    if (isEmpty(*lista) == 1) {
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        printf("Cadastro realizado!!\n");
        lista->qtd++;
        return;
    }
    else {
        LDECNode* aux = lista->inicio;
        do {
            if (strcmp(aux->info->nome, novoNo->info->nome) == 0) {
                free(novoNo);
                printf("Ja existe um aluno com esse nome!\n");
                return;
            }
            aux = aux->prox;
        } while (aux != lista->inicio);

        if (strcmp(novoNo->info->nome, lista->inicio->info->nome) < 0) { // < 0 se o primeiro termo vier antes do segundo
            novoNo->prox = lista->inicio;
            novoNo->ant = lista->fim;
            lista->fim->prox = novoNo;
            lista->inicio->ant = novoNo;
            lista->inicio = novoNo;
        }
        else if (strcmp(novoNo->info->nome, lista->fim->info->nome) > 0) { // > 0 se o primeiro termo vier depois do segundo
            novoNo->ant = lista->fim;
            novoNo->prox = lista->inicio;
            lista->inicio->ant = novoNo;
            lista->fim->prox = novoNo;
            lista->fim = novoNo;
        }
        else {
            aux = lista->inicio;
            do {
                if (strcmp(aux->info->nome, novoNo->info->nome) < 0) {
                    novoNo->prox = aux;
                    novoNo->ant = aux->ant;
                    aux->ant->prox = novoNo;
                    aux->ant = novoNo;
                }
                aux = aux->prox;
            } while (aux != lista->inicio);
        }
        lista->qtd++;
        printf("Cadastro realizado!!\n");
    }
}

void listar (LDEC lista) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    LDECNode* aux = lista.inicio;
    int count = 0;
    printf("Alunos cadastrados:\n\n");
    do {
        printf("%d - Nome: %s\n", count, aux->info->nome);
        printf("%d - Media final: %f\n", count, aux->info->media_final);
        printf("%d - Quantidade de faltas: %d\n\n", count, aux->info->quantidade_faltas);
        aux = aux->prox;
    } while (aux != lista.inicio);
}

LDECNode* consultar (LDEC lista, char* nome) {
    if (isEmpty(lista) == 1) {
        return NULL;
    }
    else {
        LDECNode* aux = lista.inicio;
        do {
            if (strcmp(aux->info->nome, nome) == 0) {
                return aux;
            }
            aux = aux->prox;
        } while (aux != lista.inicio);
    }
    return NULL;
}

void alterarMediaFinal (LDEC* lista, char* nome) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    else {
        LDECNode* aux = consultar(*lista, nome);
        if (aux != NULL) {
            float novaMedia;
            printf("Insira a nova media final de %s: ", nome);
            scanf("%f", &novaMedia);
            printf("\n\n");
            aux->info->media_final = novaMedia;
            return;
        }
        else {
            printf("Nao foi possivel realizar a mudanca, nome nao encontrado!\n");
        }
    }
}

void alterarQuantidadeDeFaltas (LDEC* lista, char* nome) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    else {
        LDECNode* aux = consultar(*lista, nome);
        if (aux != NULL) {
            int mudanca;
            char escolha;
            printf("Voce quer adicionar(a) ou remover faltas(r) r ou a : ");
            scanf("%c ", &escolha);
            if (escolha == 'r') {
                printf("Insira o numero de faltas a ser retirado: ");
                scanf("%d", &mudanca);
                printf("\n\n");
                aux->info->quantidade_faltas = aux->info->quantidade_faltas - mudanca;
                return;
            }
            else if (escolha == 'a') {
                printf("Insira o numero de faltas a ser acrecido: ");
                scanf("%d", &mudanca);
                printf("\n\n");
                aux->info->quantidade_faltas = aux->info->quantidade_faltas + mudanca;
                return;
            }
        }
        else {
            printf("Nao foi possivel realizar a mudanca, nome nao encontrado!\n");
        }
    }
}
