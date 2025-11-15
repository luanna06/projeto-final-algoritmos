#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../arquivosh/contato.h"

// SALVAR 1 CONTATO (modo append)
void salvarContato(Contato c) {
    FILE *file = fopen("contatos.csv", "a");
    if (!file) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    // escreve os campos principais + quantidade de telefones
    fprintf(file, "%d;%s;%s;%s;%s;%d",
            c.IDPessoa,
            c.nome,
            c.dataNascimento,
            c.cpf,
            c.email,
            c.quantidadeTelefones);

    // escreve os telefones, se houver
    for (int i = 0; i < c.quantidadeTelefones; i++) {
        fprintf(file, ";%s", c.telefone[i]);
    }

    fprintf(file, "\n");
    fclose(file);
}


// CARREGAR TODOS
int carregarContatos(Contato agenda[]) {
    FILE *file = fopen("contatos.csv", "r");
    if (!file) return 0;

    int qtd = 0;
    char linha[512];

    while (fgets(linha, sizeof(linha), file)) {
        Contato c;
        char *token;
        int campo = 0;

        // Inicializa telefones
        c.quantidadeTelefones = 0;

        // separa cada campo pelo ';'
        token = strtok(linha, ";");
        while (token != NULL) {
            switch (campo) {
                case 0: c.IDPessoa = atoi(token); break;
                case 1: strncpy(c.nome, token, sizeof(c.nome)-1); c.nome[sizeof(c.nome)-1] = '\0'; break;
                case 2: strncpy(c.dataNascimento, token, sizeof(c.dataNascimento)-1); c.dataNascimento[sizeof(c.dataNascimento)-1] = '\0'; break;
                case 3: strncpy(c.cpf, token, sizeof(c.cpf)-1); c.cpf[sizeof(c.cpf)-1] = '\0'; break;
                case 4: strncpy(c.email, token, sizeof(c.email)-1); c.email[sizeof(c.email)-1] = '\0'; break;
                case 5: c.quantidadeTelefones = atoi(token); break;
                default:
                    if (campo >= 6 && campo < 6 + c.quantidadeTelefones) {
                        strncpy(c.telefone[campo - 6], token, sizeof(c.telefone[0])-1);
                        c.telefone[campo - 6][sizeof(c.telefone[0])-1] = '\0';
                    }
                    break;
            }
            campo++;
            token = strtok(NULL, ";");
        }

        agenda[qtd++] = c;
    }

    fclose(file);
    return qtd;
}




// SALVAR TODOS OS CONTATOS (reescreve arquivo)
void salvarContatos(Contato agenda[], int qtd) {
    FILE *file = fopen("contatos.csv", "w");
    if (!file) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {

        fprintf(file, "%d;%s;%s;%s;%s;%d",
                agenda[i].IDPessoa,
                agenda[i].nome,
                agenda[i].dataNascimento,
                agenda[i].cpf,
                agenda[i].email,
                agenda[i].quantidadeTelefones);

        for (int t = 0; t < agenda[i].quantidadeTelefones; t++) {
            fprintf(file, ";%s", agenda[i].telefone[t]);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}
