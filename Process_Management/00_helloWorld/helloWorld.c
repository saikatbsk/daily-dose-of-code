/*
 * Introduction to POSIX threads; a simple Hello World program.
 * Compile with gcc:
 *                  gcc -o helloWorld main.c -pthread
 */

#include <pthread.h> //-- required header for pthread
#include <stdlib.h>
#include <stdio.h>
#define MAX_THREAD 10 //-- define max number of threads

void* printHello(void* arg) {
    long pID = (long) arg;

    printf("Hello World! I'm in thread #%ld\n", pID);
    pthread_exit(NULL); //-- exit pthread
} /* --- printHello function; to be fed to pthread_create --- */

int main(int argc, char* argv[]) {
    int ret;
    long pID;
    pthread_t thread[MAX_THREAD]; //-- declare a pthread

    for(pID=0 ; pID<MAX_THREAD ; pID++) {
        /*
         * the pthread_create() function creates a pthread; to know more
         * about function prototype see manual page for pthread_create;
         */
        ret = pthread_create(&thread[pID], NULL, printHello, (void*) pID);
        if(ret) {
            printf("Error!! pthread_create terminated with exit code: %d\n", ret);
        } //-- pthread_create returns the error code on error
    }

    pthread_exit(NULL); //-- finally call pthread_exit from main

    return 0;
} /* --- fin --- */
