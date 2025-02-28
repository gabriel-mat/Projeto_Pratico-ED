/**
 * @file main.c
 * @authors André, Arthur, Gabriel e Otávio
 * @brief Arquivo principal
 *
 * Arquivo principal com a implementação do quebra-cabeça.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../API/fila/fila.h"
#include "../API/deque/deque.h"
#include "../API/pilha/pilha.h"

/**
 * @def NUM_FASES
 * Define o número máximo de fases do jogo.
 */
#define NUM_FASES 5

/**
 * @def MAX_DISCOS
 * Define o número máximo de discos em torres.
 */
#define MAX_DISCOS 5

/**
 * @def MAX_COMANDO
 * Número máximo do vetor de comando.
 */
#define MAX_COMANDO 3

// Protótipos de funções e procedimentos

/**
 * @brief Mostra ao usuário o menu principal do jogo.
 * @details Esse menu é composto pelas opções de "iniciar", "como jogar" e "regras".
 *
 */
void menu();

/**
 * @brief Inicia o jogo.
 *
 */
void iniciar();

/**
 * @brief Mostra ao usuário instruções de como utilizar corretamente a aplicação.
 *
 */
void como_jogar();

/**
 * @brief Mostra ao usuário regras básicas do quebra-cabeça "Torre de hanói".
 *
 */
void regras();

/**
 * @brief Mostra ao usuário uma mensagem caso ele atinja o número máximo de movimentos.
 *
 */
void msg_max_movs();

/**
 * @brief Mostra ao usuário uma mensagem caso ele passe por todas as fases.
 *
 */
void msg_final();

/**
 * @brief Limpa o buffer de entrada para que a próxima entrada seja lida corretamente.
 *
 */
void limpar_buffer();

/**
 * @brief Executa a fase representada pelo nó apontado pelo iterador.
 *
 * @param i iterador para a fase
 * @return int
 */
int jogar_fase(iterador i);

/**
 * @brief Verifica se a fase foi vencida ou não
 *
 * @param A apontador para a primeira torre
 * @param B apontador para a segunda torre
 * @param C apontador para a terceira torre
 * @return int
 */
int vitoria(pilha *A, pilha *B, pilha *C);

/**
 * @brief Inicializa a torre inical com os discos.
 *
 * @param num Número de discos da torre.
 * @return pilha: Ponteiro para torre com os discos prontos para o ínicio do jogo.
 */
pilha *criar_torre(int num);

/**
 * @brief Limpa o terminal do usuário.
 * Essa função limpa o terminal do usuário de acordo com o sistema operacional utilizado.
 *
 */
void limpar_tela();

/**
 * @brief Copia os elementos de uma pilha para um vetor.
 *
 * Esta função transfere os elementos de uma pilha para um vetor,
 * garantindo que a pilha original permaneça inalterada.
 *
 * @param p1 Ponteiro para a pilha a ser copiada.
 * @param i Posição do vetor que deve ser inserido o elemento da pilha
 * @param v Vetor onde os elementos da pilha serão armazenados.
 */
void copiar_pilha(pilha *p1, int v[], int i)
{
    if (pilha_vazia(p1))
        return;

    int elemento = *pilha_topo(p1);
    pilha_remover(p1);
    copiar_pilha(p1, v, i + 1);
    v[i] = elemento;
    pilha_inserir(p1, elemento);
}

/**
 * @brief Exibe um andar de uma torre.
 *
 * Esta função imprime visualmente um andar específico de uma torre.
 *
 * @param v Vetor que representa a torre.
 * @param andar O nível da torre a ser impresso (de 1 a 5).
 */
void printar_andar_torre(int v[], int andar)
{
    int espacos, discos;
    printf("  ");
    espacos = 5 - v[5 - andar];
    while (espacos)
    {
        printf(" ");
        espacos--;
    }
    discos = v[5 - andar];
    while (discos)
    {
        printf("=");
        discos--;
    }
    printf("|");
    discos = v[5 - andar];
    while (discos)
    {
        printf("=");
        discos--;
    }
    espacos = 5 - v[5 - andar];
    while (espacos)
    {
        printf(" ");
        espacos--;
    }
}

/**
 * @brief Exibe as torres do jogo.
 *
 * Esta função imprime visualmente o estado atual das torres,
 * mostrando a disposição dos discos para o usuário.
 *
 * @param v1 Vetor representando a primeira torre.
 * @param v2 Vetor representando a segunda torre.
 * @param v3 Vetor representando a terceira torre.
 */
void printar_torre(int v1[], int v2[], int v3[])
{
    printf("       A            B            C\n");
    for (int i = 5; i >= 1; i--)
    {
        printar_andar_torre(v1, i);
        printar_andar_torre(v2, i);
        printar_andar_torre(v3, i);
        printf("\n");
    }
}

int main()
{
    int codigo;

    // Exibindo o menu e recebendo a opção do usuário
    menu();

    return 0;
}

void menu()
{
    int opt;

    do
    {
        limpar_tela();

        printf("\tMENU:\n");
        printf("\tiniciar\t\t01\n");
        printf("\tcomo jogar\t02\n");
        printf("\tregras\t\t03\n");

        printf("\ninsira o codigo do comando: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            opt = 0;
            iniciar();
            break;

        case 2:
            opt = 0;
            como_jogar();
            break;

        case 3:
            opt = 0;
            regras();
            break;

        default:
            opt = 0;
            printf("Comando invalido! Tente novamente.");
            limpar_buffer();
            getchar();
            break;
        }
    } while (!opt);
}

void iniciar()
{
    int game_over, fim;
    iterador it;
    fila fases;

    fila_inicializa(&fases);

    for (int i = 1; i <= NUM_FASES; i++)
        fila_inserir(&fases, i);

    it = primeiro(&fases);

    for (int i = 0; i < NUM_FASES; i++)
    {
        game_over = jogar_fase(it);

        if (!game_over)
        {
            fim = proximo(&it);
            if (fim)
            {
                msg_final();
                return;
            }
        }
        else
        {
            msg_max_movs();
            i--;
        }
    }

    msg_max_movs();
}

void como_jogar()
{
    limpar_tela();

    printf("\tCOMO JOGAR\n");
    printf("\t\tO jogo consiste em 5 fases em ordem crescente de dificuldade, cada fase 'n' possui 'n' discos na torre inicial;\n");
    printf("\t\tAs 3 torres sao denomidadas A, B e C; respectivamente, da esquerda para a direita;\n");
    printf("\t\tA cada nova fase com 'n' discos, o minimo de movimentos necessarios e calculado (2^n - 1);\n");
    printf("\t\tUsar mais que o minimo de movimentos reiniciara seu progresso na fase atual!\n");

    printf("\n\tCOMANDOS\n");
    printf("\t\tX Y\t|  move o disco do topo de X para o topo de Y;\n");

    printf("\nLembre-se de considerar as regras do jogo e usar a notacao 'A', 'B' e 'C'\npressionte enter");

    limpar_buffer();
    getchar();
}

void regras()
{
    limpar_tela();

    printf("\tREGRAS:\n");
    printf("\t\t  O quebra-cabeca consiste em uma base com tres pinos, onde varios discos sao empilhados em um deles,\n");
    printf("\t\torganizados em ordem crescente de diametro, do menor no topo ao maior na base.\n");
    printf("\t\t  O desafio e transferir todos os discos para outro pino, seguindo duas regras fundamentais:\n\n");

    printf("\t\t1. Apenas um disco pode ser movido por vez.\n");
    printf("\t\t2. Nenhum disco maior pode ficar sobre um menor em nenhum momento.\n\n");
    printf("\t\t  A solucao exige planejamento estrategico e raciocinio logico para garantir\n");
    printf("\t\tque todos os discos sejam movidos corretamente dentro do limite de jogadas.\npressione enter");

    limpar_buffer();
    getchar();
}

void msg_max_movs()
{
    limpar_tela();

    printf("\tGAME OVER\n");
    printf("\tNumero maximo de movimentos atingido, tente novamente!\n");
    printf("\npressione enter\n");
    getchar();
}

void msg_final()
{
    limpar_tela();

    printf("\tVOCE VENCEU!\n");
    printf("\tVamos considerar aumentar o nivel na proxima.\n");
    limpar_buffer();
    getchar();
}

int jogar_fase(iterador i)
{
    pilha *A, *B, *C;
    pilha *source, *dest;
    int movs, max_movs, num;
    char comando[MAX_COMANDO + 1], src, dst;
    int A1[MAX_DISCOS], B2[MAX_DISCOS], C3[MAX_DISCOS];

    movs = 0;
    num = (i.posicao)->data;
    max_movs = pow(2, num) - 1;

    A = criar_torre(num);
    B = criar_torre(0);
    C = criar_torre(0);

    while (!vitoria(A, B, C))
    {
        limpar_tela();

        if (movs >= max_movs)
        {
            msg_max_movs();

            pilha_destruir(A);
            pilha_destruir(B);
            pilha_destruir(C);

            return 1;
        }

        for (int i = 0; i < 5; i++)
            A1[i] = B2[i] = C3[i] = 0;

        copiar_pilha(A, A1, 5 - pilha_tamanho(A));
        copiar_pilha(B, B2, 5 - pilha_tamanho(B));
        copiar_pilha(C, C3, 5 - pilha_tamanho(C));

        printf("Fase %d\n", num);
        printf("Movimentos restantes: %d\n", max_movs - movs);
        printar_torre(A1, B2, C3);

        printf("\nmove ");

        scanf(" %[^\n]", comando);
        src = comando[0];
        dst = comando[2];

        if (src == 'A')
            source = A;
        else if (src == 'B')
            source = B;
        else if (src == 'C')
            source = C;
        else
        {
            printf("\nPilha de origem invalida!\npressione enter");
            limpar_buffer();
            getchar();
            continue;
        }

        if (dst == 'A')
            dest = A;
        else if (dst == 'B')
            dest = B;
        else if (dst == 'C')
            dest = C;
        else
        {
            printf("\nPilha de destino invalida!\npressione enter");
            limpar_buffer();
            getchar();
            continue;
        }

        if (pilha_vazia(source))
        {
            printf("\nPilha de origem vazia!\npressione enter");
            limpar_buffer();
            getchar();
            continue;
        }

        if (!pilha_vazia(dest) && (*(pilha_topo(source)) > *(pilha_topo(dest))))
        {
            printf("\nUm disco maior nao pode sobrepor um disco menor!\npressione enter");
            limpar_buffer();
            getchar();
            continue;
        }

        pilha_inserir(dest, *(pilha_topo(source)));
        pilha_remover(source);
        movs++;
    }

    pilha_destruir(A);
    pilha_destruir(B);
    pilha_destruir(C);

    return 0;
}

void limpar_buffer()
{
    while (getchar() != '\n')
        ;
}

int vitoria(pilha *A, pilha *B, pilha *C)
{
    return (pilha_vazia(A) && (pilha_vazia(B) || pilha_vazia(C)));
}

pilha *criar_torre(int num)
{
    pilha *p = (pilha *)malloc(sizeof(pilha));

    pilha_inicializa(p);

    for (int i = num; i > 0; i--)
        pilha_inserir(p, i);

    return (p);
}

void limpar_tela()
{
    // Limpando o terminal de acordo com cada OS
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif
}
