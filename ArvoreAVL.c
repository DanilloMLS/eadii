#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no* pai;
    struct no* esq;
    struct no* dir;
} no;

iniciar (){
    return NULL;
}

no *busca (no *n, int ch){
    if (ch==n->chave || n==NULL){
        return n;
    }
    if (ch<n->chave){
        return busca(n->esq,ch);
    }
    else{
        return busca(n->dir,ch);
    }
}

no *minimo (no *n){
    while (n->esq != NULL){
        n = n->esq;
    }
    return n;
}

no *maximo (no *n){
    while (n->dir != NULL){
        n = n->dir;
    }
    return n;
}

no *sucessor (no *n){
    if (n->dir != NULL){
        return minimo(n->dir);
    }
    no p = n->pai;
    while (p != NULL && n == p->dir){
        n = p;
        p = p->pai;
    }
    return p;
}

no *antecessor (no *n){
    if (n->esq != NULL){
        return maximo(n->esq);
    }
    p = n->pai;
    while (p != NULL && n == p->esq){
        n = p;
        p = p->pai;
    }
    return p;
}

no *inserir (no *n, int ch){
    
}

no *remover (no *n, int ch){
    
}

