/*
 * This program aims to swap two numbers from two
 * different positions of a stack, using only stacks.
 * I do not know why I am doing this but I do know
 * that I'm loving it :D
 *
 * Author: Saikat Basak
 */

#include <stdio.h>
#define MAXSIZE 10

typedef struct {
    int element[MAXSIZE];
    int top;
} Stack;

initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int ele) {
    /*
     * i do not require the stack overflow condition here
     */
    stack->top += 1;
    stack->element[stack->top] = ele;
}

int pop(Stack* stack) {
    int tmp = stack->element[stack->top];
    stack->top -= 1;

    return tmp;
}

void display(Stack* stack) {
    int i;

    for(i=0 ; i<=stack->top ; i++) {
        printf("[ %3d ]", stack->element[i]);
    }
    printf("\n");
}

int swap(Stack* stack, int pos1, int pos2) {
    Stack anotherStack;
    initStack(&anotherStack);

    Stack backupStack;
    initStack(&backupStack);

    Stack yetAnotherStack;
    initStack(&yetAnotherStack);

    /*
     * push all items of the primary stack, except
     * the items in positions pos1 and pos2 to the
     * backupStack; the items in pos1 and pos2 goes
     * to anotherStack.
     */
    int i,
        h = stack->top;

    for(i=stack->top ; i>=0 ; i--) {
        if(i == pos1 || i == pos2) {
            push(&anotherStack, pop(stack));
        }
        else {
            push(&backupStack, pop(stack));
        }
    }

    /*
     * pop items from another stack to yetAnotherStack.
     */
    for(i=0 ; i<2 ; i++) {
        push(&yetAnotherStack, pop(&anotherStack));
    }

    /*
     * recreate the primary stack popping items from
     * yetAnotherStack(in pos1 and pos2) and backupStack.
     */
    for(i=0 ; i<=h ; i++) {
        if(i == pos1 || i == pos2) {
            push(stack, pop(&yetAnotherStack));
        }
        else {
            push(stack, pop(&backupStack));
        }
    }
}

int main() {
    /*
     * creating the primary stack; this will hold
     * some integer numbers for god knows what purpose.
     */
    Stack primaryStack;
    initStack(&primaryStack);

    /*
     * feed integer numbers to the primary stack;
     * one may insert any number of integers and
     * choose which two numbers to be swapped in
     * a later stage.
     */
    int n;

    printf("Number of integers to be fed to the Primary Stack? ");
    scanf("%d", &n);

    printf("\n// Feed integer numbers to the Primary Stack //\n");
    printf(">> "); //-- just some lame decoration, don't mind

    int i, ele;

    for(i=0 ; i<n ; i++) {
        if(i == MAXSIZE) {
            printf(">>> Stack overflow! pushed first %d items...\n", i);
            break;
        }
        else {
            scanf("%d", &ele);
            push(&primaryStack, ele);
        }
    }

    /*
     * enter the positions(array indexes) of the
     * integers to be swapped.
     */
    int pos1, pos2;

    printf("\n// Enter the positions to be swapped(index starts from 0) //\n");
    printf(">> "); //-- i had an urge to put a comment here
    scanf("%d %d", &pos1, &pos2);

    /*
     * "Well, there are Switching Spells... but what's
     * the point of Switching it? Unless you swapped
     * its fangs for wine-gums or something that would
     * make it less dangerous..." — Hermione
     *
     * anyway, let the swapping begin...
     */
    if(
            pos1 > primaryStack.top ||
            pos2 > primaryStack.top ||
            pos1 < 0 || pos2 < 0) {
        printf("ERROR!! Position(s) does not exist...\n");
    }
    else {
        swap(&primaryStack, pos1, pos2);
    }

    /*
     * i am not a big fan of Harry Potter but i love Hermione.
     */
    printf("\n// Displaying the Primary Stack after swapping //\n");
    display(&primaryStack);

    return 0; //-- live long, and prosper
}
