/* ==================================================================
 * Assignment 04
 * ------------------------------------------------------------------
 * A program to implement the queue data structure.
 * ==================================================================
 */

#include <iostream>
#include <stdlib.h>
#define MAXITEMS 100
using namespace std;

class Queue {
    int front;
    int rear;
    int data[MAXITEMS];
public:
    void init();
    void enqueue(int item);
    void dequeue();
    void display();
};

void Queue::init() {
    front = -1;
    rear = -1;
}

void Queue::enqueue(int item) {
    if(rear > MAXITEMS)
        cout << ">>> Queue overflow.\n";
    else {
        if(front < 0)
            front++;

        rear++;
        data[rear] = item;
    }
}

void Queue::dequeue() {
    if(front < 0 || front > rear) {
        cout << ">> Queue empty.\n";

        init(); //-- Reset the queue for re-usability.
    }
    else {
        cout << "Removing " << data[front] << "\n";
        front++;
    }
}

void Queue::display() {
    if(front < 0 || front > rear) {
        cout << ">> Queue empty.\n";
        return;
    }

    for(int i = front ; i <= rear ; i++)
        cout << data[i] << " ";
    cout << "\n";
}

int main() {
    int op, item;
    Queue q;

    q.init();

    while(1) {
        cout << "\n"
             << "\tChoose an option..\n"
             << "\t1. Insert item into queue.\n"
             << "\t2. Delete an item from queue.\n"
             << "\t3. Display existing queue.\n"
             << "\t4.Exit\n"
             << "(1/2/3/4)? ";

        cin >> op;

        switch(op) {
            case 1:
                cout << "Item to insert: ";
                cin >> item;

                q.enqueue(item);

                break;
            case 2:
                q.dequeue();

                break;
            case 3:
                q.display();

                break;
            case 4:
                exit(0);
            default:
                continue;
        }
    }

    return 0;
}
