/* INCOMPLETE */
class Queue {
    final int MAXITEMS = 100;

    int Items[];
    int front;
    int rear;

    Queue() {
        Items[] = new int[MAXITEMS];
        front = -1;
        rear  = -1;
    }

    void enqueue(int item) {    //-- add an item at the rear end
        if(rear > MAXITEMS)
            System.out.println("Queue overflow!");
        else {
            if(front < 0)
                front = front + 1;

            rear = rear + 1;
            Items[rear] = item;
        }
    }

    void dequeue() {            //-- delete an item from the front end
        if(front < 0 || front > rear) {
            System.out.println("Queue underflow!");

            /* Reset queue */
            front = -1;
            rear  = -1;
        }
        else {
            front = front + 1;
        }
    }
}
