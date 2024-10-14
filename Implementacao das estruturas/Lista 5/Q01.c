#include <stdio.h>
#include <stdlib.h>
#include "..\ESTUDOS\Implementacao\zpilha_de_malloc.h"

int main(){
    Stack pilha1;
    inicialize(&pilha1);

    int num;
    int cont = 0;

    while (cont < 10) {
        printf("Insira um numero maior que zero: ");
        scanf("%d", &num);
        if (num < 0) {
            printf("Insira outro numero!\n");
        }
        else {
            push(&pilha1, num);
            cont++;
        }
    }

    while (isEmpty(pilha1) == 0){
        int valor = pop(&pilha1);
        printf("%d\n", valor);
    }

    return 0;
}    