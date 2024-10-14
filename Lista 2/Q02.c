#include <stdio.h>
#include <stdlib.h>

void copiar(LSE original, LSE* copia) {
    if (isEmpty(original) == 1) {
        printf("Lista vazia! Add valores\n");
        return;
    }
    else {
        for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
            inserirFinal(copia, aux->info);
        }
        printf("Copia realizada!\n");
    }
}

int isEmpty(LSE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1
    }
    else {
        return 0;
    }
}

void inserirFinal(LSE* lista, int valor) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}