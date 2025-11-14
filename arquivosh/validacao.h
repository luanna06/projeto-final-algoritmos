#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <stdbool.h>
#include "contato.h"


int LerNumeroValido(int max, int min);

// validacoes
bool ValidarNome(const char *nome);
bool ValidarTelefone(const char *telefone);
bool ValidarEmail(const char *email);
bool ValidarCPF(const char *cpf);
bool ValidarDataNascimento(const char *dataNascimento);

// buscas
int BuscarContatoPorNome(const Contato *agenda, int quantidade, const char *nome);
int BuscarContatoPorID(const Contato *agenda, int quantidade, int id);

#endif
