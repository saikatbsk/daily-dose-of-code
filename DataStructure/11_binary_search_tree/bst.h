#ifndef _BST_H_
#define _BST_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node {
    int data;
    int nNodes;

    struct tree_node * left;
    struct tree_node * right;
} tree_node_t;

void insert(tree_node_t ** root, tree_node_t * node);
void find(tree_node_t * root, int * data);
void findMax(tree_node_t * root);
void findMin(tree_node_t * root);
void viewInOrder(tree_node_t * root);
void viewPreOrder(tree_node_t * root);
void viewPostOrder(tree_node_t * root);

#endif
