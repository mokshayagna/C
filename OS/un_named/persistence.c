#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);

    printf("file descriptor to write = %d\n", fd[1]);
    printf("file descriptor to read = %d\n", fd[0]);
    return 0;
}