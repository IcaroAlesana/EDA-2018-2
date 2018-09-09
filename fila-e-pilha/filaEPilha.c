#include <stdio.h>
#include<stdlib.h>
#include "filaEPilha.h"

struct Fila {
    int obj[MAX];
    int inicio;
    int fim;
    int qtd;
};

struct Pilha{
    int obj[MAX];
    int topo;
};

fila* inicializaFila (){
    fila *fi;
    fi = (fila*) malloc(sizeof(struct Fila));
    if(fi != NULL){
        fi->fim = 0;
        fi->inicio = 0;
        fi->qtd = 0;
    }
    return fi;
}

pilha* inicializaPilha(){
    pilha* pi = (pilha*) malloc(sizeof(struct Pilha));
    if (pi != NULL){
        pi->topo = 0;
    }
    return pi;
}


//-------------- Funções da pilha --------------

int pilha_vazia(pilha* pi){
    if (pi == NULL) return -1;
    return (pi->topo == 0);
}

int pilha_cheia(pilha* pi){
    if (pi == NULL) return -1;
    return (pi->topo == MAX);
}

int empilha(pilha* pi, int x){
    if (pi == NULL) return 0;
    if (pilha_cheia(pi)) return 0;

    pi->obj[pi->topo] = x;
    pi->topo++;
    return 1;
}

int desempilha(pilha* pi){
    if (pi == NULL) return 0;
    if (pilha_vazia(pi)) return 0;

    pi->topo--;
    return 1;
}

int consulta_pilha(pilha* pi, int* x){
    if (pi == NULL) return 0;
    if (pilha_vazia(pi)) return 0;

    *x = pi->obj[pi->topo-1];
    return 1;
}

int tamanho_pilha(pilha* pi){
    if(pi == NULL) return -1;

    return(pi->topo);
}

int libera_pilha(pilha* pi){
    if (pi == NULL) return 0;
    free(pi);

    return 1;
}

//------------- Funções da fila ----------------

int fila_vazia(fila* fi){
    if(fi == NULL) return 0;

    return(fi->qtd == 0);
}

int fila_cheia(fila* fi){
    if(fi == NULL) return 0;

    return (fi->qtd == MAX);
}

int insere_fila(fila* fi, int x){
    if(fi == NULL) return 0;
    if(fila_cheia(fi)) return 0;

    fi->obj[fi->fim] = x;
    fi->fim = ((fi->fim+1)%MAX);
    fi->qtd++;
    return 1;
}

int remove_fila(fila* fi){
    if(fi == NULL) return 0;
    if(fila_vazia(fi)) return 0;

    fi->inicio = ((fi->inicio+1)%MAX);
    fi->qtd--;
    return 1;
}

int tamanho_fila(fila* fi){
    if(fi == NULL)return -1;

    return fi->qtd;
}

int consulta_fila(fila* fi, int *x){
    if (fi == NULL) return 0;
    if (fila_vazia(fi)) return 0;

    *x = fi->obj[fi->inicio];
    return 1;
}
