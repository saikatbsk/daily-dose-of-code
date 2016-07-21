/*
 * Introduction to pthread; initializing and setting
 * thread detached attribute and pthread joining;
 */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_THREAD 5

void* calculateSum(void* arg) {
    int i;
    long sum = 0;
    long threadID = (long) arg;

    for(i=0 ; i<1000000 ; i++) {
        sum += i + rand();
    }

    printf("Thread #%ld done. Sum= %ld\n", threadID, sum);
    pthread_exit((void*) sum);
}

int main() {
    int ret;
    long tID;
    void* status;
    pthread_t thread[MAX_THREAD]; //-- declare pthreads
    pthread_attr_t attr;          //-- declare pthread attribute variable

    /* initilize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(tID=0 ; tID<MAX_THREAD ; tID++) {
        printf(">>> Creating threads...\n");
        ret = pthread_create(&thread[tID], &attr, calculateSum, (void*) tID);
        if(ret) {
            printf("ERROR!! pthread_create terminated with exit code: %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }

    /* free attribute and wait for other threads */
    pthread_attr_destroy(&attr);
    for(tID=0 ; tID<MAX_THREAD ; tID++) {
        ret = pthread_join(thread[tID], &status);
        if(ret) {
            printf("ERROR!! pthread_join terminated with exit code: %d\n", ret);
            exit(EXIT_FAILURE);
        }

        printf(">>> Completed join with thread #%ld having status %ld\n",
                tID, (long) status);
    }

    printf(">>> Exiting...\n");
    pthread_exit(NULL);

    return 0;
}
