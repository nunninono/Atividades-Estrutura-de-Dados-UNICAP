#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacoes {
    int RG;
    char nome[50];
    int idade;
    float peso;
    float altura;
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

Informacoes* criarInfo (int RG, char* nome, int idade, float peso, float altura) {
    Informacoes* novaInfo = (Informacoes*) malloc (sizeof(Informacoes));
    novaInfo->RG = RG;
    strcpy(novaInfo->nome, nome);
    novaInfo->idade = idade;
    novaInfo->peso = peso;
    novaInfo->altura = altura;
    return novaInfo;
}

ListNode* criarNo (Informacoes* novaInfo) {
    ListNode* novoNo = (ListNode*) malloc (sizeof(Informacoes));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = novaInfo;
    return novoNo;
}

void inserirFinal (LDEC* lista, int RG, char* nome, int idade, float peso, float altura) {
    Informacoes* novaInfo = criarInfo (RG, nome, idade, peso, altura);
    ListNode* novoNo = criarNo (novaInfo);

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
    printf("No inserido!!\n");
}

void inserirOrdenado () {

}

/*LDEC copiaOrdenada (LDEC lista) {
    LDEC copia;
    inicializar(&copia);

    if (isEmpty(lista) == 1) {
        return copia;
    }
    else if (lista.qtd == 1) {
        inserirFinal(&copia, lista.inicio->info->RG, lista.inicio->info->nome, lista.inicio->info->idade, lista.inicio->info->peso, lista.inicio->info->altura);
        copia.qtd++;
        return copia;
    }
    else {
        ListNode* aux = lista.inicio;
        do {
            if (strcmp(aux->info->nome, copia.inicio->info->nome) < 0) { //strcmp Retorna um valor negativo se a primeira string for alfabeticamente menor que a segunda.
                copia.inicio->ant = aux;
                aux->prox = copia.inicio;
                copia.inicio = aux;
                copia.fim->prox = copia.inicio;
                copia.inicio->ant = copia.fim;
                copia.qtd++;
            }
            else if (strcmp(aux->info->nome, copia.fim->info->nome) > 0) {  //strcmp Retorna um valor positivo se a primeira string for alfabeticamente maior que a segunda.
                copia.fim->prox = aux;
                aux->ant = copia.fim;
                copia.fim = aux;
                copia.fim->prox = copia.inicio;
                copia.inicio->ant = copia.fim;
                copia.qtd++;
            }
            else {
                ListNode* aux2 = copia.inicio;
                do {
                    if (strcmp(aux->info->nome, aux2->info->nome) < 0) {
                        aux2->ant->prox = aux;
                        aux->ant = aux2->ant;
                        aux->prox = aux2;
                        aux2->ant = aux;
                        copia.qtd++;
                        break;
                    }
                    aux2 = aux2->prox;
                } while (aux2 != copia.inicio);
            }
            aux = aux->prox;
        } while (aux != lista.inicio);
        return copia;
    }
}*/
