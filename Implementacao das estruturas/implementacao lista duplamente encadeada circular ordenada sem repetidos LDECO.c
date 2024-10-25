#include <stdio.h>
#include <stdlib.h>

typedef struct ldecoNode {
    struct ldecoNode* ant;
    int info;
    struct ldecoNode* prox;
} LDECONode;

typedef struct ldeco {
    LDECONode* inicio;
    LDECONode* fim;
    int qtd;
} LDECO;

void inicializar (LDECO* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty (LDECO lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

LDECONode* criarNo(int valor) {
    LDECONode* novo = (LDECONode*) malloc (sizeof(LDECONode)); 
    novo->info = valor;
    return novo;
}

void inserir (LDECO* lista, int valor) {
    LDECONode* novo = criarNo(valor);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else if (valor < lista->inicio->info) {
        lista->inicio->ant = novo;
        novo->prox = lista->inicio;
        lista->inicio = lista->inicio->ant;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else if (valor > lista->fim->info) {
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = lista->fim->prox;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        LDECONode* aux = lista->inicio;
        do {
            if (valor == aux->info) {
                printf("Valor ja presente na lista!!!\n");
                free(novo);
                return;
            }
            else if (aux->ant->info < valor && aux->info > valor){
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
            }
            aux = aux->prox;
        } while (aux != lista->inicio);
        printf("\n");
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n\n");
}

void listar (LDECO lista) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!\n");
    }
    else {
        printf("\nValores listados: ");
        LDECONode* aux = lista.inicio;
        do {
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != lista.inicio);
        printf("\n\n");
    }
}

int main () {
    LDECO lista1;
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
                inserir(&lista1, num);
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
