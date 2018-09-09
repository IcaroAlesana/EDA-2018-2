#define MAX =12
struct livro {
    char nome [30];
    int pg;
};

typedef struct PilhaDupla pilha;

pilha* inicializa();
void libera_pilha(pilha* pi);
int pilha1_vazia(pilha* pi);
int pilha2_vazia(pilha* pi);
int pilhas_cheias(pilha* pi);
int empilha1(pilha* pi, struct livro li);
int empilha2(pilha* pi, struct livro li);
int desempilha1(pilha* pi);
int desempilha2(pilha* pi);
