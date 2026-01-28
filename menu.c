#include "menu.h"
#include <stdio.h>
#include "funcoes.h"

int menuPrincipal(){
    printf("\n                  BEM VINDO Á ....           \n");
    printf("--------------Menu Principal------------");
    

    int entrada;
    while (1)
    {
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
    printf("\nPor favor digite um número:\n");

}

    