#include "floyd.h"

void iniciaMatrizAdj(int matriz[tamanho][tamanho]){
	int i,j;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
            if(i != j){
                matriz[i][j] = 32767;
            }
			else{
                matriz[i][j] = 0;
			}
		}
	}
}

void incluiAresta(int matriz[tamanho][tamanho], int a, int b, int peso){
    int i,j;
    if(peso == 0 || peso == 32767){
        printf("O peso nao deve ser zero nem 32767\n");
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

int grau(int matriz[tamanho][tamanho], int a){
    int i,cont;
    cont = 0;
    if(a >= tamanho || a < 0){
        printf("Vertice nao existe\n");
        return -1;
    }
    else{
        for(i=0;i<tamanho;i++){
            if(matriz[a][i] != 0 || matriz[a][i] != 32767){
                cont++;
            }
        }
    }
    return cont;
}

void imprimeMatriz(int matriz[tamanho][tamanho]){
	int i,j,c;
    printf("\n");
	for(i=0;i<tamanho;i++){
        printf("%d -> ",i);
        for(j=0;j<tamanho;j++){
            if(matriz[i][j] != 32767){
                printf("%d ",matriz[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void imprimeAdj(int matriz[tamanho][tamanho]){
    int i,j,c;
    printf("\n");
	for(i=0;i<tamanho;i++){
        printf("%d -> ",i);
        for(j=0;j<tamanho;j++){
            if(matriz[i][j] != 0 || matriz[i][j] != 32767){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

//encontra a distancia entre cada par de vertices
void floyd(int matriz[tamanho][tamanho]){
    int i,j,k;
    int matMin[tamanho][tamanho];//matriz que guarda as distancias

    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            matMin[i][j] = matriz[i][j];
        }
    }

	//encontra as distancias entre dois vertices i e j, passando por um vertice k
    for (k = 0; k < tamanho; k++) {
        for (i = 0; i < tamanho; i++) {
            for (j = 0; j < tamanho; j++) {
                if(matMin[i][j] > matMin[i][k] + matMin[k][j]){
                    matMin[i][j] = matMin[i][k] + matMin[k][j];
                }
            }
        }
    }

	//imprime as distancias
    for(i=0;i<tamanho;i++){
        printf("%d->",i);
        for(j=0;j<tamanho;j++){
            if(matMin[i][j] == 32767){
                printf("0 ");
            }
            else{
                printf("%d ",matMin[i][j]);
            }
        }
        printf("\n");
    }
}
