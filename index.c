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
    exibirmenu();
    int opcao = LerNumeroValido(5, 1);
    printf("Voce escolheu a opcao: %d\n", opcao);
    menuCadastro(opcao, &contato);



    return 0;
}
