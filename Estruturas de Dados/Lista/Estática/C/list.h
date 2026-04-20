#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define SIZE 10

typedef struct list{
    int V[SIZE];
    int n;
}list_t;

void _start_list(list_t *L);

bool _is_full(list_t L);

bool _is_empty(list_t L);

bool _insert(list_t *L, int x);

bool _remove(list_t *L, int x);

#endif // LIST_H