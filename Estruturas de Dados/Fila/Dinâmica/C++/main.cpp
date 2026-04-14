#include <iostream>

#include "queue.hpp"

int main(void){
    queue_t* Q = stage_queue();
    int x;

    if(is_empty(Q))std::cout << "A fila está vazia." << std::endl;

    std::cout << "Enfileirando" << std::endl;
    for(x = 1; x <= 10; x++)
        enqueue(Q, x);

    std::cout << "Desenfileirando" << std::endl;
    while(dequeue(Q, &x)){
        std::cout << x << std::endl;
    }

    destage_queue(Q);

    return 0;
}