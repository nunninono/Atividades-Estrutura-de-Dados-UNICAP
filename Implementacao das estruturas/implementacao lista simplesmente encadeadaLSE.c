#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {  // Define o que tem dentro do nó
    int info;
    struct listNode* prox;
} ListNode;

typedef struct lse { // Cria os DESCRITORES inicio, fim e qtd
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LSE;

void inicializar (LSE* lista1) {    // Inicia os DESCRITORES da lista
    lista1->inicio = NULL;
    lista1->fim = NULL;
    lista1->qtd = 0;
}

int isEmpty (LSE lista1) {
    if (lista1.inicio == NULL && lista1.fim == NULL) {
        return 1;   // Está vazia
    }
    else {
        return 0;       // Não está vazia
    }
}

int buscaSimples (LSE lista1, int valor) {  // Busca sequencial simples
    if (isEmpty(lista1) == 1){  
        return 0;
    }
    else {  // Percorre toda a lista em busca do valor
        for (ListNode* aux = lista1.inicio; aux != NULL; aux = aux->prox) {
            if (aux->info == valor) {
                return 1;   // Achou
            }
        }
        return 0;   // Nao achou
    }
}

void inserirFinal (LSE* lista1, int valor) {
    ListNode* novo;
    novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*lista1) == 1) {        // Caso a lista esteja vazia
        lista1->inicio = novo;
        lista1->fim = novo;
    }
    else {      // Caso a lista ja possua valores
        if (buscaSimples (*lista1, valor) == 0) {   // Verifica se o valor ja esta na lista
            lista1->fim->prox = novo;
            lista1->fim = novo;
        }
        else {
            printf("O valor ja esta na lista!\n");
            return;
        }
    }
    lista1->qtd++;
    printf("Valor foi inserido!\n");
}

void inserirInicio (LSE* lista1, int valor) {
    ListNode* novo;
    novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    if (isEmpty(*lista1) == 1) {    // Caso a lsita esteja vazia
        lista1->inicio = novo;
        lista1->fim = novo;
        novo->prox = NULL;  
    }
    else {      // Caso a lista ja possua valores
        if (buscaSimples(*lista1, valor) == 0) {    // Verifica se o valor ja esta na lista
            novo->prox = lista1->inicio;
            lista1->inicio = novo;
        }
        else {
            printf("O valor ja esta na lista!\n");
            return;
        }
    }
    lista1->qtd++;
    printf("Valor inserido!!\n");
}

void removerInicio (LSE* lista1) {
    ListNode* aux;
    aux = lista1->inicio;
    if (lista1->inicio->prox == NULL) {     // Caso so tenha um elemento
        free(aux);
        lista1->inicio = NULL;
        lista1->fim = NULL;
    }
    else {      // Mais de um elemento
        lista1->inicio = lista1->inicio->prox;
        free(aux);
    }
    lista1->qtd--;
}

void removerFinal (LSE* lista1) {
    if (isEmpty(*lista1) == 1) {
        printf("Sua lista esta vazia! Insira algum valor\n");
        return;   
    }
    if (lista1->inicio->prox == NULL){
        free(lista1->inicio);
        lista1->fim = NULL;
        lista1->inicio = NULL;
    }
    else {
        ListNode* aux = lista1->inicio;
        while (aux->prox != lista1->fim) {
            aux = aux->prox;
        }
        lista1->fim = aux;
        free(aux->prox);
        aux->prox = NULL; 
    }
    lista1->qtd--;
    printf("Valor removido com sucesso!!\n");
}

void listar (LSE lista1) {
    if (isEmpty(lista1) == 1){
        printf("A lista esta vazia!!\n");
    }
    else {
        printf("\nValores listados: \n");
        for (ListNode* aux = lista1.inicio; aux != NULL; aux = aux->prox) {
            printf("%d\n", aux->info);
        }
    }
}

void remover (LSE* lista1, int valor) {
    if (isEmpty(*lista1) == 1) {
        printf("A lista esta vazia!!\n");
    }
    else if (lista1->inicio == lista1->fim) {    // Caso tenha apenas num nó
        if (lista1->inicio->info == valor) {
            free(lista1->inicio);
            lista1->inicio = NULL;
            lista1->fim = NULL;
            printf("Remocao efetuada!\n");
            lista1->qtd--;

        }
        else{
            printf("Valor nao encontrado!!\n");
        }
    }
    else {      // Caso possua mais de um nó
        ListNode* aux = lista1->inicio;
        ListNode* aux2 = aux->prox;
        if (lista1->inicio->info == valor) {
            lista1->inicio = aux->prox;
            free(aux);
            printf("Remocao efetuada!\n");
            lista1->qtd--;
        }
        else {
            while(aux2 != NULL) {
                if (aux2->info == valor) {
                    aux->prox = aux2->prox;
                    if (aux2 == lista1->fim) {
                        lista1->fim = aux;
                    }
                    free(aux2);
                    printf("Remocao efetuada!\n");
                    lista1->qtd--;
                    return;
                }
                else {
                    aux = aux2;
                    aux2 = aux2->prox;
                }
            }
            printf("Valor nao encontrado!\n");
        }
    }
    
}

void copiar (LSE lista1, LSE* copia) {
    if (isEmpty(lista1) == 1) {
        printf("A lista original esta vazia!! adicione valores a ela primeiro\n");
        return;
    }
    else {
        for (ListNode* aux = lista1.inicio; aux != NULL; aux = aux->prox) {
            inserirFinal(copia, aux->info);
        }
        printf("Copia criada com sucesso!!\n");
    }
}

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
    listar(*lista3);
}

int main() {
    LSE lista1;
    LSE lista2;
    LSE lista3;
    LSE copia;
    inicializar(&lista1);
    inicializar(&lista2);
    inicializar(&lista3);
    inicializar(&copia);

    printf("=======================================\n");
    printf("1. Verificar se a lista esta vazia.\n");
    printf("2. Inserir valor no final.\n");
    printf("3. Inserir valor no inicio.\n");
    printf("4. Retirar valor do inicio\n");
    printf("5. Retirar valor do final.\n");
    printf("6. Exibir todos os valores da lista.\n");
    printf("7. Remover valor especifico da lista.\n");
    printf("8. Criar uma copia da lista.\n");
    printf("9. Some os valores para outra lista.\n");
    printf("10. Exit.\n");
    printf("=======================================\n");

    int escolha;
    int valor;

    while (1) {
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha) {

            case 1: 
                if (isEmpty(lista1) == 1) {
                    printf("A lista esta vazia (return 1)\n");
                }
                else {
                    printf("A lista nao esta vazia (return 0)\n");
                }
                break;

            case 2: 
                printf("Insira o valor a ser inserido no final da lista 1: ");
                scanf("%d", &valor);
                inserirFinal(&lista1, valor);
                break;

            case 3: 
                printf("Insira o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inserirInicio(&lista1, valor);
                break;

            case 4: 
                removerInicio(&lista1);
                printf("Valor removido com sucesso!!\n");
                break;

            case 5: 
                removerFinal(&lista1);
                break;

            case 6: 
                listar(lista1);
                break;
            
            case 7:
                printf("Qual o valor a ser removido: ");
                scanf("%d", &valor);
                remover(&lista1, valor);
                break;
            
            case 8:
                copiar(lista1, &copia);
                listar(copia);
                break;
            
            case 9:
                somar(lista1, lista2, &lista3);
                break;

            case 10:
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
