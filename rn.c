#include "rn.h"

//faz rotacao a esquerda
void rotEsq(no *T, no *x){
    no *y;
    y = x->dir;
    x->dir = y->esq;
    if(x->dir != NULL){
        x->dir->pai = x;
    }
    if(y->esq != NULL){
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if(x->pai == NULL){//se o pai de x for nulo, y sera a nova raiz
        T = y;
    }
    else if((x->pai->esq != NULL) && (x == x->pai->esq)){
        x->pai->esq = y;
    }
    else{
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
    T->pai = NULL;
}

//faz rotacao a direita
void rotDir(no *T, no *x){
    no *y;
    y = x->esq;
    x->esq = y->dir;
    if(y->dir != NULL){
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if(x->pai == NULL){//se o pai de x for nulo, y sera a nova raiz
        T = y;
    }
    else if((x->pai->dir != NULL) && (x == x->pai->dir)){
        x->pai->dir = y;
    }
    else{
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
    T->pai = NULL;
}

//insere um novo no na arvore
no *inserir(no *T, no *z){
	no *y = NULL;
	no *x = T;
	
	//informacoes do novo no (z)
    z->esq = NULL;
    z->dir = NULL;
    z->cor = 'V';
    
    while(x != NULL){//procura a posicao apropriada para z
        y = x;
        if(z->chave < x->chave){
            x = x->esq;
        }
        else{
            x = x->dir;
        }
    }

    z->pai = y;
    if(y == NULL){//z sera a raiz se a arvore estiver vazia
        T = z;
    }
    else if (z->chave < y->chave){
        y->esq = z;
    }
    else{
        y->dir = z;
    }
    
    inserirCor(T,z);
    return T;
}

//faz o balancemento da arvore e insere a cor
void inserirCor(no *T, no *z){
    no *y;
    
    while((z->pai != NULL) && (z->pai->cor == 'V')){
        if((z->pai->pai->esq != NULL) && (z->pai == z->pai->pai->esq)){//Se o pai de z for filho a esquerda do avo de z
            if(z->pai->pai->dir != NULL){//verifica se z tem um tio e o armazena em y
                y = z->pai->pai->dir;
            }
            if((y != NULL) && (y->cor == 'V')){//verifica a cor do tio de z
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                if(z->pai->pai != NULL){
                    z = z->pai->pai;
                }
            }
            else{
                if((z->pai->dir != NULL) && (z == z->pai->dir)){//verifica se z e filho a direita do pai dele
                    z = z->pai;
                    rotEsq(T,z);//Rotacao dupla a direita
                }
                z->pai->cor = 'P';
                z->pai->pai->cor = 'V';
                rotDir(T,z->pai->pai);
            }
        }
        else{
            if(z->pai->pai->esq != NULL){//verifica se z tem um tio e o armazena em y
                y = z->pai->pai->esq;
            }
            if((y != NULL) && (y->cor == 'V')){//verifica a cor do tio de z
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                if(z->pai->pai != NULL){
                    z = z->pai->pai;
                }
            }
            else{
                if((z->pai->esq != NULL) && (z == z->pai->esq)){//verifica se z e filho a esquerda do pai dele
                    z = z->pai;
                    rotDir(T,z);//Rotacao dupla a esquerda
                }
                z->pai->cor = 'P';
                z->pai->pai->cor = 'V';
                rotEsq(T,z->pai->pai);
            }
        }
    }
    T->cor = 'P';
}

//cria um novo no
no *criaNovoNoh(){
    no *novo = (no*)malloc(sizeof(no));
    printf("Informe um numero para a Arvore...: ");
    scanf("%d", &novo->chave);
    return novo;
}

void visitarEmOrdem(no* T){
    if (T != NULL){
        visitarEmOrdem(T->esq);
        mostraDadosNoh(T);
        visitarEmOrdem(T->dir);
    }
}

void visitarPreOrdem(no* T){
    if (T != NULL){
        mostraDadosNoh(T);
        visitarPreOrdem(T->esq);
        visitarPreOrdem(T->dir);
    }
}

void visitarPosOrdem(no* T){
    if (T != NULL){
        visitarPosOrdem(T->esq);
        visitarPosOrdem(T->dir);
        mostraDadosNoh(T);
    }
}

void mostraDadosNoh(no* T){
    printf("Endereco do noh....................: %p\n", T);
    printf("Valor do noh.......................: %d\n", T->chave);
    printf("Cor do noh.........................: %c\n\n", T->cor);
    printf("Pai do noh.........................: %p\n", T->pai);
    printf("Filho da esquerda..................: %p\n", T->esq);
    printf("Filho da direita...................: %p\n\n", T->dir);
    printf("\n\n");
}

int menu(){
    int opcao;

    printf("1.Inserir noh na arvore...:\n");
    printf("2.Mostrar arvore (em Ordem):\n");
    printf("3.Mostrar arvore (pre Ordem):\n");
    printf("4.Mostrar arvore (pos Ordem):\n");
    printf("5.Calcular altura preta...:\n");
    printf("0.Sair do programa........:\n");
    printf("?: ");

    scanf("%d", &opcao);
    return opcao;
}

//calcula a altura da arvore
int calcularAlturaPreta(no *z){
    int alt_esquerda = 0, alt_direita = 0;

    if(!z){
        return 0;
    }

    if (z == NULL){
        return 1;
    }

    if (z->cor == 'P'){
        alt_esquerda += calcularAlturaPreta(z->esq);
        alt_direita +=  calcularAlturaPreta(z->dir);
    }
    else{
        calcularAlturaPreta(z->esq);
        calcularAlturaPreta(z->dir);
    }

    if (alt_esquerda > alt_direita){
        return alt_esquerda + 1;
    }
    else{
        return alt_direita + 1;
    }
}
