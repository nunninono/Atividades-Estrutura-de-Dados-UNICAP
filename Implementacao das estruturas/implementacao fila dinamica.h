#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {  // Define um elemento da fila (num nó)
    int info;                 // Valor alocado no nó
    struct queueNode* prox;     // Aponta pro proximo elemento da fila
} QueueNode;

typedef struct queue {     // Cria os ponteiros pra guardar o endereço inicial e final
    QueueNode* inicio;    // Guarda o endereço do inicio da fila (Primeiro nó alocado)
    QueueNode* fim;    // Guarda o endereço do fim da fila (Ultimo nó alocado)
    // QueueNode* qtd (para pilas que possuem restrição de tamanho)
} Queue;


void inicializar (Queue* fila) {  // inicializa uma fila 
    fila->inicio = NULL;    // Inicia o endereço inicial como NULL
    fila->fim = NULL;    // Inicia o endereço final como NULL 
    // fila->qtd = 0; (Inicializa a pilha com a quantida = 0)
}

int isEmpty (Queue fila) {  // Verifica se a fila ta vazia
    if (fila.inicio == NULL && fila.fim == NULL) {  // Verificação
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (Queue fila) { // Verifica se a fila está cheia
    return 0;   // Retorna sempre 0, pois a fila aloca dinamicamente
}

void enQueue (Queue* fila, int valor){   // Adiciona um novo nó na fila 
    QueueNode* novo;    // Cria um novo nó para a fila
    novo = (QueueNode*) malloc (sizeof(QueueNode));     // Aloca dinamicdamente
    novo->info = valor;
    novo->prox = NULL;
    // Faz uma verificação, pois se a fila estiver vazia aloca-se de forma diferente
    if (isEmpty(*fila) == 1) {  // Caso esteja vazia
        fila->inicio = novo; // Faz com que o inicio (antes NULL) aponte para o novo nó
        fila->fim = novo; // Faz com que o fim (antes NULL) aponte para o novo nó
    }
    else {  // Caso a pilha ja possua valores
        fila->fim->prox = novo;  // Faz com que o prox do ultimo nó alocado aponte para o novo nó
        fila->fim = novo;  // Faz com que o fim aponte pra o novo nó
    }
    // qtd++; (Caso exista limite de tamanho na fila)
    printf("Inserção efetuada!\n");
}
    
int deQueue (Queue* fila) {  // Retira o primeiro nó da fila
    QueueNode* aux;   // Cria um nó para guardar o endereço do primeiro valor da fila (depois receberá free(aux))
    int retorno;  // Cria variável para receber o valor fila->inicio->info (valor do primeiro nó)
    if (fila->inicio == NULL) {  // Caso voce esteja desalocando o único elemento da fila
        fila->fim = NULL;  // Faz que fila->fim receba NULL (para nao apontar para uma variavel desalocada)
    }
    aux = fila->inicio;   // Aux recebe o endereço do primeiro valor 
    fila->inicio = aux->prox;  // Inicio agora aponta para o segundo termo da fila, pois pegou quem prox aponta 
    // Ou fila->inicio = fila->inicio->prox
    retorno = aux->info; // Recebe o valor que estava alocado no primeiro nó da fila
    free(aux); // Desaloca quem aux está apontando (O primeiro nó da fila)
    return retorno;  // Retorna o valor que estava no nó desalocado   
}
    
int head (Queue fila) {  // Ver o inicio da fila
    return fila.inicio->info;  // Retorna o elemento que está no primeiro nó da fila
}