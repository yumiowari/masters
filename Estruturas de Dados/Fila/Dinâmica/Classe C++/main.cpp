#include <iostream>

#include "queue.hpp"

int main(void){
    Queue* Q = new Queue();
    int x;

    if(Q->is_empty())std::cout << "A fila está vazia." << std::endl;

    std::cout << "Enfileirando" << std::endl;
    for(x = 1; x <= 10; x++)
        Q->enqueue(x);

    std::cout << "Desenfileirando" << std::endl;
    while(Q->dequeue(x)){
        std::cout << x << std::endl;
    }

    delete Q;

    return 0;
}