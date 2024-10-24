#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int valor;
} Info;

typedef struct ldeNode {
    struct ldeNode* ant;
    Info* info;
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
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Info* criarInfo (int valor) {
    Info* novoInfo = (Info*) malloc (sizeof(Info));
    novoInfo->valor = valor;
    return novoInfo;
}

LDENode* criarNo (Info* novoInfo) {
    LDENode* novoNo = (LDENode*) malloc (sizeof(LDENode*));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = novoInfo;
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
    printf("\nValor foi inserido na lista!\n\n");
}

void remover (LDE* lista, int valor) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!\n");
        return;
    }
    int count= 0;
    for (LDENode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
        if (aux->info->valor == valor) {
            if (aux == lista->inicio && aux == lista->fim) {
                free(aux);
                lista->inicio = NULL;
                lista->fim = NULL;
                count++;
            }
            else if (aux == lista->inicio) {
                lista->inicio = lista->inicio->prox;
                free(lista->inicio->ant);
                lista->inicio->ant = NULL;
                lista->qtd--;
                count++;
            }
            else if (aux == lista->fim) {
                lista->fim = lista->fim->ant;
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
    }
    if (count == 0) {
        printf("\nNao foi encontrado nenhum %d na lista!\n\n", valor);
    }
    else {
        printf("\nUm total de %d valores foram removidos!!\n\n", count);
    }
}

void listar(LDE lista) {
    if (isEmpty(lista) == 1) {
        printf("\nA lista esta vazia!!\n\n");
    }
    else {
        printf("\nValores listados: ");
        for (LDENode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
            printf("%d ", aux->info->valor);
        }
        printf("\n\n");
    }
}

int main () {
    LDE lista1;
    inicializar(&lista1);
    
    int escolha;
    int num;

    printf("===========================================\n");
    printf("1. Inserir valor na lista.\n");
    printf("2. Listar valores da lista.\n");
    printf("3. Remover valor da lista.\n");
    printf("4. Sair do programa.\n");
    printf("===========================================\n");
    
    
    while (1) {
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("\nInsira o valor a ser inserido: ");
                scanf("%d", &num);
                inserirFinal(&lista1, num);
                break;
                
            case 2:
                listar(lista1);
                break;

            case 3:
                printf("\nInsira o valor a ser removido da lista: ");
                scanf("%d", &num);
                remover(&lista1, num);
                break;

            case 4:
                printf("\nSaindo do programa...");
                return 0;
                break;
                
            default:
                printf("Insira um valor válido!\n");
                break;
        }
    }
}
