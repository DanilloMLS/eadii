#include "prim.h"

int main(){
	printf("Digite o numero de vertices:\n");
    do{
        scanf("%d",&tamanho);
        if(tamanho < 1){
            printf("Digite um tamanho valido, ele deve ser ao menos 1\n");
        }
    }while(tamanho <= 0);

    int mAdj[tamanho][tamanho], a, b;
	int peso, g;
	int op = 0;

    iniciaMatrizAdj(mAdj);

	do{
		printf("Escolha uma opcao:\n");
		printf("1-Incluir aresta\n");
		printf("2-Imprimir matriz de pesos\n");
		printf("3-Imprimir matriz de adjacencias\n");
		printf("4-Arvore geradora minima\n");
		printf("5-Grau de um vertice\n");
		printf("6-Remover aresta\n");
		printf("0-Sair\n");
		scanf("%d",&op);
		switch(op){
			case 1:
                printf("Digite o peso da aresta\n");
                scanf("%d",&peso);
                printf("Digite os vertices que serao unidos\n");
                printf("1o vertice: ");
                scanf("%d",&a);
                printf("2o vertice: ");
                scanf("%d",&b);
                printf("\n");
                incluiAresta(mAdj,a,b,peso);
				break;
			case 2:
				imprimeMatriz(mAdj);
				break;
			case 3:
				imprimeAdj(mAdj);
				break;
			case 4:
			    printf("Digite um vertice\n");
			    scanf("%d",&a);
                prim(mAdj,a);
                break;
			case 5:
				printf("Digite o vertice\n");
				scanf("%d",&a);
				g = grau(mAdj,a);
				if(g != -1){
                    printf("Grau do vertice: %d",g);
                    printf("\n");
                }
				break;
            case 6:
                imprimeMatriz(mAdj);
                printf("Digite os vertices que contem a aresta que vc quer remover\n");
                printf("1o vertice: ");
                scanf("%d",&a);
                printf("\n2o vertice: ");
                scanf("%d",&b);
                printf("\n");
                removeAresta(mAdj,a,b);
                break;
			case 0:
				exit(0);
			default: printf("Opcao invalida\n");
		}
	}while(op != 0);
}
