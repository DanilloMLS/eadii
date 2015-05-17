#include "hashencadeado.h"

//cria e inicia a hash
void criarHash(Tabela tabela){
	int i;
	for(i=0;i<tam;i++){
		tabela[i] = NULL;
	}
}

//funcao de hash: metodo da divisao
int funcao(int k){
	return (k%tam);
}

//insere uma chave k na hash
void inserir(Tabela tabela, int k){
	int i = 0;
	int chave = funcao(k);
	Hash *aux = tabela[chave];
	while(aux != NULL){
		if(aux->chave == k){//impede a insercao de duas chaves iguais
			break;
		}
		aux = aux->prox;
	}
	if(aux == NULL){//inicializa os atributos e insere a chave
		aux = (Hash*)malloc(sizeof(Hash));
		aux->chave = k;
		aux->prox = tabela[chave];
		tabela[chave] = aux;
	}
}

//imprime a tabela hash
void imprimir(Tabela tabela){
	int i = 0, cont = 0;
	for(i=0;i<tam;i++){
		if(tabela[i] != NULL){
			printf("\n %d",tabela[i]->chave);
			Hash *aux = tabela[i]->prox;
			while(aux != NULL){
				printf("-> %3d",aux->chave);
				aux = aux->prox;
			}
		}
	}
}

//busca uma chave na tabela hash
Hash *busca(Tabela tabela, int k){
	int pos = funcao(k);
	Hash *aux;
	if(tabela[pos] != NULL){
		if(tabela[pos]->chave == k){
			return tabela[pos];
		}
		else{
			aux = tabela[pos]->prox;
			while(aux != NULL && aux->chave!= k){
				aux = aux->prox;
			}
			return(aux);
		}
	}	
	else{
		return NULL;
	}
}


//remove uma chave da hash
void remover(Tabela tabela, int k){
	int pos = funcao(k);
	Hash *aux;
	if(tabela[pos] != NULL){
		if(tabela[pos]->chave == k){
			aux = tabela[pos];
			tabela[pos] = tabela[pos]->prox;
			free(aux);
		}
		else{
			aux = tabela[pos]->prox;
			Hash *ant = tabela[pos];
			while(aux != NULL && aux->chave != k){//procura a chave para remocao
				ant = aux;
				aux = aux->prox;
			}
			if(aux != NULL){
				ant->prox = aux->prox;
				free(aux);
			}
			else{
				printf("\nNao encontrado!");
			}
		}
	}
	else{
		printf("\nNao encontrado!");
	}
}
