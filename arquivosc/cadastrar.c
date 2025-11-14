
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"
#include "../arquivosh/validacao.h"

// Agenda principal
Contato agenda[100];
int quantidadeContatos = 0;

void CadastroPessoa(Contato *contato);
void salvarContato(Contato c);
void CadastroTelefone(Contato *agenda , int quantidadeContatos);

int opcao2;

//menu cadastro principal
void cadastrar(Contato *contato) {
    do {
        printf("*** Menu de Cadastro ***\n");
        printf("1. Pessoa\n");
        printf("2. Telefone\n");
        printf("3. Retornar\n");

        opcao2 = LerNumeroValido(3, 1);

        switch(opcao2) {
            case 1:
                CadastroPessoa(contato);
                break;

            case 2:
                CadastroTelefone(agenda, quantidadeContatos);
                break;

            case 3:
                printf("Retornando ao menu principal...\n");
                break;
        }

    } while(opcao2 != 3);
}

//funçao cadastro pessoa todos os dados
void CadastroPessoa(Contato *contato) {

    bool dadosValidos = false;

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

    // cadastro email
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
    scanf(" %c", &escolha);

    if (escolha == 's' || escolha == 'S') {

        contato->quantidadeTelefones = 0; // inicializa

        dadosValidos = false;

        while(!dadosValidos) {

            printf("Digite o telefone (DDD + numero): ");
            scanf(" %14s", contato->telefone[0]);

            dadosValidos = ValidarTelefone(contato->telefone[0]);
        }

        contato->quantidadeTelefones = 1;
    }

    printf("Cadastro concluido!\n");

    salvarContato(*contato);

    printf("Pressione ENTER para voltar...");
    getchar();
    getchar();
}


//menu telefone adicional
void CadastroTelefone(Contato *agenda, int quantidadeContatos) {

    int opcao3;
    bool dadosValidos = false;

    do {
        printf("*** Cadastro de Telefone ***\n");
        printf("1. Cadastrar por nome\n");
        printf("2. Cadastrar por ID\n");
        printf("3. Retornar\n");

        opcao3 = LerNumeroValido(3, 1);

        char nomeBusca[50];

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
            } else {
                printf("Telefone invalido.\n");
            }
            break;
        }

        } 

    } while(opcao3 != 3);
}




