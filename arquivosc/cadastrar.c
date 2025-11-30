#include <stdio.h>
#include <stdbool.h>
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"
#include "../arquivosh/validacao.h"
#include "../arquivosh/arquivo.h"

void cadastrar(Contato *agenda, int *quantidadeContatos) {

    int opcao2;

    do {
        printf("*** Menu de Cadastro ***\n");
        printf("1. Pessoa\n");
        printf("2. Telefone\n");
        printf("3. Retornar\n");

        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao2);  

        switch(opcao2) {

            case 1: {
                CadastroPessoa(&agenda[*quantidadeContatos], agenda, *quantidadeContatos);
                (*quantidadeContatos)++;
                salvarContatos(agenda, *quantidadeContatos);
                break;
            }

            case 2:
                CadastroTelefone(agenda, *quantidadeContatos);
                break;

            case 3:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");   
        }

    } while(opcao2 != 3);
}

void CadastroPessoa(Contato *contato, Contato agenda[], int quantidadeContatos) {

    bool dadosValidos = false;
    int c;

    while(!dadosValidos) {
        printf("*** Cadastro de Informacoes Pessoais ***\n");
        printf("Digite o nome da pessoa: ");
        scanf(" %99[^\n]", contato->nome);

        if (nomeJaExiste(agenda, quantidadeContatos, contato->nome)) {
            printf("Ja existe um contato cadastrado com esse nome.\n");
            continue;
        }
        dadosValidos = ValidarNome(contato->nome);
    }
    printf("Nome cadastrado com sucesso!\n");

    dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %10s", contato->dataNascimento);
        dadosValidos = ValidarDataNascimento(contato->dataNascimento);
    }
    printf("Data cadastrada com sucesso!\n");

    dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite o CPF (apenas numeros): ");
        scanf(" %11s", contato->cpf);
        dadosValidos = ValidarCPF(contato->cpf);
    }
    printf("CPF cadastrado com sucesso!\n");

    dadosValidos = false;
    while(!dadosValidos) {
        printf("Digite o email: ");
        scanf(" %99s", contato->email);
        dadosValidos = ValidarEmail(contato->email);
    }
    printf("Email cadastrado com sucesso!\n");

    dadosValidos = false;
    while (!dadosValidos)
    {
    printf("Digite o telefone (DDD + numero): ");
    scanf(" %14s", contato->telefone[0]);     // primeiro telefone
    dadosValidos = ValidarTelefone(contato->telefone[0]);
    }
    printf("Telefone cadastrado com sucesso!\n");

    contato->quantidadeTelefones = 1;  // já cadastrou o primeiro

char escolha = 's';

while (1) {

    printf("Deseja cadastrar outro telefone? (s/n): ");
    scanf(" %c", &escolha);

    // validação da resposta
    if (escolha == 'n' || escolha == 'N') {
        break; // sai do loop
    }

    if (escolha != 's' && escolha != 'S') {
        printf("Opcao invalida! Digite apenas 's' ou 'n'.\n");
        continue; // volta e pergunta de novo
    }

    // se chegou aqui, escolha é 's'
    int i = contato->quantidadeTelefones;

    dadosValidos = false;
    while (!dadosValidos) {
        printf("Digite o telefone (DDD + numero): ");
        scanf(" %14s", contato->telefone[i]);
        dadosValidos = ValidarTelefone(contato->telefone[i]);
    }

    contato->quantidadeTelefones++;
    printf("Telefone cadastrado com sucesso!\n");
}

    contato->IDPessoa = ++ultimoID;

    printf("Cadastro concluido!\n");
}   

void CadastroTelefone(Contato *agenda, int quantidadeContatos) {

    int opcao3;
    bool dadosValidos = false;
    char nomeBusca[50];

    do {
        printf("\n*** Cadastro de Telefone ***\n");
        printf("1. Cadastrar por nome\n");
        printf("2. Cadastrar por ID\n");
        printf("3. Retornar\n");

        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao3);

        switch(opcao3) {

        case 1: {
            printf("Digite o nome: ");
            scanf(" %49[^\n]", nomeBusca);     // leitura correta

            int pos = BuscarContatoPorNome(agenda, quantidadeContatos, nomeBusca);
            if (pos == -1) {
                printf("Contato nao encontrado!\n");
                break;
            }

            if (agenda[pos].quantidadeTelefones >= 5) {
                printf("Limite maximo de telefones atingido!\n");
                break;
            }

            int indice = agenda[pos].quantidadeTelefones;

            dadosValidos = false;
            while (!dadosValidos) {
                printf("Digite o novo telefone: ");
                scanf(" %14s", agenda[pos].telefone[indice]);

                dadosValidos = ValidarTelefone(agenda[pos].telefone[indice]);

                if (!dadosValidos) {
                    printf("Telefone invalido! Tente novamente.\n");
                }
            }

            agenda[pos].quantidadeTelefones++;
            printf("Telefone cadastrado!\n");
            salvarContatos(agenda, quantidadeContatos);

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

            if (agenda[pos].quantidadeTelefones >= 5) {
                printf("Limite maximo de telefones atingido!\n");
                break;
            }

            int indice = agenda[pos].quantidadeTelefones;

            dadosValidos = false;
            while (!dadosValidos) {
                printf("Digite o novo telefone: ");
                scanf(" %14s", agenda[pos].telefone[indice]);

                dadosValidos = ValidarTelefone(agenda[pos].telefone[indice]);

                if (!dadosValidos) {
                    printf("Telefone invalido! Tente novamente.\n");
                }
            }

            agenda[pos].quantidadeTelefones++;
            printf("Telefone cadastrado!\n");
            salvarContatos(agenda, quantidadeContatos);

            break;
        }
        case 3:
            printf("Retornando ao menu de anterior...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao3 != 3);
}
