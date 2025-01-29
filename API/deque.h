#ifndef DEQUE_H
#define DEQUE_H

#define TAM_MAX_DEQUE 100000

typedef int T;

typedef struct {
  T *array;
  unsigned max_size, qtd;
  int inicio, fim;
} deque;

int inicializa_deque(deque *d, unsigned maxsize);
int destroi_deque(deque *d);
int vazia(deque *d);
int cheia(deque *d);
int insereI(deque *d, T data);
int insereF(deque *d, T data);
int removeI(deque *d);
int removeF(deque *d);
int *elementoI(deque *d);
int *elementoF(deque *d);

#endif