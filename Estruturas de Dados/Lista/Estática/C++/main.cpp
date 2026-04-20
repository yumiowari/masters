#include <iostream>

#include "list.hpp"

void _print_list(list_t L){
    if(_is_empty(L)){
        std::cout << "Lista vazia" << std::endl;
        return;
    }

    for(int i = 0; i < L.n; i++)
        std::cout << L.V[i] << " ";
    std::cout << std::endl;
}

int main(void){
    int x;
    list_t L;
    _start_list(L);

    while(1){
        std::cout << "1 - Insert" << std::endl;
        std::cout << "2 - Remove" << std::endl;
        std::cout << "3 - Print" << std::endl;
        std::cout << "0 - Exit" << std::endl;

        int op;
        std::cin >> op;

        switch(op){
            case 1:
                // insert    
                std::cin >> x;

                if(_insert(L, x)){
                    std::cout << "Elemento inserido: " << x << std::endl;
                }else{
                    std::cout << "Lista cheia" << std::endl;
                }

                break;

            case 2:
                // remove
                std::cin >> x;

                if(_remove(L, x)){
                    std::cout << "Elemento removido: " << x << std::endl;
                }else{
                    std::cout << "Elemento não encontrado" << std::endl;
                }

                break;

            case 3:
                // print
                _print_list(L);    

                break;

            case 0:
                // exit
                std::cout << "Saindo..." << std::endl;

                return 0;

            default:
                std::cout << "Opção inválida" << std::endl;

                break;
        }
    }

    return 0;
}