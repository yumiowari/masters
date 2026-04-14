#ifndef QUEUE_HPP
#define QUEUE_HPP

typedef struct node node_t;
typedef struct queue queue_t;

queue_t* stage_queue();

bool is_empty(queue_t*);

bool enqueue(queue_t*, int);

bool dequeue(queue_t*, int*);

void destage_queue(queue_t*);

#endif // QUEUE_HPP