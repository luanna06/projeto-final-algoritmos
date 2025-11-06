#include <stdio.h>
#include "validacao.h"

#define MIN 1
#define MAX 5

int LerNumeroValido() {
    int num;

    printf("Digite uma opcao: ");
    scanf("%d", &num);

    while (getchar() != '\n');

    if (num < MIN || num > MAX) {
        printf("Opcao invalida! Tente novamente.\n");
        return LerNumeroValido();
    } else {
        return num;
    }
}
