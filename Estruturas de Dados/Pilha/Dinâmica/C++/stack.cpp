#include "stack.hpp"

struct node{
    struct node *next;
    int value;
};

struct stack{
    struct node *top;
};

stack_t* lift_stack(){
    stack_t* stack = new stack_t;
    if(stack == nullptr)return nullptr;

    stack->top = nullptr;

    return stack;
}

node_t* make_node(int value){
    node_t* node = new node_t;
    if(node == nullptr)return nullptr;

    node->next = nullptr;
    node->value = value;

    return node;
}

bool push(stack_t* stack, int value){
    node_t* node = make_node(value);
    if(node == nullptr)return false;

    node->next = stack->top;
    stack->top = node;

    return true;
}

bool pop(stack_t* stack, int& value){
    if(stack->top == nullptr)return false;

    value = stack->top->value;

    node_t* aux = stack->top;

    stack->top = stack->top->next;

    delete aux;

    return true;
}

void drop_stack(stack_t* stack){
    int x;

    while(pop(stack, x));

    delete stack;
}