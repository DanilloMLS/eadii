#include "avl.h"

//calcula a altura da árvore com base no nó dado
int alt(no *raiz){
	int altesq, altdir;
	if (raiz == NULL){//se a árvore estiver vazia
		return 0;
	}
	else{
        //chamadas recursivas que percorrem a árvore calculando a altura
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
//calcula o fator de balanceamento, que será usado para determinar 
//se é ou não necessário balancear a árvore
int fb(no *raiz){
	return (alt(raiz->dir) - alt(raiz->esq));
}
//efetua uma rotação simples a esquerda
no *rotEsq(no *raiz){
	no *aux = NULL;
	aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;
	return aux;
}
//efetua uma rotação simples a direita
no *rotDir(no *raiz){
	no *aux = NULL;
	aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;
	return aux;
}
//função que balanceia a árvore se acordo com o fator de balanceamento
no *bl(no *raiz){
	if (raiz->fb == -2){//lado esquerdo mais alto
		if (raiz->esq->fb == 1) //se essa condição for verdadeira será feita uma rotação dupla à direita
			raiz->esq = rotEsq(raiz->esq); 
		raiz = rotDir(raiz);
	}
	else if (raiz->fb == 2){//lado direito mais alto
			if (raiz->dir->fb == -1)//se essa condição for verdadeira será feita uma rotação dupla à esquerda
				raiz->dir = rotDir(raiz->dir);
			raiz = rotEsq(raiz);
	}
	return raiz;
}

//insere um novo nó na árvore
no *inserirNo(no *raiz, int valor){
	no *novo = (no*)malloc(sizeof(no));
	if (!raiz){//se a árvore estiver vazia ou quando a posição correta for encontrada o nó é criado
		novo->esq = NULL;
		novo->dir = NULL;
		novo->chave = valor;
		novo->fb = 0;
		return novo;
	}
	else{
		if (raiz->chave == valor){ //testa se valor passado como parâmentro é igual a chave
			printf("valor ja existe!\n");
			return raiz;
		}
		//percorre a árvore para encontrar o local apropriado para inserir o novo nó
		if (valor < raiz->chave){
			raiz->esq = inserirNo(raiz->esq,valor);
		}
		else{
			raiz->dir = inserirNo(raiz->dir,valor);
		}
		//calcula o fator de balanceamento e balanceia a árvore
		raiz->fb = fb(raiz);
		raiz = bl(raiz);
		return raiz;
	}
}
//função que remove um nó da árvore, recebe a raiz da árvore
//e a chave do nó que se quer remover como parâmetros
no *remover(no *raiz, int valor){
	no *aux = NULL;
	//testa se a chae dada é igual à chave do nó
	if (raiz->chave == valor){
		if (raiz->esq == NULL && raiz->dir == NULL){ //se o nó não tem filhos
			free(raiz);
			return NULL;
		}
		else if (raiz->esq == NULL){ //se o nó tem um filho a direita
			aux = raiz->dir;
			free(raiz);
			return aux;
		}
		else if (raiz->dir == NULL){ //se o nó tem um filho a esquerda
			aux = raiz->esq;
			free(raiz);
			return aux;
		}
		else{ // se o nó tem os dois filhos
			aux = maximo(raiz->esq);
			raiz->chave = aux->chave;
			raiz->esq = remover(raiz->esq,raiz->chave);
			free(aux);
			return raiz;
		}
	}
	/*testa se o nó a ser removido é maior ou menor que o nó que
      está sendo percorrido no momento*/
	if (raiz->chave < valor){
        raiz->dir = remover(raiz->dir,valor);
    }
    else{
        raiz->esq = remover(raiz->esq,valor);
    }
    //calcula o fator de balanceamento e balanceia a árvore
    raiz -> fb = fb(raiz);
    raiz = bl(raiz);
    return raiz;
}


//busca um nó passando sua chave e a raiz da árvore como parâmetro
no *buscarNo(no *raiz, int valor){
	no *aux = raiz;
	if (aux != NULL){
		if (aux->chave == valor){
			return aux;
		}
		if (valor < aux->chave){//percorre a árvore
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


//impressão em ordem
void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d \n",raiz->chave);
        emOrdem(raiz->dir);
    }
}

//impressão em pré-ordem
void preOrdem(no *raiz){
    if (raiz != NULL){
        printf("%d \n",raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
//impressão em pós-ordem
void posOrdem(no *raiz){
    if (raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d \n",raiz->chave);
    }
}


//retorna o nó de menor chave da subárvore dada
no *minimo(no *raiz){
	no *aux = raiz;
	while (aux->esq != NULL){
		aux = aux->esq;
	}
	return aux;
}

//retorna o nó de maior chave da subárvore dada
no *maximo(no *raiz){
	no *aux = raiz;
	while (aux->dir != NULL){
		aux = aux->dir;
	}
	return aux;
}

//retorna o sucessor do nó dado
no *sucessor(no* raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		if (aux->dir != NULL){
			return minimo(aux->dir);
		}
	}
	return aux;	
}

//retorna o nó antecessor do nó dado
no *antecessor(no *raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		if (aux->esq != NULL){
			return maximo(aux->esq);
		}
	}
	return aux;	
}
