/*
 * Introduction to POSIX thread; passing structures as arguments to
 * pthreads. Compile using gcc:
 *                              gcc -o argPass main.c -pthread
 */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_THREAD 8

typedef struct thread_data {
    int threadID;
    char *message;
} thread_data_t;

thread_data_t thread_data_array[MAX_THREAD];

void* printHello(void* arg) {
    thread_data_t* data;
    data = (thread_data_t*) arg;

    long threadID  = data->threadID;
    char* message = data->message;

    sleep(1);
    fprintf(stdout, "Thread #%ld says, %s\n", threadID, message);

    pthread_exit(NULL);
}

int main() {
    long tID;
    int ret;
    pthread_t thread[MAX_THREAD];

    char** messages;
    messages[0] = "Hello World!";        //-- English
    messages[1] = "Bonjour, le monde!";  //-- French
    messages[2] = "Hola al mundo!";      //-- Spanish
    messages[3] = "Nuq neH!";            //-- Klingon
    messages[4] = "Guten Tag, Welt!";    //-- German
    messages[5] = "Zdravstvytye, mir!";  //-- Russian
    messages[6] = "Sekai e konnichiwa!"; //-- Japanese
    messages[7] = "Orbis, te saluto!";   //-- Latin

    for(tID=0 ; tID<MAX_THREAD ; tID++) {
        thread_data_array[tID].threadID = tID;
        thread_data_array[tID].message  = messages[tID];

        printf(">>> Creating thread...\n");
        ret = pthread_create(
                &thread[tID], NULL,
                printHello, (void*) &thread_data_array[tID]);
        if(ret) {
            printf("ERROR!! pthread_create terminated with exit code: %d", ret);
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);

    return 0;
}
