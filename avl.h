#ifndef __AVL_H__
#define __AVL_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct no 
{
    int chave;
    int fb;
    struct no *esq;
    struct no *dir;
    
}no;

no *maximo(no *raiz);
int alt(no *raiz);
int fb(no *raiz);
no *rotEsq(no *raiz);
no *rotDir(no *raiz);
no *bl(no *raiz);
no *inserirNo(no *raiz, int valor);
no *remover(no *raiz, int valor);
no *buscarNo(no *raiz, int valor);
void emOrdem(no *raiz);
void preOrdem(no *raiz);
void posOrdem(no *raiz);
no *minimo(no *raiz);
no *maximo(no *raiz);
no *sucessor(no* raiz, int valor);
no *antecessor(no *raiz, int valor);

#endif // __AVL_H__
