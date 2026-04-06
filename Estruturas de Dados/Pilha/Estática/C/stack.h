#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define SIZE 10

typedef struct stack{
    int V[SIZE];
    int n;
}stack_t;

void lift_stack(stack_t*);

bool is_empty(stack_t);

bool is_full(stack_t);

bool pop(stack_t*, int*);

bool push(stack_t*, int);

#endif // STACK_H