#ifndef HASH_HPP
#define HASH_HPP

/*
 *  Implementação de Tabela Hash em C++ com objeto e tratamento de colisões utilizando listas encadeadas.
 *
 *  Rafael Renó Corrêa, Gustavo Renó Corrêa
 *  
 *  27 de abril de 2026
 */

#include <iostream>

#define SIZE 10

class Node{
    private:
        int value;
        Node* next;

    public:
        Node(int v): value(v), next(nullptr) {}

        int get_value() const{ return this->value; }
        Node* get_next() const{ return this->next; }
        void set_value(int v){ this->value = v; }
        void set_next(Node* n){ this->next = n; }
};

class Hash{
    private:
        Node* table[SIZE];
        int size;

    public:
        Hash(int s) : size(s){
            for(int i = 0; i < size; ++i)
                table[i] = nullptr;
        }

        ~Hash(){
            for(int i = 0; i < this->size; ++i){
                Node* prev = this->table[i];
                while(prev != nullptr){
                    Node* next = prev->get_next();

                    delete prev;

                    prev = next;
                }
            }
        }

        int hash_function(int value, int size){
            return value % size;
        }

        bool insert_hash(int);

        bool remove_hash(int);

        bool search_hash(int);

        void show_hash();
};

#endif // HASH_HPP