#ifndef contato_h
#define contato_h

#include "contato.h"

typedef struct {
    char nome[100];
    char telefone[15];
    char email[100];
    char cpf[12];
    char dataNascimento[11];
    int IDPessoa;
} Contato;

#endif