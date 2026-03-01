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
        write(fd[1], "Hello there", strlen("Hello there"));
        close(fd[1]);
    }
    else{
        sleep(1);
        int n = read(fd[0], buffer, 2);
        buffer[n] = '\0';
        printf("the string is %s\n", buffer);
        n = read(fd[0], buffer, 2);
        buffer[n] = '\0';
        printf("the string is %s\n", buffer);
    }

    return 0;
}