/*
 *  Implementação de Tabela Hash em C com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include "hash.h"

int main(void){
    int option, value;

    hash_t* hash = init_hash(SIZE);
    if(hash == NULL)printf("Falha na alocação da tabela hash.\n");

    while(true){
        printf("\n1. Inserir\n2. Remover\n3. Buscar\n4. Imprimir\n0. Sair\n");
        printf("Opção: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Valor: ");
                scanf("%d", &value);

                if(!insert_hash(hash, value))printf("Falha na inserção do valor %d.\n", value);

                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &value);

                if(!remove_hash(hash, value))printf("Falha na remoção do valor %d.\n", value);

                break;
            case 3:
                printf("Valor: ");
                scanf("%d", &value);

                if(search_hash(hash, value))
                    printf("Valor %d encontrado.\n", value);
                else
                    printf("Valor %d não encontrado.\n", value);

                break;
            case 4:
                show_hash(hash);

                break;
            case 0:
                printf("Saindo...\n");

                if(!destroy_hash(hash))printf("Falha na liberação da tabela hash.\n");

                return 0;
            default:
                printf("Opção inválida.\n");

                break;
        }
    }
}