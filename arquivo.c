#include <stdio.h>
#include "contato.h"

void salvarContato(Contato c) {
    FILE *file = fopen("contatos.csv", "w");
    if (file != NULL) {
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
        printf("Contato salvo com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo para salvar o contato.\n");
    }
}