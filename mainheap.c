#include "heap.h"

int main(){
	heap h;
	int m,opc,valor;
	iniciarHeap(&h,100);
	
	do{
        opc = menu();
        switch(opc){
            case 1:
                printf("Digite um valor:\n");
                scanf("%d",&valor);
                inserirHeap(&h,valor);
                construirHeapMax(&h);
                break;
            case 2:
                construirHeapMax(&h);
                printf("Valor maximo da Heap:\n");
                m = extrairMaxHeap(&h);
                printf("->%d\n",m);
                break;
            case 3:
                printf("Listagem dos elementos:\n");
                construirHeapMax(&h);
                imprimir(h);
                break;
            case 4:
                printf("Listagem dos elementos apos o heapsort:\n");
                heapSort(&h);
                imprimir(h);
                break;
        }
    }while(opc!=0);
	return 0;
}
