#include <iostream>

#include "list.hpp"

int main(void){
    int value;
    List *L = new List();

    while(1){
        int op;

        std::cout << "1 - Inserir elemento\n";
        std::cout << "2 - Remover elemento\n";
        std::cout << "3 - Imprimir lista\n";
        std::cout << "0 - Sair\n";
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
                // exit
                std::cout << "Saindo...\n";
                
                delete L;

                return 0;

            default:
                std::cout << "Opção inválida\n";

                break;
        }
    }

    return 0;
}