#include "bst.h"

void insert(tree_node_t ** root, tree_node_t * node) {
    if(!(*root)) {
        *root = node;
    }
    else {
        if(node->data <= (*root)->data) {
            insert(&(*root)->left, node);
        }
        else if(node->data > (*root)->data) {
            insert(&(*root)->right, node);
        }
    }
}

void find(tree_node_t * root, int * data) {
    if(!root) {
        printf("\n>>> Data does not exist!!\n");
    }
    else {
        if(*data < root->data) {
            find(root->left, data);
        }
        else if(*data > root->data) {
            find(root->right, data);
        }
        else {
            printf("\n>>> Data found!!\n");
        }
    }
}

void findMax(tree_node_t * root) {
    if(!root) {
        printf("\n>>> Create a TREE first.\n");
    }
    else if (root->right == NULL){
        printf("\nThe maximum is : %d\n", root->data);
    }
    else {
        findMax(root->right);
    }
}

void findMin(tree_node_t * root) {
    if(!root) {
        printf("\n>>> Create a TREE first.\n");
    }
    else if (root->left == NULL){
        printf("\nThe minimum is : %d\n", root->data);
    }
    else {
        findMin(root->left);
    }
}

void viewInOrder(tree_node_t * root) {
    if(root->left) {
        viewInOrder(root->left);
    }
    printf("%d ", root->data);
    if(root->right) {
        viewInOrder(root->right);
    }
}

void viewPreOrder(tree_node_t * root) {
    printf("%d ", root->data);
    if(root->left) {
        viewPreOrder(root->left);
    }
    if(root->right) {
        viewPreOrder(root->right);
    }
}

void viewPostOrder(tree_node_t * root) {
    if(root->left) {
        viewPostOrder(root->left);
    }
    if(root->right) {
        viewPostOrder(root->right);
    }
    printf("%d ", root->data);
}
