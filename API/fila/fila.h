/**
 * \file fila.h
 * \brief Protótipos das funções de uma fila.
 *
 */
#ifndef FILA_H
#define FILA_H

/**
 * \brief Renomeia o tipo de dado da fila.
 *
 */
typedef int T;

/**
 * \struct node
 * \brief Estrutura de um nó.
 *
 * A estrutura node representa um nó da fila que armazena um dado e os ponteiros para o próximo nó e o nó anterior.
 *
 * \var node::data
 * Dado armazenado no nó
 *
 * \var node::next
 * Ponteiro para o próximo nó
 *
 * \var node::prev
 * Ponteiro para o nó anterior
 */
typedef struct node
{
    T data;
    struct node *next, *prev;
} node;

/**
 * \struct fila
 * \brief Estrutura de uma fila.
 *
 * A estrutura fila representa uma fila que permite remoções no seu início e inserções no seu fim.
 *
 * \var fila::qtd
 * Quantidade atual de elementos na fila
 *
 * \var fila::sentinela
 * Ponteiro para o nó sentinela da fila
 */
typedef struct fila
{
    unsigned qtd;
    node *sentinela;
} fila;

/**
 * \struct iterador
 * \brief Estrutura de um iterador.
 *
 * Um iterador possibilita algumas operações muito práticas em nossa lista, como acessar elementos adjacentes.
 *
 * \var iterador::posicao
 * Ponteiro para o nó iterado
 *
 * \var iterador::estrutura
 * Ponteiro a fila iterada
 */
typedef struct iterador
{
    node *posicao;
    fila *estrutura;
} iterador;

/**
 * \brief Inicializa uma fila.
 *
 * \param f ponteiro para a fila
 * \param maxsize tamanho máximo da fila
 */
void fila_inicializa(fila *f, unsigned maxsize);

/**
 * \brief Destroi uma fila.
 *
 * \param f ponteiro para a fila
 */
void fila_destruir(fila *f);

/**
 * \brief Insere um elemento no fim da fila.
 *
 * \param f ponteiro para a fila
 * \param data dado para inserção
 */
int fila_inserir(fila *f, T data);

/**
 * \brief Remove um elemento do início da fila.
 *
 * \param f ponteiro para a fila
 */
int fila_remover(fila *f);

/**
 * \brief Retorna a quantidade de dados na fila.
 *
 * \param f ponteiro para a fila
 */
unsigned fila_quantidade(fila *f);

/**
 * \brief Verifica se a fila está vazia.
 *
 * \param f ponteiro para a fila
 */
int fila_vazia(fila *f);

/**
 * \brief Retorna o endereço de memória do dado do início da fila.
 *
 * \param f ponteiro para a fila
 */
T *fila_inicio_data(fila *f);

/**
 * \brief Retorna o endereço de memória do dado do fim da fila.
 *
 * \param f ponteiro para a fila
 */
T *fila_fim_data(fila *f);

/**
 * \brief Retorna o iterador para o primeiro elemento da fila.
 *
 * \param f ponteiro para a fila
 */
iterador primeiro(fila *f);

/**
 * \brief Retorna o iterador para o último elemento da fila.
 *
 * \param f ponteiro para a fila
 */
iterador ultimo(fila *f);

/**
 * \brief Retorna o iterador para o próximo elemento da fila a partir do iterador recebido como parâmetro.
 *
 * \param i ponteiro para o iterador
 */
int proximo(iterador *i);

/**
 * \brief Retorna o iterador para o elemento anterior a partir do iterador recebido como parâmetro.
 *
 * \param i ponteiro para o iterador
 */
int anterior(iterador *i);

/**
 * \brief Verifica se o iterador está apontando para o sentinela da fila.
 *
 * \param i ponteiro para o iterador
 */
int acabou(iterador i);

#endif