#include <stdlib.h>
#include <string.h>

typedef struct listNode {
    char nome[50];
    int RG;
    struct listNode* prox;
} ListNode;

typedef struct lse {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LSE;

void inicializar(LSE* lista) {
    lista->inicio = NULL;
    lista->fim =  NULL;
    lista->qtd = 0;
}

int isEmpty(LSE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(LSE lista) {
    return 0;
}

void inserirFinal(LSE* lista, char nome[50], int registro) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode));
    novo->prox = NULL;
    strcpy(novo->nome, nome);
    novo->RG = registro;
    if (isEmpty(*lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->qtd++;
}

int buscaSimples(LSE lista, char nome[50], int registro) {
    if (isEmpty(lista) == 0) {
        for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
            if (strcmp(aux->nome, nome) == 0 && aux->RG == registro) {
                return 1;
            } 
        }
        return 0;
    }
    return;
}

void registrar(LSE* lista, char nome[50], int registro) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode));
    novo->prox = NULL;
    strcpy(novo->nome, nome);
    novo->RG = registro;
    if (isEmpty(*lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else if (buscaSimples(*lista, nome, registro) == 1) {
        printf("Pessoa ja registrada!!\n");
        return;
    }
    else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->qtd++;
    printf("Registro realizado!\n");
}

void cancelar(LSE* lista) {
    if (isEmpty(*lista) == 1) {
        printf("Nao existe nenhum cadastro!\n");
        return;
    }
    if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->fim = NULL;
        lista->inicio = NULL;
    }
    else {
        ListNode* aux = lista->inicio;
        while (aux->prox != lista->fim) {
            aux = aux->prox;
        }   
        free(lista->fim);
        lista->fim = aux;
        lista->fim->prox = NULL;
    }
    lista->qtd--;
}

void exibir(LSE lista) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!\n");
        return;
    }
    else {
        for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
            printf("Nome: %s", aux->nome);
            printf("RG: %d", aux->RG);
            printf("\n");
        }
    }
}

int verificar(LSE lista, int registro) {
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        if (aux->RG == registro) {
            printf("Registro encontrado!\n");
            return 1;
        }
    }
    printf("Registro nao encontrado!\n");
    return 0;
}

int remover(LSE* lista, int registro) {
    if (isEmpty(*lista) == 1) {
        printf("Lista esta vazia!!\n");
        return;
    }
    ListNode* aux = lista->inicio;
    ListNode* aux2 = aux->prox;
    if (lista->inicio == lista->fim) {
        if (aux->RG == registro) {
            free(aux);
            lista->fim = NULL;
            lista->inicio = NULL;
            lista->qtd--;
            printf("Registro removido!\n");
        }
        else{
            printf("Registro nao encontrado!\n");
        }     
    }
    else {
        if (lista->inicio->RG == aux->RG) {
            free(lista->inicio);
            lista->inicio = aux2;
            lista->qtd--;
            printf("Registro removido!\n");
        }
        else {
            while (aux2 != NULL) {
                if (aux2->RG == registro) {
                    aux->prox = aux2->prox;
                    free(aux2);
                    lista->qtd--;
                    return;
                }
                else {
                    aux = aux2;
                    aux2 = aux2->prox;
                }
            }
            printf("Registro nao encontrado!\n");
        }
    }
}

int informar(LSE lista) {
    printf("O predio possui um total de %d pessoas!!\n", lista.qtd);
}