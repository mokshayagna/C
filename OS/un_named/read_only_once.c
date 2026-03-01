#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int tid;
    int fd[2];
    char buffer[50];
    pipe(fd);

    tid = fork();
    if(tid == 0){
        printf("1st child = %d\n", getpid());
        write(fd[1], "writing in 1st child", strlen("writing in 1st child"));
        close(fd[1]);
    }
    else{
        printf("in the parent = %d\n", getpid());
        int n = read(fd[0], buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("message received %s\n", buffer);
        close(fd[0]);
        sleep(1);
    }
    tid = fork();
    if(tid == 0){
        printf("second child = %d\n", getpid());
        int x = read(fd[0], buffer, sizeof(buffer));
        if(x<0){
            printf("read failed as it is unrelated child\n");
        }
        else{
            buffer[x] = '\0';
        }
    }
    return 0;
}