#include <stdio.h>
#include <stdlib.h>

typedef struct ldecNode {
    struct ldecNode* ant;
    int info;
    struct ldecNode* prox;
} LDECNode;

typedef struct ldec {
    LDECNode* inicio;
    LDECNode* fim;
    int qtd;
} LDEC;

void inicializar (LDEC* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
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

LDECNode* criarNo (int valor) {
    LDECNode* novoNo = (LDECNode*) malloc (sizeof(LDECNode));
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    novoNo->info = valor;
    return novoNo;
}

void inserirInicio (LDEC* lista, int valor) {
    LDECNode* novoNo = criarNo(valor);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        novoNo->prox = lista->inicio;
        lista->inicio->ant = novoNo;
        lista->inicio = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    lista->qtd++;
    printf("Valor inserido!!\n");
}

void inserirFinal (LDEC* lista, int valor) {
    LDECNode* novoNo = criarNo (valor);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    else {
        a->fim->prox = novoNo;
        novoNo->ant = lista->fim;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    lista->qtd++;
    printf("Valor inserido!!\n");
}

LDEC* dividir (LDEC* lista) {
    LDEC listaAux;
    inicializar (&listaAux);
    if (isEmpty(*lista) == 1) {
        return listaAux;
    }
    else {
        int quantidade = lista->qtd / 2;
        contador = 0;
        if (lista->incio == lista->fim) {
            return listaAux;
        }
        else if ((lista->qtd)%2 == 1) {
            quantidade++;
            for (LDECNode* aux = lista->inicio; contador < quantidade; aux = aux->prox);
            listaAux->inicio = aux;
            listaAux->fim = lista->fim;
            lista->fim = aux;
            lista->fim->prox = lista->inicio;
            lista->inicio->ant = lista->fim;
            listaAux->fim->prox = listaAux->inicio;
            lista->qtd = quantidade;
            quantidade--;
            listaAux->qtd = quantidade;
        }
        else if ((lista->qtd)%2 == 0){
            for (LDECNode* aux = lista->inicio; contador < quantidade; aux = aux->prox);
            listaAux->inicio = aux;
            listaAux->fim = lista->fim;
            lista->fim = aux;
            lista->fim->prox = lista->inicio;
            lista->inicio->ant = lista->fim;
            listaAux->fim->prox = listaAux->inicio;
            listaAux->inicio->ant = listaAux->fim;
            lista->qtd = quantidade;
            listaAux->qtd = quantidade;
        }
        return listaAux;
    }
}

void listar (LDE lista) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    LDECNode* aux = lista->inicio;
    printf("Valores listados: ");
    do {
        printf("%d ", aux->info);
        aux = aux->prox;
    } while (aux != lista->inicio);
}

void retirarTudo (LDE* lista) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
    }
    else {
        // IMPLEMENTAR
        do {
            
        } while (lista->qtd > 1);
    }
}

int main () {
    LDEC lista1;
    inicializar (&lista1);
    
    printf("==================================\n");
    printf("1. Inserir valor no inicio.\n");
    printf("2. Inserir valor no final.\n");
    printf("3. Dividir as listas.\n");
    printf("4. Listar\n");
    printf("==================================\n\n");
    int escolha;
    
    while(1) {
        switch (escolha) {
            case 1:
                int valor;
                printf("Escolha o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inserirInicio(&lista1, valor);
                break;
            
            case 2:
                int valor;
                printf("Escolha o valor a ser inserido no final: ");
                scanf("%d", &valor);
                inserirInicio(&lista1, valor);
                break;
            
            case 3:
                LDEC* lista2 = dividir(&lista1);
                break;
            
            case 4:
                printf("Lista 1:\n");
                listar(lista1);
                printf("Lista2:\n");
                listar(lista2);
                break;
            
            case 5:
                printf("Saindo do programa...");
                return 0;
                break;
            
            dafault:
                printf("Insira uma opcao valida!!\n");
                break;
        }
    }
    
    
    return 0;
}




