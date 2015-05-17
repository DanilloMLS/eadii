#include "avl.h"

//calcula a altura da �rvore com base no n� dado
int alt(no *raiz){
	int altesq, altdir;
	if (raiz == NULL){//se a �rvore estiver vazia
		return 0;
	}
	else{
        //chamadas recursivas que percorrem a �rvore calculando a altura
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
//calcula o fator de balanceamento, que ser� usado para determinar 
//se � ou n�o necess�rio balancear a �rvore
int fb(no *raiz){
	return (alt(raiz->dir) - alt(raiz->esq));
}
//efetua uma rota��o simples a esquerda
no *rotEsq(no *raiz){
	no *aux = NULL;
	aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;
	return aux;
}
//efetua uma rota��o simples a direita
no *rotDir(no *raiz){
	no *aux = NULL;
	aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;
	return aux;
}
//fun��o que balanceia a �rvore se acordo com o fator de balanceamento
no *bl(no *raiz){
	if (raiz->fb == -2){//lado esquerdo mais alto
		if (raiz->esq->fb == 1) //se essa condi��o for verdadeira ser� feita uma rota��o dupla � direita
			raiz->esq = rotEsq(raiz->esq); 
		raiz = rotDir(raiz);
	}
	else if (raiz->fb == 2){//lado direito mais alto
			if (raiz->dir->fb == -1)//se essa condi��o for verdadeira ser� feita uma rota��o dupla � esquerda
				raiz->dir = rotDir(raiz->dir);
			raiz = rotEsq(raiz);
	}
	return raiz;
}

//insere um novo n� na �rvore
no *inserirNo(no *raiz, int valor){
	no *novo = (no*)malloc(sizeof(no));
	if (!raiz){//se a �rvore estiver vazia ou quando a posi��o correta for encontrada o n� � criado
		novo->esq = NULL;
		novo->dir = NULL;
		novo->chave = valor;
		novo->fb = 0;
		return novo;
	}
	else{
		if (raiz->chave == valor){ //testa se valor passado como par�mentro � igual a chave
			printf("valor ja existe!\n");
			return raiz;
		}
		//percorre a �rvore para encontrar o local apropriado para inserir o novo n�
		if (valor < raiz->chave){
			raiz->esq = inserirNo(raiz->esq,valor);
		}
		else{
			raiz->dir = inserirNo(raiz->dir,valor);
		}
		//calcula o fator de balanceamento e balanceia a �rvore
		raiz->fb = fb(raiz);
		raiz = bl(raiz);
		return raiz;
	}
}
//fun��o que remove um n� da �rvore, recebe a raiz da �rvore
//e a chave do n� que se quer remover como par�metros
no *remover(no *raiz, int valor){
	no *aux = NULL;
	//testa se a chae dada � igual � chave do n�
	if (raiz->chave == valor){
		if (raiz->esq == NULL && raiz->dir == NULL){ //se o n� n�o tem filhos
			free(raiz);
			return NULL;
		}
		else if (raiz->esq == NULL){ //se o n� tem um filho a direita
			aux = raiz->dir;
			free(raiz);
			return aux;
		}
		else if (raiz->dir == NULL){ //se o n� tem um filho a esquerda
			aux = raiz->esq;
			free(raiz);
			return aux;
		}
		else{ // se o n� tem os dois filhos
			aux = maximo(raiz->esq);
			raiz->chave = aux->chave;
			raiz->esq = remover(raiz->esq,raiz->chave);
			free(aux);
			return raiz;
		}
	}
	/*testa se o n� a ser removido � maior ou menor que o n� que
      est� sendo percorrido no momento*/
	if (raiz->chave < valor){
        raiz->dir = remover(raiz->dir,valor);
    }
    else{
        raiz->esq = remover(raiz->esq,valor);
    }
    //calcula o fator de balanceamento e balanceia a �rvore
    raiz -> fb = fb(raiz);
    raiz = bl(raiz);
    return raiz;
}


//busca um n� passando sua chave e a raiz da �rvore como par�metro
no *buscarNo(no *raiz, int valor){
	no *aux = raiz;
	if (aux != NULL){
		if (aux->chave == valor){
			return aux;
		}
		if (valor < aux->chave){//percorre a �rvore
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


//impress�o em ordem
void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d \n",raiz->chave);
        emOrdem(raiz->dir);
    }
}

//impress�o em pr�-ordem
void preOrdem(no *raiz){
    if (raiz != NULL){
        printf("%d \n",raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
//impress�o em p�s-ordem
void posOrdem(no *raiz){
    if (raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d \n",raiz->chave);
    }
}


//retorna o n� de menor chave da sub�rvore dada
no *minimo(no *raiz){
	no *aux = raiz;
	while (aux->esq != NULL){
		aux = aux->esq;
	}
	return aux;
}

//retorna o n� de maior chave da sub�rvore dada
no *maximo(no *raiz){
	no *aux = raiz;
	while (aux->dir != NULL){
		aux = aux->dir;
	}
	return aux;
}

//retorna o sucessor do n� dado
no *sucessor(no* raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		if (aux->dir != NULL){
			return minimo(aux->dir);
		}
	}
	return aux;	
}

//retorna o n� antecessor do n� dado
no *antecessor(no *raiz, int valor){
	no *aux = buscarNo(raiz,valor);
	if (aux != NULL){
		if (aux->esq != NULL){
			return maximo(aux->esq);
		}
	}
	return aux;	
}
