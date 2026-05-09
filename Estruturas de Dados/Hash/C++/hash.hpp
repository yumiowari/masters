#ifndef HASH_HPP
#define HASH_HPP

/*
 *  Implementação de Tabela Hash em C++ com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  9 de maio de 2026
 */

#include <iostream>

typedef struct node* node_t;
typedef struct hash* hash_t;

// Função de inicialização da tabela hash, alocando memória
// para a estrutura hash e para a tabela de ponteiros de nós.
hash_t init_hash(int);

// Função de hash que calcula a chave para um valor dado o tamanho da tabela hash.
int hash_function(int, int);

// Função de inserção de um valor na tabela hash, com tratamento de colisões
// utilizando listas encadeadas ordenadas (do menor para o maior).
bool insert_hash(hash_t, int);

// Função de remoção de um valor da tabela hash.
bool remove_hash(hash_t, int);

// Função de busca de um valor na tabela hash.
bool search_hash(hash_t, int);

// Função de destruição da tabela hash, liberando toda a memória alocada 
// para os nós e para a estrutura hash.
bool destroy_hash(hash_t);

// Função de exibição da tabela hash, imprimindo cada posição da tabela e 
// os valores presentes em cada lista encadeada.
bool show_hash(hash_t);

#endif // HASH_HPP