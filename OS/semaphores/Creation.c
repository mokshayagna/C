#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

union semun {
    int val;
};

int main() {

    key_t key = ftok("progfile", 75);
    int semid = semget(key, 1, IPC_CREAT | 0666);

    union semun arg;
    arg.val = 0;   
    semctl(semid, 0, SETVAL, arg);

    struct sembuf wait_op = {0, -1, 0};
    struct sembuf signal_op = {0, 1, 0};

    int pid = fork();

    if (pid > 0) {   

        printf("Parent: Hello there\n");
        sleep(2);

        semop(semid, &signal_op, 1);   
        wait(NULL);

        semctl(semid, 0, IPC_RMID);    
    }
    else {   

        semop(semid, &wait_op, 1);     
        printf("Child: The message is received\n");
    }

    return 0;
}