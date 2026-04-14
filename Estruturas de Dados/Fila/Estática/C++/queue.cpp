#include "queue.hpp"

void stage_queue(queue_t& Q){
    Q.s = 0;
    Q.e = -1;

    Q.n = 0;
}

bool is_empty(queue_t Q){
    return Q.n == 0;
}

bool is_full(queue_t Q){
    return Q.n == SIZE;
}

bool enqueue(queue_t& Q, int x){
    if(is_full(Q))return false;

    Q.n++;
    Q.e = (Q.e + 1) % SIZE;
    Q.V[Q.e] = x;

    return true;
}

bool dequeue(queue_t& Q, int& x){
    if(is_empty(Q))return false;

    Q.n--;
    x = Q.V[Q.s];
    Q.s = (Q.s + 1) % SIZE;

    return true;
}