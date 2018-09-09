#include <stdio.h>
#include <stdlib.h>
#include "FilaDePrioridade.h"

struct Fila {
    int obj[MAX];
    int inicio;
    int fim;
    int qtd;
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

    int i = fi->fim;
    if (fi->qtd == 0){
        fi->obj[fi->fim] = x;
    }
    else if(x > fi->obj[fi->fim-1]){
       fi->obj[fi->fim] = x;
    } else{
        do {
            fi->obj[i] = fi->obj[i-1];
            i--;
        } while(x < fi->obj[i-1] && i>0);
        fi->obj[i] = x;
    }

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
