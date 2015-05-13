#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef struct{
	int *a;
	int tamAtual;
	int tamMax;
} heap;

void iniciarHeap(heap *h, int tamMax);
void destruirHeap(heap *h);
int pai(int i);
int filhoEsquerda(int i);
int filhoDireita(int i);
void maxHeapify(heap *h, int i);
void construirHeapMax(heap *h);
void imprimir(heap h);
void heapSort(heap *h);
bool inserirHeap(heap *h, int chave);

int main(){
	heap h;
	iniciarHeap(&h,100);
	inserirHeap(&h,9);
	inserirHeap(&h,3);
	inserirHeap(&h,1);
	inserirHeap(&h,0);
	inserirHeap(&h,7);
	imprimir(h);
	construirHeapMax(&h);
	imprimir(h);
	heapSort(&h);
	imprimir(h);
	getch();
	return 0;
}

void iniciarHeap(heap *h, int max){
	h->a = (int*) malloc(sizeof(int)*(max+1));
	h->tamAtual = 0;
	h->tamMax = max;
}

void destruirHeap(heap *h){
	int tam = h->tamMax;
	free(h->a);
	h->tamMax = 0;
	h->tamAtual = 0;
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
		printf("%d",h.a[i]);
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

