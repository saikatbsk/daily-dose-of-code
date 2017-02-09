#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void queueInit(Queue_t * Q) {
    Q->begin = -1;
    Q->end   = -1;
}

int extractHead(Queue_t * Q) {
    int head;

    if(Q->end - Q->begin <= 0)
        head = -1;
    else {
        head = Q->item[Q->begin];
        Q->begin += 1;
    }

    return head;
}

void append2Queue(Queue_t * Q, int item) {
    if(Q->begin < 0) {
        Q->begin += 1;
        Q->end   += 1;
    }

    Q->item[Q->end] = item;
    Q->end += 1;
}

void displayQueue(Queue_t Q) {
    int i;

    for(i = Q.begin ; i < Q.end ; i++)
        fprintf(stdout, "%d ", Q.item[i]);

    fprintf(stdout, "\n");
}

void findNeighbours(Queue_t * Q, int adjMat[][MAXVAL], int nNodes, int node) {
    int i;

    for(i = 0 ; i < nNodes ; i++)
        if(adjMat[node - 1][i] == 1 && (node - 1) != i)
            append2Queue(Q, i + 1);
}

void findPath(Queue_t * path, int parent[], int start, int end) {
    if(start == end) {
        append2Queue(path, start);

        return;
    }

    append2Queue(path, start);
    findPath(path, parent, parent[start], end);
}

Result_t BFS(int adjMat[][MAXVAL], int start, int nNodes, int key) {
    int j, k;
    int level[nNodes];
    int parent[nNodes];

    Result_t r;
    r.found = 0;
    r.distance = -1;

    Queue_t ne;
    Queue_t Q;
    Queue_t P;

    /* Initialization */
    for(j = 1 ; j <= nNodes ; j++) {
        level[j]  = -1;
        parent[j] = -1;
    }
    queueInit(&ne);
    queueInit(&Q);
    queueInit(&P);

    /* Start exploration at start */
    level[start] = 0;
    append2Queue(&Q, start);

    /* Explore each vertex in Q */
    while(Q.end - Q.begin > 0) {
        j = extractHead(&Q);

        if(j == key) {
            r.found = 1;
            r.distance = level[j];
            findPath(&r.Path, parent, j, start);

            return r;
        }

        queueInit(&ne);
        findNeighbours(&ne, adjMat, nNodes, j);

        while(ne.end - ne.begin > 0) {
            k = extractHead(&ne);

            if(level[k] == -1) {
                level[k]  = 1 + level[j];
                parent[k] = j;
                append2Queue(&Q, k);
            }
        }
    }

    return r;
}
