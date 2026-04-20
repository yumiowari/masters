#include <stdio.h>

#include "list.h"

int main(void){
    int value;
    list_t *L = _make_list();

    while(1){
        int op;

        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir lista\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                // insert
                scanf("%d", &value);
                if(_insert(L, value)){
                    printf("Elemento inserido: %d\n", value);
                }else{
                    printf("Falha na inserção do elemento: %d\n", value);
                }

                break;

            case 2:
                // remove
                scanf("%d", &value);
                if(_remove(L, value)){
                    printf("Elemento removido: %d\n", value);
                }else{
                    printf("Falha na remoção do elemento: %d\n", value);
                }

                break;

            case 3:
                // print
                _print_list(L);

                break;

            case 0:
                // exit

                printf("Saindo...\n");
                
                _free_list(L);

                return 0;

            default:
                printf("Opção inválida\n");

                break;
        }
    }

    return 0;
}