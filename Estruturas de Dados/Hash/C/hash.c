/*
 *  Implementação de Tabela Hash em C com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include "hash.h"

struct node{
    int value;
    struct node* next;
};

struct hash{
    struct node* table[SIZE];
    int size;
};

hash_t* init_hash(int size){
    hash_t* hash = (hash_t*) malloc(sizeof(hash_t));
    if(hash == NULL)return NULL;

    hash->size = size;

    // Inicia a tabela com valores nulos
    for(int i = 0; i < size; ++i)
        hash->table[i] = NULL;

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

    node_t* node = (node_t*) malloc(sizeof(node_t));
    if(node == NULL)return false;

    node->value = value;
    node->next = NULL;

    if(hash->table[key] == NULL || hash->table[key]->value >= value){
        // 1º Caso: Insere o nó no início da lista
        
        node->next = hash->table[key];
        hash->table[key] = node;
    }else{
        node_t* aux = hash->table[key];
        while(aux->next != NULL && aux->next->value < value)
            aux = aux->next;

        if(aux->next == NULL){
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
    while(aux != NULL && aux->value != value)
        aux = aux->next;

    if(aux == NULL)return false; // valor não encontrado

    if(aux == hash->table[key]){
        // 1º Caso: Remove o primeiro nó da lista

        hash->table[key] = aux->next;

        free(aux);
    }else{
        // 2º Caso: Remove um nó do meio ou do final da lista

        node_t* prev = hash->table[key];
        while(prev->next != aux){
            prev = prev->next;
        }

        prev->next = aux->next;

        free(aux);
    }

    return true;
}

// Complexidade:
//     Melhor caso: O(1) - O valor está no início da lista encadeada.
//     Pior caso: O(n) - O valor está no final da lista encadeada ou não está presente.
bool search_hash(hash_t* hash, int value){
    int key = hash_function(value, hash->size);

    node_t* aux = hash->table[key];
    while(aux != NULL){
        if(aux->value == value)return true;

        aux = aux->next;
    }

    return false; // Valor não encontrado
}

bool destroy_hash(hash_t* hash){
    if(hash == NULL)return false;

    for(int i = 0; i < hash->size; ++i){
        node_t* prev = hash->table[i];
        while(prev != NULL){
            node_t* next = prev->next;

            free(prev);

            prev = next;
        }
    }
    
    free(hash);

    return true;
}

void show_hash(hash_t* hash){
    for(int i = 0; i < hash->size; ++i){
        printf("%d: ", i);

        node_t* aux = hash->table[i];
        while(aux != NULL){
            printf("%d -> ", aux->value);
            
            aux = aux->next;
        }
        printf("NULL\n");
    }
}