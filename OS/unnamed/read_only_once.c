#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// i want to write code that for unrelated processes unmnamed pipe will not work, only related processes can communicate through unnamed pipes.
int main(){
    char buffer[20];
    int tpid;
    int fd[2];

    pipe(fd); // pipe created
    tpid = fork();
    if(tpid == 0){ //child
        printf("child ID:%d\n",getpid());
        write(fd[1],"Hello",strlen("Hello"));
    }

    else{ //parent
        printf("parent ID:%d\n",getpid());
        int n = read(fd[0],buffer,sizeof(buffer));
        printf("n:%d\n",n);
        buffer[n] = '\0';
        printf("parent received:%s\n",buffer); 
        close(fd[0]);
        sleep(1);
    }
    tpid = fork();
    if(tpid == 0){ // new child, unrelated to the first child
        int x = read(fd[0],buffer,sizeof(buffer));
        printf("x:%d\n",x);
        if(x<0){
            printf("read failed in unrelated child\n");
        }
        else{
            buffer[x] = '\0';
    }
    return 0;
}
}