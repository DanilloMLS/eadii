#ifndef __RN_H__
#define __RN_H__

#include <stdio.h> 
#include <stdLib.h>

typedef struct no{
	int chave;
	char cor;
	struct no *pai;
	struct no *esq;
	struct no *dir;
}no;

no *criaNovoNoh();
void rotEsq(no *T, no *x);
void rotDir(no *T, no *x);
no *inserir(no *T, no *z);
void inserirCor(no *T, no *z);
no *criaNovoNoh();
void visitarEmOrdem(no* T);
void visitarPreOrdem(no* T);
void visitarPosOrdem(no* T);
void mostraDadosNoh(no* z);
int menu();
int calcularAlturaPreta(no *z);

#endif // __RN_H__
