#include <stdio.h>
#include <string.h>
#include "../arquivosh/validacao.h"
#include "../arquivosh/consultar.h"
#include "../arquivosh/contato.h"

void consultar(Contato *agenda, int quantidadeContatos){
    int opcao, c;

    do {
        printf("\n*** Menu de Consulta ***\n");
        printf("1. Pessoa\n");
        printf("2. Telefone\n");
        printf("3. Retornar\n");

        printf("Escolha uma opcao: ");
        scanf("%d", opcao);

        switch(opcao){

            case 1: {
                int opcaoPessoa;

                printf("\n*** Consultar Pessoa ***\n");
                printf("1. Consultar por Nome\n");
                printf("2. Consultar por ID\n");
                printf("3. Retornar\n");

                opcaoPessoa = LerNumeroValido(3, 1);

                switch(opcaoPessoa){

                    //consultar pessoa por nome
                    case 1: {
                        char nomeBusca[31];

                        printf("Digite o nome da pessoa: ");
                        fgets(nomeBusca, sizeof(nomeBusca), stdin);
                        nomeBusca[strcspn(nomeBusca, "\n")] = 0;

                        int indice = BuscarContatoPorNome(agenda, quantidadeContatos, nomeBusca);
                        if(indice == -1){
                            printf("Contato nao encontrado!\n");
                        } else {
                            printf("\n*** Contato Encontrado ***\n");
                            printf("ID: %d\n", agenda[indice].IDPessoa);
                            printf("Nome: %s\n", agenda[indice].nome);
                            printf("Data de Nascimento: %s\n", agenda[indice].dataNascimento);
                            printf("CPF: %s\n", agenda[indice].cpf);
                            printf("Email: %s\n", agenda[indice].email);
                            printf("Telefones:\n");
                            for(int i = 0; i < agenda[indice].quantidadeTelefones; i++){
                                printf("- %s\n", agenda[indice].telefone[i]);
                            }
                        }
                        break;
                    }

                    // consultar pessoa por ID
                    case 2: {
                        int idBusca;
                        printf("Digite o ID da pessoa: ");
                        scanf(" %d", &idBusca);

                        int indice = BuscarContatoPorID(agenda, quantidadeContatos, idBusca);
                        if(indice == -1){
                            printf("Contato nao encontrado!\n");
                        } else {
                            printf("\n*** Contato Encontrado ***\n");
                            printf("ID: %d\n", agenda[indice].IDPessoa);
                            printf("Nome: %s\n", agenda[indice].nome);
                            printf("Data de Nascimento: %s\n", agenda[indice].dataNascimento);
                            printf("CPF: %s\n", agenda[indice].cpf);
                            printf("Email: %s\n", agenda[indice].email);
                            printf("Telefones:\n");
                            for(int i = 0; i < agenda[indice].quantidadeTelefones; i++){
                                printf("- %s\n", agenda[indice].telefone[i]);
                            }
                        }
                        break;
                    }

                    case 3:
                        printf("Retornando...\n");
                        break;
                        default:
                        printf("Opcao invalida! Tente novamente.\n");
                }

                break;
            }

            case 2: {
                int opcaoTel;

                printf("\n*** Consultar Telefone ***\n");
                printf("1. Consultar telefone por Nome\n");
                printf("2. Consultar telefone por ID\n");
                printf("3. Retornar\n");

                printf("Escolha uma opcao: ");
                scanf(" %d", &opcaoTel);    

                switch(opcaoTel){

                    //consultar telefone por nome
                    case 1: {
                        char nomeBusca[31];

                        printf("Digite o nome da pessoa: ");
                        fgets(nomeBusca, sizeof(nomeBusca), stdin);
                        nomeBusca[strcspn(nomeBusca, "\n")] = 0;

                        int indice = BuscarContatoPorNome(agenda, quantidadeContatos, nomeBusca);
                        if(indice == -1){
                            printf("Contato nao encontrado!\n");
                        } else {
                            if(agenda[indice].quantidadeTelefones == 0){
                                printf("Esse contato nao possui telefones cadastrados.\n");
                            } else {
                                printf("\nTelefones cadastrados:\n");
                                for(int i = 0; i < agenda[indice].quantidadeTelefones; i++){
                                    printf("- %s\n", agenda[indice].telefone[i]);
                                }
                            }
                        }
                        break;
                    }

                    //consultar telefone por ID
                    case 2: {
                        int idBusca;

                        printf("Digite o ID da pessoa: ");
                        scanf(" %d", &idBusca);
                        while((c = getchar()) != '\n' && c != EOF);

                        int indice = BuscarContatoPorID(agenda, quantidadeContatos, idBusca);
                        if(indice == -1){
                            printf("Contato nao encontrado!\n");
                        } else {
                            if(agenda[indice].quantidadeTelefones == 0){
                                printf("Esse contato nao possui telefones cadastrados.\n");
                            } else {
                                printf("\nTelefones cadastrados:\n");
                                for(int i = 0; i < agenda[indice].quantidadeTelefones; i++){
                                    printf("- %s\n", agenda[indice].telefone[i]);
                                }
                            }
                        }
                        break;
                    }
                    case 3:
                        printf("Retornando...\n");
                        break;
                }
                break;
            }
            case 3:
                printf("Voltando ao menu de Consulta...\n");
                break;
                default:
                printf("Opcao invalida! Tente novamente.\n");   
        }
    } while(opcao != 3);
}