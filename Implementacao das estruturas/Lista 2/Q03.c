#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Estrutura de Dados\Atividade 2\Q03.h"

int main() {    
    LSE lista1;
    inicializar(&lista1);

    printf("==========================================\n");
    printf("a) Cadastrar uma nova pessoa.\n");
    printf("b) Cancelar registro imediato.\n");
    printf("c) Exibir todos presentes no predio.\n");
    printf("d) Verificar se alguem especifico esta no predio.\n");
    printf("e) Informar quantas pessoas estao no predio.\n");
    printf("f) remover alguem especifico.\n");
    printf("==========================================\n\n");

    char escolha;

    while (1) {
        printf("Escolha uma das opções: ");
        scanf(' %c', &escolha);

        switch (escolha){
            case 'a':  
                char nome[50];
                int registro;
                printf("Insira o nome da pessoa: ");
                scanf("%s", nome);
                printf("Insira o RG da pessoa: ");
                scanf("%d", registro);
                registrar(&lista1, nome, registro);
                break;

            case 'b':
                cancelar(&lista1);
                break;

            case 'c':
                exibir(lista1);
                break;
            
            case 'd':
                int registro;
                printf("Insira o registro a ser buscado: ");
                scanf("%d", registro);
                verificar(lista1, registro);
                
            case 'e':
                informar(lista1);
                break;

            case 'f':
                remover(&lista1, registro);
                break;
            

        }
    }
}
