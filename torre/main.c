#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../API/fila/fila.h"
#include "../API/deque/deque.h"
#include "../API/pilha/pilha.h"

#define NUM_FASES 5
#define MAX_COMANDO 15

// Protótipos de funções e procedimentos

void menu();
void iniciar();
void como_jogar();
void regras();
void msg_max_movs();
int jogar_fase(int num);
pilha criar_torre(int num);

void limpar_tela();

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
            scanf("%*c");
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
    printf("\t\tmv X Y, move o disco do topo de X para o topo de Y, use a notacao 'A', 'B' e 'C';\n");

    printf("\nLembre-se de considerar as regras do jogo, boa sorte!");

    scanf("%*c");
    getchar();
    limpar_tela();
}

void regras()
{
    limpar_tela();

    printf("REGRAS:\n\n");
    printf("O quebra-cabeca consiste em uma base com tres pinos, onde varios discos sao empilhados em um deles,\n");
    printf("organizados em ordem crescente de diametro, do menor no topo ao maior na base.\n");
    printf("O desafio e transferir todos os discos para outro pino, utilizando o terceiro como auxiliar,\n");
    printf("seguindo tres regras fundamentais:\n\n");
    printf("1. Apenas um disco pode ser movido por vez.\n");
    printf("2. Nenhum disco maior pode ficar sobre um menor em nenhum momento.\n");
    printf("3. Ha um numero limitado de movimentos para concluir o desafio.\n\n");
    printf("A solucao exige planejamento estrategico e raciocinio logico para garantir\n");
    printf("que todos os discos sejam movidos corretamente dentro do limite de jogadas. Boa sorte!\n\n");

    scanf("%*c");
    getchar();
}

void msg_max_movs()
{
    limpar_tela();

    printf("\tGAME OVER\n");
    printf("\tNumero maximo de movimentos atingido, tente novamente!");
    scanf("%*c");
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