#include <stdio.h>

#include "list.h"

void _print_list(list_t L){
    if(_is_empty(L)){
        printf("Lista vazia\n");
        
        return;
    }

    for(int i = 0; i < L.n; i++)
        printf("%d ", L.V[i]);
    printf("\n");
}

int main(void){
    int x;
    list_t L;
    _start_list(&L);

    while(1){
        printf("1 - Insert\n");
        printf("2 - Remove\n");
        printf("3 - Print\n");
        printf("0 - Exit\n");

        int op;
        scanf("%d", &op);

        switch(op){
            case 1:
                // insert    
                scanf("%d", &x);

                if(_insert(&L, x)){
                    printf("Elemento inserido: %d\n", x);
                }else{
                    printf("Lista cheia\n");
                }

                break;

            case 2:
                // remove
                scanf("%d", &x);

                if(_remove(&L, x)){
                    printf("Elemento removido: %d\n", x);
                }else{
                    printf("Elemento não encontrado\n");
                }

                break;

            case 3:
                // print
                _print_list(L);    

                break;

            case 0:
                // exit
                printf("Saindo...\n");

                return 0;

            default:
                printf("Opção inválida\n");

                break;
        }
    }

    return 0;
}