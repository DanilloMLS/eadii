#ifndef __HASHENDABERTO_H__
#define __HASHENDABERTO_H__


#include <stdlib.h>
#include <stdio.h>

//estrutura hash
typedef struct hash{
	int chave;
	char livre;//L-livre, O-ocupado, R-removido
}Hash;

Hash *criarHash(int tamanho);
int funcao(int k, int m, int i);
void inserir(Hash *h, int m, int k);
int busca(Hash *h, int m, int k, int i);
int remover(Hash *h, int m, int k);
void imprimir(Hash *h, int m);

#endif // __HASHENDABERTO_H__
