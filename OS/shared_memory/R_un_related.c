#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    key_t key = ftok("progfile", 65);

    int shmid = shmget(key, 1024, 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    char *data = (char *)shmat(shmid, NULL, 0);

    printf("Read: %s\n", data);

    shmdt(data);

    return 0;
}