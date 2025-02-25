/**
 * \file pilha.h
 * \brief Protótipos das funções de uma pilha.
 *
 */
#ifndef PILHA_H
#define PILHA_H

/**
 * \brief Renomeia o tipo de dado da pilha.
 *
 */
typedef int T;

/**
 * \struct pilha
 * \brief Estrutura de uma pilha.
 *
 * A estrutura pilha permite inserções e remoções apenas em uma extremidade.
 *
 * \var deque::array
 * Array dinâmico que armazena os elementos da pilha
 *
 * \var deque::qtd
 * Quantidade atual de elementos na pilha
 *
 * \var deque::inicio
 * Índice do início da pilha
 *
 * \var deque::fim
 * Índice do fim da pilha
 */
typedef struct
{
  T *array;
  unsigned qtd;
  int inicio, fim;
} pilha;

/**
 * \brief Inicializa uma pilha.
 *
 * \param p ponteiro para a pilha
 */
int pilha_inicializa(pilha *p);
/**
 * \brief Destroi uma pilha.
 *
 * \param p ponteiro para a pilha
 */
int pilha_destruir(pilha *p);
/**
 * \brief Verifica se a pilha está vazia.
 *
 * \param p ponteiro para a pilha
 */
int pilha_vazia(pilha *p);

/**
 * \brief Verifica se a pilha atingiu a quantidade máxima de elementos.
 *
 * \param p ponteiro para a pilha
 */

int pilha_cheia(pilha *p);
/**
 * \brief Insere um elemento na pilha.
 *
 * \param p ponteiro para a pilha
 * \param data dado a ser inserido
 */

int pilha_inserir(pilha *p, T data);
/**
 * \brief Remove um elemento na pilha.
 *
 * \param p ponteiro para a pilha
 */

int pilha_remover(pilha *p);
/**
 * \brief Retorna um ponteiro para o dado do elemento no topo da pilha.
 *
 * \param p ponteiro para a pilha
 */

int *pilha_topo(pilha *p);
/**
 * \brief Imprime a pilha desde o topo até a base.
 *
 * \param p ponteiro para a pilha
 */

void pilha_imprimir(pilha *p);

#endif