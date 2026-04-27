/*
 *  Implementação de Tabela Hash em C++ com objeto e tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include "hash.hpp"

// Complexidade:
//     Melhor caso: O(1) - O valor é inserido no início da lista encadeada.
//     Pior caso: O(n) - O valor é inserido no final da lista encadeada.
bool Hash::insert_hash(int value){
    int key = this->hash_function(value, this->size);

    Node* node = new Node(value);
    if(node == nullptr)return false;

    node->set_value(value);
    node->set_next(nullptr);

    if(this->table[key] == nullptr || this->table[key]->get_value() >= value){
        // 1º Caso: Insere o nó no início da lista
        
        node->set_next(this->table[key]);
        this->table[key] = node;
    }else{
        Node* aux = this->table[key];
        while(aux->get_next() != nullptr && aux->get_next()->get_value() < value)
            aux = aux->get_next();

        if(aux->get_next() == nullptr){
            // 2º Caso: Insere o nó no final da lista

            aux->set_next(node);
        }else{
            // 3º Caso: Insere o nó no meio da lista

            node->set_next(aux->get_next());
            aux->set_next(node);
        }
    }

    return true;
}

// Complexidade:
//     Melhor caso: O(1) - O valor a ser removido está no início da lista encadeada.
//     Pior caso: O(n) - O valor a ser removido está no final da lista encadeada ou não está presente.
bool Hash::remove_hash(int value){
    int key = this->hash_function(value, this->size);

    Node* aux = this->table[key];
    while(aux != nullptr && aux->get_value() != value)
        aux = aux->get_next();

    if(aux == nullptr)return false; // valor não encontrado

    if(aux == this->table[key]){
        // 1º Caso: Remove o primeiro nó da lista

        this->table[key] = aux->get_next();

        delete aux;
    }else{
        // 2º Caso: Remove um nó do meio ou do final da lista

        Node* prev = this->table[key];
        while(prev->get_next() != aux){
            prev = prev->get_next();
        }

        prev->set_next(aux->get_next());

        delete aux;
    }

    return true;
}

// Complexidade:
//     Melhor caso: O(1) - O valor está no início da lista encadeada.
//     Pior caso: O(n) - O valor está no final da lista encadeada ou não está presente.
bool Hash::search_hash(int value){
    int key = this->hash_function(value, this->size);

    Node* aux = this->table[key];
    while(aux != nullptr){
        if(aux->get_value() == value)return true;

        aux = aux->get_next();
    }

    return false; // Valor não encontrado
}

void Hash::show_hash(){
    for(int i = 0; i < this->size; ++i){
        std::cout << i << ": ";

        Node* aux = this->table[i];
        while(aux != nullptr){
            std::cout << aux->get_value() << " -> ";
            
            aux = aux->get_next();
        }
        std::cout << "nullptr" << std::endl;
    }
}