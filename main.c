#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    int entrada;
    while (1)
    {
        menuExterno();
        scanf("%d", &entrada);
        switch (entrada)
        {
        case 1:
            printf("apertei um");
        case 2:
            printf("apertei 2");
        case 3:
            printf("apertei 3");
        case 0:
            return 0;
        default:
            printf("opcao invalida");
            break;
        }
    }

    return 0;
}