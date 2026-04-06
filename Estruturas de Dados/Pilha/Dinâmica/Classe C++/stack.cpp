#include "stack.hpp"

bool Stack::push(int x){
    Node* node = new Node(x);
    if(node == nullptr)return false;

    node->set_next(this->top);

    this->top = node;

    return true;
}

bool Stack::pop(int& x){
    if(this->top == nullptr)return false;

    x = this->top->get_value();

    Node* aux = this->top;

    this->top = this->top->get_next();

    delete aux;

    return true;
}