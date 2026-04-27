#ifndef HASH_H
#define HASH_H

/*
 *  Implementação de Tabela Hash em C com tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct node node_t;
typedef struct hash hash_t;

hash_t* init_hash(int);

bool insert_hash(hash_t*, int);

bool remove_hash(hash_t*, int);

bool search_hash(hash_t*, int);

bool destroy_hash(hash_t*);

void show_hash(hash_t*);

#endif // HASH_H