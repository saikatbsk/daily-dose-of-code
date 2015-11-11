#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

int main() {
    int i, j;
    int key, start;
    int nNodes;                         //-- Total number of nodes
    int adjMat[MAXVAL][MAXVAL];         //-- Adjacency matrix

    Result_t r;

    FILE * fp;

    if(!(fp = fopen("data.txt", "r+"))) {
        fprintf(stderr, ">>> Error! Input file specified does not exist!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", &nNodes);
    for(i = 0 ; i < nNodes ; i++) {
        for(j = 0 ; j < nNodes ; j++) {
            fscanf(fp, "%d", &adjMat[i][j]);
        }
    }

    fprintf(stdout, "Enter search key (node you want to search): ");
    fscanf(stdin, "%d", &key);

    fprintf(stdout, "Where to begin the search? ");
    fscanf(stdin, "%d", &start);

    r = BFS(adjMat, start, nNodes, key);

    if(r.found == 1) {
        fprintf(stdout, "Node %d reached! Distance from parent = %d\n", key, r.distance);
        fprintf(stdout, "Path from node %d to %d: ", key, start);
        displayQueue(r.Path);
    }
    else
        fprintf(stdout, "Node %d could not be reached!\n", key);

    return 0;
}
