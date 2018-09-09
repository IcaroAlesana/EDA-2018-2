#include<stdio.h>
#include<stdlib.h>
#include "deque.h"

struct Deque{
    obj[MAX];
    int esq;
    int dir;
    int qtd;
};

douque* inicializa_deque(){
    douque* de = (douque*) malloc(sizeof(struct Deque));
    de->dir =0;
    de->esq =0;
    de->qtd =0;
}
