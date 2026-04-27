/*
 *  Implementação de Tabela Hash em C++ com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include "hash.hpp"

int main(void){
    int option, value;

    hash_t* hash = init_hash(SIZE);
    if(hash == nullptr)std::cout << "Falha na alocação da tabela hash." << std::endl;

    while(true){
        std::cout << "\n1. Inserir\n2. Remover\n3. Buscar\n4. Imprimir\n0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> option;

        switch(option){
            case 1:
                std::cout << "Valor: ";
                std::cin >> value;

                if(!insert_hash(hash, value))std::cout << "Falha na inserção do valor " << value << ".\n" << std::endl;

                break;
            case 2:
                std::cout << "Valor: ";
                std::cin >> value;

                if(!remove_hash(hash, value))std::cout << "Falha na remoção do valor " << value << ".\n" << std::endl;

                break;
            case 3:
                std::cout << "Valor: ";
                std::cin >> value;

                if(search_hash(hash, value))
                    std::cout << "Valor " << value << " encontrado.\n" << std::endl;
                else
                    std::cout << "Valor " << value << " não encontrado.\n" << std::endl;

                break;
            case 4:
                show_hash(hash);

                break;
            case 0:
                std::cout << "Saindo...\n";

                if(!destroy_hash(hash))std::cout << "Falha na liberação da tabela hash.\n" << std::endl;

                return 0;
            default:
                std::cout << "Opção inválida.\n";

                break;
        }
    }
}