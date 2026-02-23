#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int shmid; // shared memory ID
    char *ptr; // pointer to shared memory

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    printf("Shared memory segment created with ID: %d\n", shmid);
    // attach to the shared memory segment
    ptr = (char *)shmat(shmid, NULL, 0);    
    int tpid = fork();
    if(tpid == 0){
        strcpy(ptr, "Hello, From child process");
        printf("Data written to shared memory from child: %s\n", ptr);
    }
    else{
        sleep(1); // wait for child to write data
        printf("Data read from shared memory in parent: %s\n", ptr);
    }
    
    // detach from the shared memory segment
    shmdt(ptr); // it is done by child process as well as parent process

    // remove the shared memory segment
    if(tpid > 0){
        shmctl(shmid, IPC_RMID, NULL);// only parent process should remove the shared memory segment
    }
    return 0;
}