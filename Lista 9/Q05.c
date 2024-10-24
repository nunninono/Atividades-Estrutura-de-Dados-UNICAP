#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    struct listNode* prox;
    struct listNode* ant;
    int info;
} ListNode;

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

void inserirValor (LDE* lista, int valor) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    if (isEmpty(*lista) == 1) {  // Lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    }
    else if (novo->info < lista->inicio->info) {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
    else if (novo->info >= lista->fim->info) {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    else {
        for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
            if (aux->info > novo->info) {
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
            }
        }
    }
    lista->qtd++;
    printf("Valor foi inserido!!\n\n");
}

void listar (LDE lista) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!");
        return;
    }
    else {
        printf("\nValores listados:\n");
        for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
            printf("%d\n", aux->info);
        }
        printf("\n");
    }
}

ListNode* buscaSequencialMelhorada (LDE lista, int valor) {
    if (isEmpty(lista) == 1) {
        return NULL;
    }
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        if (aux->info == valor) {
            return aux;
        }
    }
    return NULL;
}

void remover (LDE* lista, int valor) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n\n");
        return;
    }

    ListNode* achado;
    while (achado != NULL) {
        achado = buscaSequencialMelhorada(*lista, valor);

        if (achado == NULL) {   // Nao achado
            printf("Valor nao encontrado na lista.\n\n");
            return;
        }
        else if (lista->inicio == achado && lista->fim == achado) {   // Unico
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        else if (lista->inicio == achado) {  // Inicio
            lista->inicio = achado->prox;
            lista->inicio->ant = NULL;
        }
        else if (lista->fim == achado) {   // Fim
            lista->fim = achado->ant;
            lista->fim->prox = NULL;
        }
        else {   // Meio
            achado->ant->prox = achado->prox;
            achado->prox->ant = achado->ant;
        }
        free(achado);
        lista->qtd--;
        printf("Valor removido da lista!!\n");
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
    printf("3. Buscar valor na lista.\n");
    printf("4. Remover valor na lissta.\n");
    printf("5. Sair do programa.\n");
    printf("===========================================\n");
    
    
    while (1) {
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("\nInsira o valor a ser inserido: ");
                scanf("%d", &num);
                inserirValor(&lista1, num);
                break;
                
            case 2:
                listar(lista1);
                break;
                
            case 3:
                printf("\nInsira o valor a ser buscado na lista: ");
                scanf("%d", &num);
                ListNode* achado = buscaSequencialMelhorada(lista1, num);
                if (achado != NULL) {
                    printf("Valor %d encontrado no endereco %p.\n\n", achado->info, achado);
                } 
                else {
                    printf("Valor nao encontrado na lista.\n\n");
                }
                break;

            case 4:
                printf("\nInsira o valor a ser removido da lista: ");
                scanf("%d", &num);
                remover(&lista1, num);
                break;

            case 5:
                printf("\nSaindo do programa...");
                return 0;
                break;
                
            default:
                printf("Insira um valor válido!\n");
                break;
        }
    }
}
