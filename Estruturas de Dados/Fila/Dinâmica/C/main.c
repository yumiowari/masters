#include <stdio.h>

#include "queue.h"

int main(void){
    queue_t Q = stage_queue();
    int x;

    if(is_empty(Q))printf("A fila está vazia.\n");

    printf("Enfileirando...\n");
    for(x = 1; x <= 10; x++)
        enqueue(Q, x);

    printf("Desenfileirando...\n");
    while(dequeue(Q, &x)){
        printf("%d\n", x);
    }

    destage_queue(Q);

    return 0;
}