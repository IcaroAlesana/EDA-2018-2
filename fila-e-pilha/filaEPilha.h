#define MAX 10

typedef struct Fila fila;
typedef struct Pilha pilha;

fila* inicializaFila ();
pilha* inicializaPilha();

int pilha_vazia(pilha* pi);
int pilha_cheia(pilha* pi);
int empilha(pilha* pi, int x);
int desempilha(pilha* pi);
int consulta_pilha(pilha* pi, int* x);
int tamanho_pilha(pilha* pi);
int libera_pilha(pilha* pi);

int fila_vazia(fila* fi);
int fila_cheia(fila* fi);
int insere_fila(fila* fi, int x);
int remove_fila(fila* fi);
int tamanho_fila(fila* fi);
int consulta_fila(fila* fi, int* x);
