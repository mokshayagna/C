#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int shmid;
    int tid;

    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    tid = fork();

    if (tid > 0) {   
        strcpy(data, "Hello I am parent");
        wait(NULL);

        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else {  
        sleep(1);
        printf("Message received: %s\n", data);

        shmdt(data);
    }

    return 0;
}