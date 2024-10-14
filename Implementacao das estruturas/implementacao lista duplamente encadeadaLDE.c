#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    struct listNode* ant;
    int info;
    struct listNode* prox;
} ListNode;

typedef struct lde {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LDE;

void inicializar(LDE* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty(LDE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int busca(LDE lista, int valor) {
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        if (aux->info == valor) {
            return 1;
        }
    }
    return 0;
}

void inserirInicio(LDE* lista, int valor) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->ant = NULL;
    if (isEmpty(*lista) == 1) {
        novo->prox = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        if (busca(*lista, valor) == 1) {
            printf("Valor ja presente! Insira outro\n");
            return;
        }
        else {
            novo->prox = lista->inicio;
            lista->inicio->ant = novo;
            lista->inicio = novo;
        }
    }
    lista->qtd++;
}

void listarInvertido(LDE lista) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    printf("\nValores listados!\n");
    for (ListNode* aux = lista.fim; aux != NULL; aux = aux->ant) {
        printf("%d\n", aux->info);
    }
}

void listar(LDE lista) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    printf("\nValores listados!\n");
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}

void inserirFinal(LDE* lista, int valor) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode));
    novo->prox = NULL;
    novo->info = valor;
    if (isEmpty(*lista) == 1) {
        novo->ant = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        if (busca(*lista, valor) == 1) {
            printf("Valor ja presente! Insira outro\n");
            return;
        }
        else {
            novo->ant = lista->fim;
            lista->fim->prox = novo;
            lista->fim = novo;
        }
    }
    lista->qtd++;
    printf("Valor inserido!!\n");
}

void removerPrimeiro(LDE* lista) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    else {
        lista->inicio = lista->inicio->prox;
        free(lista->inicio->ant);
        lista->inicio->ant = NULL;
    }
    lista->qtd--;
    printf("Valor removido!!\n");
}

void removerUltimo(LDE* lista) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!\n");
        return;
    }
    if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    else {
        lista->fim = lista->fim->ant;
        free (lista->fim->prox);
        lista->fim->prox = NULL;
    }
    lista->qtd--;
    printf("Valor removido!!\n");
}

void esvaziar(LDE* lista) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
        return;
    }
    for (ListNode* aux = lista->inicio->prox; aux != NULL; aux = aux->prox) {   // Libera todos até o penultimo
        free(aux->ant);
        lista->qtd--;
    }
    free(lista->fim);   // Libera o ultimo que sobrou
    lista->inicio = NULL;
    lista->fim = NULL;
    if (isEmpty(*lista) == 1) {
        printf("Lista esvaziada com sucesso!\n");
    }
    else {
        printf("Ocorreu um erro ao tentar esvaziar a lista!\n");
    }

}

void remocaoEspecifica(LDE* lista, int valor) {
    if (isEmpty(*lista) == 1) {     // Se estiver vazio
        printf("Lista vazia!!\n");
        return;
    }
    if (lista->inicio == lista->fim) {  // Se so tiver um termo
        if (lista->inicio->info == valor) {
            free(lista->inicio);
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->qtd--;
            printf("Valor removido da lista!!\n");
            return;
        }
    }
    else {      // Se tiver mais de um termo
        for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
            if (busca(*lista, valor) == 1) {
                if (aux == lista->fim) {    // Lista->fim para o penultimo antes de desalocar o ultimo
                    lista->fim = aux->ant;
                }
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
                lista->qtd--;
            }
        }
        printf("Valor removido da lista!!\n");
        return;
    }
    printf("Valor nao esta presente na lista!!\n");
}


int main() {
    LDE lista1;
    int escolha;
    inicializar(&lista1);
    int num;
    
    printf("=======================================\n");
    printf("0. Esvaziar lista.\n");
    printf("1. Inserir no inicio.\n");
    printf("2. Listar valores de tras pra frente.\n");
    printf("3. Listar valores.\n");
    printf("4. Inserir no final.\n");
    printf("5. Remover o primeiro.\n");
    printf("6. Remover o ultimo.\n");
    printf("7. Remover valor especifico.\n");
    printf("8. Exit.\n");
    printf("=======================================\n");
    
    while (1) {
        printf("\nEscolha uma das opções: ");
        scanf("%d", &escolha);
        
        switch(escolha) {
            
            case 0:
                esvaziar(&lista1);
                printf("\nSaindo do programa...");
                return 0;
                break;

            case 1:
                printf("Escolha o valor a ser inserido no inicio: ");
                scanf("%d", &num);
                inserirInicio(&lista1, num);
                break;
            
            case 2:
                listarInvertido(lista1);
                break;
                
            case 3:
                listar(lista1);
                break;
            
            case 4:
                printf("Escolha o valor a ser inserido no final: ");
                scanf("%d", &num);
                inserirFinal(&lista1, num);
                break;
                
            case 5:
                removerPrimeiro(&lista1);
                break;
            
            case 6:
                removerUltimo(&lista1);
                break;

            case 7:
                printf("Insira o valor a ser removido: ");
                scanf("%d", &num);
                remocaoEspecifica(&lista1, num);
                break;

            case 8:
                printf("Saindo do programa...\n");
                return 0;
                break;
            
            default:
                printf("insira um valor valido!!\n");
                break;
            
        }
    }
}
