#include "deque.h"
#include <stdlib.h>

int inicializa_deque(deque *d, unsigned maxsize) {
  d->array = (T *)malloc(TAM_MAX_DEQUE * sizeof(T));

  if (d->array == NULL)
    return 1;

  d->max_size = maxsize;
  d->inicio = 0;
  d->fim = 1;
  d->qtd = 0;
  return 0;
}

int destroi_deque(deque *d) {
  if (d == NULL)
    return 1;

  free(d->array);
  d->array = NULL;
  return 0;
}

int vazia(deque *d) { return (d->qtd == 0); }

int cheia(deque *d) { return (d->qtd == d->max_size); }

int insereI(deque *d, T data) {
  if (cheia(d))
    return 1;

  d->array[d->inicio] = data;
  d->inicio = (d->inicio - 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd + 1;
  return 0;
}

int insereF(deque *d, T data) {
  if (cheia(d))
    return 1;

  d->array[d->fim] = data;
  d->fim = (d->fim + 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd + 1;
  return 0;
}

int removeI(deque *d) {
  if (vazia(d))
    return 1;

  d->inicio = (d->inicio + 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd - 1;
  return 0;
}

int removeF(deque *d) {
  if (vazia(d))
    return 1;

  d->fim = (d->fim - 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd - 1;
  return 0;
}

int *elementoI(deque *d) {
  if (vazia(d))
    return NULL;
  return &(d->array[(d->inicio + 1 + d->max_size) % d->max_size]);
}

int *elementoF(deque *d) {
  if (vazia(d))
    return NULL;
  return &(d->array[(d->fim - 1 + d->max_size) % d->max_size]);
}