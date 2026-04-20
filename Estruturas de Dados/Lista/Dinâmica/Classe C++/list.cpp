#include <iostream>

#include "list.hpp"

bool List::insert(int value){
    if(this == nullptr)return false; // <-- a lista não existe

    Node* node = new Node(value);
    if(node == nullptr)return false;

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
    // caso genérico: o elemento a ser inserido esteja no meio ou no final da lista

        prev->set_next(node);
        node->set_next(next);
    }

    this->size++;

    return true;
}

bool List::remove(int value){
    if(this == nullptr)return false;
    if(this->is_empty())return false;

    Node* next = this->root;
    Node* prev = nullptr;

    // encontra o elemento
    while(next != nullptr && next->get_value() != value){
        prev = next;
        next = next->get_next();
    }

    if(next == nullptr)return false; // <-- o elemento não existe na lista

    // remove o elemento
    if(prev == nullptr){
        // caso 1º o elemento da lista seja o elemento a ser removido
        this->root = next->get_next();

        delete next;
    }else{
        // caso genérico: o elemento a ser removido esteja no meio ou no final da lista
        prev->set_next(next->get_next());

        delete next;
    }

    this->size--;

    return true;
}

void List::print(){
    if(this == nullptr)return;
    if(this->is_empty()){
        std::cout << "Lista vazia\n";
        return;
    }

    Node* aux = this->root;
    while(aux != nullptr){
        std::cout << aux->get_value() << " ";
        aux = aux->get_next();
    }
    std::cout << std::endl;
}