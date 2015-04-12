#include <stdio.h> 
#include <stdLib.h>

typedef struct no 
{
    int chave;
    int fb;
    struct no *esq;
    struct no *dir;
    
}no;

no *maximo(no *raiz);

int alt(no *raiz){
	int altesq, altdir;
	if (raiz == NULL){
		return 0;
	}
	else{
		altesq = alt(raiz->esq);
		altdir = alt(raiz->dir);
		if (altesq < altdir){
			return altesq+1;
		}
		else{
			return altdir+1;
		}
	}
}

int fb(no *raiz){
	return (alt(raiz->dir) - alt(raiz->dir));
}

no *rotEsq(no *raiz){
	no *aux = NULL;
	aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;
	return aux;
}

no *rotDir(no *raiz){
	no *aux = NULL;
	aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;
	return aux;
}

no *bl(no *raiz){
	if (raiz->fb == -2){
		if (raiz->esq->fb == 1)
			raiz->esq = rotDir(raiz->esq);
		raiz = rotEsq(raiz);
	}
	else{
		if (raiz->fb == 2){
			if (raiz->dir->fb == -1)
				raiz->dir = rotEsq(raiz->dir);
			raiz = rotEsq(raiz);
		}
	}
	return raiz;
}

no *inserirNo(no *raiz, int valor){
	no *novo = (no*)malloc(sizeof(no));
	if (!raiz){
		novo->esq = NULL;
		novo->dir = NULL;
		novo->chave = valor;
		novo->fb = 0;
		return novo;
	}
	else{
		if (raiz->chave == valor){
			printf("valor ja existe!\n");
			return raiz;
		}
		if (valor < raiz->chave){
			raiz->esq = inserirNo(raiz->esq,valor);
		}
		else{
			raiz->dir = inserirNo(raiz->dir,valor);
		}
		raiz->fb = fb(raiz);
		raiz = bl(raiz);
		return raiz;
	}
}

no *remover(no *raiz, int valor){
	no *aux = NULL;
	if (raiz->chave == valor){
		if (raiz->esq == NULL && raiz->dir == NULL){
			free(raiz);
			return NULL;
		}
		else if (raiz->esq == NULL){
			aux = raiz->dir;
			free(raiz);
			return aux;
		}
		else if (raiz->dir == NULL){
			aux = raiz->esq;
			free(raiz);
			return aux;
		}
		else{
			aux = maximo(raiz->esq);
			raiz->chave = aux->chave;
			raiz->esq = remover(raiz->esq,raiz->chave);
			free(aux);
			return raiz;
		}
	}
	if (raiz->chave < valor){
        raiz->dir = remover(raiz->dir,valor);
    }
    else{
        raiz->esq = remover(raiz->esq,valor);
    }
    raiz -> fb = fb(raiz);
    return raiz;
}



no *buscarNo(no *raiz, int valor){
	no *aux = raiz;
	if (aux != NULL){
		if (aux->chave == valor){
			return aux;
		}
		if (valor < aux->chave){
			return buscarNo(aux->esq,valor);
		}
		else{
			return buscarNo(aux->dir,valor);
		}
	}
	else{
		return NULL;
	}
}

void imprimeBusca(no *raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		printf("Encontrado: %d",aux->chave);
	}
	else{
		printf("Nao encontrado");
	}
}



void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d \n",raiz->chave);
        emOrdem(raiz->dir);
    }
}

void preOrdem(no *raiz){
    if (raiz != NULL){
        printf("%d \n",raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz){
    if (raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d \n",raiz->chave);
    }
}



no *minimo(no *raiz){
	no *aux = raiz;
	while (aux->esq != NULL){
		aux = aux->esq;
	}
	return aux;
}

no *maximo(no *raiz){
	no *aux = raiz;
	while (aux->dir != NULL){
		aux = aux->dir;
	}
	return aux;
}

no *sucessor(no* raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		if (aux->dir != NULL){
			return minimo(aux->dir);
		}
	}
	return aux;	
}

no *antecessor(no *raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		if (aux->esq != NULL){
			return maximo(aux->esq);
		}
	}
	return aux;	
}

int main(){
    no *avl = NULL;
    int num, op;
    do{
        printf("\n\t\t Menu \n");
        printf("\t\t   1-Inserir \n");
        printf("\t\t   2-Imprimir em Ordem \n");
        printf("\t\t   3-Imprimir em Pre-Ordem \n");
        printf("\t\t   4-Imprimir em Pos-Ordem \n");
        printf("\t\t   5-Excluir \n");
        printf("\t\t   6-Altura \n");
        printf("\t\t   7-Sair \n");
        printf("\n\tOpcao: ");
        scanf("%d",&op);
        switch(op){
            case 1: printf("\tNumero: ");
                    scanf("%d",&num);
                    avl = inserirNo(avl,num);
                    break;
            case 2: if (!avl){
                        printf("\tArvore Vazia\n");
                        break;
                    }
                    printf("\tArvore em Ordem\n");
                    emOrdem(avl);
                    break;
            case 3: if (!avl){
                        printf("\tArvore Vazia\n");
                        break;
                    }
                    printf("\tArvore em pre-Ordem\n");
                    preOrdem(avl);
                    break;
            case 4: if (!avl){
                        printf("\tArvore Vazia\n");
                        break;
                    }
                    printf("\tArvore em pos-Ordem\n");
                    posOrdem(avl);
                    break;
            case 5: if(!avl){
                        printf("\tArvore vazia\n");
                        break;
                    }
                    printf("\tNumero: \n");
                    scanf("%d",&num);
                    avl = remover(avl,num);
                    printf("\tExcluido.\n");
                    break;
            case 6: if(!avl){
                        printf("\tArvore vazia\n");
                        break;
                    }
                    num = alt(avl);
                    printf("\tAltura da arvore: %d\n",num);
                    break;
            case 7: exit(0);
            default: printf("\topcao invalida!\n");
        }
        getch();
        system("cls");
    }while(op!=7);
}
