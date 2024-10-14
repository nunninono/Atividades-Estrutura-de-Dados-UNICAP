#include <stdlib.h>
#include <stdio.h>

typedef struct stackNode {      // Definição da estrutura do nó da pilha
    int info;          // Armazena o valor inteiro no nó.
    struct stackNode* prox;     // Ponteiro para o próximo nó (nó abaixo na pilha)
} StackNode;

// Definindo a pilha como um ponteiro para o tipo StackNode.
// Define a pilha como um nó
typedef StackNode* Stack; 

void inicialize (Stack* pilha) {
    *pilha = NULL;
}

int isEmpty (Stack pilha) {
    if (pilha == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (Stack pilha) {
    return 0;
}

void push (Stack* pilha, int valor) {
    StackNode* novo;
    novo = (StackNode*) malloc (sizeof(StackNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*pilha) == 1) {
        *pilha = novo;
    }
    else {
        novo->prox = *pilha;
        *pilha = novo;
    }
}

int pop (Stack* pilha) {
    StackNode* aux = *pilha;
    int valor;
    *pilha = (*pilha)->prox;
    valor = aux->info;
    free(aux);
    return valor;
}

int top (Stack pilha) {
    return pilha->info;
}
