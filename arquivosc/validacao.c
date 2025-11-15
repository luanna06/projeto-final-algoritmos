#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../arquivosh/validacao.h"
#include "../arquivosh/contato.h"
#include "../arquivosh/cadastrar.h"


int LerNumeroValido(int max, int min) {
    int num;
    char buffer[50];

    while (1) {
        printf("Digite uma opcao: ");
        fgets(buffer, sizeof(buffer), stdin);

        // verifica se é número válido
        if (sscanf(buffer, "%d", &num) == 1) {
            if (num >= min && num <= max) {
                return num;
            }
        }

        printf("Opcao invalida! Tente novamente.\n");
    }
}



bool ValidarNome(const char *nome) {
    int tamanho = strlen(nome);

    if (tamanho < 3 || tamanho > 30) {
        printf("Nome invalido! Deve ter entre 3 e 30 caracteres.\n");
        return false;
    }

    bool temEspaco = false;
    bool palavraAntesDoEspaco = false;
    bool palavraDepoisDoEspaco = false;

    for (int i = 0; i < tamanho; i++) {
        char c = nome[i];

        // Verificação se possui somente letras
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (temEspaco)
                palavraDepoisDoEspaco = true;
            else
                palavraAntesDoEspaco = true;
        }
        // Verifica se é espaço
        else if (c == ' ') {
            temEspaco = true;
        }
        // Se for qualquer outro caractere
        else {
            printf("Nome invalido! Deve conter apenas letras e espacos.\n");
            return false;
        }
    }

    if (!palavraAntesDoEspaco || !palavraDepoisDoEspaco) {
        printf("Nome invalido! Deve conter pelo menos um nome e um sobrenome.\n");
        return false;
    }

    return true;
}

bool ValidarTelefone(const char *telefone){
    int tamanho = strlen(telefone);
    if(tamanho != 11){
        printf("Telefone invalido! Deve ter 11 caracteres.\n");
        return false;
    }

    for(int i = 0; i < tamanho; i++){
        if(telefone[i] < '0' || telefone[i] > '9'){
            printf("Telefone invalido! Deve conter apenas numeros.\n");
            return false;
        }
    }
    return true;

}

bool ValidarEmail(const char *email) {
    int tamanho = strlen(email);

    if (tamanho < 10 || tamanho > 30) {
        printf("Email invalido! Deve ter entre 10 e 30 caracteres.\n");
        return false;
    }

    const char *arroba = strchr(email, '@');
    if (arroba == NULL || arroba == email || arroba == email + tamanho - 1) {
        printf("Email invalido! Deve conter um caractere '@' valido.\n");
        return false;
    }

    const char *ponto = strrchr(arroba, '.');
    if (ponto == NULL || ponto == arroba + 1 || ponto == email + tamanho - 1) {
        printf("Email invalido! Deve conter um ponto ('.') apos o '@'.\n");
        return false;
    }

    return true;
}

bool ValidarCPF(const char *cpf) {
    int tamanho = strlen(cpf);

    if (tamanho != 11) {
        printf("CPF invalido! Deve ter 11 caracteres.\n");
        return false;
    }

    for (int i = 0; i < tamanho; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            printf("CPF invalido! Deve conter apenas numeros.\n");
            return false;
        }
    }

    for(int i =0; i <10; i++) {
        char repetido[12];
        for(int j =0; j <11; j++) {
            repetido[j] = i + '0';
        }
        repetido[11] = '\0';
        if (strcmp(cpf, repetido) == 0) {
            printf("CPF invalido! Nao pode conter todos os digitos iguais.\n");
            return false;
        }
    }
    
    for(int i = 0; i < 2; i++) {
        int soma = 0;
        int peso = 10 + i;

        for (int j = 0; j < 9 + i; j++) {
            soma += (cpf[j] - '0') * peso;
            peso--;
        }

        int resto = soma % 11;
        int digitoVerificador = (resto < 2) ? 0 : 11 - resto;

        if (digitoVerificador != (cpf[9 + i] - '0')) {
            printf("CPF invalido! Digito verificador incorreto.\n");
            return false;
        }
    }
    return true;
}

bool ValidarDataNascimento(const char *dataNascimento) {
    if (strlen(dataNascimento) != 10) {
        printf("Data de nascimento invalida! Deve estar no formato DD/MM/AAAA.\n");
        return false;
    }

    int dia, mes, ano;
    if (sscanf(dataNascimento, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
        printf("Data de nascimento invalida! Deve estar no formato DD/MM/AAAA.\n");
        return false;
    }

    if (ano < 1900 || ano > 2025) {
        printf("Ano invalido! Deve estar entre 1900 e 2025.\n");
        return false;
    }

    if (mes < 1 || mes > 12) {
        printf("Mes invalido! Deve estar entre 1 e 12.\n");
        return false;
    }

    int diasNoMes;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31; break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30; break;
        case 2:
            diasNoMes = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28; break;
        default:
            diasNoMes = 0; 
    }

    if (dia < 1 || dia > diasNoMes) {
        printf("Dia invalido! Deve estar entre 1 e %d para o mes %d.\n", diasNoMes, mes);
        return false;
    }

    return true;
}

int BuscarContatoPorNome(const Contato *agenda, int quantidadeContatos, const char *nome) {
    for (int i = 0; i < quantidadeContatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            return i; 
        }
    }
    return -1; 
}

int BuscarContatoPorID(const Contato *agenda, int quantidadeContatos, int IDPessoa) {
    for (int i = 0; i < quantidadeContatos; i++) {
        if (agenda[i].IDPessoa == IDPessoa) {
            return i; 
        }
    }
    return -1; 
}

