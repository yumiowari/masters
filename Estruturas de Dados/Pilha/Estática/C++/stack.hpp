#ifndef STACK_HPP
#define STACK_HPP

#define SIZE 10

typedef struct stack{
    int V[SIZE];
    int n;
}stack_t;

void lift_stack(stack_t&);

bool is_empty(const stack_t&);

bool is_full(const stack_t&);

bool pop(stack_t&, int&);

bool push(stack_t&, int);

#endif // STACK_HPP