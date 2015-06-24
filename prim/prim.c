#include "prim.h"

//inicializa a matriz de adjacencias
void iniciaMatrizAdj(int matriz[tamanho][tamanho]){
	int i,j;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			matriz[i][j] = 0;
		}
	}
}

//inclui uma aresta
void incluiAresta(int matriz[tamanho][tamanho], int a, int b, int peso){
    int i,j;
    if(peso < 1){
        printf("O peso deve ser maior que 0\n");
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
        matriz[a][b] = matriz[b][a] = 0;
        printf("Removido\n");
    }
}

//imprime o grau de um vertice
int grau(int matriz[tamanho][tamanho], int a){
    int i,cont;
    cont = 0;
    if(a >= tamanho || a < 0){
        printf("Vertice nao existe\n");
        return -1;
    }
    else{
        for(i=0;i<tamanho;i++){
            if(matriz[a][i] > 0){
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
            printf("%d ",matriz[i][j]);
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
            if(matriz[i][j] != 0){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void prim(int matriz[tamanho][tamanho], int raiz){
    int i,j,k,cont = 0,h = 0;
    int visitado[tamanho];
    int matMinima[tamanho][tamanho];

    for(i=0;i<tamanho;i++){//inicializando a matriz minima
        for(j=0;j<tamanho;j++){
            matMinima[i][j] = 0;
        }
    }

    for(i=0;i<tamanho;i++){//definindo a quantia de arestas do grafo
        for(j=i;j<tamanho;j++){
            if(i != j){
                cont++;
            }
        }
    }

    for(i=0;i<tamanho;i++){//lista de vertices visitados
        visitado[i] = 0;
    }
    visitado[raiz] = 1;

    int arestas[cont][3];//criando e inicializando a lista de arestas
    for(i=0;i<cont;i++){
        for(j=0;j<3;j++){
            arestas[i][j] = 0;
        }
    }

    int b;
    int menorPeso[3];
    for(k=0;k<tamanho-1;k++){//para cada interação pode ser colocada uma aresta
        h = b = 0;
        for(i=0;i<tamanho;i++){
            for(j=i;j<tamanho;j++){//encontra vizinhos do vertice e preenche a lista de arestas
                if(matriz[i][j] != 0 && i != j){
                    if(visitado[i] == 1 && visitado[j] == 0){
                        arestas[h][0] = matriz[i][j];
                        arestas[h][1] = i;
                        arestas[h][2] = j;
                        h++;
                        b = 1;
                    }
                    else if(visitado[i] == 0 && visitado[j] == 1){
                        arestas[h][0] = matriz[i][j];
                        arestas[h][1] = i;
                        arestas[h][2] = j;
                        h++;
                        b = 1;
                    }
                }
            }
        }
        if(b == 1){//no caso de ao menos um vertice ter sido encontrado
            menorPeso[0] = arestas[0][0];
            menorPeso[1] = arestas[0][1];
            menorPeso[2] = arestas[0][2];
            for(i=0;i<cont;i++){
                if(arestas[i][0] < menorPeso[0] && arestas[i][0] != 0){//escolhe a aresta de menor peso entre um vertice visitado e um nao visitado
                    menorPeso[0] = arestas[i][0];
                    menorPeso[1] = arestas[i][1];
                    menorPeso[2] = arestas[i][2];
                }
            }
            matMinima[menorPeso[1]][menorPeso[2]] = menorPeso[0];//coloca o vertice na matriz minima
            visitado[menorPeso[1]] = visitado[menorPeso[2]] = 1;
            b = 0;
            for(i=0;i<cont;i++){//zera a lista de arestas para uma nova interacao
                for(j=0;j<3;j++){
                    arestas[i][j] = 0;
                }
            }
        }
    }

    for(i=0;i<tamanho;i++){//matriz simetrica
        for(j=0;j<tamanho;j++){
            matMinima[j][i] = matMinima[i][j];
        }
    }

    for(i=0;i<tamanho;i++){//imprime
        for(j=0;j<tamanho;j++){
            printf("%d ",matMinima[i][j]);
        }
        printf("\n");
    }
}
