
#ifndef CADASTRAR_H
#define CADASTRAR_H

#include "contato.h"

void cadastrar(Contato *agenda, int *quantidadeContatos);
void CadastroPessoa(Contato *contato, Contato agenda[], int quantidadeContatos);
void CadastroTelefone(Contato *agenda, int quantidadeContatos);
void salvarTodosContatos(Contato *agenda, int quantidade);

#endif
