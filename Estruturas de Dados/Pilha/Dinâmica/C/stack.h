#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct stack* stack_t;

typedef struct node* node_t;

stack_t lift_stack();

bool push(stack_t, int);

bool pop(stack_t, int*);

void drop_stack(stack_t);

#endif // STACK_H