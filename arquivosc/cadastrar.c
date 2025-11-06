#include "cadastrar.h"
#include <stdio.h>
#include "validacao.h"
#include "contato.h"

#include <stdbool.h>
 
void cadastrar(Contato **contato){
    printf("1. Pessoa\n");
    printf("2. Telefone\n");
    printf("3. Retornar\n");
    int opcao2;
    opcao2 =  LerNumeroValido(3, 1);

    switch(opcao2) {
        case 1:
        CadastroPessoa(*contato);
        break;

        case 2:
        printf("Cadastro de Telefone selecionado.\n");
        break;

        case 3:
        printf("Retornando ao menu principal...\n");
        break;
    }
}

void CadastroPessoa(Contato *contato){
    bool dadosValidos = false;
    while(!dadosValidos){
         printf("Digite o nome da pessoa: ");
        scanf("%49s", contato->nome);
        
    }
}










