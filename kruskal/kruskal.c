#include "kruskal.h"

void iniciaMatrizAdj(int matriz[tamanho][tamanho]){
	int i,j;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			matriz[i][j] = 0;
		}
	}
}

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

//Encontra a arvore geradora minima do grafo
void kruskal(int matriz[tamanho][tamanho]){
    int i,h,j,qtde,aux[3];
    qtde = 0;
    h = 0;
    aux[0] = aux[1] = aux[2] = 0;
    int vertices[tamanho][2];//lista de vertices que diferencia comp. conexos
    int matMinima[tamanho][tamanho];//matriz de adj da arvore geradora minima


    for(i=0;i<tamanho;i++){//incializa a arvore geradora minima
        for(j=0;j<tamanho;j++){
            matMinima[i][j] = 0;
        }
    }
    for(i=0;i<tamanho;i++){//inicia a lista dos vertices
        vertices[i][0] = vertices[i][1] = i;
    }
    for(i=0;i<tamanho;i++){//Define quantas arestas ha no grafo
        for(j=i;j<tamanho;j++){
            if(i != j){
                qtde++;
            }
        }
    }

    int arestas[qtde][3];//lista de arestas do grafo
    for(i=0;i<qtde;i++){
        arestas[i][0] = arestas[i][1] = arestas[i][2] = 0;
    }

    for(i=0;i<tamanho;i++){//preenchimento da lista de arestas do grafo
        for(j=i;j<tamanho;j++){
            if(i != j){
                arestas[h][0] = matriz[i][j];
                arestas[h][1] = i;
                arestas[h][2] = j;
                h++;
            }
        }
    }
    for(i=qtde-1;i>=1;i--){//ordena as arestas por peso
        for(j=0;j<i;j++){
            if(arestas[j][0] > arestas[j+1][0]){
                aux[0] = arestas[j][0];
                aux[1] = arestas[j][1];
                aux[2] = arestas[j][2];
                arestas[j][0] = arestas[j+1][0];
                arestas[j][1] = arestas[j+1][1];
                arestas[j][2] = arestas[j+1][2];
                arestas[j+1][0] = aux[0];
                arestas[j+1][1] = aux[1];
                arestas[j+1][2] = aux[2];
            }
        }
    }

    int a;//variavel auxiliar
    for(i=0;i<qtde;i++){//encontra a arvore geradora minima
        if(vertices[arestas[i][1]][1] != vertices[arestas[i][2]][1] && arestas[i][0] != 0){
            matMinima[vertices[arestas[i][1]][0]][vertices[arestas[i][2]][0]] = arestas[i][0];
            a = vertices[arestas[i][2]][1];

            for(j=0;j<tamanho;j++){//torna as duas sub-arvores que acabaram de se unir em um unico componente
                if(vertices[j][1] == a){
                    vertices[j][1] = vertices[arestas[i][1]][1];
                }
            }
        }
    }
    for(i=0;i<tamanho;i++){//arruma a matriz tornando ela simetrica
        for(j=0;j<tamanho;j++){
            matMinima[j][i] = matMinima[i][j];
        }
    }

    for(i=0;i<tamanho;i++){//imprime a matriz de adjacencias da arvore minima
        for(j=0;j<tamanho;j++){
            printf("%d ",matMinima[i][j]);
        }
        printf("\n");
    }
}
