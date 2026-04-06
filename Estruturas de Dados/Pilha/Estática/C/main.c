#include <stdio.h>

#include "stack.h"

int main(void){
    stack_t stack;
    int x;

    lift_stack(&stack);

    if(is_empty(stack))printf("A pilha está vazia.\n");

    printf("Empilhando...\n");
    for(x = 1; x <= 10; x++)
        push(&stack, x);

    if(is_full(stack))printf("A pilha está cheia.\n");

    if(!push(&stack, x))printf("Não é possível empilhar mais elementos.\n");

    printf("Desempilhando...\n");
    while(!is_empty(stack)){
        pop(&stack, &x);

        printf("%d\n", x);
    }

    if(!pop(&stack, &x))printf("Não é possível desempilhar mais elementos.\n");

    return 0;
}