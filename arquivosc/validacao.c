#include <stdio.h>
#include "validacao.h"


int LerNumeroValido(int max, int min) {
    int num;

    printf("Digite uma opcao: ");
    scanf("%d", &num);

    while (getchar() != '\n');

    if (num < min || num > max) {
        printf("Opcao invalida! Tente novamente.\n");
        return LerNumeroValido(max, min);
    } else {
        return num;
    }
}

int menu (int i){
    
}
