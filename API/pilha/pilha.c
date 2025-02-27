/**
 * \file pilha.c
 * \authors André, Arthur, Gabriel e Otávio
 * \brief Implementação de uma pilha
 *
 * \details Este arquivo contém a implementação das funções de uma pilha.
 */
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

/**
 * \brief Inicializa uma pilha.
 *
 * \param p ponteiro para a pilha.
 * \return int 0 se inicializou com sucesso, 1 caso contrário.
 */
int pilha_inicializa(pilha *p)
{
  p->array = (T *)malloc(MAX_SIZE * sizeof(T));

  if (p->array == NULL)
    return 1;

  p->inicio = 0;
  p->fim = 1;
  p->qtd = 0;
  return 0;
}

/**
 * \brief Destroi uma pilha.
 *
 * \param p ponteiro para a pilha.
 * \return int 0 se destruiu com sucesso, 1 caso contrário.
 */
int pilha_destruir(pilha *p)
{
  if (p == NULL)
    return 1;

  free(p->array);
  p->array = NULL;
  return 0;
}

/**
 * \brief Verifica se a pilha está vazia.
 *
 * \param p ponteiro para a pilha.
 * \return int 1 se vazia, 0 caso contrário.
 */
int pilha_vazia(pilha *p) { return (p->qtd == 0); }

/**
 * \brief Verifica se a pilha está cheia.
 *
 * \param p ponteiro para a pilha.
 * \return int 1 se cheia, 0 caso contrário.
 */
int pilha_cheia(pilha *p) { return (p->qtd >= MAX_SIZE); }

/**
 * \brief Insere um elemento no topo da pilha.
 *
 * \param p ponteiro para a pilha.
 * \param data elemento a ser inserido.
 * \return int 0 se inseriu com sucesso, 1 caso a pilha esteja cheia.
 */
int pilha_inserir(pilha *p, T data)
{
  if (pilha_cheia(p))
    return 1;

  p->array[p->inicio] = data;
  p->inicio = (p->inicio - 1 + MAX_SIZE) % MAX_SIZE;
  p->qtd = p->qtd + 1;
  return 0;
}

/**
 * \brief Remove um elemento do topo da pilha.
 *
 * \param p ponteiro para a pilha.
 * \return int 0 se removeu com sucesso, 1 caso a pilha esteja vazia.
 */
int pilha_remover(pilha *p)
{
  if (pilha_vazia(p))
    return 1;

  p->inicio = (p->inicio + 1 + MAX_SIZE) % MAX_SIZE;
  p->qtd = p->qtd - 1;
  return 0;
}

/**
 * \brief Retorna o elemento armazenado do topo da pilha.
 *
 * \param p ponteiro para a pilha.
 * \return int* ponteiro para o elemento do início, NULL caso a pilha esteja vazia.
 */
int *pilha_topo(pilha *p)
{
  if (pilha_vazia(p))
    return NULL;
  return &(p->array[(p->inicio + 1 + MAX_SIZE) % MAX_SIZE]);
}

/**
 * \brief Imprime a pilha do topo à base.
 *
 * \param p ponteiro para a pilha.
 */
void pilha_imprimir(pilha *p)
{
  for (int i = 0; i < p->qtd; i++)
    printf("%d ", p->array[(p->inicio + i + 1 + MAX_SIZE) % MAX_SIZE]);
}