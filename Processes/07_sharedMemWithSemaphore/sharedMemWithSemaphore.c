/*
 * A simple semaphore example using Sys V IPC type segments
 * Consumer creates a semaphore and blocks
 * Producer attaches to the semaphore and signals
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>

/* semun may be defined on some systems */
union semun {
    int val;                      /* value for SETVAL */
    struct semid_ds *buf;         /* buffer for IPC_STAT, IPC_SET */
    unsigned short int *array;    /* array for GETALL, SETALL */
    struct seminfo *__buf;        /* buffer for IPC_INFO */
};

#define KEY 3013        /* identification key to get segment */
#define PERMS 0666      /* -rw-rw-rw- */
#define MEMSIZE 80      /* bytes to allocate */

int main(int argc, char* argv[]) {
    union semun arg;      /* used to set semaphore parameters */
    struct sembuf sembuf; /* used to do a wait and signal */
    int semID;            /* the shared memory id */
    int flags;            /* flags for semget() call */

    /* check command line args */
    if((argc != 2) || (argv[1][0] != 'p' && argv[1][0] != 'c')) {
        fprintf(stderr, "Usage: a.out {p|c}\n");
        fprintf(stderr, "Where:\n");
        fprintf(stderr, "\tp: Producer (Start second)\n");
        fprintf(stderr, "\tc: Consumer (start first)\n");
        exit(1);
    }

    flags = PERMS|IPC_CREAT;

    /* system calls to create the semaphore */
    semID = semget(KEY, 1, flags);  /* create 1 semaphore in set (index 0) */
    if(semID < 0) {
        perror(">>> ERROR! Consumer must be started first.");
        exit(1);
    }

    if(argv[1][0] != 'p') {
        /* initialize the semaphore */
        arg.val = 0;    /* initalize semphore to 0 */
        if(semctl(semID, 0, SETVAL, arg) < 0) {
            perror (">>> ERROR! Initialization failed.");
            exit(1);
        }
    }

    if(argv[1][0] == 'p') {
        /* Producer does a semsignal() */
        fprintf(stdout, "Producer signaling....\n");
        sembuf.sem_num = 0;     /* first sem in set */
        sembuf.sem_op = 1;      /* 1 means signal */
        sembuf.sem_flg = 0;
        if(semop(semID, &sembuf, 1) == -1) {
            perror(">>> ERROR! Signal failed.");
            exit(1);
        }
    }
    else {
        /* Consumer does a semwait() */
        fprintf(stdout, "Consumer waiting ....\n");
        sembuf.sem_num = 0;     /* first sem in set */
        sembuf.sem_op = -1;     /* -1 means wait */
        sembuf.sem_flg = 0;
        if(semop(semID, &sembuf, 1) == -1) {
            perror(">>> ERROR! Wait failed");
            exit(1);
        }

        fprintf(stdout, "Producer has signaled.\n");

        /* delete */
        if(semctl(semID, 0, IPC_RMID, arg) == -1) {
            perror(">>> ERROR! Unsuccessful delete");
            exit(1);
        }
    }

    fprintf(stdout, "Done.\n");
    return 0;
}
