
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"
#include "../arquivosh/validacao.h"

void CadastroPessoa(Contato *contato);
void salvarContato(Contato c);


// Função principal de cadastro
void cadastrar(Contato *contato) {
    printf("*** Menu de Cadastro ***\n");
    printf("1. Pessoa\n");
    printf("2. Telefone\n");
    printf("3. Retornar\n");

    int opcao2 = LerNumeroValido(3, 1);

    switch(opcao2) {
        case 1:
            CadastroPessoa(contato); 
            break;

        case 2:
            printf("Funcao de cadastro de telefone ainda nao implementada.\n");
            break;

        case 3:
            printf("Retornando ao menu principal...\n");
            break;
    }
}

bool ValidarNome(const char *nome);
bool ValidarTelefone(const char *telefone);
bool ValidarEmail(const char *email);
bool ValidarCPF(const char *cpf);
bool ValidarDataNascimento(const char *dataNascimento);

void CadastroPessoa(Contato *contato) {

    // Cadastro do nome
    bool dadosValidos = false;
    while(!dadosValidos) {
        printf("*** Cadastro de Informacoes Pessoais ***\n");
        printf("Digite o nome da pessoa: ");
        scanf(" %49[^\n]", contato->nome);

        dadosValidos = ValidarNome(contato->nome);
    }

    printf("Nome cadastrado com sucesso!\n", contato->nome);

    //Data de nascimento 
    dadosValidos = false;
    while(!dadosValidos) {
        printf("*** Cadastro de Data de Nascimento ***\n");
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %10s", contato->dataNascimento);

        dadosValidos = ValidarDataNascimento(contato->dataNascimento); 
    }

    printf("Data de nascimento cadastrada com sucesso!\n", contato->dataNascimento);

    //Cadastro de CPF
    dadosValidos = false;
    while(!dadosValidos) {
        printf("*** Cadastro de CPF ***\n");
        printf("Digite o CPF (apenas numeros): ");
        scanf(" %11s", contato->cpf);

        dadosValidos = ValidarCPF(contato->cpf);
    }
    printf("CPF cadastrado com sucesso!\n", contato->cpf);

    // Cadastro do email
    dadosValidos = false;
    while(!dadosValidos) {
    printf("*** Cadastro de Email ***\n");
    printf("Digite o email: ");
    scanf(" %30s", contato->email);

    dadosValidos = ValidarEmail(contato->email);
    }

    printf("Email cadastrado com sucesso!\n", contato->email);

    // Cadastro do telefone
    char escolha;
    printf("Voce deseja cadastrar um telefone? 's' para sim, 'n' para nao: ");
    scanf(" %c", &escolha);

    if(escolha == 's' || escolha == 'S'){
    dadosValidos = false;   
    while(!dadosValidos) {
        printf("*** Cadastro de Telefone ***\n");
        printf("Digite o numero de telefone: DDD + Numero (apenas numeros): ");
        scanf("%14s", contato->telefone);

        dadosValidos = ValidarTelefone(contato->telefone);  
    }
    }
    else {
        printf("Cadastro finalizado sem adicionar telefone adicional.\n");
    }
    printf("Cadastro concluido com sucesso!\n");

    salvarContato(*contato);

    printf("Pressione ENTER para voltar ao menu principal...");
    getchar(); 
    getchar(); 
}







