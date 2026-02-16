#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char buffer[20];
    mkfifo("mypipe",0666);
    int tpid = fork();
    if(tpid > 0){
        int fd = open("mypipe",O_WRONLY);
        write(fd,"HELLO WORLD",11);
        close(fd);
    }
    else{
        int fd = open("mypipe",O_RDONLY);
        int n = read(fd,buffer,sizeof(buffer));
        buffer[n] = '\0';
        printf("child received:%s\n",buffer);
        close(fd);
    }
    return 0;
}
