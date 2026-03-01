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
        write(fd[1], "Hello", strlen("Hello"));
        write(fd[1], "There", strlen("There"));
        close(fd[1]);
    }
    else{
        int n = read(fd[0], buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("the received message is %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}