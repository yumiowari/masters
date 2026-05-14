#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct node* node_t;
typedef struct tree* tree_t;

tree_t create_tree();

bool is_empty(tree_t);

bool insert_node(tree_t, int);

bool remove_node(tree_t, int);

bool search_node(tree_t, int);

bool destroy_tree(tree_t);

bool in_order(tree_t);
bool pre_order(tree_t);
bool post_order(tree_t);

#endif // TREE_H