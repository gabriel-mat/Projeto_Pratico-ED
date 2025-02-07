/**
 * \file deque.h
 * \brief Protótipos das funções de um deque
 *
 */
#ifndef DEQUE_H
#define DEQUE_H

/**
 * \brief Renomeia o tipo de dado do deque
 *
 */
typedef int T;

/**
 * \struct deque
 * \brief Estrutura de um deque
 *
 * A estrutura deque representa uma fila de deque (double-ended queue) que permite inserções e remoções em ambas as extremidades.
 *
 * \var deque::array
 * Array dinâmico que armazena os elementos do deque.
 *
 * \var deque::max_size
 * Capacidade máxima do deque.
 *
 * \var deque::qtd
 * Quantidade atual de elementos no deque.
 *
 * \var deque::inicio
 * Índice do início do deque.
 *
 * \var deque::fim
 * Índice do fim do deque.
 */
typedef struct
{
  T *array;
  unsigned max_size, qtd;
  int inicio, fim;
} deque;

/**
 * \brief Inicializa um deque
 *
 * \param d ponteiro para o deque
 * \param maxsize tamanho máximo do deque
 */
int inicializa_deque(deque *d, unsigned maxsize);
/**
 * \brief Destroi um deque
 *
 * \param d ponteiro para o deque
 */
int destroi_deque(deque *d);
/**
 * \brief Verifica se o deque está vazio
 *
 * \param d ponteiro para o deque
 */
int vazia(deque *d);
/**
 * \brief Verifica se o deque está cheio
 *
 * \param d ponteiro para o deque
 */
int cheia(deque *d);
/**
 * \brief Insere um elemento no início do deque
 *
 * \param d ponteiro para o deque
 * \param data dado a ser inserido
 */
int insereI(deque *d, T data);
/**
 * \brief Insere um elemento no fim do deque
 *
 * \param d ponteiro para o deque
 * \param data dado a ser inserido
 */
int insereF(deque *d, T data);
/**
 * \brief Remove um elemento do início do deque
 *
 * \param d ponteiro para o deque
 */
int removeI(deque *d);
/**
 * \brief Remove um elemento do fim do deque
 *
 * \param d ponteiro para o deque
 */
int removeF(deque *d);
/**
 * \brief Retorna o elemento do início do deque
 *
 * \param d ponteiro para o deque
 */
int *elementoI(deque *d);
/**
 * \brief Retorna o elemento do fim do deque
 *
 * \param d ponteiro para o deque
 */
int *elementoF(deque *d);
/**
 * \brief Imprime o deque do inicio ao fim
 *
 * \param d ponteiro para o deque
 */
void imprime_deque(deque *d);

#endif