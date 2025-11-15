#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"
#include "../arquivosh/validacao.h"
#include "../arquivosh/arquivo.h"

// declarações de funções
void CadastroPessoa(Contato *contato, Contato agenda[], int quantidadeContatos);
void CadastroTelefone(Contato *agenda, int quantidadeContatos);

// menu cadastro
void cadastrar(Contato *agenda, int *quantidadeContatos) {

    int opcao2;
    int c; // para limpeza de buffer

    do {
        printf("*** Menu de Cadastro ***\n");
        printf("1. Pessoa\n");
        printf("2. Telefone\n");
        printf("3. Retornar\n");

        while ((c = getchar()) != '\n' && c != EOF); // limpa buffer
        opcao2 = LerNumeroValido(3, 1);

        switch(opcao2) {

            case 1: {
                CadastroPessoa(&agenda[*quantidadeContatos], agenda, *quantidadeContatos);
                (*quantidadeContatos)++;
                salvarContatos(agenda, *quantidadeContatos); // salva após adicionar pessoa
                break;
            }

            case 2:
                CadastroTelefone(agenda, *quantidadeContatos);
                // salvarContatos já chamado dentro da função CadastroTelefone
                break;

            case 3:
                printf("Retornando ao menu principal...\n");
                break;
        }

    } while(opcao2 != 3);
}

// Função CadastroPessoa
void CadastroPessoa(Contato *contato, Contato agenda[], int quantidadeContatos) {

    bool dadosValidos = false;
    int c; // para limpar buffer

    // nome
    while(!dadosValidos) {
        printf("*** Cadastro de Informacoes Pessoais ***\n");
        printf("Digite o nome da pessoa: ");
        scanf(" %99[^\n]", contato->nome);

        dadosValidos = ValidarNome(contato->nome);
    }
    printf("Nome cadastrado com sucesso!\n");

    // data de nascimento
    dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %10s", contato->dataNascimento);
        dadosValidos = ValidarDataNascimento(contato->dataNascimento);
    }
    printf("Data cadastrada com sucesso!\n");

    // CPF
    dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite o CPF (apenas numeros): ");
        scanf(" %11s", contato->cpf);
        dadosValidos = ValidarCPF(contato->cpf);
    }
    printf("CPF cadastrado com sucesso!\n");

    // email
    dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite o email: ");
        scanf(" %99s", contato->email);
        dadosValidos = ValidarEmail(contato->email);
    }
    printf("Email cadastrado com sucesso!\n");

    // telefone opcional
    char escolha;
    printf("Deseja cadastrar um telefone agora? (s/n): ");
    while ((c = getchar()) != '\n' && c != EOF); // limpa buffer
    scanf(" %c", &escolha);

    contato->quantidadeTelefones = 0;

    if (escolha == 's' || escolha == 'S') {
        dadosValidos = false;
        while(!dadosValidos) {
            printf("Digite o telefone (DDD + numero): ");
            scanf(" %14s", contato->telefone[0]);
            dadosValidos = ValidarTelefone(contato->telefone[0]);
        }
        contato->quantidadeTelefones = 1;
    }

    printf("Cadastro concluido!\n");
}

// Função CadastroTelefone
void CadastroTelefone(Contato *agenda, int quantidadeContatos) {

    int opcao3;
    bool dadosValidos = false;
    int c; // para limpar buffer
    char nomeBusca[50];

    do {
        printf("*** Cadastro de Telefone ***\n");
        printf("1. Cadastrar por nome\n");
        printf("2. Cadastrar por ID\n");
        printf("3. Retornar\n");

        while ((c = getchar()) != '\n' && c != EOF); // limpa buffer
        opcao3 = LerNumeroValido(3, 1);

        switch(opcao3) {

        case 1: {
            printf("Digite o nome: ");
            scanf(" %49[^\n]", nomeBusca);

            int pos = BuscarContatoPorNome(agenda, quantidadeContatos, nomeBusca);
            if (pos == -1) {
                printf("Contato nao encontrado!\n");
                break;
            }

            int indice = agenda[pos].quantidadeTelefones;
            printf("Digite o novo telefone: ");
            scanf(" %14s", agenda[pos].telefone[indice]);

            dadosValidos = ValidarTelefone(agenda[pos].telefone[indice]);
            if (dadosValidos) {
                agenda[pos].quantidadeTelefones++;
                printf("Telefone cadastrado!\n");
                salvarContatos(agenda, quantidadeContatos); // salva imediatamente
            } else {
                printf("Telefone invalido.\n");
            }
            break;
        }

        case 2: {
            int idBusca;
            printf("Digite o ID: ");
            scanf(" %d", &idBusca);

            int pos = BuscarContatoPorID(agenda, quantidadeContatos, idBusca);
            if (pos == -1) {
                printf("Contato nao encontrado!\n");
                break;
            }

            int indice = agenda[pos].quantidadeTelefones;
            printf("Digite o novo telefone: ");
            scanf(" %14s", agenda[pos].telefone[indice]);

            dadosValidos = ValidarTelefone(agenda[pos].telefone[indice]);
            if (dadosValidos) {
                agenda[pos].quantidadeTelefones++;
                printf("Telefone cadastrado!\n");
                salvarContatos(agenda, quantidadeContatos); // salva imediatamente
            } else {
                printf("Telefone invalido.\n");
            }
            break;
        }

        }

    } while(opcao3 != 3);
}
