/*
 * This is an example of POSIX process synchronization;
 * Given problem given is,
 *      Using semaphore design a system which will print
 *      010101010 where ‘0’ stands for process 1 and ‘1’ stands for
 *      process 2.
 */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define NUM_THREADS 2
#define MAX_COUNT   6

sem_t mutex;      //-- mutex variable
long syncCounter; //-- a shared resource

void init() {
    syncCounter = 2;
    sem_init(&mutex, 0, 1); //-- initializing a binary semaphore
}

void* print(void* arg) {
    int count = MAX_COUNT;
    long threadID = (long) arg;

    while(count) {
        if(syncCounter%2 == threadID) {
            sem_wait(&mutex);
            fprintf(stdout, "%ld ", threadID);
            syncCounter++;
            count--;
            sem_post(&mutex);
        }
    }

    pthread_exit((void*) threadID);
}

int main() {
    int ret;
    long tID;
    void* status;
    pthread_t thread[NUM_THREADS];
    pthread_attr_t attr;

    init();

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(tID = 0 ; tID < NUM_THREADS ; tID++) {
        ret = pthread_create(&thread[tID], &attr, print, (void*) tID);
        if(ret) {
            fprintf(
                    stderr,
                    "ERROR!! pthread_create terminated with exit status: %d\n",
                    ret);
            exit(EXIT_FAILURE);
        }
    }

    pthread_attr_destroy(&attr);

    for(tID = 0 ; tID < NUM_THREADS ; tID++) {
        ret = pthread_join(thread[tID], &status);
        if(ret) {
            fprintf(
                    stderr,
                    "ERROR!! pthread_join terminated with exit status: %d\n",
                    ret);
            exit(EXIT_FAILURE);
        }
    }

    fprintf(stdout, "\n");
    fprintf(stdout, "Exiting main...\n");

    sem_destroy(&mutex);
    pthread_exit(NULL);
}
