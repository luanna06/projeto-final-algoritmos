#ifndef CONTATO_H
#define CONTATO_H

typedef struct {
    char nome[100];
    char telefone[50][15];
    int quantidadeTelefones;
    char email[100];
    char cpf[12];
    char dataNascimento[11];
    int IDPessoa;
} Contato;


int BuscarContatoPorNome(const Contato *agenda, int quantidade, const char *nome);
int BuscarContatoPorID(const Contato *agenda, int quantidade, int id);

void cadastrarContato(Contato agenda[], int *qtd);
int carregarContatos(Contato agenda[]);
void salvarContatos(Contato agenda[], int qtd);


#endif
