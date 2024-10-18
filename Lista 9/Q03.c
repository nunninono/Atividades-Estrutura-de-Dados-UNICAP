// CODIGO NAO ESTA TOTALMENTE MODULARIZADO (falta dunção buscar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode {
    char descricao[50];
    int prioridade;
    struct listNode* prox;
    struct listNode* ant;
} ListNode;

typedef struct lde {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LDE;

void inicializar (LDE* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty (LDE lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void inserirTarefa (LDE* lista, int valor, char* descricao) {
    ListNode* novo = (ListNode*) malloc (sizeof(ListNode*));
    novo->prioridade = valor;
    strcpy(novo->descricao, descricao);
    novo->ant = NULL;
    novo->prox = NULL;

    if (isEmpty(*lista) == 1) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
        return;
    }

    for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
        if (strcmp(novo->descricao, aux->descricao) == 0) { // 2 descrições iguais
            printf("Ja existe uma tarefa com essa mesma descricao!!\n");
            free(novo);
            return;
        }
    }

    if (novo->prioridade > lista->inicio->prioridade) {    // inseir inicio
        lista->inicio->ant = novo;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
        return;
    }
    else if (novo->prioridade <= lista->fim->prioridade) {   // inserir fim
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;        
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
        return;
    }
    else {
        ListNode* aux = lista->inicio;
        while (aux != NULL && aux->prioridade >= novo->prioridade) {    // vai par ao nó onde deve ser adicionado
            aux = aux->prox;
        }
        // Insere o nó entre 'aux->ant' e 'aux' (antes do aux)
        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
        lista->qtd++;
        printf("Tarefa adicionada!!\n");
    }
}

void buscaDescricao (LDE lista, char* descricao) {
    int count = 0;
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        if (strcmp(aux->descricao, descricao) == 0) {
            printf("Existem um total de %d tarefas a serem executadas antes da tarefa requerida.\n", count);
        }
        count++;
    }
    printf("A tarefa com a descricao digitada nao existe!!\n");
}

ListNode* executarTarefa (LDE* lista) {  // NÃO SEI COMO DAR O FREE(AUX) DEPOIS (pq tem return antes)
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return NULL;
    }
    else if (lista->fim == lista->inicio) {
        ListNode* aux = lista->inicio;
        lista->inicio = NULL;
        lista->fim = NULL;
        return aux;
    }
    else {
        ListNode* aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->inicio->ant = NULL;
        return aux;
    }
}

void cancelarTarefa (LDE* lista, char* descricao) {
    if (isEmpty(*lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
        if (strcmp(aux->descricao, descricao) == 0) {
            if (lista->inicio == lista->fim) {
                free(aux);   // ou free(lista->inicio) ou free(lista->fim)
                lista->inicio = NULL;
                lista->fim = NULL;
            }
            else if (strcmp(lista->fim->descricao, descricao) == 0) {  // ou if (aux == lista->fim)
                lista->fim = lista->fim->ant;
                free(lista->fim->prox);  // ou free(aux)
                lista->fim->prox = NULL;
            }
            else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
            }
            lista->qtd--;
            printf("Tarefa cancelada!!\n");
        }
    }
    printf("Descricao nao bate com as descricoes cadastradas!!\n");
}

void exibirDescricoes (LDE lista, int valor) {
    if (isEmpty(lista) == 1) {
        printf("A lista esta vazia!!\n");
        return;
    }
    printf("Descricao das tarefas da prioridade %d:\n\n", valor);
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        if (aux->prioridade == valor) {
            printf("- %s\n", aux->descricao);
        }
        else if (aux->prioridade < valor) {
            break;
        }
    }
    printf("Nenhuma tarefa encontrada nessa prioridade!!\n");
}

void listarTarefas (LDE lista) {
    if (isEmpty(lista) == 1) {
        printf("Lista vazia!!\n");
    }
    for (ListNode* aux = lista.inicio; aux != NULL; aux = aux->prox) {
        printf("prioridade(%d): %s\n", aux->prioridade, aux->descricao);
    }
    printf("\n");
}

void mudarPrioridade (LDE* lista, char* descricao, int novaPrioridade) {
    if (isEmpty(*lista) == 1) {
        printf("Lista vazia!!\n");
    }
    cancelarTarefa(lista, descricao);
    inserirTarefa(lista, novaPrioridade, descricao);
    /*for (ListNode* aux = lista->inicio; aux != NULL; aux = aux->prox) {
        if (strcmp(aux->descricao, descricao) == 0) {
            if (lista->inicio == lista->fim) {
                free(aux);
                lista->inicio = NULL;
                lista->fim = NULL;
                inserirTarefa(&lista, novaPrioridade, &descricao);
            }
            else if (aux == lista->fim) {
                lista->fim = lista->fim->ant;
                free(lista->fim->prox);
                lista->fim = NULL;
                inserirTarefa(&lista, novaPrioridade, &descricao);
            }
            else {

            }
        }
    }*/
}

int main() {
    LDE lista1;
    inicializar(&lista1);

    int escolha, num;
    char texto[50];
    ListNode* tarefa;

    while(1) {
        printf("=========================================\n");
        printf("1. Inserir nova tarefa.\n");
        printf("2. Buscar tarefa pela descricao.\n");
        printf("3. Executar tarefa.\n");
        printf("4. Cancelar execucao especifica.\n");
        printf("5. Exibir descricoes de uma prioridade.\n");
        printf("6. Listar todas as tarefas.\n");
        printf("7. Mudar prioridade.\n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Insira a prioridade da nova tarefa (ente 1 e 10): ");
                scanf("%d", &num);
                if (num < 1 || num > 10) {
                    printf("\nInisra uma prioridade valida!!\n");
                    break;
                }
                printf("Insira uma descricao para a tarefa: ");
                scanf("%s", texto);
                inserirTarefa(&lista1, num, texto);
                break;
            
            case 2:
                printf("Insira a descricao a ser buscada: ");
                scanf("%s", texto);
                buscaDescricao(lista1, texto);
                break;

            case 3:
                tarefa = executarTarefa(&lista1);
                if (tarefa == NULL) {
                    printf("A lista esta vazia!!\n");
                    break;
                }
                printf ("A tarefa de prioridade %d e descricao ""%d"" foi executada!\n", tarefa->prioridade, tarefa->descricao);
                break;
            
            case 4:
                printf("Insira a descricao da tarefa a ser cancelada: ");
                scanf("%s", texto);
                cancelarTarefa(&lista1, texto);
                break;
            
            case 5:
                printf("Insira o numero da prioridade: ");
                scanf("%d", &num);
                exibirDescricoes(lista1, num);
                break;

            case 6:
                listarTarefas(lista1);
                break;

            case 7:
                printf("Insira a descricao da tarefa: ");
                scanf("%s", texto);              
                printf("Insira a prioridade da tarefa: ");
                scanf("%d", &num);
                mudarPrioridade(&lista1, texto, num);
                break;

            default:
                break;
        }
    }
}
