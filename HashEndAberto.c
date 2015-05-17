#include "hashendaberto.h"

//cria e inicializa a hash
Hash *criarHash(int tamanho){
	Hash *temp;
	int i;
	if((temp = (Hash*)malloc(tamanho*sizeof(Hash))) != NULL){
		for(i=0;i<tamanho;i++){
			temp[i].livre = 'L';//todas as suas posicoes estao livres
		}
		return temp;
	}
	else{
		return 0;
	}
}

//funcao de hash, no caso uma Tentativa linear
int funcao(int k, int m, int i){ 
    return ((k+i)%m);
}

//insere uma chave k na hash h de tamanho m
void inserir(Hash *h, int m, int k){
    int j, i = 0;

    do 
    { //encontra uma posicao apropriada para insercao
        j = funcao(k, m, i); 
        if(h[j].livre == 'L' || h[j].livre == 'R'){
            h[j].chave = k; 
            h[j].livre = 'O'; 
            printf("\nElemento inserido com sucesso!"); 
            return; 
        } 
        else 
            i++; 
    }while(i < m); 
    printf("\nTabela cheia!"); 
}

//busca uma chave na hash
int busca(Hash *h, int m, int k, int i){
	int j;
	if(i<m){
		j = funcao(k,m,i);
		if(h[j].livre == 'L'){//nao encontrou a chave
			return -1;
		}
		else{
			if(h[j].livre == 'R'){//usa recursao para acessar uma outra posicao
				return busca(h,m,k,i+1);
			}
			else{
				if(h[j].chave == k){//encontrou a chave
					return j;
				}
				else{
					return busca(h,m,k,i+1);//usa recursao para acessar uma outra posicao
				}
			}
		}
	}
	return -1;
}

//marca uma chave como removida
int remover(Hash *h, int m, int k){
    int i;

    i = busca(h, m, k, 0);

    if(i == -1) 
        return -1; 
    else 
    { 
        h[i].livre = 'R';
        return 1;
    } 
}

//imprime a estrutura hash
void imprimir(Hash *h, int m){
	int i;
	for(i=0;i<m;i++){
		if(h[i].livre=='O'){
			printf("\n%d",h[i].chave);
		}
	}
}
