#include <stdio.h>
#include "../ESTUDOS/Implementacao\zfila_de_inteiros.h"

int main() {
    Queue fila1;
    inicializar(&fila1);

    printf("=======================================\n");
    printf("1. Verificar se esta cheia.\n");
    printf("2. Verificar se esta vazia.\n");
    printf("3. Adicionar valor na fila.\n");
    printf("4. Retirar valor da fila.\n");
    printf("5. Visualizar o cabeça da fila.\n");
    printf("6. Exit.\n");
    printf("=======================================\n");

    int escolha;
    int valor;

    while (1) {
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha) {

            case 1: 
                if (isFull(fila1) == 1) {
                    printf("A pilha esta cheia (return 1)\n");
                }
                else {
                    printf("A pilha nao esta cheia (return 0)\n");
                }
                break;

            case 2: 
                if (isEmpty(fila1) == 1) {
                    printf("A fila esta vazia (return 1)\n");
                }
                else {
                    printf("A fila nao esta vazia (return 0)\n");
                }
                break;

            case 3: 
                printf("Qual valor voce quer inserir na fila? ");
                scanf("%d", &valor);
                enQueue (&fila1, valor);
                break;

            case 4: 
                printf("%d foi desalocado\n", deQueue(&fila1));
                break;

            case 5: 
                printf("%d é o valor na cabeca da fila\n",head(fila1));
                break;

            case 6: 
                printf("Saindo do programa..");
                return 0;
                break;
            
            default: 
                printf("Opcao invalida. Escolha outra!\n");
                break;    
        }
    }
    return 0;
}