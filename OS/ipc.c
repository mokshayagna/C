#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    int fd[2];
    char buffer[20];
    int tpid;
    pipe(fd);            // creating a unnamed pipe
    tpid = fork();
    if(tpid > 0){            //checking if it is parent
        write(fd[1],"Hello world",11);  // parent sending hello world
        close(fd[1]);                // closing write part
    }
    else{
        int n = read(fd[0],buffer,sizeof(buffer)-1);        // child reading from fd[0] 
        buffer[n] = '\0';                        //reading until end
        printf("child recived:%s\n",buffer);
        close(fd[0]);                             //closing read part
    }
    return 0;
    
}
