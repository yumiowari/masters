#ifndef LIST_HPP
#define LIST_HPP

typedef struct node node_t;
typedef struct list list_t;

list_t* _make_list();

node_t* _make_node(int);

bool _is_empty(list_t*);

bool _insert(list_t*, int);

bool _remove(list_t*, int);

void _print_list(list_t*);

void _free_list(list_t*);

#endif // LIST_HPP