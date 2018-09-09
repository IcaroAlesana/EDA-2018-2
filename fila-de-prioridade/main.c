#include <stdio.h>
#include <stdlib.h>
#include "FilaDePrioridade.h"

int main(){
    fila* fi = inicializaFila();

    int e,*x, y, ins, cons, rem;
    y = 0;
    x = &y;
    int val[MAX] = {4,5,8,7,15,18,10,3,14,12};

    int i;
    for (i=0; i<MAX; i++){
        ins = insere_fila(fi, val[i]);
        printf("Insercao: %d\n", ins);
    }

    printf("\n\n");

    for (i=0; i<MAX; i++){
    cons = consulta_fila(fi, x);
    printf("Valor: %d\n", y);
    rem = remove_fila(fi);
    }

    return 0;
}
