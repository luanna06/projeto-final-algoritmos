#include <stdio.h>
#include <stdlib.h>
#include "../arquivosh/menuP.h"
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"
#include "../arquivosh/consultar.h"
#include "../arquivosh/editar.h"
#include "../arquivosh/excluir.h"
#include "../arquivosh/validacao.h"

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
        cadastrar(contato);
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