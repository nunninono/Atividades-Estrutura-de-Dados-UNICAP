#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacao {
    char texto[100];
    int num;
} Informacao;

typedef struct listnode {
    struct listnode* ant;
    Informacao* info;
    struct listnode* prox;
} ListNode;

typedef struct ldec {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LDEC;

void inicializar (LDEC* lista) {
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->qtd = 0;
}

int isEmpty (LDEC lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Informacao* criarInfo (int num, char* texto) {
    Informacao* novaInfo = (Informacao*) malloc (sizeof(Informacao));
    strcpy(novaInfo->texto, texto);
    novaInfo->num = num;
    return novaInfo;
}

ListNode* criarNo (Informacao* novaInfo) {
    ListNode* novoNo = (ListNode*) malloc (sizeof(ListNode));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = novaInfo;
    return novoNo;
}

void inserirFinal (LDEC* lista, int num, char* text) {
    Informacao* novaInfo = criarInfo(num, text);
    ListNode* novoNo = criarNo(novaInfo);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        novoNo->ant = lista->fim;
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
        lista->inicio->ant = lista->fim;
        lista->fim->prox = lista->inicio;
    }
    lista->qtd++;
    printf("Valor inserido!\n");
}

void listar (LDEC lista) {
        if (isEmpty(lista) == 1) {
        printf("vazia\n\n");
    }
    else {
        ListNode* aux = lista.inicio;
        do {
            printf("(%d, ", aux->info->num);
            printf("%s) ", aux->info->texto);
            aux = aux->prox;
        } while (aux != lista.inicio);
        printf("\n\n");
    }
}

void concatenar (LDEC* lista1, LDEC* lista2) {
    if (isEmpty(*lista2) == 1) {
        printf("A lista 2 esta vazia!!\n");
    }
    else {
        lista1->fim->prox = lista2->inicio;
        lista1->fim = lista2->fim;
        lista1->fim->prox = lista1->inicio;
        lista1->inicio->ant = lista1->fim;
        lista1->qtd += lista2->qtd;
        lista2->fim = NULL;
        lista2->inicio = NULL;
        lista2->qtd = 0;
    }
    printf("Concatenacao realizada!!\n");
}

LDEC dividir (LDEC* lista1) {
    LDEC lista2;
    inicializar(&lista2);

    if (isEmpty(*lista1) == 1) {
        return lista2;
    }
    else if (lista1->qtd == 1) {
        return lista2;
    }
    else if (lista1->qtd % 2 == 1) {
        int metade = (lista1->qtd - 1) / 2;
        lista1->qtd++;
        metade++;
        int count = 0;
        ListNode* aux;
        for (aux = lista1->inicio; count <= metade; aux = aux->prox) {
            count++;
        }
        lista2.inicio = aux->prox;
        lista2.fim = lista1->fim;
        lista1->fim = aux;
        lista1->fim->prox = lista1->inicio;
        lista1->inicio->ant = lista1->fim;
        lista2.fim->prox = lista2.inicio;
        lista2.inicio->ant = lista2.fim;
        lista2.qtd = lista1->qtd - metade;
        lista1->qtd = metade;
        return lista2; 
    }
    else if (lista1->qtd % 2 == 0) {
        int metade = (lista1->qtd / 2) + 1;
        int count = 0;
        ListNode* aux;
        for (aux = lista1->inicio; count <= metade; aux = aux->prox) {
            count++;
        }
        lista2.inicio = aux;
        lista2.fim = lista1->fim;
        lista1->fim = aux->ant;
        lista1->fim->prox = lista1->inicio;
        lista1->inicio->ant = lista1->fim;
        lista2.fim->prox = lista2.inicio;
        lista2.inicio->ant = lista2.fim;
        lista2.qtd = lista1->qtd - metade;
        lista1->qtd = metade;
        return lista2;
    }
    return lista2;
}

int comparar (LDEC lista1, LDEC lista2) {
    if (isEmpty(lista1) == 1 && isEmpty(lista2) == 1) {
        return 1;
    }
    if (lista1.qtd != lista2.qtd) {
        return 0;
    }

    ListNode* aux1 = lista1.inicio;
    ListNode* aux2 = lista2.inicio;

    do {
        if (aux1->info->num != aux2->info->num || strcmp(aux1->info->texto, aux2->info->texto) == 1 ) {
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    } while (aux1 != lista1.inicio);
    return 1;
}

int main() {
    LDEC lista1, lista2;
    inicializar(&lista1);
    inicializar(&lista2);

    printf("=======================================\n");
    printf("1. Adicionar valores na lista 1.\n");
    printf("2. Adicionar valores na lista 2.\n");
    printf("3. Listar valores das listas.\n");
    printf("4. Concatenar listas.\n");
    printf("5. Dividir listas.\n");
    printf("6. Comparar listas 1 e 2.\n");
    printf("7. Exit.\n");
    printf("=======================================\n");

    int escolha;
    int valor;
    char texto[100];

    while (1) {
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha) {

            case 1: 
                printf("Insira o valor a ser adicionado na lista 1: ");
                scanf("%d", &valor);
                getchar();
                printf("Insira o texto a ser adicionado na lista 1: ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0'; // acostumar a usar isso
                inserirFinal(&lista1, valor, texto);
                break;
            
            case 2:
                printf("Insira o valor a ser adicionado na lista 2: ");
                scanf("%d", &valor);
                getchar();
                printf("Insira o texto a ser adicionado na lista 2: ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0'; // acostumar a usar isso
                inserirFinal(&lista2, valor, texto);
                break;

            case 3:
                printf("Lista 1: ");
                listar(lista1);
                printf("Lista 2: ");
                listar(lista2);
                break;

            case 4:
                concatenar(&lista1, &lista2);
                break;

            case 5: {
                LDEC lista2 = dividir(&lista1);
                printf("Lista 1: ");
                listar(lista1);
                printf("Lista 2: ");
                listar(lista2);
                break;
            }
            
            case 6:
                if (comparar(lista1, lista2) == 1) {
                    printf("As duas listas sao iguais!\n");
                }
                else {
                    printf("As duas listas sao diferentes!\n");
                }
                break;

            case 7:
                printf("Saindo do programa...\n");
                return 0;
                break;

            default: 
                printf("Opcao invalida. Escolha outra!\n");
                break;    
        }
    }
    return 0;
}
