#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int tpid;
    mkfifo("mypipe", 0666);
    tpid = fork();
    if(tpid > 0){
        int fd = open("mypipe", O_WRONLY);
        write(fd, "HELLO WORLD", 11);
        close(fd);
    }
}
