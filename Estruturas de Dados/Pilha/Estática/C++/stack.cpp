#include "stack.hpp"

void lift_stack(stack_t& S){
    S.n = 0;
}

bool is_empty(const stack_t& S){
    return S.n <= 0;
}

bool is_full(const stack_t& S){
    return S.n >= SIZE;
}

bool pop(stack_t& S, int& x){
    if(is_empty(S))return false;

    x = S.V[--S.n];

    return true;
}

bool push(stack_t& S, int x){
    if(is_full(S))return false;

    S.V[S.n++] = x;

    return true;
}