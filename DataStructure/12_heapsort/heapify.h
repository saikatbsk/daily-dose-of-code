#ifndef _HEAPIFY_H_
#define _HEAPIFY_H_

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

void maxHeapify(int *, int, int);
void buildMaxHeap(int *, int);
void minHeapify(int *, int, int);
void buildMinHeap(int *, int);
void swap(int *, int *);

#endif
