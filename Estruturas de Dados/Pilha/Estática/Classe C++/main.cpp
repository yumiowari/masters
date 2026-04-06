#include <iostream>

#include "stack.hpp"

int main(void){
    Stack stack = Stack();
    int x;

    if(stack.is_empty())std::cout << "A pilha está vazia." << std::endl;

    std::cout << "Empilhando..." << std::endl;
    for(x = 1; x <= 10; x++)
        stack.push(x);

    if(stack.is_full())std::cout << "A pilha está cheia." << std::endl;

    if(!stack.push(x))std::cout << "Não é possível empilhar mais elementos." << std::endl;

    std::cout << "Desempilhando..." << std::endl;
    while(!stack.is_empty()){
        stack.pop(x);

        std::cout << x << std::endl;
    }

    if(!stack.pop(x))std::cout << "Não é possível desempilhar mais elementos." << std::endl;

    return 0;
}