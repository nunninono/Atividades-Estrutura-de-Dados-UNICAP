#include <stdio.h>
#define TAM 10
// #include "..\NomeDaPasta\NomeDoArquivo.h"    // caso a definição da pilha esteja em outra folder
                                                // muda o nome do arquivo pra .h
                                                // ../ sobe um nível no explorador de arquivos
                                                
typedef struct stack {
    int dados [TAM];
    int topo;
} Stack;


void inicialize (Stack* s) {    // s aponta apara o struct
    s->topo = -1;   // notação de ponteiro (s->topo) ou ((*s).topo))
}

int isEmpty (Stack s){  // s é o proprio struct, variavel diferente do Stack* s
    if (s.topo == -1){  // notação de struct (s.topo)
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (Stack s){
    if (s.topo == TAM-1){  // verifica se a pilha esta cheia
        return 1;
    }    
    else {
        return 0;
    }
}

void push (Stack* s, int valor){   // adicionar valor na pilha
    s->topo = s->topo + 1;         // adiciona 1 no valor do topo, pois ela inicia com -1
    s->dados[s->topo] = valor;     // dados[0] = valor
}

int pop (Stack* s){    // retira o elemento do topo da pilha e o retorna
    int retorno = s->dados[s->topo];   // guarda o valor atual do topo na variavel retorno
    s->topo = s->topo - 1;    // retira 1 do valor do topo (o que esta acima vira lixo de memoria)
    return retorno;
}

int top (Stack s){   // visualiza o valor do topo da pilha
    return s.dados[s.topo];   
}

