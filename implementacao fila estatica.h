#define TAM 10

// SEMPRE QUE FOR ALTERAR ALGO NA STRUCT USA O (QUEUE* F) NA FUNÇÃO
// SE NAO FOR ALTERAR USA-SE (QUEUE F)

typedef struct queue {  // Definição da estrutura da fila
    int dados[TAM];     // Vetor que armazena os elementos da fila.
    int inicio, fim;    // 'inicio' é o índice do primeiro elemento, 'fim' é o índice do último elemento.
} Queue;

void inicializar (Queue* fila) {    // Função para inicializar a fila
    fila->inicio = 0;       // O índice de 'inicio' começa em 0.
    fila->fim = -1;     // 'fim' começa em -1 porque indica que a fila está inicialmente vazia.
}

int isEmpty (Queue fila) {      // Função que verifica se a fila está vazia
    if (fila.inicio > fila.fim){    // A fila está vazia se o índice de 'inicio' for maior que 'fim'.
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (Queue fila) {   // Função que verifica se a fila está cheia
    if (fila.fim == TAM-1) {    // A fila está cheia se o índice 'fim' for igual a TAM-1 (última posição).
        return 1;
    }    
    else {
        return 0;
    }
}

void enQueue (Queue *fila, int valor) {     // Função para inserir um valor na fila 
    fila->fim++;     // Aponta para a próxima posição disponível.
    fila->dados[fila->fim] = valor;     // Armazena o valor na posição indicada por 'fim'.
}

int deQueue (Queue* fila) {     // Função para remover um valor da fila 
    int retorno = fila->dados[fila->inicio];    // Guarda o valor na posição 'inicio'  
            // (FOR) Move toda fila pra esquerda (preencher o "espaço" deixado pelo elemento removido)
    for (int i = fila->inicio; i <= fila->fim-1; i++) {     
        fila->dados[i] = fila->dados[i+1];
    }
    fila->fim--;    // Retira um dp incide 'fim'
    return retorno;     // Retorna o valor que estava no elemento removido
}

int head (Queue fila){  // Função para acessar o primeiro elemento da fila sem removê-lo (head da fila)
    return fila.dados[fila.inicio];     // Retorna o valor do elemento 'cabeça' da fila
}