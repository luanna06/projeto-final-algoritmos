#include <stdio.h>
#include "contato.h"

void salvarContato(Contato c) {
    FILE *file = fopen("contatos.csv", "a"); // "a" = adiciona no fim do arquivo
    if (file != NULL) {
        fprintf(file, "%s;%s;%s;%s;%s\n",
                c.nome,
                c.dataNascimento,
                c.cpf,
                c.email,
                c.telefone);
        fclose(file);
        printf("Contato salvo com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo para salvar o contato.\n");
    }
}
