#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);

    printf("pipe created\n");
    printf("fd[0]:%d\n",fd[0]);
    printf("fd[1]:%d\n",fd[1]);
    return 0;
}
