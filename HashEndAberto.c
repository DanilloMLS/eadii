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

int main(){
	int m, i, k; 
    int resp; 
    Hash *h;

    printf("\nEntre com o tamanho da tabela: "); 
    scanf("%d", &m); 
    h = criarHash(m);

    while(1) 
    { 
        printf("\nInserir(1) Buscar(2) Remover(3) Imprimir(4) Sair(5)\n"); 
        scanf("%d",&resp);
        switch(resp) 
        { 
            case 1: 
                printf("\nEntre com o numero a ser inserido na tabela: "); 
                scanf("%d", &k); 
                inserir(h, m, k); 
                break; 
            case 2: 
                printf("\nEntre com o numero a ser buscado na tabela: "); 
                scanf("%d", &k); 
                i = busca(h, m, k, 0); 
                if(i == -1)
                    printf("\nNumero nao encontrado!"); 
                else 
                    printf("\nNumero encontrado!"); 
                break; 
            case 3: 
                printf("\nEntre com o numero a ser removido da tabela: "); 
                scanf("%d", &k); 
                i = remover(h, m, k); 
                if(i == -1) 
                    printf("\nNumero nao encontrado!"); 
                else 
                    printf("\nNumero removido com sucesso!"); 
                break; 
            case 4:
            	printf("\nListagem dos elementos: ");
            	imprimir(h,m);
            	break;
            case 5: 
                exit(0);
                break;
      }
   }
}
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
