#ifndef _BFS_H_
#define _BFS_H_
#define MAXVAL 1000

typedef struct Queue {
    int begin;
    int end;
    int item[MAXVAL];
} Queue_t;

typedef struct Result {
    int found;
    int distance;
    Queue_t Path;
} Result_t;

/* --- --- Queue operations --- --- */
void queueInit(Queue_t * Q);
int  extractHead(Queue_t * Q);
void append2Queue(Queue_t * Q, int item);
void displayQueue(Queue_t Q);

/* --- --- BFS operations --- --- */
void findNeighbours(Queue_t * Q, int adjMat[][MAXVAL], int nNodes, int node);
void findPath(Queue_t * path, int parent[], int start, int end);
Result_t BFS(int adjMat[][MAXVAL], int start, int nNodes, int key);

#endif
