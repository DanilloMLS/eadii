#include "avl.h"

int main(){
    no *avl = NULL;
    int num, op;
    do{
        printf("\n\t\t Menu \n");
        printf("\t\t   1-Inserir \n");
        printf("\t\t   2-Imprimir em Ordem \n");
        printf("\t\t   3-Imprimir em Pre-Ordem \n");
        printf("\t\t   4-Imprimir em Pos-Ordem \n");
        printf("\t\t   5-Excluir \n");
        printf("\t\t   6-Altura \n");
        printf("\t\t   7-Sair \n");
        printf("\n\tOpcao: ");
        scanf("%d",&op);
        switch(op){
            case 1: printf("\tNumero: ");
                    scanf("%d",&num);
                    avl = inserirNo(avl,num);
                    break;
            case 2: if (!avl){
                        printf("\tArvore Vazia\n");
                        break;
                    }
                    printf("\tArvore em Ordem\n");
                    emOrdem(avl);
                    break;
            case 3: if (!avl){
                        printf("\tArvore Vazia\n");
                        break;
                    }
                    printf("\tArvore em pre-Ordem\n");
                    preOrdem(avl);
                    break;
            case 4: if (!avl){
                        printf("\tArvore Vazia\n");
                        break;
                    }
                    printf("\tArvore em pos-Ordem\n");
                    posOrdem(avl);
                    break;
            case 5: if(!avl){
                        printf("\tArvore vazia\n");
                        break;
                    }
                    printf("\tNumero: \n");
                    scanf("%d",&num);
                    avl = remover(avl,num);
                    printf("\tExcluido.\n");
                    break;
            case 6: if(!avl){
                        printf("\tArvore vazia\n");
                        break;
                    }
                    num = alt(avl);
                    printf("\tAltura da arvore: %d\n",num);
                    break;
            case 7: exit(0);
            default: printf("\topcao invalida!\n");
        }

    }while(op!=7);
}
