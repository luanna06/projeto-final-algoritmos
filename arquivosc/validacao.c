#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../arquivosh/validacao.h"
#include "../arquivosh/contato.h"


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

bool ValidarNome(const char *nome){
    int tamanho = strlen(nome);
    if(tamanho > 2 || tamanho < 30){
        printf("Nome invalido! Deve ter entre 2 e 30 caracteres.\n");
        return false;
    }
    return true;
}