/*  
 *  Implementação de Lista Encadeada Simples e Dinâmica em C++ utilizando classes.
 * 
 *  Rafael Renó Corrêa, 20 de abril de 2026.
 */

#include <iostream>

#include "list.hpp"

int main(void){
    int value;
    List *L = new List();

    while(1){
        int op;

        std::cout << "1 - Inserir elemento" << std::endl;
        std::cout << "2 - Remover elemento" << std::endl;
        std::cout << "3 - Imprimir lista" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cin >> op;

        switch(op){
            case 1:
                // insert
                std::cin >> value;

                if(L->insert(value)){
                    std::cout << "Elemento inserido: " << value << std::endl;
                }else{
                    std::cout << "Falha na inserção do elemento: " << value << std::endl;
                }

                break;

            case 2:
                // remove
                std::cin >> value;

                if(L->remove(value)){
                    std::cout << "Elemento removido: " << value << std::endl;
                }else{
                    std::cout << "Falha na remoção do elemento: " << value << std::endl;
                }

                break;

            case 3:
                // print
                L->print();

                break;

            case 0:
                // destroy
                std::cout << "Saindo..." << std::endl;
                
                delete L;

                return 0;

            default:
                std::cout << "Opção inválida." << std::endl;

                break;
        }
    }

    return 0;
}