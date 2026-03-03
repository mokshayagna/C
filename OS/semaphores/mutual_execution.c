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

    key_t key = ftok("progfile", 90);
    int semid = semget(key, 1, IPC_CREAT | 0666);

    union semun arg;
    arg.val = 1;   
    semctl(semid, 0, SETVAL, arg);

    struct sembuf lock = {0, -1, 0};   
    struct sembuf unlock = {0, 1, 0};   

    int pid = fork();

    for(int i = 0; i < 3; i++) {

        semop(semid, &lock, 1);   

        if(pid > 0)
            printf("Parent in critical section\n");
        else
            printf("Child in critical section\n");

        sleep(1);

        semop(semid, &unlock, 1); 
    }

    if(pid > 0) {
        wait(NULL);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}