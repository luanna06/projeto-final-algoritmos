
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"
#include "../arquivosh/validacao.h"

void CadastroPessoa(Contato *contato);

// Função principal de cadastro
void cadastrar(Contato *contato) {
    printf("1. Pessoa\n");
    printf("2. Telefone\n");
    printf("3. Retornar\n");

    int opcao2 = LerNumeroValido(3, 1);

    switch(opcao2) {
        case 1:
            CadastroPessoa(contato); 
            break;

        case 2:
            printf("Cadastro de Telefone selecionado.\n");
            break;

        case 3:
            printf("Retornando ao menu principal...\n");
            break;
    }
}

// Função auxiliar para cadastrar uma pessoa
bool ValidarNome(const char *nome);

void CadastroPessoa(Contato *contato) {
    bool dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite o nome da pessoa: ");
        scanf("%49s", contato->nome);

        dadosValidos = ValidarNome(contato->nome);
    }

    printf("Pessoa cadastrada com sucesso\n", contato->nome);
}







