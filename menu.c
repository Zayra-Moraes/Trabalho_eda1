#include "menu.h"

#include <stdio.h>

int menuPrincipal() {
    // concertei, o problema é que ele printa tao rapido e reprinta a 
    // primeira parte tao rapido que nao da pra ver, mas esta funcional.
  int entrada = -1;

  while (entrada != 0) {

    printf("\n              BEM VINDO Á ....           \n");
    printf("--------------Menu Principal--------------\n");
    
    printf("\nPor favor digite um número:\n");

    if (scanf("%d", &entrada) != 1) {
      printf("entrada invalida\n");
      while (getchar() != '\n');
      continue;
    }
    while (getchar() != '\n');

    switch (entrada) {
    case 1:
      printf("apertei um\n");
      break;

    case 2:
      printf("apertei 2\n");
      break;
    case 3:
      printf("apertei 3\n");
      break;
    case 0:
      printf("saindo...\n");
      return 0;
    default:
      printf("opcao invalida\n");
      break;
    }
  }

  return 0;
}
