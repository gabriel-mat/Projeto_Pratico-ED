/**
 * \file deque.c
 * \authors André, Arthur, Gabriel e Otávio
 * \brief Implementação de um deque
 *
 * \details Este arquivo contém a implementação das funções de um deque.
 */
#include "deque.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Inicializa um deque.
 *
 * \param d ponteiro para o deque
 * \param maxsize tamanho máximo do deque
 * \return int 0 se inicializou com sucesso, 1 caso contrário
 */
int inicializa_deque(deque *d, unsigned maxsize)
{
  d->array = (T *)malloc(maxsize * sizeof(T));

  if (d->array == NULL)
    return 1;

  d->max_size = maxsize;
  d->inicio = 0;
  d->fim = 1;
  d->qtd = 0;
  return 0;
}

/**
 * \brief Destroi um deque.
 *
 * \param d ponteiro para o deque
 * \return int 0 se destruiu com sucesso, 1 caso contrário
 */
int destroi_deque(deque *d)
{
  if (d == NULL)
    return 1;

  free(d->array);
  d->array = NULL;
  return 0;
}

/**
 * \brief Verifica se o deque está vazio.
 *
 * \param d ponteiro para o deque
 * \return int 1 se vazio, 0 caso contrário
 */
int vazia(deque *d) { return (d->qtd == 0); }

/**
 * \brief Verifica se o deque está cheio.
 *
 * \param d ponteiro para o deque
 * \return int 1 se cheio, 0 caso contrário
 */
int cheia(deque *d) { return (d->qtd == d->max_size); }

/**
 * \brief Insere um elemento no início do deque.
 *
 * \param d ponteiro para o deque
 * \param data elemento a ser inserido
 * \return int 0 se inseriu com sucesso, 1 caso contrário
 */
int insereI(deque *d, T data)
{
  if (cheia(d))
    return 1;

  d->array[d->inicio] = data;
  d->inicio = (d->inicio - 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd + 1;
  return 0;
}

/**
 * \brief Insere um elemento no fim do deque.
 *
 * \param d ponteiro para o deque
 * \param data elemento a ser inserido
 * \return int 0 se inseriu com sucesso, 1 caso contrário
 */
int insereF(deque *d, T data)
{
  if (cheia(d))
    return 1;

  d->array[d->fim] = data;
  d->fim = (d->fim + 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd + 1;
  return 0;
}

/**
 * \brief Remove um elemento do início do deque.
 *
 * \param d ponteiro para o deque
 * \return int 0 se removeu com sucesso, 1 caso contrário
 */
int removeI(deque *d)
{
  if (vazia(d))
    return 1;

  d->inicio = (d->inicio + 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd - 1;
  return 0;
}

/**
 * \brief Remove um elemento do fim do deque.
 *
 * \param d ponteiro para o deque
 * \return int 0 se removeu com sucesso, 1 caso contrário
 */
int removeF(deque *d)
{
  if (vazia(d))
    return 1;

  d->fim = (d->fim - 1 + d->max_size) % d->max_size;
  d->qtd = d->qtd - 1;
  return 0;
}

/**
 * \brief Retorna o elemento do início do deque.
 *
 * \param d ponteiro para o deque
 * \return int* ponteiro para o elemento do início, NULL se vazio
 */
int *elementoI(deque *d)
{
  if (vazia(d))
    return NULL;
  return &(d->array[(d->inicio + 1 + d->max_size) % d->max_size]);
}

/**
 * \brief Retorna o elemento do fim do deque.
 *
 * \param d ponteiro para o deque
 * \return int* ponteiro para o elemento do fim, NULL se vazio
 */
int *elementoF(deque *d)
{
  if (vazia(d))
    return NULL;
  return &(d->array[(d->fim - 1 + d->max_size) % d->max_size]);
}

/**
 * \brief Imprime o deque do inicio ao fim.
 *
 * \param d ponteiro para o deque
 */
void imprime_deque(deque *d)
{
  for (int i = 0; i < d->qtd; i++)
    printf("%d ", d->array[(d->inicio + i + 1 + d->max_size) % d->max_size]);
}