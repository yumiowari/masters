#include <stdlib.h>

#include "queue.h"

struct node{
    struct node* next;
    int info;
};

struct queue{
    struct node* front;
    struct node* back;
};

queue_t stage_queue(){
    queue_t queue = (queue_t) malloc(sizeof(queue_t));
    if(queue == NULL)return NULL;

    queue->front = NULL;
    queue->back = NULL;

    return queue;
}

node_t make_node(int info){
    node_t node = (node_t) malloc(sizeof(node_t));
    if(node == NULL)return NULL;

    node->next = NULL;
    node->info = info;

    return node;
}

bool is_empty(queue_t queue){
    return queue->front == NULL && queue->back == NULL;
}

bool enqueue(queue_t queue, int info){
    node_t node = make_node(info);
    if(node == NULL)return false; // sem memória RAM disponível

    if(is_empty(queue)){
    // fila vazia: front e back apontam para o novo nó

        queue->front = node;
        queue->back = node;
    }else{
    // fila com elementos: pendura o novo nó no final e atualiza o back

        queue->back->next = node;
        queue->back = node;
    }

    return true;
}

bool dequeue(queue_t queue, int* info){
    if(is_empty(queue))return false; // fila vazia

    node_t aux = queue->front;
    *info = aux->info;

    // avança o front
    queue->front = queue->front->next;

    // se o front ficou nulo, significa que o último elemento foi removido e,
    // portanto, o back também precisa ser atualizado.
    if(queue->front == NULL){
        queue->back = NULL;
    }

    // quando aux é a referência para o último elemento na fila,
    // tanto front quanto back apontam para ele. Dessa forma,
    // somente um free() é necessário.
    free(aux);

    return true;
}

void destage_queue(queue_t queue){
    int x;
    
    while(dequeue(queue, &x));

    free(queue);
}
