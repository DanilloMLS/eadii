#ifndef __HASHENCADEADO_H__
#define __HASHENCADEADO_H__


#include <stdlib.h>
#include <stdio.h>
#define tam 50
//estrutura hash
typedef struct hash{
	int chave;
	struct Hash *prox;
}Hash;

typedef Hash* Tabela[tam];

void criarHash(Tabela tabela);
int funcao(int k);
void inserir(Tabela tabela, int k);
void imprimir(Tabela tabela);
Hash *busca(Tabela tabela, int k);
void remover(Tabela tabela, int k);

#endif // __HASHENCADEADO_H__
