#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *vetorDesordenado, int posicaoInicio, int posicaoFim){
	int i,j,k,metadeTamanho,*vetorTemp;
	if (posicaoInicio == posicaoFim){
		return;
	}
	
	//ordenação recursiva das duas metades
	metadeTamanho = (posicaoInicio+posicaoFim)/2;
	mergeSort(vetorDesordenado, posicaoInicio, metadeTamanho);
	mergeSort(vetorDesordenado,metadeTamanho+1,posicaoFim);
	
	//intercalação no vetor temporario t
	i = posicaoInicio;
	j = metadeTamanho+1;
	k = 0;
	vetorTemp = (int *)malloc(sizeof(int)*(posicaoFim-posicaoInicio+1));
	
	while(i<metadeTamanho+1 || j<posicaoFim+1){
		if(i==metadeTamanho+1){
			//i passou do final da primeira metade, pegar v[j]
			vetorTemp[k] = vetorDesordenado[j];
			j++;
			k++;
		}
		else
		{
			if(j==posicaoFim+1){
				//j passou do final da segunda metade, pegar v[i]
				vetorTemp[k] = vetorDesordenado[i];
				i++;
				k++;
			}
			else{
				if(vetorDesordenado[i]<vetorDesordenado[j]){
					vetorTemp[k] = vetorDesordenado[i];
					i++;
					k++;
				}
				else{
					vetorTemp[k] = vetorDesordenado[j];
					j++;
					k++;
				}
			}
		}
	}
	//copia vetor intercalado para o vetor original
	for(i=posicaoInicio;i<=posicaoFim;i++){
		vetorDesordenado[i] = vetorTemp[i-posicaoInicio];
	}
	free(vetorTemp);
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
    
    printf("mergeSort:\n");
    mergeSort(v,0,n-1);
    for (j=0;j<n;j++){
        printf("%d\n",v[j]);
    }
}
