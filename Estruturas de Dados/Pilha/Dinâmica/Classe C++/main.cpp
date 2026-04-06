#include <iostream>

#include "stack.hpp"

int main(void){
    Stack* stack = new Stack;
    int x;

    std::cout << "Empilhando..." << std::endl;
    for(x = 1; x <= 10; x++)
        stack->push(x);

    std::cout << "Desempilhando..." << std::endl;
    while(stack->pop(x)){
        std::cout << x << std::endl;
    }

    delete stack;

    return 0;
}