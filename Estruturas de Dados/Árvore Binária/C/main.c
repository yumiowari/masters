#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void){
    tree_t tree = create_tree();
    int data, option = -1;

    while(option != 0){
        printf("1. Inserir nó\n");
        printf("2. Remover nó\n");
        printf("3. Buscar nó\n");
        printf("4. Em ordem\n");
        printf("5. Pré ordem\n");
        printf("6. Pós ordem\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Digite o valor do nó a ser inserido: ");
                scanf("%d", &data);

                if(insert_node(tree, data))
                    printf("Nó inserido com sucesso!\n");
                else
                    printf("Falha ao inserir nó. O nó já existe ou a árvore é inválida.\n");

                break;

            case 2:
                printf("Digite o valor do nó a ser removido: ");
                scanf("%d", &data);

                if(remove_node(tree, data))
                    printf("Nó removido com sucesso!\n");
                else
                    printf("Falha ao remover nó. O nó não existe ou a árvore é inválida.\n");

                break;

            case 3:
                printf("Digite o valor do nó a ser buscado: ");
                scanf("%d", &data);

                if(search_node(tree, data))
                    printf("Nó encontrado na árvore!\n");
                else
                    printf("Nó não encontrado na árvore ou a árvore é inválida.\n");

                break;

            case 4:
                if(!in_order(tree))
                    printf("Falha ao realizar percurso em ordem. A árvore é inválida ou está vazia.\n");

                break;

            case 5:
                if(!pre_order(tree))
                    printf("Falha ao realizar percurso pré ordem. A árvore é inválida ou está vazia.\n");

                break;

            case 6:
                if(!post_order(tree))
                    printf("Falha ao realizar percurso pós ordem. A árvore é inválida ou está vazia.\n");

                break;

            case 0:
                destroy_tree(tree);
                printf("Saindo... A árvore foi destruída.\n");

                break;

            default:
                printf("Opção inválida. Tente novamente.\n");

                break;
        }
    }

    return 0;
}