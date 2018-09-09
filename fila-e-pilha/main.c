#include <stdio.h>
#include <stdlib.h>
#include "filaEPilha.h"

int main(){
    pilha *pi = inicializaPilha();
    fila* fi = inicializaFila();

    int t = tamanho_pilha(pi);
    printf("Tamanho da pilha: %d\n\n", t);
    int e,*x, y, ins, cons, rem;
    y = 0;
    x = &y;
    int val[MAX] = {4,6,8,7,15,18,5,3,14,12};

    int i;
    for (i=0; i<MAX; i++){
        ins = insere_fila(fi, val[i]);
        printf("Insercao: %d\n", ins);
    }

    printf("\n\n");

    for (i=0; i<MAX; i++){
        cons = consulta_fila(fi, x);
        printf("Consulta: %d\nValor: %d\n", cons, y);
        e = empilha(pi, y);
        printf("Empilha: %d\n", e);
        rem = remove_fila(fi);
        printf("Remove: %d\n", rem);
    }

    printf("\n\n");

    for (i=0; i<MAX; i++){
        cons = consulta_pilha(pi, x);
        printf("Consulta: %d\nValor: %d\n", cons, y);
        ins = insere_fila(fi, y);
        printf("Insercao: %d\n", ins);
        rem = desempilha(pi);
        printf("Desempilha: %d\n", rem);
    }

    printf("\n\n");

    for (i=0; i<MAX; i++){
        cons = consulta_fila(fi, x);
        printf("Valor: %d\n", y);
        rem = remove_fila(fi);

    return 0;
}
