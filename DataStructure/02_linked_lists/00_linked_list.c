#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node_t;

int main() {
    int val, pos, _pos, length, c, i;

    node_t * first;     //-- To be used as pointer to the first node
    node_t * last;      //-- To be used as pointer to the last node
    node_t * ptr;       //-- To be used as a movable marker

    /* Initialize all the pointers to NULL */
    first = NULL;
    last  = NULL;
    ptr   = NULL;

    node_t * NODE;      //-- Temporary pointer to any node created

    /* We are writing a simple text based menu driven program */
    while(1) {
        printf("\n");
        printf("1. Insert a New Node.\n");
        printf("2. Display the List.\n");
        printf("3. Exit\n");
        printf("? ");
        scanf("%d", &c);

        switch(c) {
            case 1:
                /* Scan the data to be inserted */
                printf("\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &val);

                /* Creating a temporary node */
                NODE = (node_t *)malloc(sizeof(node_t));
                NODE->data = val;
                NODE->next = NULL;

                /* Ask user for the location */
                printf("\n");
                printf("Location to insert node:\n");
                printf("\t[Beginning(0) | End(1) | InBetween(2): (Default: 0)] ");
                scanf("%d", &pos);

                switch(pos) {
                    case 1:     //-- Insert node at the end
                        if(first == NULL) {
                            first = NODE;
                            last  = first;
                        }
                        else {
                            last->next = NODE;
                            last       = NODE;
                        }

                        length++;

                        break;

                    case 2:     //-- Insert node within an existing list
                        if(first == NULL /* List does not exist */ || last == first /* There is only one node */) {
                            printf(">>> First create a list with at least 2 nodes.\n");
                        }
                        else {
                            printf("Enter position to insert node (1 - %d): ", length - 1);
                            scanf("%d", &_pos);

                            if(_pos < 1 || _pos > length - 1) {
                                printf(">>> Position should be within 1 to %d\n", length - 1);
                            }
                            else {
                                ptr = first;
                                i = 0;

                                while(i < _pos - 1) {
                                    ptr = ptr->next;
                                    i++;
                                }

                                NODE->next = ptr->next;
                                ptr->next  = NODE;

                                length++;
                            }
                        }

                        break;

                    default:
                    case 0:     //-- Insert node in the beginning
                        if(first == NULL) {
                            first = NODE;
                            last  = first;
                        }
                        else {
                            NODE->next = first;
                            first      = NODE;
                        }

                        length++;

                        break;
                }

                break;

            case 2:
                ptr = first;

                printf("\n");
                while(ptr != NULL) {
                    printf("[ %d ]-->", ptr->data);
                    ptr = ptr->next;
                }
                printf("NULL\n");

                break;

            case 3:
                exit(0);

            default:
                printf(">>> Wrong choice!\n");
        }
    }
}
