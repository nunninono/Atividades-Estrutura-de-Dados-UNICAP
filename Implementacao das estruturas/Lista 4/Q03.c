#include <stdio.h>
#include "..\ESTUDOS\Implementacao\zpilha_de_inteiros.h"

int main() {
    Stack pilha1;
    inicialize(&pilha1);

    char palavra[50];
    int tamanho = 0;
    int saida;
    
    printf("Insira uma palavra: ");
    scanf("%s", palavra);
    
    while (palavra[tamanho] != '\0') {
        tamanho++;
    }

    if (isFull(pilha1) == 0) {
        for (int i = 0; i < tamanho; i++){
            push(&pilha1, palavra[i]);
        }
    }
    else {
        return printf("A pilha esta cheia!!");
    }

    for (int i = 0; i < tamanho; i++) {
        saida = pop(&pilha1);
        if (saida != palavra[i]) {
            return printf("A palavra nao e um palindromo");
        }
    }
    printf("A palavra e um palindromo :)");

    return 0;
}