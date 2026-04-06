#include <iostream>

#include "stack.hpp"

int main(void){
    stack_t stack;
    int x;

    lift_stack(stack);

    if(is_empty(stack))std::cout << "A pilha está vazia." << std::endl;

    std::cout << "Empilhando..." << std::endl;
    for(x = 1; x <= 10; x++)
        push(stack, x);

    if(is_full(stack))std::cout << "A pilha está cheia." << std::endl;

    if(!push(stack, x))std::cout << "Não é possível empilhar mais elementos." << std::endl;

    std::cout << "Desempilhando..." << std::endl;
    while(!is_empty(stack)){
        pop(stack, x);

        std::cout << x << std::endl;
    }

    if(!pop(stack, x))std::cout << "Não é possível desempilhar mais elementos." << std::endl;

    return 0;
}