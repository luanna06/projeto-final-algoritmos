#include <stdio.h>
#include "validacao.h"
#include "arquivosh/menuP.h"
#include "Cadastrar.h"
#include "Editar.h"
#include "Excluir.h"
#include "Consultar.h"
#include "arquivosh/contato.h"

int main() {

Contato contato;
int opcao;

    do {
    exibirmenu();
    opcao = LerNumeroValido(5, 1);
    printf("Voce escolheu a opcao: %d\n", opcao);
    menuCadastro(opcao, &contato);

    int c;
    if(opcao != 5){
        printf("Pressione Enter para continuar...\n");
        while ((c = getchar()) != '\n' && c != EOF);
        getchar();
    }

    } while (opcao != 5);
    return 0;
    }
    
