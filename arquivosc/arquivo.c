#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../arquivosh/contato.h"

int ultimoID = 0;

//funçao para salvar todos os contatos no arquivo
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

// função para carregar contatos do arquivo
int carregarContatos(Contato agenda[]) {
    FILE *file = fopen("contatos.csv", "r");
    if (!file) return 0;

    int qtd = 0;
    char linha[512];

    while (fgets(linha, sizeof(linha), file)) {

        linha[strcspn(linha, "\n")] = '\0';

        Contato c;
        char *token;
        int campo = 0;

        c.quantidadeTelefones = 0;

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
                        strncpy(c.telefone[campo - 6], token, sizeof(c.telefone[0]) - 1);
                        c.telefone[campo - 6][sizeof(c.telefone[0]) - 1] = '\0';
                    }
                    break;
            }
            campo++;
            token = strtok(NULL, ";");
        }

        if (c.IDPessoa > ultimoID) ultimoID = c.IDPessoa;

        agenda[qtd++] = c;
    }

    fclose(file);
    return qtd;
}

void salvarEdicao(Contato *agenda, int quantidade)
{
    FILE *arquivo = fopen("contatos.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar edicoes.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {

        fprintf(arquivo, "%d;%s;%s;%s;%s;%d",
            agenda[i].IDPessoa,
            agenda[i].nome,
            agenda[i].dataNascimento,
            agenda[i].cpf,
            agenda[i].email,
            agenda[i].quantidadeTelefones
        );

        // salvar os telefones no arquivo
        for (int t = 0; t < agenda[i].quantidadeTelefones; t++) {
            fprintf(arquivo, ";%s", agenda[i].telefone[t]);
        }

        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Edicao salva com sucesso!\n");
}