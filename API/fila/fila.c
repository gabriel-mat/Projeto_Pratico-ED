/**
 * \file fila.c
 * \authors André, Arthur, Gabriel e Otávio
 * \brief Implementação de uma fila
 *
 * \details Este arquivo contém a implementação das funções de uma fila.
 */
#include "fila.h"
#include <stdlib.h>

/**
 * \brief Inicializa uma fila.
 *
 * \param f ponteiro para a fila.
 * \param maxsize tamanho máximo da fila.
 */
void fila_inicializa(fila *f)
{
    node *sent = (node *)malloc(sizeof(node));
    sent->prev = sent->next = f->sentinela = sent;
    f->qtd = 0;
}

/**
 * \brief Destroi uma fila.
 *
 * \param f ponteiro para a fila.
 */
void fila_destruir(fila *f)
{
    while (!fila_vazia(f))
        fila_remover(f);

    free(f->sentinela);
}

/**
 * \brief Insere um elemento no fim da fila.
 *
 * \param f ponteiro para a fila.
 * \param data dado a ser inserido.
 * \return int 0 se inseriu com sucesso, int 1 caso a fila não exista.
 */
int fila_inserir(fila *f, T data)
{
    node *n = (node *)malloc(sizeof(node));

    if (n == NULL)
        return 1;

    n->data = data;
    n->next = f->sentinela;
    n->prev = f->sentinela->prev;

    f->sentinela->prev = n;
    n->prev->next = n;
    f->qtd++;

    return 0;
}

/**
 * \brief Remove um elemento do início da fila.
 *
 * \param f ponteiro para a fila.
 * \return int 0 se removeu com sucesso, int 1 caso a fila esteja vazia.
 */
int fila_remover(fila *f)
{
    node *temp;

    if (fila_vazia(f))
        return 1;

    temp = f->sentinela->next;
    f->sentinela->next = temp->next;
    temp->next->prev = f->sentinela;
    free(temp);

    f->qtd--;

    return 0;
}

/**
 * \brief Retorna a quantidade de dados na fila.
 *
 * \param f ponteiro para a fila.
 * \return quantidade de dados na fila.
 */
unsigned fila_quantidade(fila *f)
{
    return f->qtd;
}

/**
 * \brief Verifica se a fila está vazia.
 *
 * \param f ponteiro para a fila.
 * \return int 1 se a fila estiver vazia, int 0 caso contrário.
 */
int fila_vazia(fila *f)
{
    return (f->qtd == 0);
}

/**
 * \brief Retorna o endereço de memória do dado do início da fila.
 *
 * \param f ponteiro para a fila.
 * \return ponteiro para o dado do início, NULL se a fila estiver vazia.
 */
T *fila_inicio_data(fila *f)
{
    if (fila_vazia(f))
        return NULL;

    return &(f->sentinela->next->data);
}

/**
 * \brief Retorna o endereço de memória do dado do fim da fila.
 *
 * \param f ponteiro para a fila.
 * \return ponteiro para o dado do fim, NULL se a fila estiver vazia.
 */
T *fila_fim_data(fila *f)
{
    if (fila_vazia(f))
        return NULL;

    return &(f->sentinela->prev->data);
}

/**
 * \brief Retorna o iterador para o primeiro elemento da fila.
 *
 * \param f ponteiro para a fila.
 * \return struct iterador i na primeira posição da fila.
 */
iterador primeiro(fila *f)
{
    iterador i;

    i.posicao = f->sentinela->next;
    i.estrutura = f;

    return i;
}

/**
 * \brief Retorna o iterador para o último elemento da fila.
 *
 * \param f ponteiro para a fila.
 * \return struct iterador i na última posição da fila.
 */
iterador ultimo(fila *f)
{
    iterador i;

    i.posicao = f->sentinela->prev;
    i.estrutura = f;

    return i;
}

/**
 * \brief Retorna o iterador para o próximo elemento da fila a partir do iterador recebido como parâmetro.
 *
 * \param i ponteiro para o iterador.
 * \return retorna 0 se ainda havia um próximo elemento, 1 caso contrário.
 */
int proximo(iterador *i)
{
    i->posicao = i->posicao->next;

    if (acabou(*i))
        return 1;

    return 0;
}

/**
 * \brief Retorna o iterador para o elemento anterior a partir do iterador recebido como parâmetro.
 *
 * \param i ponteiro para o iterador.
 * \return retorna 0 se ainda havia um elemento anterior, 1 caso contrário.
 */
int anterior(iterador *i)
{
    i->posicao = i->posicao->prev;

    if (acabou(*i))
        return 1;

    return 0;
}

/**
 * \brief Verifica se o iterador está apontando para o sentinela da fila.
 *
 * \param i ponteiro para o iterador.
 * \return 1 se o iterador aponta para o sentinela, 0 caso contrário.
 */
int acabou(iterador i)
{
    return (i.posicao == i.estrutura->sentinela);
}