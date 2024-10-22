#include <stdio.h>
#include <stdlib.h>

typedef struct lsecNode {
    int info;
    struct lsecNode* prox;
} LSECNode;

typedef struct lsec {
    LSECNode* inicio;
    LSECNode* fim;
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
    if (isEmpty(*lista) == 1) {
        lista->fim = novo;
        lista->inicio = novo;
        lista->fim->prox = novo;
    }
    else {
        lista->inicio = novo;
        lista->fim->prox = novo;
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void listar (LSEC lista) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
    }
    else {
        int count = 0;
        for (LSECNode* aux = lista.inicio; count < lista.qtd; aux = aux->prox) {
            printf("%d ",aux->info);
            count++;
        }
        printf("\n");
    }
}

int main () {
    LSEC lista1;
    inicializar(&lista1);
    
    int escolha;
    int num;

    printf("===========================================\n");
    printf("1. Inserir valor na lista.\n");
    printf("2. Listar valores da lista.\n");
    printf("4. Sair do programa.\n");
    printf("===========================================\n");
    
    
    while (1) {
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("\nInsira o valor a ser inserido: ");
                scanf("%d", &num);
                inserirInicio(&lista1, num);
                break;
                
            case 2:
                listar(lista1);
                break;

            case 3:
                printf("\nSaindo do programa...");
                return 0;
                break;
                
            default:
                printf("Insira um valor válido!\n");
                break;
        }
    }
}
