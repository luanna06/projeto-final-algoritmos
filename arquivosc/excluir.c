#include <stdio.h>
#include <string.h>
#include "../arquivosh/arquivo.h"
#include "../arquivosh/validacao.h"
#include "../arquivosh/excluir.h"
#include "../arquivosh/contato.h"

void excluir(Contato *agenda, int *quantidadeContatos) {
    int c;
    int opcao;

    do{
    printf("*** Menu de Exclusao ***\n");  
    printf("1. Pessoa\n");
    printf("2. Telefone\n");
    printf("3. Retornar\n");

    opcao = LerNumeroValido(3, 1);

    switch(opcao){
        case 1: 
            excluirPessoa(agenda, quantidadeContatos);
            break;
        case 2:
            excluirTelefone(agenda, *quantidadeContatos);
            break;
        case 3:
            printf("Retornando ao menu principal...\n");
            break;
    }
    } while (opcao != 3);
}

void excluirPessoa(Contato *agenda, int *quantidadeContatos){

    int c;
    int opcao;
    do{
        printf("*** Exclusao de Pessoa ***\n");
        printf("1. Excluir por Nome\n");
        printf("2. Excluir por ID\n");
        printf("3. Retornar\n");

        opcao = LerNumeroValido(3, 1);

        switch(opcao){
            case 1: {
                char nomeBusca[31];

                printf("Digite o nome da pessoa que deseja excluir: ");    //excluir por nome
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0; 

                int indice = BuscarContatoPorNome(agenda, *quantidadeContatos, nomeBusca);
                if(indice == -1){
                    printf("Contato nao encontrado!\n");
                    break;
                } 
                else {
                    for(int i = indice; i < *quantidadeContatos - 1; i++){
                        agenda[i] = agenda[i + 1];
                    }
                    (*quantidadeContatos)--;

                    salvarContatos(agenda, *quantidadeContatos);
                    printf("Contato excluido com sucesso!\n");
                }
                break;
            }

            //excluir por ID
            case 2: {
                int idBusca;

                printf("Digite o ID da pessoa que deseja excluir: "); 
                scanf(" %d", &idBusca);
                while((c = getchar()) != '\n' && c != EOF);
                
                int indiceID = BuscarContatoPorID(agenda, *quantidadeContatos, idBusca);
                if(indiceID == -1){
                    printf("Contato nao encontrado!\n");
                    break;
                } 
                else {
                    for(int i = indiceID; i < *quantidadeContatos - 1; i++){
                        agenda[i] = agenda[i + 1];
                    }
                    (*quantidadeContatos)--;

                    salvarContatos(agenda, *quantidadeContatos);

                    printf("Contato excluido com sucesso!\n");
                }
            }
                break;
            case 3:
                printf("Retornando ao menu anterior...\n");
                break;
        }
    } while(opcao != 3);
}

void excluirTelefone(Contato *agenda, int quantidadeContatos){

    int c;
    int opcao;
    do{
        printf("*** Exclusao de Telefone ***\n");
        printf("1. Excluir por Nome\n");
        printf("2. Excluir por ID\n");
        printf("3. Retornar\n");

        while((c = getchar()) != '\n' && c != EOF);
        opcao = LerNumeroValido(3, 1);

        switch(opcao){
            case 1: {
                char nomeBusca[31];

                printf("Digite o nome da pessoa cujo telefone deseja excluir: ");  //excluir telefone por nome
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0; 

                int indice = BuscarContatoPorNome(agenda, quantidadeContatos, nomeBusca);
                if(indice == -1){
                    printf("Contato nao encontrado!\n");
                    break;
                } 
                else {
                    if(agenda[indice].quantidadeTelefones == 0){
                        printf("Esse contato nao possui telefones cadastrados.\n");
                        break;
                    }

                    printf("Telefones cadastrados:\n");
                    for(int i = 0; i < agenda[indice].quantidadeTelefones; i++){
                        printf("%d - %s\n", i + 1, agenda[indice].telefone[i]);
                    }

                    int telefoneEscolhido;
                    printf("Digite o numero do telefone que deseja excluir: ");
                    telefoneEscolhido = LerNumeroValido(agenda[indice].quantidadeTelefones, 1);

                    for(int i = telefoneEscolhido - 1; i < agenda[indice].quantidadeTelefones - 1; i++){
                        strcpy(agenda[indice].telefone[i], agenda[indice].telefone[i + 1]);
                    }
                    agenda[indice].quantidadeTelefones--;

                    salvarContatos(agenda,  quantidadeContatos);
                    printf("Telefone excluido com sucesso!\n");
                }
                break;
            }
            case 2: {
                int idBusca;    //excluir telefone por ID   

                printf("Digite o ID da pessoa cujo telefone deseja excluir: "); 
                scanf(" %d", &idBusca);
                
                int indiceID = BuscarContatoPorID(agenda, quantidadeContatos, idBusca);
                if(indiceID == -1){
                    printf("Contato nao encontrado!\n");
                    break;
                } 
                else {
                    if(agenda[indiceID].quantidadeTelefones == 0){
                        printf("Esse contato nao possui telefones cadastrados.\n");
                        break;
                    }

                    printf("Telefones cadastrados:\n");
                    for(int i = 0; i < agenda[indiceID].quantidadeTelefones; i++){
                        printf("%d - %s\n", i + 1, agenda[indiceID].telefone[i]);
                    }

                    int telefoneEscolhido;
                    printf("Digite o numero do telefone que deseja excluir: ");
                    telefoneEscolhido = LerNumeroValido(agenda[indiceID].quantidadeTelefones, 1);

                    for(int i = telefoneEscolhido - 1; i < agenda[indiceID].quantidadeTelefones - 1; i++){
                        strcpy(agenda[indiceID].telefone[i], agenda[indiceID].telefone[i + 1]);
                    }
                    agenda[indiceID].quantidadeTelefones--;

                    salvarContatos(agenda, quantidadeContatos);
                    printf("Telefone excluido com sucesso!\n");
                }
                break;
            }
            case 3:
                printf("Retornando ao menu anterior...\n");
                break;
        }
    } while(opcao != 3);
}