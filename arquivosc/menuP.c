#include <stdio.h>
#include <stdio.h>
#include "menuP.h"
#include "Cadastrar.h"
#include "Editar.h"
#include "Excluir.h"
#include "Consultar.h"
#include "contato.h"

void exibirmenu() {
    printf("1. Cadastrar\n");
    printf("2. Editar\n");
    printf("3. Excluir\n");
    printf("4. Consultar\n");
    printf("5. Sair\n");
}

void menuCadastro(int opcao, Contato *contato) {
    switch(opcao) {
        case 1:
        cadastrar(*contato);
        break;

        case 2:
        editar();
        break;

        case 3:
        excluir();
        break;

        case 4:
        consultar();
        break;

        case 5:
        printf("Saindo...\n");
    }
}