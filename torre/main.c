#include <stdio.h>
#include <string.h>
#include "../API/fila/fila.h"
#include "../API/deque/deque.h"

int traduzircomandomenu(char comando[])
{
    if (strcmp(comando, "iniciar") == 0)
    {
        return 0;
    }
    else if (strcmp(comando, "comojogar") == 0)
    {
        return 1;
    }
    else if (strcmp(comando, "regras") == 0)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int main()
{
    printf("Digite um comando (iniciar, comojogar, regras): ");

    char comando[10];
    scanf("%s", comando);

    int codigo = traduzircomandomenu(comando);

    switch (codigo)
    {
    case 0:
        printf("iniciar\n");
        break;
    case 1:
        printf("comojogar\n");
        break;
    case 2:
        printf("regras\n");
        break;
    default:
        printf("COMANDO INVALIDO\n");
    }

    return 0;
}
