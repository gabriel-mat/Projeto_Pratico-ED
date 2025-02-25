#include <stdio.h>
#include <stdlib.h>
#include "../API/fila/fila.h"
#include "../API/deque/deque.h"

// Protótipos de funções e procedimentos

void imprimir_menu();

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
// Limpando o terminal de acordo com cada OS
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif

    printf("* MENU *\n");
}