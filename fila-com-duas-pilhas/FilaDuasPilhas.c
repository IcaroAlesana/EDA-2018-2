#include <stdio.h>
#include<stdlib.h>
#include "FilaDuasPilhas.h"

struct Pilha{
    int obj[MAX];
    int topo;
};

struct Fila {
    pilha* in;
    pilha* out;
};

pilha* inicializaPilha(){
    pilha* pi = (pilha*) malloc(sizeof(struct Pilha));
    if (pi != NULL){
        pi->topo = 0;
    }
    return pi;
}


fila* inicializaFila (){
    fila *fi;
    fi = (fila*) malloc(sizeof(struct Fila));
    fi->in = inicializaPilha();
    fi->out = inicializaPilha();
    if(fi != NULL){
        if (fi->in != NULL){
            fi->in->topo = 0;
        }
        if (fi->out != NULL){
            fi->out->topo = 0;
        }
    }
    return fi;
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

    *x = pi->obj[pi->topo];
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

    return(fi->out->topo == 0 && fi->in->topo == 0);
}

int fila_cheia(fila* fi){
    if(fi == NULL) return 0;

    return (fi->out->topo + fi->in->topo == MAX);
}

int insere_fila(fila* fi, int x){
    if(fi == NULL) return 0;
    if(fila_cheia(fi)) return 0;

    fi->in->obj[fi->in->topo] = x;
    fi->in->topo++;
    return 1;
}

int remove_fila(fila* fi){
    if(fi == NULL) return 0;
    if(fila_vazia(fi)) return 0;
    if (fi->out->topo == 0){
        int *x, y;
        x = &y;
        while((fi->in->topo) != 0){
            consulta_pilha(fi->in, *x);
            empilha(fi->out, y);
            desempilha(fi->in);
        }
    }
    desempilha(fi->out);

    return 1;
}

int tamanho_fila(fila* fi){
    if(fi == NULL)return -1;

     return (fi->in->topo + fi->out->topo);
}

int consulta_fila(fila* fi, int *x){
    if (fi == NULL) return 0;
    if (fila_vazia(fi)) return 0;

    if (fi->out->topo == 0){
        int *w, y = 0;
        w = &y;
        while((fi->in->topo) != 0){
            consulta_pilha(fi->in, w);
            empilha(fi->out, y);
            desempilha(fi->in);
        }
    }

    *x = (fi->out->obj[fi->out->topo]);
    return 1;
}
