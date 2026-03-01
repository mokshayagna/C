#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    key_t key = ftok("progfile", 65);

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    strcpy(data, "Hello from parent process!");
    printf("Written: %s\n", data);

    shmdt(data);

    return 0;
}