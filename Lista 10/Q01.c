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
    
}

LDENode* criarNo () {
    
}

void inserirFinal (LDE* lista) {
    
    if (isEmpty(*lista) == 1) {
        
    }
}
