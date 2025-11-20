#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../arquivosh/validacao.h"
#include "../arquivosh/editar.h"
#include "../arquivosh/contato.h"
#include "../arquivosh/arquivo.h"

void editarTelefonePorNome(Contato *agenda, int quantidade);
void editarTelefonePorID(Contato *agenda, int quantidade);


void editar(Contato *agenda, int quantidadeContatos) {

    int c;
    int opcao4;

    do {
        printf("*** Menu de Edicao ***\n");
        printf("1. Pessoa\n");
        printf("2. Telefone\n");
        printf("3. Retornar\n");

        while ((c = getchar()) != '\n' && c != EOF);

        opcao4 = LerNumeroValido(3, 1);

        switch(opcao4) {

            case 1: {
                printf("Editar contato por: \n");
                printf("1. Nome\n");
                printf("2. ID\n");
                printf("3. Retornar\n");

                int opcaoedicao = LerNumeroValido(3, 1);
                while ((c = getchar()) != '\n' && c != EOF);

                switch(opcaoedicao){
                    case 1: editarPorNome(agenda, quantidadeContatos); break;
                    case 2: editarPorID(agenda, quantidadeContatos); break;
                    case 3: printf("Retornando ao menu anterior...\n"); break;
                }
                break;
            }

            case 2: {
                printf("Editar telefone por: \n");
                printf("1. Nome\n");
                printf("2. ID\n");
                printf("3. Retornar\n");

                int opc = LerNumeroValido(3, 1);
                while ((c = getchar()) != '\n' && c != EOF);

                switch(opc){
                    case 1: editarTelefonePorNome(agenda, quantidadeContatos); break;
                    case 2: editarTelefonePorID(agenda, quantidadeContatos); break;
                    case 3: printf("Retornando ao menu anterior...\n"); break;
                }
                break;
            }

            case 3:
                printf("Retornando ao menu principal.\n");
                break;
        }

    } while(opcao4 != 3);
}

void editarPorNome(Contato *agenda, int quantidadeContatos) {

    int c;
    char nomeBusca[31];

    printf("Digite o nome: ");
    scanf(" %30[^\n]", nomeBusca);

    int pos = BuscarContatoPorNome(agenda, quantidadeContatos, nomeBusca);
    if (pos == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    int opcao;

    do {
        printf("\n*** Informacao que deseja editar ***\n");
        printf("1. Nome\n");
        printf("2. Data de Nascimento\n");
        printf("3. CPF\n");
        printf("4. Email\n");
        printf("5. Retornar\n");

        opcao = LerNumeroValido(5, 1);
        while ((c = getchar()) != '\n' && c != EOF);

        switch(opcao) {

            case 1: {
                char novoNome[31];
                bool valido = false;

                while (!valido) {
                    printf("Digite o novo nome: ");
                    scanf(" %30[^\n]", novoNome);

                    if (!ValidarNome(novoNome))
                        continue;

                    if (nomeJaExiste(agenda, quantidadeContatos, novoNome) &&
                        strcmp(agenda[pos].nome, novoNome) != 0)
                    {
                        printf("Erro: ja existe um contato com esse nome.\n");
                        continue;
                    }

                    strcpy(agenda[pos].nome, novoNome);
                    valido = true;
                }
                printf("Nome atualizado com sucesso!\n");
                break;
            }

            case 2: {
                char novaData[11];
                bool valido = false;

                while(!valido) {
                    printf("Digite a nova data (DD/MM/AAAA): ");
                    scanf(" %10s", novaData);
                    valido = ValidarDataNascimento(novaData);
                }

                strcpy(agenda[pos].dataNascimento, novaData);
                printf("Data de nascimento atualizada com sucesso!\n");
                break;
            }

            case 3: {
                char novoCPF[12];
                bool valido = false;

                while(!valido) {
                    printf("Digite o novo CPF: ");
                    scanf(" %11s", novoCPF);
                    valido = ValidarCPF(novoCPF);
                }

                strcpy(agenda[pos].cpf, novoCPF);
                printf("CPF atualizado com sucesso!\n");
                break;
            }

            case 4: {
                char novoEmail[100];
                bool valido = false;

                while(!valido) {
                    printf("Digite o novo email: ");
                    scanf(" %99s", novoEmail);
                    valido = ValidarEmail(novoEmail);
                }

                strcpy(agenda[pos].email, novoEmail);
                printf("Email atualizado com sucesso!\n");
                break;
            }

            case 5:
                printf("Retornando ao menu de edicao.\n");
                break;
        }

        salvarEdicao(agenda, quantidadeContatos);
        printf("Alteracoes salvas com sucesso!\n");

    } while(opcao != 5);
}


void editarPorID(Contato *agenda, int quantidadeContatos) {

    int c;
    int idBusca;

    printf("Digite o ID: ");
    scanf(" %d", &idBusca);

    int pos = BuscarContatoPorID(agenda, quantidadeContatos, idBusca);
    if (pos == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    int opcao;

    do {
        printf("\n*** Informacao que deseja editar ***\n");
        printf("1. Nome\n");
        printf("2. Data de Nascimento\n");
        printf("3. CPF\n");
        printf("4. Email\n");
        printf("5. Retornar\n");

        opcao = LerNumeroValido(5, 1);
        while ((c = getchar()) != '\n' && c != EOF);

        switch(opcao) {

            case 1: {
                char novoNome[31];
                bool valido = false;

                while (!valido) {
                    printf("Digite o novo nome: ");
                    scanf(" %30[^\n]", novoNome);

                    if (!ValidarNome(novoNome))
                        continue;

                    if (nomeJaExiste(agenda, quantidadeContatos, novoNome) &&
                        strcmp(agenda[pos].nome, novoNome) != 0)
                    {
                        printf("Erro: ja existe um contato com esse nome.\n");
                        continue;
                    }

                    strcpy(agenda[pos].nome, novoNome);
                    valido = true;
                }

                printf("Nome atualizado com sucesso!\n");
                break;
            }

            case 2: {
                char novaData[11];
                bool valido = false;

                while(!valido) {
                    printf("Digite a nova data (DD/MM/AAAA): ");
                    scanf(" %10s", novaData);
                    valido = ValidarDataNascimento(novaData);
                }

                strcpy(agenda[pos].dataNascimento, novaData);
                printf("Data de nascimento atualizada com sucesso!\n");
                break;
            }

            case 3: {
                char novoCPF[12];
                bool valido = false;

                while(!valido) {
                    printf("Digite o novo CPF: ");
                    scanf(" %11s", novoCPF);
                    valido = ValidarCPF(novoCPF);
                }

                strcpy(agenda[pos].cpf, novoCPF);
                printf("CPF atualizado com sucesso!\n");
                break;
            }

            case 4: {
                char novoEmail[100];
                bool valido = false;

                while(!valido) {
                    printf("Digite o novo email: ");
                    scanf(" %99s", novoEmail);
                    valido = ValidarEmail(novoEmail);
                }

                strcpy(agenda[pos].email, novoEmail);
                printf("Email atualizado com sucesso!\n");
                break;
            }

            case 5:
                printf("Retornando ao menu de edicao.\n");
                break;  
        }

        salvarEdicao(agenda, quantidadeContatos);
        printf("Alteracoes salvas com sucesso!\n");

    } while(opcao != 5);
}

//editar telefone por nome

void editarTelefonePorNome(Contato *agenda, int quantidade) {

    char nomeBusca[31];
    printf("Digite o nome: ");
    scanf(" %30[^\n]", nomeBusca);

    int pos = BuscarContatoPorNome(agenda, quantidade, nomeBusca);
    if (pos == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    if (agenda[pos].quantidadeTelefones == 0) {
        printf("Esse contato nao possui telefones cadastrados.\n");
        return;
    }

    printf("\nTelefones cadastrados:\n");
    for (int i = 0; i < agenda[pos].quantidadeTelefones; i++)
        printf("%d - %s\n", i+1, agenda[pos].telefone[i]);

    int escolha;
    printf("Qual telefone deseja alterar? ");
    escolha = LerNumeroValido(agenda[pos].quantidadeTelefones, 1);
    escolha--; // índice real

    char novoTelefone[15];
    printf("Digite o novo telefone: ");
    scanf(" %14s", novoTelefone);

    strcpy(agenda[pos].telefone[escolha], novoTelefone);

    salvarEdicao(agenda, quantidade);
    printf("Telefone atualizado com sucesso!\n");
}

//editar telefone por ID

void editarTelefonePorID(Contato *agenda, int quantidade) {

    int idBusca;
    printf("Digite o ID: ");
    scanf(" %d", &idBusca);

    int pos = BuscarContatoPorID(agenda, quantidade, idBusca);
    if (pos == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    if (agenda[pos].quantidadeTelefones == 0) {
        printf("Esse contato nao possui telefones cadastrados.\n");
        return;
    }

    printf("\nTelefones cadastrados:\n");
    for (int i = 0; i < agenda[pos].quantidadeTelefones; i++)
        printf("%d - %s\n", i+1, agenda[pos].telefone[i]);

    int escolha;
    printf("Qual telefone deseja alterar? ");
    escolha = LerNumeroValido(agenda[pos].quantidadeTelefones, 1);
    escolha--;

    char novoTelefone[15];
    printf("Digite o novo telefone: ");
    scanf(" %14s", novoTelefone);

    strcpy(agenda[pos].telefone[escolha], novoTelefone);

    salvarEdicao(agenda, quantidade);
    printf("Telefone atualizado com sucesso!\n");
}

