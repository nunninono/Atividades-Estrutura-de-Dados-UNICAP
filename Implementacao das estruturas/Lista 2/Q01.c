#include <stdio.h>
#include <stdio.h>

void somar(LSE lista1, LSE lista2, LSE* lista3) {
    if (isEmpty(lista1) == 1 && isEmpty(lista2) == 1) {  // As duas listas vazias
        printf("Listas vazias!! Insira valores\n");
        return;
    }
    else if (isEmpty(lista1) == 0 && isEmpty(lista2) == 1) {  // Apenas lista 2 vazia
        for (ListNode* aux1 = lista1.inicio; aux1 != NULL; aux1 = aux1->prox) {
            inserirFinal(lista3, aux1->info);
        }
        printf("Soma realizada!\n");
    }
    else if (isEmpty(lista1) == 1 && isEmpty(lista2) == 0) {  // Apenas lista 1 vazia
        for (ListNode* aux2 = lista2.inicio; aux2 != NULL; aux2 = aux2->prox) {
            inserirFinal(lista3, aux2->info);
        }
        printf("Soma ralizada!\n");
    }
    else {  // Lista1 e lista2 possuindo valores
        ListNode* aux1 = lista1.inicio;
        ListNode* aux2 = lista2.inicio;
        int soma = 0;
        while (aux1 != NULL && aux2 != NULL) {
            if (aux1 == NULL) {
                aux1->info = 0;
            }
            if (aux2 == NULL) {
                aux2->info = 0;
            }
            soma = aux1->info + aux2->info;
            inserirFinal(lista3, soma);
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        printf("Soma realizada!!\n");
    }
}

int isEmpty (LSE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;   // Está vazia
    }
    else {
        return 0;       // Não está vazia
    }
}

void inserirFinal (LSE* lista, int valor) {
    ListNode* novo;
    novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*lista) == 1) {        // Caso a lista esteja vazia
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {      // Caso a lista ja possua valores
        if (buscaSimples (*lista, valor) == 0) {   // Verifica se o valor ja esta na lista
            lista->fim->prox = novo;
            lista->fim = novo;
        }
        else {
            printf("O valor ja esta na lista!\n");
            return;
        }
    }
    lista->qtd++;
    printf("Valor foi inserido!\n");
}