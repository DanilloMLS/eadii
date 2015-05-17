#include "hashencadeado.h"

int main(){
	Tabela t;
	criarHash(t);
	int k,resp;
	while(1) 
    { 
        printf("\nInserir(1) Buscar(2) Remover(3) Imprimir(4) Sair(5)\n"); 
        scanf("%d",&resp);
        switch(resp) 
        { 
            case 1: 
                printf("\nEntre com o numero a ser inserido na tabela: "); 
                scanf("%d", &k); 
                inserir(t, k); 
                break; 
            case 2: 
                printf("\nEntre com o numero a ser buscado na tabela: "); 
                scanf("%d", &k); 
                busca(t, k); 
                if(busca(t, k) == NULL)
                    printf("\nNumero nao encontrado!"); 
                else 
                    printf("\nNumero encontrado!"); 
                break; 
            case 3: 
                printf("\nEntre com o numero a ser removido da tabela: "); 
                scanf("%d", &k); 
                remover(t, k); 
                break; 
            case 4:
            	printf("\nListagem dos elementos: ");
            	imprimir(t);
            	break;
            case 5: 
                exit(0); 
                break; 
      } 
   } 
}
