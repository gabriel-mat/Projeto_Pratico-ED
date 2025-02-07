#include "fila.h"
#include <stdlib.h>

void fila_inicializa(fila *f, unsigned maxsize){
    node *sent = (node *)malloc(sizeof(node));
    sent->prev = sent->next = f->sentinela = sent; 
    f->qtd = 0;
}

void fila_destruir(fila *f){
    while(!fila_vazia(f))
        fila_remover(f);

    free(f->sentinela);    
    sentinela = NULL;
}

void fila_inserir(fila *f, T data){
    node *n = (node *)malloc(sizeof(node));
    
    n->data = data;
    n->next = f->sentinela;
    n->prev = f->sentinela->prev;

    f->sentinela->prev = n;
    n->prev->next = n;
    f->qtd++;
}

int fila_remover(fila *f){
    if(fila_vazia(f))
        return 0;

    
    
    f->qtd--;
}   

int fila_quantidade(fila *f);

int fila_vazia(fila *f){
    return (f->qtd == 0);
}

T  *fila_inicio_data(fila *f);
T  *fila_fim_data(fila *f);