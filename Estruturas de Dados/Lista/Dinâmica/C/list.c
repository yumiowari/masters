#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct node{
    int value;
    struct node* next;
};

struct list{
    struct node* root;
    int size;
};

list_t* _make_list(){
    list_t* list = (list_t*) malloc(sizeof(struct list));
    if(list == NULL)return NULL;
    
    list->root = NULL;
    list->size = 0;

    return list;
}

node_t* _make_node(int value){
    node_t* node = (node_t*) malloc(sizeof(struct node));
    if(node == NULL)return NULL;

    node->value = value;
    node->next = NULL;

    return node;
}

bool _is_empty(list_t* list){
    return list->size == 0;
}

bool _insert(list_t* list, int value){
    if(list == NULL)return false; // <-- a lista não existe

    node_t* node = _make_node(value);
    if(node == NULL)return false;

    // 1º caso: lista vazia
    if(_is_empty(list)){
        list->root = node;

        list->size++;

        return true;
    }

    // 2º caso: lista preenchida

        // encontra o elemento anterior ao primeiro elemento maior que o valor a ser inserido
    node_t* next = list->root;
    node_t* prev = NULL;
    while(next != NULL && next->value < value){
        prev = next;
        next = next->next;
    }

        // insere o novo nó na lista
    if(prev == NULL){
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
    if(list == NULL)return false;
    if(_is_empty(list))return false;

    node_t* next = list->root;
    node_t* prev = NULL;

    // encontra o elemento
    while(next != NULL && next->value != value){
        prev = next;
        next = next->next;
    }

    if(next == NULL)return false; // <-- o elemento não existe na lista

    // remove o elemento
    if(prev == NULL){
        // caso 1º o elemento da lista seja o elemento a ser removido
        list->root = next->next;

        free(next);
    }else{
        // caso genérico: o elemento a ser removido esteja no meio ou no final da lista
        prev->next = next->next;

        free(next);
    }

    list->size--;

    return true;
}

void _print_list(list_t* list){
    if(list == NULL)return;
    if(_is_empty(list)){
        printf("Lista vazia\n");
        
        return;
    }

    node_t* aux = list->root;
    while(aux != NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void _free_list(list_t* list){
    if(list == NULL)return;

    node_t* prev = list->root;
    while(prev != NULL){
        node_t* next = prev->next;

        free(prev);

        prev = next;
    }

    free(list);
}