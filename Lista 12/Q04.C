#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacoes {
    char nome[50];
    int matricula;
    float media;
    int quantidadeFaltas;
} Informacoes;

typedef struct listNode {
    struct listNode* ant;
    Informacoes* info;
    struct listNode* prox;
} ListNode;

typedef struct ldec {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LDEC;

void inicializar (LDEC* lista) {
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->qtd = 0;
}

int isEmpty (LDEC lista) {
    if (lista.inicio == NULL && lista.fim == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Informacoes* criarInfo (char* nome, int matricula, float media, int quantidadeFaltas) {
    Informacoes* novaInfo = (Informacoes*) malloc (sizeof(Informacoes));
    strcpy(novaInfo->nome, nome);
    novaInfo->matricula = matricula;
    novaInfo->media = media;
    novaInfo->quantidadeFaltas = quantidadeFaltas;
    return novaInfo;
}

ListNode* criarNo (Informacoes* novaInfo) {
    ListNode* novoNo = (ListNode*) malloc (sizeof(ListNode));
    novoNo->info = novaInfo;
    return novoNo;
}

void inserirFinal (LDEC* lista, char* nome, int matricula, float media, int quantidadeFaltas) {
    Informacoes* novaInfo = criarInfo(nome, matricula, media, quantidadeFaltas);
    ListNode* novoNo = criarNo(novaInfo);
    if (isEmpty(*lista) == 1) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->inicio->ant = lista->fim;
        lista->fim->prox = lista->inicio;
    }
    else {
        lista->fim->prox = novoNo;
        novoNo->ant = lista->fim;
        lista->fim = novoNo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
    }
    lista->qtd++;
    printf("No inserido!!\n");
}

void listar (LDEC lista) {
        if (isEmpty(lista) == 1) {
        printf("============================\n");
        printf("vazia.\n");
        printf("============================\n\n");
    }
    else {
        int count = 1;
        ListNode* aux = lista.inicio;
        do {
            printf("============================\n");
            printf("Aluno %d:\n", count);
            printf(" Nome: %s\n",aux->info->nome);
            printf(" Matricula: %d\n", aux->info->matricula);
            printf(" Media: %.2f\n", aux->info->media);
            printf(" Quantidade de faltas: %d\n", aux->info->quantidadeFaltas);
            printf("============================\n\n");
            aux = aux->prox;
            count++;
        } while (aux != lista.inicio);
        printf("\n\n");
    }
}

void classificar(LDEC turma, LDEC* aprovados, LDEC* reporvadosFalta, LDEC* reprovadosMedia) {
    if (isEmpty(turma) == 1) {
        printf("A turma esta vazia!\n\n");
        return;
    }
    ListNode* aux = turma.inicio;
    do {
        if (aux->info->media < 7 && aux->info->quantidadeFaltas <= 18) {    // reprovado por media
            inserirFinal(reprovadosMedia, aux->info->nome, aux->info->matricula, aux->info->media, aux->info->quantidadeFaltas);
        }
        else if (aux->info->quantidadeFaltas > 18) {    // reprovado por falta
            inserirFinal(reporvadosFalta, aux->info->nome, aux->info->matricula, aux->info->media, aux->info->quantidadeFaltas);
        }
        else if (aux->info->media >= 7) {   // aprovado por media
            inserirFinal(aprovados, aux->info->nome, aux->info->matricula, aux->info->media, aux->info->quantidadeFaltas);
        }
        aux = aux->prox;
    } while (aux != turma.inicio);
}

int main() {
    LDEC turma, reprovadosMedia, aprovados, reporvadosFalta;
    inicializar(&turma);
    inicializar(&reprovadosMedia);
    inicializar(&aprovados);
    inicializar(&reporvadosFalta);

    printf("=======================================\n");
    printf("1. Adicionar aluno na turma.\n");
    printf("2. Listar alunos da turma.\n");
    printf("3. Classificar alunos.\n");
    printf("4. Exit.\n");
    printf("=======================================\n");

    int escolha;
    int cont = turma.qtd + 1;
    char nome[50];
    int matricula;
    float media;
    int quantidadeFaltas;

    while (1) {
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha) {

            case 1: 
                printf("Qual o nome do aluno %d: ", cont);
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // acostumar a usar isso
                printf("Qual a matricula do aluno %d: ", cont);
                scanf("%d", &matricula);
                printf("Qual a media final do aluno %d: ", cont);
                scanf("%f", &media);
                printf("Qual a quantidade de faltas do aluno %d: ", cont);
                scanf("%d", &quantidadeFaltas);
                inserirFinal(&turma, nome, matricula, media, quantidadeFaltas);
                break;
            
            case 2:
                printf("Alunos na turma:\n");
                listar(turma);
                break;

            case 3:
                classificar(turma, &aprovados, &reporvadosFalta, &reprovadosMedia);
                printf("Aprovados:\n");
                listar(aprovados);
                printf("Reprovados por falta:\n");
                listar(reporvadosFalta);
                printf("Reprovados por media:\n");
                listar(reprovadosMedia);
                break;

            case 4:
                printf("Saindo do programa...\n");
                return 0;
                break;

            default: 
                printf("Opcao invalida. Escolha outra!\n");
                break;    
        }
    }
    return 0;
}
