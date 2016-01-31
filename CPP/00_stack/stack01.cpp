#include <iostream>
#define MAXSIZE 100

using namespace std;

class Stack {
    int items[MAXSIZE];
    int top;
public:
    void init();
    void push(int item);
    int pop();
};

void Stack::init() {
    top = 0;
}

void Stack::push(int item) {
    /*
     * If top is less than MAXSIZE  (that is,  if there is still some
     * space left) add the item to items array,  and increase current
     * numerical value of top.
     */
    if(top < MAXSIZE) {
        items[top] = item;
        top++;
    }
    else {      //-- No space left for a new item.
        cout << ">>> Stack overflow!\n";
    }
}

int Stack::pop() {
    /*
     * If numerical value of top  is greater than zero decrease value
     * of top  (as the last legitimate item was at position top - 1),
     * and return the element  that is in  the position indicated by
     * the current numerical value of top, from items array.
     */
    if(top > 0) {
        top--;
        return items[top];
    }

    return 0;
}

int main() {
    int c, e;
    Stack myStack;

    myStack.init();

    while(1) {
        cout << "Choose option:\n"
             << "\t1. Push an item into stack.\n"
             << "\t2. Pop an item from stack.\n"
             << "\t3. Exit.\n"
             << "\t? ";

        take_input:     //-- This is a label
        cin >> c;

        switch(c) {
            case 1:
                cout << "Enter an element: ";
                cin >> e;

                myStack.push(e);
                break;
            case 2:
                cout << "Popped " << myStack.pop() << endl;
                break;
            case 3:
                return 1;
            default:
                cout << "(1/2/3) ? ";
                goto take_input;
        }
    }

    return 0;
}
