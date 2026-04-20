/*  
 *  Implementação de Lista Encadeada Simples e Dinâmica em C++ utilizando classes.
 * 
 *  Rafael Renó Corrêa, 20 de abril de 2026.
 */

#include <iostream>

#include "list.hpp"

bool List::insert(int value){
    Node* node = new Node(value);
    if(node == nullptr)return false; // memória insuficiente para alocar o novo nó

    // 1º caso: lista vazia
    if(this->is_empty()){
        this->root = node;

        this->size++;

        return true;
    }

    // 2º caso: lista preenchida

        // encontra o elemento anterior ao primeiro elemento maior que o valor a ser inserido
    Node* next = this->root;
    Node* prev = nullptr;
    while(next != nullptr && next->get_value() < value){
        prev = next;
        next = next->get_next();
    }

        // insere o novo nó na lista
    if(prev == nullptr){
            // caso o elemento a ser inserido seja o menor da lista
        node->set_next(this->root);
        this->root = node;
    }else{ 
            // caso o elemento a ser inserido esteja no meio ou no final da lista
        prev->set_next(node);
        node->set_next(next);
    }

    this->size++;

    return true;
}

bool List::remove(int value){
    if(this->is_empty())return false;

    Node* next = this->root;
    Node* prev = nullptr;

    // encontra o elemento a ser removido
    while(next != nullptr && next->get_value() != value){
        prev = next;
        next = next->get_next();
    }

    if(next == nullptr)return false; // o elemento não existe na lista

    // remove o elemento
    if(prev == nullptr){
        // caso o elemento a ser removido seja o primeiro da lista
        this->root = next->get_next();
    }else{
        // caso o elemento a ser removido esteja no meio ou no final da lista
        prev->set_next(next->get_next());
    }

    delete next;

    this->size--;

    return true;
}

void List::print(){
    if(this->is_empty()){
        std::cout << "Lista vazia" << std::endl;
        return;
    }

    Node* aux = this->root;
    std::cout << "L -> ";
    while(aux != nullptr){
        std::cout << aux->get_value() << " -> ";
        aux = aux->get_next();
    }
    std::cout << "nullptr" << std::endl;
}