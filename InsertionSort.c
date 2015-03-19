#include <stdlib.h>
#include <stdio.h>

void insertionSort(int vetorDesordenado[], int tamanhoVetor){
	int i, j, valorAtual;
	for(j=1;j<tamanhoVetor;j++){
		valorAtual = vetorDesordenado[j];
		i=j-1;
		while(i>=0 && vetorDesordenado[i]>valorAtual){
			vetorDesordenado[i+1] = vetorDesordenado[i];
			i--;
		}
		vetorDesordenado[i+1] = valorAtual;
	}
}

int main(){
    int n,i,j;
    printf("Numero de elementos:\n");
    scanf("%d",&n);
    int v[n];
    printf("Digite os valores:\n");
    for(i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    insertionSort(v,n);
    for (j=0;j<n;j++){
        printf("%d",v[j]);
    }
    getch();
}
