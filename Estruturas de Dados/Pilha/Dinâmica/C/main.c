#include <stdio.h>

#include "stack.h"

int main(void){
    stack_t stack = lift_stack();
    int x;

    printf("Empilhando...\n");
    for(x = 1; x <= 10; x++)
        push(stack, x);

    printf("Desempilhando...\n");
    while(pop(stack, &x)){
        printf("%d\n", x);
    }

    drop_stack(stack);

    return 0;
}