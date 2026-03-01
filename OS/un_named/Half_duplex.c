#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    int tid;
    char buffer[20];

    pipe(fd);
    tid = fork();

    if(tid == 0){
        write(fd[1], "Half duplex", strlen("Half, duplex"));
        close(fd[1]);
    }

    else{
        sleep(1);
        int n = read(fd[0], buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("the message is %s\n", buffer);
        close(fd[0]);
        write(fd[1], "second check", strlen("second check"));
        close(fd[1]);
        n = read(fd[0], buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("the 2nd message is %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}