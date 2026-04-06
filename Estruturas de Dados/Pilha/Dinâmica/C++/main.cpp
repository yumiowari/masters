#include <iostream>

#include "stack.hpp"

int main(void){
    stack_t* stack = lift_stack();
    int x;

    std::cout << "Empilhando..." << std::endl;
    for(x = 1; x <= 10; x++)
        push(stack, x);

    std::cout << "Desempilhando..." << std::endl;
    while(pop(stack, x)){
        std::cout << x << std::endl;
    }

    drop_stack(stack);

    return 0;
}