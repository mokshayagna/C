#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
    char buffer[20];
    int tpid;
    
    mkfifo("mypipe",0666);
    tpid = fork();
    if(tpid == 0){
        int fd = open("mypipe",O_WRONLY);
        write(fd,"Hello",strlen("Hello"));
        write(fd,"World",strlen(" World"));
        close(fd);
    }
    else{
        sleep(1);
        int fd = open("mypipe",O_RDONLY);
        read(fd,buffer,sizeof(buffer));
        printf("parent received:%s\n",buffer);
        close(fd);
    }
}