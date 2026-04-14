#include "queue.hpp"

struct node{
    struct node* next;
    int info;
};

struct queue{
    struct node* front;
    struct node* back;
};

queue_t* stage_queue(){
    queue_t* queue = new queue_t;
    if(queue == nullptr)return nullptr;

    queue->front = nullptr;
    queue->back = nullptr;

    return queue;
}

node_t* make_node(int info){
    node_t* node = new node_t;
    if(node == nullptr)return nullptr;

    node->next = nullptr;
    node->info = info;

    return node;
}

bool is_empty(queue_t* queue){
    return queue->front == nullptr && queue->back == nullptr;
}

bool enqueue(queue_t* queue, int info){
    node_t* node = make_node(info);
    if(node == nullptr)return false; // sem memória RAM disponível

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

bool dequeue(queue_t* queue, int* info){
    if(is_empty(queue))return false; // fila vazia

    node_t* aux = queue->front;
    *info = aux->info;

    // avança o front
    queue->front = queue->front->next;

    // se o front ficou nulo, significa que o último elemento foi removido e,
    // portanto, o back também precisa ser atualizado.
    if(queue->front == nullptr){
        queue->back = nullptr;
    }

    // quando aux é a referência para o último elemento na fila,
    // tanto front quanto back apontam para ele. Dessa forma,
    // somente um free() é necessário.
    delete aux;

    return true;
}

void destage_queue(queue_t* queue){
    int x;
    
    while(dequeue(queue, &x));

    delete queue;
}
