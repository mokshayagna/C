#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char buffer[20];
    int tpid;
    int fd[2];

    pipe(fd);
    tpid = fork();
    if(tpid == 0){
        char *msg = "hello world";
        write(fd[1],msg,strlen(msg));
        close(fd[1]);
    }
    else{
        read(fd[0],buffer,5);
        printf("parent received(related):%s\n",buffer);
        read(fd[0],buffer,6);
        printf("parent received(related):%s\n",buffer);
        close(fd[0]);
    }   
    return 0;
}
