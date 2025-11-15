#include <stdio.h>
#include "validacao.h"
#include "arquivosh/menuP.h"
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
        exibirmenu();
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
                printf("Encerrando...\n");
                break;
        }

        int c;
        if(opcao != 5){
            printf("Pressione Enter para continuar...\n");
            while ((c = getchar()) != '\n' && c != EOF);
            getchar();
        }

    } while (opcao != 5);

    return 0;
}

    
