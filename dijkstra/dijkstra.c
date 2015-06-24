#include "dijkstra.h"

//inclui uma aresta no grafo
void incluiAresta(int matriz[tamanho][tamanho], int a, int b, int peso){
    int i,j;
    if(peso < 1 || peso >= 32767){
        printf("O peso deve ser maior que 0 e menor que 32767\n");
        return;
    }
    if(a == b){
        printf("Um vertice nao pode ser ligado com ele mesmo\n");
        return;
    }
    if((a >= 0 && b >= 0) && (a < tamanho && b < tamanho)){
        matriz[a][b] = matriz[b][a] = peso;
    }
    else{
        printf("Pelo menos um dos vertices nao existe\n");
        return;
    }
}

//remove uma aresta
void removeAresta(int matriz[tamanho][tamanho], int a, int b){
    int i,j;
    if(a == b){
        printf("Um vertice nao pode estar ligado com ele mesmo por uma aresta\n");
        return;
    }
    if((a > tamanho) || (b > tamanho)){
        printf("Um dos vertices nao existe\n");
        return;
    }
    else{
        matriz[a][b] = matriz[b][a] = 32767;
        printf("Removido\n");
    }
}

//retorna o grau de um vertice
int grau(int matriz[tamanho][tamanho], int a){
    int i,cont;
    cont = 0;
    if(a >= tamanho || a < 0){
        printf("Vertice nao existe\n");
        return -1;
    }
    else{
        for(i=0;i<tamanho;i++){
            if(matriz[a][i] > 0 || matriz[a][i] <= 32767){
                cont++;
            }
        }
    }
    return cont;
}

//imprime a matriz de pesos
void imprimeMatriz(int matriz[tamanho][tamanho]){
	int i,j,c;
    printf("\n");
	for(i=0;i<tamanho;i++){
        printf("%d -> ",i);
        for(j=0;j<tamanho;j++){
        	if(matriz[i][j] == 32767){
        		printf("0 ");
        	}
        	else{
        		printf("%d ",matriz[i][j]);
        	}
        }
        printf("\n");
    }
}

//imprime a matriz de adjacencias
void imprimeAdj(int matriz[tamanho][tamanho]){
    int i,j,c;
    printf("\n");
	for(i=0;i<tamanho;i++){
        printf("%d -> ",i);
        for(j=0;j<tamanho;j++){
            if(matriz[i][j] > 0 && matriz[i][j] < 32767){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void dijkstra(int matriz[tamanho][tamanho], int origem){
	int i,j,v,dist[tamanho],prev[tamanho],visitado[tamanho],atual;
	
	for(i=0;i<tamanho;i++){
		dist[i] = 32767;//distancia de i ate a origem
		visitado[i] = 0;//vertice i visitado ou nao
		prev[i] = -1;//vertice anterior ao vertice i
	}
	dist[origem] = 0;//distancia da origem ate ela mesma
	atual = origem;
	
	while(atual != -1){//enquanto houver vertice que pode ser visitado
		visitado[atual] = 1;//vertice que esta sendo visitado
		
		for(i=0;i<tamanho;i++){
			if(dist[atual] + matriz[atual][i] < dist[i]){//comparacao de distancias
				dist[i] = dist[atual] + matriz[atual][i];
				prev[i] = atual;
			}
		}
		
		atual = -1;
		int minDist = 32767;//guarda a distancia minima
		for(i=0;i<tamanho;i++){//verifica os vertices ja visitados e escolhe o que tem menor distancia para uma nova interacao
			if(visitado[i] != 1 && dist[i] < minDist){
				atual = i;
				minDist = dist[i];
			}
		}
	}
	
	//imprime a lista de distancias
	printf("Distancias a partir de %d (nossa origem):\n",origem);
	for(i=0;i<tamanho;i++){
		printf("Vertice %d: ",i);
		printf("%d ",dist[i]);
		if(prev[i] != -1){
			v = prev[i];
			printf("-> ");
			while(v != -1){
				printf("%d ",v);
				v = prev[v];
			}
		}
		printf("\n");
	}
}
