#include <stdio.h>

#include "queue.h"

int main(void){
    queue_t Q;
    int x;

    stage_queue(&Q);

    if(is_empty(Q))printf("A fila está vazia.\n");

    printf("Enfileirando...\n");
    for(x = 1; x <= 10; x++)
        enqueue(&Q, x);

    if(is_full(Q))printf("A fila está cheia.\n");

    if(!enqueue(&Q, x))printf("Não é possível enfileirar mais elementos.\n");

    printf("Desenfileirando...\n");
    while(dequeue(&Q, &x)){
        printf("%d\n", x);
    }

    if(!dequeue(&Q, &x))printf("Não é possível desenfileirar mais elementos.\n");

    return 0;
}