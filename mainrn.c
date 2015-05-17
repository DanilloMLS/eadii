#include "rn.h"

int main(){
	no *T = NULL;
    int valor, altura, opc;
    
    do
    {
        opc = menu();
        switch (opc)
        {

        case 1:
            T = inserir(T, criaNovoNoh());
            break;
        case 2:
            printf("Listagem dos nohs da Arvore \n\n");
            if(T != NULL){
                visitarEmOrdem(T);
            }
            else{
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 3:
            printf("Listagem dos nohs da Arvore \n\n");
            if(T != NULL){
                visitarPreOrdem(T);
            }
            else{
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 4:
            printf("Listagem dos nohs da Arvore \n\n");
            if(T != NULL){
                visitarPosOrdem(T);
            }
            else{
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 5:
            if(T != NULL){
                altura = calcularAlturaPreta(T);
                printf("Altura preta da arvore: %d\n", altura);
            }
            else{
                printf("Sem Elementos na Arvore \n");
            }
            break;
        }
    }
    while (opc != 0);

    return 0;
}
