#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char buffer[20];
    int tpid;
    int fd[2];

    pipe(fd); //parent created pipe
    tpid = fork();

    if(tpid == 0){ //child
        write(fd[1],"P:Moksha",strlen("P:Moksha"));
        close(fd[1]);
    }

    else{
        int n = read(fd[0],buffer,sizeof(buffer));
        buffer[n] = '\0';
        printf("parent received:%s\n",buffer); 
    }
    return 0;
}
