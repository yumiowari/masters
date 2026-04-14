#include "queue.hpp"

bool Queue::is_empty(){
    return this->front == nullptr && this->back == nullptr;
}

bool Queue::enqueue(int value){
    Node* node = new Node(value);

    if(this->is_empty()){
    // fila vazia: front e back apontam para o novo nó

        this->front = node;
        this->back = node;
    }else{
    // fila com elementos: pendura o novo nó no final e atualiza o back

        this->back->set_next(node);
        this->back = node;
    }

    return true;
}

bool Queue::dequeue(int& value){
    if(this->is_empty())return false; // fila vazia

    Node* aux = this->front; 
    value = aux->get_value();

    // avança o front
    this->front = this->front->get_next();

    // se o front ficou nulo, significa que o último elemento foi removido e,
    // portanto, o back também precisa ser atualizado.
    if(this->front == nullptr){
        this->back = nullptr;
    }

    // quando aux é a referência para o último elemento na fila,
    // tanto front quanto back apontam para ele. Dessa forma,
    // somente um free() é necessário.
    delete aux;

    return true;
}