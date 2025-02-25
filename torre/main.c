#include <stdio.h>
#include <stdlib.h>
#include "../API/fila/fila.h"
#include "../API/deque/deque.h"

// Protótipos de funções e procedimentos

void imprimir_menu();
void limpar_tela();

// == == == == == == == == == == == == == == ==

int main()
{
    int codigo;

    // Exibindo o menu
    imprimir_menu();

    return 0;
}

void imprimir_menu()
{
    int opt;

    limpar_tela();

    printf("  MENU:\n");
    printf("\tiniciar\t\t01\n");
    printf("\tcomo jogar\t02\n");
    printf("\tregras\t\t03\n");

    printf("\ninsira o codigo do comando: ");
    scanf("%d", &opt);
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