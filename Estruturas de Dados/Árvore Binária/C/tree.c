#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct tree{
    int qty; // Quantidade de nós na árvore
    struct node* root;
};

tree_t create_tree(){
    tree_t tree = (tree_t) malloc(sizeof(struct tree));
    if(!tree)return NULL;

    tree->qty = 0;
    tree->root = NULL;

    return tree;
}

node_t create_node(int data){
    node_t node = (node_t) malloc(sizeof(struct node));
    if(!node)return NULL;

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool is_empty(tree_t tree){
    return tree->root == NULL;
}

bool insert_node(tree_t tree, int data){
    if(tree == NULL)return false;

    if(is_empty(tree)){
        tree->root = create_node(data);
        
        return true;
    }else{
        node_t next = tree->root;
        node_t prev = NULL;

        // Percorre a árvore até encontrar o nó folha onde o novo nó deve ser inserido
        while(next != NULL){
            prev = next;

            if(next->data == data)
                return false; // O nó já existe na árvore, não insere a duplicata

            if(data < next->data)
                next = next->left;
            else
                next = next->right;
        }

        if(data < prev->data)
            prev->left = create_node(data);
        else
            prev->right = create_node(data);
    }

    tree->qty++;

    return true;
}

bool remove_node(tree_t tree, int data){
    if(tree == NULL || is_empty(tree))return false;

    node_t next = tree->root;
    node_t prev = NULL;

    while(next != NULL){
        if(next->data == data){
            if(next->left == NULL && next->right == NULL){
            // Remoção de nó folha
            
                if(prev == NULL)
                    tree->root = NULL;
                else if(prev->left == next)
                    prev->left = NULL;
                else
                    prev->right = NULL;

                free(next);

                tree->qty--;
                return true;
            }else if(next->left == NULL || next->right == NULL){
            // Remoção de nó com um filho

                node_t child = (next->left != NULL) ? next->left : next->right;

                if(prev == NULL)
                    tree->root = child;
                else if(prev->left == next)
                    prev->left = child;
                else
                    prev->right = child;

                free(next);

                tree->qty--;
                return true;
            }else{
            // Remoção de nó com dois filhos

                node_t successor = next->right;
                node_t successor_prev = next;

                // Encontra o sucessor: o filho mais à esquerda da subárvore direita
                while(successor->left != NULL){
                    successor_prev = successor;

                    successor = successor->left;
                }

                next->data = successor->data; // Substitui o valor do nó a ser removido pelo valor do sucessor

                if(successor_prev->left == successor)
                    successor_prev->left = successor->right;
                else
                    successor_prev->right = successor->right;

                free(successor);

                tree->qty--;
                return true;
            }
        }else{
            prev = next;

            if(data < next->data)
                next = next->left;
            else
                next = next->right;
        }
    }

    return false; // O nó a ser removido não foi encontrado na árvore
}

bool search_node(tree_t tree, int data){
    if(tree == NULL || is_empty(tree))return false;

    node_t next = tree->root;

    while(next != NULL){
        if(next->data == data)
            return true;
        else if(data < next->data)
            next = next->left;
        else
            next = next->right;
    }

    return false; // O nó buscado não foi encontrado na árvore
}

// Função auxiliar para liberar os nós da árvore recursivamente
void destroy_node_rec(node_t node){
    if(node != NULL){
        destroy_node_rec(node->left);
        destroy_node_rec(node->right);

        free(node);
    }
}

bool destroy_tree(tree_t tree){
    if(tree == NULL)return false;

    destroy_node_rec(tree->root);
    free(tree);

    return true;
}

void in_order_rec(node_t node){
    if(node != NULL){
        in_order_rec(node->left);
        printf("%d ", node->data);
        in_order_rec(node->right);
    }
}

bool in_order(tree_t tree){
    if(tree == NULL || is_empty(tree))return false;

    in_order_rec(tree->root);
    printf("\n");

    return true;
}

void pre_order_rec(node_t node){
    if(node != NULL){
        printf("%d ", node->data);
        pre_order_rec(node->left);
        pre_order_rec(node->right);
    }
}

bool pre_order(tree_t tree){
    if(tree == NULL || is_empty(tree))return false;

    pre_order_rec(tree->root);
    printf("\n");

    return true;
}

void post_order_rec(node_t node){
    if(node != NULL){
        post_order_rec(node->left);
        post_order_rec(node->right);
        printf("%d ", node->data);
    }
}

bool post_order(tree_t tree){
    if(tree == NULL || is_empty(tree))return false;

    post_order_rec(tree->root);
    printf("\n");

    return true;
}