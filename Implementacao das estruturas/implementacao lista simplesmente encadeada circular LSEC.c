#include <stdio.h>
#include <stdlib.h>

typedef struct ldeNode {
    int info;
    struct ldeNode* prox;
} LSENode;

typedef struct lsec {
    LSENode* inicio;
    LSENode* fim;
    int qtd;
} LSEC;

void inicializar (LSEC* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty (LSEC lista) {
    if (lista.fim == NULL && lista.inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void inserirInicio (LSEC* lista, int valor) {
    LSECNode* novo = (LSECNode*) malloc (sizeof(LSECNode));
    novo->info = valor;
    novo->prox = lista->inicio;
    lista->fim->prox = novo;   // circular
    lista->inicio = novo;
    if (isEmpty(*lista) == 1) {
        lista->fim = novo;
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void listar (LSEC lista) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
    }
    else {
      for (LSECNode* aux = lista->inicio; aux->prox != lista->inicio->prox; aux = aux->prox) {
          printf("%d ",aux->info);
      }
      printf("\n");
    }
}

int main() {
  
}
