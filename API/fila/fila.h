#ifndef FILA_H
#define FILA_H

typedef int T;

typedef struct node{
    T data;
    struct node *next, *prev;
}node;

typedef struct fila{
    unsigned qtd;
    node *sentinela;
}fila;

void fila_inicializa(fila *f, unsigned maxsize);
void fila_destruir(fila *f);
int fila_inserir(fila *f, T data);
int fila_remover(fila *f);
unsigned fila_quantidade(fila *f);
int fila_vazia(fila *f);
T  *fila_inicio_data(fila *f);
T  *fila_fim_data(fila *f);

#endif