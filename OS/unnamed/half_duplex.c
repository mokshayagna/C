#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char buffer[20];
    int tpid;
    int fd[2];

    pipe(fd); // pipe created
    tpid = fork(); // process created
    if(tpid > 0){
        write(fd[1],"Hello",strlen("Hello"));
        close(fd[1]);

        int n = read(fd[0],buffer,sizeof(buffer));
        buffer[n] = '\0';
        printf("parent received:%s\n",buffer);
        close(fd[0]);
    }
    else{
        int x = read(fd[0],buffer,sizeof(buffer));
        buffer[x] = '\0';   
        printf("child received:%s\n",buffer);
        close(fd[0]);

        write(fd[1],"World",strlen("World"));
        close(fd[1]);
    }   
    return 0;
}

