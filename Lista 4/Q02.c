#include <stdio.h>
#include "..\ESTUDOS\Implementacao\zpilha_de_inteiros.h"

int main(){
    Stack pilha1;
    inicialize(&pilha1);

    int num;

    printf("Informe um nuemro inteiro: ");
    scanf("%d", &num);

    while (num > 0) {
        if (isFull(pilha1) == 0) {
            push(&pilha1, num%2);
        }
        else {
            printf("A pilha esta cheia!");
            return 0;
        }
        num = num/2;
    }

    while (isEmpty(pilha1) == 0) {
        printf("%d\n",pop(&pilha1));
    }

}