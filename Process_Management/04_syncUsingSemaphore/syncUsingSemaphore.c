#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_THREAD 10

sem_t mutex; //-- semaphore is used as a mutex
int counter = 0;

void* justAnotherFunction(void* arg) {
    long threadID = (long) arg;

    printf("Thread #%ld attempting to incrementing counter..\n", threadID);

    /* down semaphore */
    sem_wait(&mutex);

    //sleep(1);
    counter++;
    printf("Thread #%ld incremented counter to %d.\n", threadID, counter);

    /* up semaphore */
    sem_post(&mutex);

    pthread_exit((void*) threadID);
}

int main() {
    long tID;
    int ret;
    void* status;

    pthread_t thread[MAX_THREAD];
    pthread_attr_t attr;

    /* initialize mutex variable */
    sem_init(&mutex, 0, 1); /* second param = 0 - semaphore is local */
    /* initialize mutex to 1 - binary semaphore */

    /* initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* creating threads */
    for(tID = 0 ; tID < MAX_THREAD ; tID++) {
        if((ret = pthread_create(
                        &thread[tID], &attr, justAnotherFunction, (void*) tID)) > 0) {
            printf(
                    "ERROR! pthread_create for thread #%ld terminated. Err code: %d\n",
                    tID, ret);
            exit(EXIT_FAILURE);
        }
    }

    /* free attribute and wait for other threads */
    pthread_attr_destroy(&attr);

    for(tID = 0 ; tID < MAX_THREAD ; tID++) {
        if((ret = pthread_join(thread[tID], &status)) > 0) {
            printf(
                    "ERROR! pthread_join for thread #%ld terminated. Err code: %d\n",
                    tID, ret);
            exit(EXIT_FAILURE);
        }
    }

    sem_destroy(&mutex);
    pthread_exit(NULL);
    return 0;
}
