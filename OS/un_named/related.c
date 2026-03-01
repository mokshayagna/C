#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
    int fd[2];
    int tid;
    char buffer[20];

    pipe(fd);
    
    tid = fork();
    if(tid == 0){
        write(fd[1], "Hello", strlen("Hello"));
        close(fd[1]);
    }
    else{
        sleep(1);
        int n = read(fd[0],buffer, sizeof(buffer));
        buffer[n] = '\0';
        close(fd[0]);
        printf("the received message is %s\n", buffer);
    }
}

