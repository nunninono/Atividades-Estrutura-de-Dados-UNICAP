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
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->qtd = 0;
}

int isEmpty (LSEC lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

LSECNode* criarNo (int valor) {
    LSECNode* novoNo = (LSECNode*) malloc (sizeof(LSECNode));
    novoNo->prox = NULL;
    novoNo->info = valor;
    return novoNo;
}

int buscaSimples (LSEC lista, int valor) {
    if (isEmpty(lista) == 1) {
        return 0;
    }
    else {
        LSECNode* aux = lista.inicio;
        do {
            if (aux->info == valor) {
                return 1;
            }
            aux = aux->prox;
        } while (aux != lista.inicio);
        return 0;
    }
}

void inserirInicio (LSEC* lista, int valor) {
    LSECNode* novoNo = criarNo(valor);
    if (isEmpty(*lista) == 1) {
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio; 
    }
    else {
        if (buscaSimples(*lista, valor) == 1) {
            printf("Valor ja presente na lista!!\n");
            free(novoNo);
            return;
        }
        else {
            novoNo->prox = lista->inicio;
            lista->inicio = novoNo;
            lista->fim->prox = lista->inicio;
        }
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void inserirFinal (LSEC* lista, int valor) {
    LSECNode* novoNo = criarNo(valor);
    if (isEmpty(*lista) == 1) {
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio;
    }
    else {
        if (buscaSimples(*lista, valor) == 1) {
            printf("Valor ja presente na lista!!\n");
            free(novoNo);
            return;
        }
        else {
            lista->fim->prox = novoNo;
            lista->fim = novoNo;
            lista->fim->prox = lista->inicio;
        }
    }
    lista->qtd++;
    printf("Valor inserido na lista!!\n");
}

void removerInicio (LSEC* lista) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    else if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    else {
        LSECNode* aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(aux);
        lista->fim->prox = lista->inicio;
    }
    lista->qtd--;
    printf("Remocao efetuada!!\n");
}

void removerFim (LSEC* lista) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    else if (lista->fim == lista->inicio) {
        free(lista->fim);
        lista->fim = NULL;
        lista->inicio = NULL;
    }
    else {
        LSECNode* aux; 
        for (aux = lista->inicio; aux->prox != lista->fim; aux = aux->prox);
        free(lista->fim);
        lista->fim = aux;
        lista->fim->prox = lista->inicio;
    }
    lista->qtd--;
    printf("Remocao efetuada!!\n");
}

void removerEspecifico (LSEC* lista, int valor) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    else if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->qtd--;
        printf("Remocao efetuada!!\n");
    }
    else {
        LSECNode* aux = lista->inicio->prox;
        LSECNode* auxAnt = lista->inicio;
        if (auxAnt->info == valor) {
            free(auxAnt);
            lista->inicio = aux;
            lista->fim->prox = lista->inicio;
            lista->qtd--;
            printf("Remocao efetuada!!\n");
            return;
        }
        do {
            if (aux->info == valor) {
                auxAnt->prox = aux->prox;
                free(aux);
                lista->qtd--;
                printf("Remocao efetuada!!\n");
                return;
            }
            else {
                auxAnt = aux;
                aux = aux->prox;
            }
        } while (aux != lista->inicio);
        printf("Valor nao encontrado na lista!\n");
    }
}

void exibirValores (LSEC lista) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    LSECNode* aux = lista.inicio;
    printf("Valores listados: ");
    do {
        printf("%d ", aux->info);   
        aux = aux->prox;
    } while (aux != lista.inicio);
    printf("\n\n");
}

void removerTodos (LSEC* lista) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    while(1) {
        if (isEmpty(*lista) == 0) {
            printf("Todos os valores foram removidos!!\n");
            return;
        }
        else {
            removerInicio(lista);
        }
    }
    lista->inicio = NULL;
    lista->fim = NULL;
}

void exibirOpcoes() {
    printf("\n===================== Opcoes ==================\n");
    printf("1- Inserir valor no inicio:\n");
    printf("2- Inserir valor no final:\n");
    printf("3- Remover primeiro da lista:\n");
    printf("4- Remover o ultimo da lista:\n");
    printf("5- Remover um especifico da lista:\n");
    printf("6- Exibir todos os valores da lista:\n");
    printf("0- Encerrar programa.\n");
    printf("===============================================\n");
    printf("Informe a opcao desejada: ");
}

int main () {
    LSEC lista1;
    inicializar(&lista1);
    
    int opcao, num;
    
    do {
        exibirOpcoes();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Informe o valor a ser inserido no inicio: ");
                scanf("%d", &num);
                inserirInicio(&lista1, num);
                break;
            
            case 2:
                printf("Informe o valor a ser inserido no final: ");
                scanf("%d", &num);
                inserirFinal(&lista1, num);
                break;
                
            case 3:
                removerInicio(&lista1);
                break;
            
            case 4:
                removerFim(&lista1);
                break;
            
            case 5:
                printf("Informe o valor a ser removido: ");
                scanf("%d", &num);
                removerEspecifico(&lista1, num);
                break;
                
            case 6:
                exibirValores(lista1);
                break;
            
            case 0:
                removerTodos(&lista1);
                printf("Saindo do programa...\n");
                break;
        }
    } while(opcao != 0);
    return 0;
}
