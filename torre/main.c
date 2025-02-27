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
 * @def MAX_COMANDO
 * Número máximo do vetor de comando.
 */
#define MAX_COMANDO 15

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
 * @brief Limpa o buffer de entrada para que a próxima entrada seja lida corretamente.
 *
 */
void limpar_buffer();

/**
 * @brief
 *
 * @param num
 * @return int
 */
int jogar_fase(int num);

/**
 * @brief Inicializa a torre inical com os discos.
 *
 * @param num Número de discos da torre.
 * @return pilha: Torre com os discos prontos para o ínicio do jogo.
 */
pilha criar_torre(int num);

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
 * @param v Vetor onde os elementos da pilha serão armazenados.
 */
void copiar_pilha(pilha* p1, int v[]){
    int i = 0;
    for(i = 0; i < 5 - pilha_tamanho(p1); i++){
        v[i] = 0;
    }
    while(!pilha_vazia(p1)){
        v[i] = pilha_topo(p1);
        pilha_remover(p1);
        copiar_pilha(p1, v);
        pilha_inserir(p1, v[i]);
        i++;
    }
}

/**
 * @brief Exibe um andar de uma torre.
 * 
 * Esta função imprime visualmente um andar específico de uma torre.
 * 
 * @param v Vetor que representa a torre.
 * @param andar O nível da torre a ser impresso (de 1 a 5).
 */
void printar_andar_torre(int v[], int andar){
    int espacos, discos;
    printf("  ");
    espacos = 5 - v[5 - andar];
    while(espacos){
        printf(" ");
        espacos--;
    }
    discos = v[5 - andar];
    while(discos){
        printf("=");
        discos--;
    }
    printf("|");
    discos = v[5 - andar];
    while(discos){
        printf("=");
        discos--;
    }
    espacos = 5 - v[5 - andar];
    while(espacos){
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
void printar_torre(int v1[], int v2[], int v3[]){
    printf("       A            B            C\n");
    for(int i = 5; i >= 1; i--){
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
    int game_over;
    iterador it;
    fila fases;

    fila_inicializa(&fases, NUM_FASES);

    for (int i = 1; i <= NUM_FASES; i++)
        fila_inserir(&fases, i);

    it = primeiro(&fases);

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
    printf("\t\tmv X Y\t|  move o disco do topo de X para o topo de Y;\n");

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
    printf("\tNumero maximo de movimentos atingido, tente novamente!");
    limpar_buffer();
    getchar();
}

int jogar_fase(int num)
{
    pilha A, B, C;
    int movs, max_movs;
    char comando[MAX_COMANDO + 1];

    movs = 0;
    max_movs = pow(2, num) - 1;

    A = criar_torre(num);
    B = criar_torre(0);
    C = criar_torre(0);

    while (movs <= max_movs)
    {
    }

    return 1;
}

void limpar_buffer()
{
    while (getchar() != '\n')
        ;
}

pilha criar_torre(int num)
{
    pilha p;

    pilha_inicializa(&p);

    for (int i = num; i > 0; i--)
        pilha_inserir(&p, i);

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
