#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY     3013    /* identification key to get segment */
#define PERMS   0666    /* rw-rw-rw */
#define MEMSIZE 80      /* bytes to allocate */

int main(int argc, char* argv[]) {
    int shmID;    /* shared memory id */
    char* shm;    /* the shared memory */
    int flags;    /* flags for shmget() call */

    /* check command line args */
    if((argc != 2) || (argv[1][0] != 'p' && argv[1][0] != 'c')) {
        fprintf(stderr, "Usage: shm {p|c}\n");
        fprintf(stderr, "Where:\n");
        fprintf(stderr, "\tp: produces (Start first)\n");
        fprintf(stderr, "\tc: consumer (Start second)\n");
        exit(1);
    }

    /* figure out who we are and set the flags
     * IPC_CREAT creates a new segment, while
     * IPC_EXCL ensures that it fails if the
     * segment exists;
     */
    if(argv[1][0] == 'p') {
        fprintf(stdout, "Producer started..\n");
        flags = PERMS|IPC_CREAT|IPC_EXCL;
    }
    else {
        fprintf(stdout, "Consumer started..\n");
        flags = PERMS|IPC_CREAT;
    }

    /* system calls to get the memory */
    if((shmID = shmget(KEY, MEMSIZE, flags)) < 0) {
        perror(">>> ERROR! Producer must be started first.");
        exit(1);
    }

    /* attach to the memory allocated */
    shm = (char*) shmat(shmID, NULL, 0);
    if(shm == (char*) -1) {
        perror(">>> ERROR! Attaching failed.");
        exit(1);
    }

    if(argv[1][0] == 'p') {
        strcpy(shm, "Live free or die!");
    }
    else {
        fprintf(stdout, "Producer says: %s\n", shm);

        /* detach and delete */
        if(shmdt(shm) == -1) {
            perror(">>> ERROR! Detach unsuccessful.");
            exit(1);
        }

        if(shmctl(shmID, IPC_RMID, NULL) == -1) {
            perror(">>> ERROR! Delete unsuccessful.");
            exit(1);
        }
    }

    fprintf(stdout, "Done.\n");
    return 0;
}
