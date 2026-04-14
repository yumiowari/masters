#ifndef QUEUE_HPP
#define QUEUE_HPP

#define SIZE 10

typedef struct queue{
    int V[SIZE];

    int s; // start index
    int e; // end index

    int n; // nº de elementos na fila
}queue_t;

void stage_queue(queue_t&);

bool is_empty(queue_t);

bool is_full(queue_t);

bool enqueue(queue_t&, int);

bool dequeue(queue_t&, int&);

#endif // QUEUE_HPP
