/*
 *  Implementação de Tabela Hash em C++ com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include "hash.hpp"

struct node{
    int value;
    struct node* next;
};

struct hash{
    struct node* table[SIZE];
    int size;
};

hash_t* init_hash(int size){
    hash_t* hash = new hash_t;
    if(hash == nullptr)return nullptr;

    hash->size = size;

    // Inicia a tabela com valores nulos
    for(int i = 0; i < size; ++i)
        hash->table[i] = nullptr;

    return hash;
}

int hash_function(int value, int size){
    return value % size;
}

// Complexidade:
//     Melhor caso: O(1) - O valor é inserido no início da lista encadeada.
//     Pior caso: O(n) - O valor é inserido no final da lista encadeada.
bool insert_hash(hash_t* hash, int value){
    int key = hash_function(value, hash->size);

    node_t* node = new node_t;
    if(node == nullptr)return false;

    node->value = value;
    node->next = nullptr;

    if(hash->table[key] == nullptr || hash->table[key]->value >= value){
        // 1º Caso: Insere o nó no início da lista
        
        node->next = hash->table[key];
        hash->table[key] = node;
    }else{
        node_t* aux = hash->table[key];
        while(aux->next != nullptr && aux->next->value < value)
            aux = aux->next;

        if(aux->next == nullptr){
            // 2º Caso: Insere o nó no final da lista

            aux->next = node;
        }else{
            // 3º Caso: Insere o nó no meio da lista

            node->next = aux->next;
            aux->next = node;
        }
    }

    return true;
}

// Complexidade:
//     Melhor caso: O(1) - O valor a ser removido está no início da lista encadeada.
//     Pior caso: O(n) - O valor a ser removido está no final da lista encadeada ou não está presente.
bool remove_hash(hash_t* hash, int value){
    int key = hash_function(value, hash->size);

    node_t* aux = hash->table[key];
    while(aux != nullptr && aux->value != value)
        aux = aux->next;

    if(aux == nullptr)return false; // valor não encontrado

    if(aux == hash->table[key]){
        // 1º Caso: Remove o primeiro nó da lista

        hash->table[key] = aux->next;

        delete aux;
    }else{
        // 2º Caso: Remove um nó do meio ou do final da lista

        node_t* prev = hash->table[key];
        while(prev->next != aux){
            prev = prev->next;
        }

        prev->next = aux->next;

        delete aux;
    }

    return true;
}

// Complexidade:
//     Melhor caso: O(1) - O valor está no início da lista encadeada.
//     Pior caso: O(n) - O valor está no final da lista encadeada ou não está presente.
bool search_hash(hash_t* hash, int value){
    int key = hash_function(value, hash->size);

    node_t* aux = hash->table[key];
    while(aux != nullptr){
        if(aux->value == value)return true;

        aux = aux->next;
    }

    return false; // Valor não encontrado
}

bool destroy_hash(hash_t* hash){
    if(hash == nullptr)return false;

    for(int i = 0; i < hash->size; ++i){
        node_t* prev = hash->table[i];
        while(prev != nullptr){
            node_t* next = prev->next;

            delete prev;

            prev = next;
        }
    }
    
    delete hash;

    return true;
}

void show_hash(hash_t* hash){
    for(int i = 0; i < hash->size; ++i){
        std::cout << i << ": ";

        node_t* aux = hash->table[i];
        while(aux != nullptr){
            std::cout << aux->value << " -> ";
            
            aux = aux->next;
        }
        std::cout << "nullptr" << std::endl;
    }
}