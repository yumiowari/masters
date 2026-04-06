#include "stack.h"

struct node{
    struct node *next;
    int value;
};

struct stack{
    struct node *top;
};

stack_t lift_stack(){
    stack_t stack = (stack_t) malloc(sizeof(stack_t));
    if(stack == NULL)return NULL;

    stack->top = NULL;

    return stack;
}

node_t make_node(int value){
    node_t node = (node_t) malloc(sizeof(node_t));
    if(node == NULL)return NULL;

    node->next = NULL;
    node->value = value;

    return node;
}

bool push(stack_t stack, int value){
    node_t node = make_node(value);
    if(node == NULL)return false;

    node->next = stack->top;
    stack->top = node;

    return true;
}

bool pop(stack_t stack, int* value){
    if(stack->top == NULL)return false;

    *value = stack->top->value;

    node_t aux = stack->top;

    stack->top = stack->top->next;

    free(aux);

    return true;
}

void drop_stack(stack_t stack){
    int x;

    while(pop(stack, &x));

    free(stack);
}