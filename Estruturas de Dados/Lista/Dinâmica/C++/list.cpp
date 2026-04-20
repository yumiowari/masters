#include <iostream>

#include "list.hpp"

struct node{
    int value;
    struct node* next;
};

struct list{
    struct node* root;
    int size;
};

list_t* _make_list(){
    list_t* list = new list_t;
    if(list == nullptr)return nullptr;
    
    list->root = nullptr;
    list->size = 0;

    return list;
}

node_t* _make_node(int value){
    node_t* node = new node_t;
    if(node == nullptr)return nullptr;

    node->value = value;
    node->next = nullptr;

    return node;
}

bool _is_empty(list_t* list){
    return list->size == 0;
}

bool _insert(list_t* list, int value){
    if(list == nullptr)return false; // <-- a lista não existe

    node_t* node = _make_node(value);
    if(node == nullptr)return false;

    // 1º caso: lista vazia
    if(_is_empty(list)){
        list->root = node;

        list->size++;

        return true;
    }

    // 2º caso: lista preenchida

        // encontra o elemento anterior ao primeiro elemento maior que o valor a ser inserido
    node_t* next = list->root;
    node_t* prev = nullptr;
    while(next != nullptr && next->value < value){
        prev = next;
        next = next->next;
    }

        // insere o novo nó na lista
    if(prev == nullptr){
    // caso o elemento a ser inserido seja o menor da lista

        node->next = list->root;
        list->root = node;
    }else{ 
    // caso genérico: o elemento a ser inserido esteja no meio ou no final da lista

        prev->next = node;
        node->next = next;
    }

    list->size++;

    return true;
}

bool _remove(list_t* list, int value){
    if(list == nullptr)return false;
    if(_is_empty(list))return false;

    node_t* next = list->root;
    node_t* prev = nullptr;

    // encontra o elemento
    while(next != nullptr && next->value != value){
        prev = next;
        next = next->next;
    }

    if(next == nullptr)return false; // <-- o elemento não existe na lista

    // remove o elemento
    if(prev == nullptr){
        // caso 1º o elemento da lista seja o elemento a ser removido
        list->root = next->next;

        delete next;
    }else{
        // caso genérico: o elemento a ser removido esteja no meio ou no final da lista
        prev->next = next->next;

        delete next;
    }

    list->size--;

    return true;
}

void _print_list(list_t* list){
    if(list == nullptr)return;
    if(_is_empty(list)){
        std::cout << "Lista vazia\n";
        return;
    }

    node_t* aux = list->root;
    while(aux != nullptr){
        std::cout << aux->value << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

void _free_list(list_t* list){
    if(list == nullptr)return;

    node_t* prev = list->root;
    while(prev != nullptr){
        node_t* next = prev->next;

        delete prev;

        prev = next;
    }

    delete list;
}