#include "hashendaberto.h"

int main(){
	int m, i, k; 
    int resp; 
    Hash *h;

    printf("\nEntre com o tamanho da tabela: "); 
    scanf("%d", &m); 
    h = criarHash(m);

    while(1) 
    { 
        printf("\nInserir(1) Buscar(2) Remover(3) Imprimir(4) Sair(5)\n"); 
        scanf("%d",&resp);
        switch(resp) 
        { 
            case 1: 
                printf("\nEntre com o numero a ser inserido na tabela: "); 
                scanf("%d", &k); 
                inserir(h, m, k); 
                break; 
            case 2: 
                printf("\nEntre com o numero a ser buscado na tabela: "); 
                scanf("%d", &k); 
                i = busca(h, m, k, 0); 
                if(i == -1)
                    printf("\nNumero nao encontrado!"); 
                else 
                    printf("\nNumero encontrado!"); 
                break; 
            case 3: 
                printf("\nEntre com o numero a ser removido da tabela: "); 
                scanf("%d", &k); 
                i = remover(h, m, k); 
                if(i == -1) 
                    printf("\nNumero nao encontrado!"); 
                else 
                    printf("\nNumero removido com sucesso!"); 
                break; 
            case 4:
            	printf("\nListagem dos elementos: ");
            	imprimir(h,m);
            	break;
            case 5: 
                exit(0);
                break;
      }
   }
}
