#ifndef __HEAP_H__
#define __HEAP_H__

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
int extrairMaxHeap(heap *h);
int menu();

#endif // __HEAP_H__
