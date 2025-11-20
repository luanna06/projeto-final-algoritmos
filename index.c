#include <stdio.h>
#include "validacao.h"
#include "Cadastrar.h"
#include "Editar.h"
#include "Excluir.h"
#include "Consultar.h"
#include "arquivosh/contato.h"
#include "../arquivosh/arquivo.h"

int main() {

    Contato agenda[100];
    int quantidadeContatos = carregarContatos(agenda);

    int opcao;

    do {
        printf("*** Menu Principal ***\n");
        printf("1. Cadastrar\n");
        printf("2. Editar\n");
        printf("3. Excluir\n");
        printf("4. Consultar\n");
        printf("5. Sair\n");
        opcao = LerNumeroValido(5, 1);
        printf("Voce escolheu a opcao: %d\n", opcao);

        switch (opcao) {
            case 1:
                cadastrar(agenda, &quantidadeContatos);
                break;

            case 2:
                editar(agenda, quantidadeContatos);
                break;

            case 3:
                excluir(agenda, &quantidadeContatos);
                break;

            case 4:
                consultar(agenda, quantidadeContatos);
                break;

            case 5:
                salvarContatos(agenda, quantidadeContatos);
                printf("Saindo do programa!\n");
                break;
        }

    } while (opcao != 5);

    return 0;
}

    
