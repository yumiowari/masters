/*
 *  Implementação de Tabela Hash em C++ com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  9 de maio de 2026
 */

#include "hash.hpp"

// Estrutura de um nó da lista encadeada utilizada para tratamento de colisões na tabela hash.
struct node{
    int value;         // Valor (chave) armazenado no nó
    struct node* next; // Ponteiro para o próximo nó da lista encadeada
};

// Estrutura da tabela hash, contendo um array de ponteiros para nós (listas encadeadas) e o tamanho da tabela.
struct hash{
    struct node** table; // Tabela de chaves-valores
    int size;            // Tamanho da tabela
};

// Função de inicialização da tabela hash, alocando memória
// para a estrutura hash e para a tabela de ponteiros de nós.
//
// Parâmetros:
//     size: Tamanho da tabela hash a ser criada.
//
// Retornos:
//     Ponteiro para a tabela hash inicializada, ou nullptr em caso de falha na alocação de memória.
//
// Complexidade:
//     O(size) - A função aloca memória para a tabela de ponteiros de nós e inicializa cada posição com nullptr.
//
hash_t init_hash(int size){
    hash_t hash = new struct hash;
    if(hash == nullptr)return nullptr;

    hash->size = size;
    hash->table = nullptr;

    // Inicia a tabela com valores nulos
    hash->table = new node_t[size](); // <-- O operador () é usado para inicializar os ponteiros com nullptr
    if(hash->table == nullptr){
        delete hash;

        return nullptr;
    }

    return hash;
}

// Função de hash que calcula a chave para um valor dado o tamanho da tabela hash.
//
// Parâmetros:
//     value: Valor para o qual a chave será calculada.
//     size: Tamanho da tabela hash.
//
// Retornos:
//     A chave calculada para o valor, que é um índice válido dentro da tabela hash.
//
// Complexidade:
//     O(1)
//
int hash_function(int value, int size){
    return abs(value) % size;
}

// Função de inserção de um valor na tabela hash, com tratamento de colisões
// utilizando listas encadeadas ordenadas (do menor para o maior).
//
// Parâmetros:
//     hash: Ponteiro para a tabela hash onde o valor será inserido.
//     value: Valor a ser inserido na tabela hash.
//
// Retornos:
//     true: O valor foi inserido com sucesso.
//     false: Ocorreu uma falha na alocação de memória para o novo nó ou a tabela hash é nula.
//
// Complexidade:
//     Melhor caso: O(1) - O valor é inserido no início da lista encadeada.
//     Pior caso: O(n) - O valor é inserido no final da lista encadeada.
//
bool insert_hash(hash_t hash, int value){
    if(hash == nullptr)return false;

    int key = hash_function(value, hash->size);

    node_t node = new struct node;
    if(node == nullptr)return false;

    node->value = value;
    node->next = nullptr;

    if(hash->table[key] == nullptr || hash->table[key]->value >= value){
        // 1º Caso: Insere o nó no início da lista
        
        node->next = hash->table[key];
        hash->table[key] = node;
    }else{
        node_t aux = hash->table[key];
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

// Função de remoção de um valor da tabela hash.
//
// Parâmetros:
//     hash: Ponteiro para a tabela hash de onde o valor será removido.
//     value: Valor a ser removido da tabela hash.
//
// Retornos:
//     true: O valor foi removido com sucesso.
//     false: O valor não foi encontrado na tabela hash ou a tabela hash é nula.
//
// Complexidade:
//     Melhor caso: O(1) - O valor a ser removido está no início da lista encadeada.
//     Pior caso: O(n) - O valor a ser removido está no final da lista encadeada ou não está presente.
//
bool remove_hash(hash_t hash, int value){
    if(hash == nullptr)return false;

    int key = hash_function(value, hash->size);

    node_t aux = hash->table[key];
    node_t prev = nullptr;
    while(aux != nullptr && aux->value < value){
        prev = aux;

        aux = aux->next;
    }

    if(aux == nullptr || aux->value > value)return false; // Valor não encontrado

    if(aux == hash->table[key]){
        // 1º Caso: Remove o primeiro nó da lista

        hash->table[key] = aux->next;

        delete aux;
    }else{
        // 2º Caso: Remove um nó do meio ou do final da lista

        prev->next = aux->next;

        delete aux;
    }

    return true;
}

// Função de busca de um valor na tabela hash.
//
// Parâmetros:
//     hash: Ponteiro para a tabela hash onde o valor será buscado.
//     value: Valor a ser buscado na tabela hash.
//
// Retornos:
//     true: O valor foi encontrado na tabela hash.
//     false: O valor não foi encontrado na tabela hash ou a tabela hash é nula.
//
// Complexidade:
//     Melhor caso: O(1) - O valor está no início da lista encadeada.
//     Pior caso: O(n) - O valor está no final da lista encadeada ou não está presente.
//
bool search_hash(hash_t hash, int value){
    if(hash == nullptr)return false;

    int key = hash_function(value, hash->size);

    node_t aux = hash->table[key];
    while(aux != nullptr && aux->value <= value){
        if(aux->value == value)return true;

        aux = aux->next;
    }

    return false; // Valor não encontrado
}

// Função de destruição da tabela hash, liberando toda a memória alocada 
// para os nós e para a estrutura hash.
//
// Parâmetros:
//     hash: Ponteiro para a tabela hash a ser destruída.
//
// Retornos:
//     true: A tabela hash foi destruída com sucesso.
//     false: A tabela hash é nula ou ocorreu uma falha na liberação de memória.
//
// Complexidade:
//     O(size + n) - A função percorre cada posição da tabela hash e libera a memória de cada nó presente, 
//                   onde size é o tamanho da tabela e n é o número total de nós alocados.
//
bool destroy_hash(hash_t hash){
    if(hash == nullptr)return false;

    for(int i = 0; i < hash->size; ++i){
        node_t prev = hash->table[i];
        while(prev != nullptr){
            node_t next = prev->next;

            delete prev;

            prev = next;
        }
    }
    
    delete [] hash->table;
    delete hash;

    return true;
}

// Função de exibição da tabela hash, imprimindo cada posição da tabela e 
// os valores presentes em cada lista encadeada.
//
// Parâmetros:
//     hash: Ponteiro para a tabela hash a ser exibida.
//
// Retornos:
//     true: A tabela hash foi exibida com sucesso.
//     false: A tabela hash é nula.
//
// Complexidade:
//     O(size + n) - A função percorre cada posição da tabela hash e imprime os valores de cada nó presente, 
//                   onde size é o tamanho da tabela e n é o número total de nós alocados.
//
bool show_hash(hash_t hash){
    if(hash == nullptr)return false;

    for(int i = 0; i < hash->size; ++i){
        std::cout << i << ": ";

        node_t aux = hash->table[i];
        while(aux != nullptr){
            std::cout << aux->value << " -> ";
            
            aux = aux->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    return true;
}