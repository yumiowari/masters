#include "stack.hpp"

bool Stack::is_empty(){
    return this->n <= 0;
}

bool Stack::is_full(){
    return this->n >= SIZE;
}

bool Stack::pop(int &x){
    if(this->is_empty())return false;

    x = this->V[--this->n];

    return true;
}

bool Stack::push(int x){
    if(this->is_full())return false;

    this->V[this->n++] = x;

    return true;
}