#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "contato.h"

int carregarContatos(Contato agenda[]);
void salvarContatos(Contato agenda[], int qtd);
void salvarEdicao(Contato agenda[], int qtd);

#endif
