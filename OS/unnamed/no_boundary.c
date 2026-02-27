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
        write(fd[1],"Hello",strlen("Hello"));
        write(fd[1],"World",strlen(" World"));
        close(fd[1]);
    }
    else{
        read(fd[0],buffer,sizeof(buffer));
        printf("parent received:%s\n",buffer);
        close(fd[0]);
    }   
    return 0;
}
