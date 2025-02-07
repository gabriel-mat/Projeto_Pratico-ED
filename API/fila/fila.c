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

int fila_inserir(fila *f, T data){
    node *n = (node *)malloc(sizeof(node));

    if(n == NULL)
        return 1;
    
    n->data = data;
    n->next = f->sentinela;
    n->prev = f->sentinela->prev;

    f->sentinela->prev = n;
    n->prev->next = n;
    f->qtd++;

    return 0;
}

int fila_remover(fila *f){
    node *temp;
    
    if(fila_vazia(f))
        return 1;

    temp = f->sentinela->next;
    f->sentinela->next = temp->next;
    temp->next->prev = f->sentinela;
    free(temp);
    
    f->qtd--;

    return 0;
}   

unsigned fila_quantidade(fila *f){
    return f->qtd;
}

int fila_vazia(fila *f){
    return (f->qtd == 0);
}

T  *fila_inicio_data(fila *f){
    if(fila_vazia(f))
        return NULL;

    return &(f->sentinela->next);
}

T  *fila_fim_data(fila *f){
    if(fila_vazia(f))
        return NULL;

    return &(f->sentinela->prev);
}