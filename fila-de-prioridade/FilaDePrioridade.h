#define MAX 10

typedef struct Fila fila;

fila* inicializaFila ();

int fila_vazia(fila* fi);
int fila_cheia(fila* fi);
int insere_fila(fila* fi, int x);
int remove_fila(fila* fi);
int tamanho_fila(fila* fi);
int consulta_fila(fila* fi, int* x);
