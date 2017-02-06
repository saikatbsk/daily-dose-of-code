#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFSIZE    100
#define MAXCOUNT    10

void childProcess() {
    int i;
    char buffer[BUFFSIZE];

    for(i = 0 ; i < MAXCOUNT ; i++) {
        sprintf(buffer, ">>> Hello from child; VALUE: %d\n", i);
        write(1, buffer, strlen(buffer));
    }
}

void parentProcess() {
    int i;
    char buffer[BUFFSIZE];

    for(i = 0 ; i < MAXCOUNT ; i++) {
        sprintf(buffer, ">>> Hello from parent; VALUE: %d\n", i);
        write(1, buffer, strlen(buffer));
    }
}

int main(void) {
    pid_t PID;

    PID = fork();

    /*
     * System call fork() returns the child process ID to the parent
     * and returns 0 to the child process
     */
    if(PID == 0) {
        childProcess();
    }
    else {
        parentProcess();
    }

    return 0;
}
