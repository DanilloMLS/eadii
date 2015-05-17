#include "heap.h"

void iniciarHeap(heap *h, int max){
	h->a = (int*) malloc(sizeof(int)*(max+1));
	h->tamAtual = 0;
	h->tamMax = max;
}

int pai(int i){
  	return i/2;
}

int filhoEsquerda(int i){
  	return 2*i;
}

int filhoDireita(int i){
  	return 2*i + 1;
}
//mantem a propriedade de heap de maximo
void maxHeapify(heap *h, int i){
	int esq = filhoEsquerda(i);
	int dir = filhoDireita(i);
	int temp;
	int maior = i;
	
	if((esq <= h->tamAtual) && (h->a[esq]>h->a[i])){
		maior = esq;
	}
	if((dir <= h->tamAtual) && (h->a[dir]>h->a[maior])){
		maior = dir;
	}
	
	if(maior != i){
		temp = h->a[i];
		h->a[i] = h->a[maior];
		h->a[maior] = temp;
		maxHeapify(h,maior);
	}
}

//constroi a heap usando maxHeapify
void construirHeapMax(heap *h){
	int i;
	int metade = (h->tamAtual)/2;
	for(i=metade;i>0;i--){
		maxHeapify(h,i);
	}
}

//imprime a heap
void imprimir(heap h){
	int tam = h.tamAtual;
	int i;
	for(i=1;i<=tam;i++){
		printf("%d ",h.a[i]);
	}
	printf("\n");
}

//ordena a heap
void heapSort(heap *h){
	int tam = h->tamAtual;
	int i, temp;
	construirHeapMax(h);
	for(i=tam;i>1;i--){
		temp = h->a[1];
		h->a[1] = h->a[i];
		h->a[i] = temp;
		(h->tamAtual)--;
		maxHeapify(h,1);
	}
	h->tamAtual = tam;
}

//metodo que insere valores na heap
bool inserirHeap(heap *h, int chave){
	int i,temp;
	if(h->tamAtual == h->tamMax){
		return false;
	}
	(h->tamAtual)++;
	i = h->tamAtual;
	h->a[i] = chave;
	while((i>1) && (h->a[pai(i)]<h->a[i])){
		temp = h->a[i];
		h->a[i] = h->a[pai(i)];
		h->a[pai(i)] = temp;
		i = pai(i);
	}
	return true;
}

//metodo e extrai e retorna o valor maximo da heap
int extrairMaxHeap(heap *h){
    if(h->tamAtual < 1){
        return;
    }
    int max = h->a[1];
    h->a[1] = h->a[h->tamAtual];
    h->tamAtual = h->tamAtual-1;
    maxHeapify(h,1);
    return max;
}

int menu(){
    int opcao;

    printf("1.Inserir ...........:\n");
    printf("2.Valor maximo.......:\n");
    printf("3.Imprimir Max Heap..:\n");
    printf("4.HeapSort e imprimir:\n");
    printf("0.Sair do programa...:\n");
    printf("?: ");

    scanf("%d", &opcao);
    return opcao;
}
