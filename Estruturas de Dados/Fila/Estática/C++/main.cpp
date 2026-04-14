#include <iostream>

#include "queue.hpp"

int main(void){
    queue_t Q;
    int x;

    stage_queue(Q);

    if(is_empty(Q))std::cout << "A fila está vazia." << std::endl;

    std::cout << "Enfileirando..." << std::endl;
    for(x = 1; x <= 10; x++)
        enqueue(Q, x);

    if(is_full(Q))std::cout << "A fila está cheia." << std::endl;

    if(!enqueue(Q, x))std::cout << "Não é possível enfileirar mais elementos." << std::endl;

    std::cout << "Desefileirando..." << std::endl;
    while(dequeue(Q, x)){
        std::cout << x << std::endl;
    }

    if(!dequeue(Q, x))std::cout << "Não é possível desenfileirar mais elementos." << std::endl;

    return 0;
}