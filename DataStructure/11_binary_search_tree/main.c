/*
 * Binary Search Tree implementation using recursion.
 * Compile with gcc,
 *              gcc main.c bst.c
 */

#include "bst.h"

int main() {
    int choice;
    int data;
    tree_node_t * root;
    tree_node_t * curr;
    root = NULL;

    while(1) {
        printf("\n1. Insert element into tree.");
        printf("\n2. Find an element from tree.");
        printf("\n3. Find the maximum.");
        printf("\n4. Find the minimum.");
        printf("\n5. Display the tree.");
        printf("\n0. EXIT.");
        printf("\nyour choice? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);

                curr = (tree_node_t *)malloc(sizeof(tree_node_t));
                curr->left = curr->right = NULL;
                curr->data = data;

                insert(&root, curr);
                root->nNodes = root->nNodes + 1;

                break;
            case 3:
                findMax(root);

                break;
            case 4:
                findMin(root);

                break;
            case 2:
                printf("\nEnter the element you want to find: ");
                scanf("%d", &data);

                find(root, &data);

                break;
            case 5:
                printf("\nViewing Depth First..");

                printf("\nIn-Order View of the TREE   : ");
                viewInOrder(root);

                printf("\nPre-Order View of the TREE  : ");
                viewPreOrder(root);

                printf("\nPost-Order View of the TREE : ");
                viewPostOrder(root);

                printf("\nTotal %d node(s) displayed.", root->nNodes);

                printf("\n");

                break;
            case 0:
                exit(0);
            default:
                printf("\n>>> Wrong choice. \n");

                break;
        }
    }

    return 0;
}
