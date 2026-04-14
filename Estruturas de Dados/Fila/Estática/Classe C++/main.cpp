#include <iostream>

#include "queue.hpp"

int main(void){
    Queue Q = Queue();
    int x;

    if(Q.is_empty())std::cout << "A fila está vazia." << std::endl;

    std::cout << "Enfileirando..." << std::endl;
    for(x = 1; x <= 10; x++)
        Q.enqueue(x);

    if(Q.is_full())std::cout << "A fila está cheia." << std::endl;

    if(!Q.enqueue(x))std::cout << "Não é possível enfileirar mais elementos." << std::endl;

    std::cout << "Desefileirando..." << std::endl;
    while(Q.dequeue(x)){
        std::cout << x << std::endl;
    }

    if(!Q.dequeue(x))std::cout << "Não é possível desenfileirar mais elementos." << std::endl;

    return 0;
}