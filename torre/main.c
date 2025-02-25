#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../API/fila/fila.h"
#include "../API/deque/deque.h"

// Protótipos de funções e procedimentos

void menu();
void iniciar();
void como_jogar();
void regras();

void limpar_tela();

// == == == == == == == == == == == == == == ==

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
            como_jogar();
            break;

        case 3:
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

void iniciar() {}
void como_jogar() {}
void regras() {}

void limpar_tela()
{
    // Limpando o terminal de acordo com cada OS
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif
}