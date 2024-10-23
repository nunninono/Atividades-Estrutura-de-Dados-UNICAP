#include <stdio.h>
#include <stdlib.h>

typedef struct lseNode {
    int info;
    struct lseNode* prox;
} LSENode;

typedef struct lse {
    LSENode* inicio;
    LSENode* fim;
    int qtd;
} LSE;

void isEmpty (LSE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
