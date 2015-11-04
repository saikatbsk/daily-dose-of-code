#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_THREAD 10

pthread_mutex_t mutex;
int counter = 0;

void* justAnotherFunction(void* arg) {
    long threadID = (long) arg;

    printf("Thread #%ld attempting to incrementing counter..\n", threadID);

    /* lock mutex variable */
    pthread_mutex_lock(&mutex);

    //sleep(1);
    counter++;
    printf("Thread #%ld incremented counter to %d.\n", threadID, counter);

    /* unlock mutex variable */
    pthread_mutex_unlock(&mutex);

    pthread_exit((void*) threadID);
}

int main() {
    long tID;
    int ret;
    void* status;

    pthread_t thread[MAX_THREAD];
    pthread_attr_t attr;

    /* initialize mutex variable */
    pthread_mutex_init(&mutex, NULL);

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

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
    return 0;
}
