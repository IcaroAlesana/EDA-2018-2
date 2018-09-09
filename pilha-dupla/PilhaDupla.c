#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"

struct PilhaDupla{
    struct livro li[MAX];
    int topo1, topo2;
};

pilha* inicializa(){
    PilhaDupla *pi;
    pi = (PilhaDupla*) malloc(sizeof(struct PilhaDupla));
    if (pi != NULL){
        pi->topo1 = 0;
        pi->topo2 = MAX-1;
    }
    return pi;
}

void libera_pilha(pilha* pi){
    free(pi);
}

int pilha1_vazia(pilha* pi){
    if(pi == NULL) return -1;
    return (pi->topo1 == 0);
}

int pilha2_vazia(pilha* pi){
    if (pi == NULL) return -1;
    return (pi->topo2 == MAX-1);
}

int pilhas_cheias(pilha* pi){
  if (pi == NULL) return -1;
  return (pi->topo1 == pi->topo2 + 1);
}

int empilha1(pilha* pi, struct livro li){
    if(pi == NULL) return 0;
    if (pilhas_cheias(pi)) return 0;

    pi->li[pi->topo1] = li;
    pi->topo1++;
    return 1;
}

int empilha2(pilha* pi, struct livro li){
    if(pi == NULL) return 0;
    if (pilhas_cheias(pi)) return 0;

    pi->li[pi->topo2] = li;
    pi->topo2--;
}

int desempilha1(pilha* pi){
    if (pi == NULL) return 0;
    if (pilha1_vazia(pi)) return 0;

    pi->topo1--;
}

int desempilha2(pilha* pi){
    if (pi == NULL) return 0;
    if (pilha2_vazia(pi)) return 0;

    pi->topo2++;
}
