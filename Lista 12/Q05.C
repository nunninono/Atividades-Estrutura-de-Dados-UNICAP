#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacoes {
    int RG;
    char nome[50];
    int idade;
    float peso;
    float altura;
} Informacoes;

typedef struct listNode {
    struct listNode* ant;
    Informacoes* info;
    struct listNode* prox;
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

Informacoes* criarInfo (int RG, char* nome, int idade, float peso, float altura) {
    Informacoes* novaInfo = (Informacoes*) malloc (sizeof(Informacoes));
    novaInfo->RG = RG;
    strcpy(novaInfo->nome, nome);
    novaInfo->idade = idade;
    novaInfo->peso = peso;
    novaInfo->altura = altura;
    return novaInfo;
}

ListNode* criarNo (Informacoes* novaInfo) {
    ListNode* novoNo = (ListNode*) malloc (sizeof(Informacoes));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = novaInfo;
    return novoNo;
}

void inserirFinal (LDEC* lista, int RG, char* nome, int idade, float peso, float altura) {
    Informacoes* novaInfo = criarInfo (RG, nome, idade, peso, altura);
    ListNode* novoNo = criarNo (novaInfo);

    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        lista->fim->prox = novoNo;
        novoNo->ant = lista->fim;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    lista->qtd++;
    printf("No inserido!!\n");
}

void inserirOrdenado (LDEC* lista, int RG, char* nome, int idade, float peso, float altura) {
    Informacoes* novaInfo = criarInfo(RG, nome, idade, peso, altura);
    ListNode* novoNo = criarNo(novaInfo);
    
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        lista->qtd++;
        return;
    }
    else if (lista->qtd == 1) {
        if (strcmp(novoNo->info->nome, lista->inicio->info->nome) < 0) {
            novoNo->prox = lista->inicio;
            lista->inicio->ant = novoNo;
            lista->inicio = novoNo;
            lista->fim->prox = lista->inicio;
            lista->inicio->ant = lista->fim;
        }
        else {
            novoNo->ant = lista->fim;
            lista->fim->prox = novoNo;
            lista->fim = novoNo;
            lista->fim->prox = lista->inicio;
            lista->inicio->ant = lista->fim;
        }
        lista->qtd++;
        return;
    }
    else if (strcmp(novoNo->info->nome, lista->inicio->info->nome) < 0) { // primeira menor
        novoNo->prox = lista->inicio;
        lista->inicio->ant = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        lista->qtd++;
        return;
    }
    else if (strcmp(novoNo->info->nome, lista->fim->info->nome) > 0) { // segunda menor
        novoNo->ant = lista->fim;
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        lista->qtd++;
        return;
    }
    else {
        ListNode* aux = lista->inicio->prox;
        do {
            if (strcmp(novoNo->info->nome, aux->info->nome) < 0) {
                novoNo->prox = aux;
                novoNo->ant = aux->ant;
                aux->ant->prox = novoNo;
                aux->ant = novoNo;
                lista->qtd++;
                return;
            }
            aux = aux->prox;
        } while (aux != lista->inicio);
    }
}

int busca (int RG, LDEC lista) {
    if (isEmpty(lista) == 1) {
        return 1;
    }
    ListNode* aux = lista.inicio;
    do {
        if (aux->info->RG == RG) {
            return 0;
        }
        aux = aux->prox;
    } while (aux != lista.inicio);
    return 1;
}

void listar (LDEC lista) {
        if (isEmpty(lista) == 1) {
        printf("============================\n");
        printf("vazia.\n");
        printf("============================\n\n");
    }
    else {
        int count = 1;
        ListNode* aux = lista.inicio;
        do {
            printf("============================\n");
            printf("Pessoa %d:\n", count);
            printf(" RG: %d\n", aux->info->RG);
            printf(" Nome: %s\n", aux->info->nome);
            printf(" Idade: %d\n", aux->info->idade);
            printf(" Peso: %.2f\n", aux->info->peso);
            printf(" Altura: %2.f\n", aux->info->altura);
            printf("============================\n\n");
            aux = aux->prox;
            count++;
        } while (aux != lista.inicio);
        printf("\n\n");
    }
}

LDEC copiaOrdenada (LDEC lista) {
    LDEC copia;
    inicializar(&copia);
    
    if (isEmpty(lista) == 1) {
        return copia;
    }
    else if (lista.qtd == 1) {
        inserirOrdenado(&copia, lista.fim->info->RG, lista.fim->info->nome, lista.fim->info->idade, lista.fim->info->peso, lista.fim->info->altura);
        return copia;
    }
    else {
        ListNode* aux = lista.inicio;
        do {
            if (busca(aux->info->RG, copia) == 1) {
                inserirOrdenado(&copia, aux->info->RG, aux->info->nome, aux->info->idade, aux->info->peso, aux->info->altura);
            }
            aux = aux->prox;
        } while (aux != lista.inicio);
        return copia;
    }
}

int main() {
    LDEC lista;
    inicializar(&lista);

    printf("=======================================\n");
    printf("1. Adicionar uma pessoa no registro.\n");
    printf("2. Listar pessoas registradas.\n");
    printf("3. Gerar lista ordenada.\n");
    printf("4. Exit.\n");
    printf("=======================================\n");

    int escolha;
    int count = lista.qtd + 1;
    int RG;
    char nome[50];
    int idade;
    float peso;
    float altura;

    while (1) {
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha) {

            case 1: 
                printf("Insira o RG da pessoa %d: ", count);
                scanf("%d", &RG);
                getchar();
                printf("Insira o nome da pessoa %d: ", count);
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Insira a idade da pessoa %d: ", count);
                scanf("%d", &idade);
                printf("Insira o peso da pessoa %d: ", count);
                scanf("%f", &peso);
                printf("Insira a altura da pessoa %d: ", count);
                scanf("%f", &altura);
                inserirFinal(&lista, RG, nome, idade, peso, altura);
                break;
            
            case 2:
                listar(lista);
                break;

            case 3: {
                LDEC copia = copiaOrdenada(lista);
                listar(copia);
                break;
            }

            case 4:
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
