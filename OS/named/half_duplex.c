#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    char buffer[20];
    int tpid;
    mkfifo("mypipe", 0666);
    tpid = fork();
    if(tpid > 0){
        int fd1 = open("mypipe", O_WRONLY);
        write(fd1, "I'm parent", 11);

        int fd2 = open("mypipe", O_RDONLY);
        int x = read(fd2, buffer, sizeof(buffer));
        buffer[x] = '\0';
        printf("parent received:%s\n", buffer);
        close(fd1);
        close(fd2);
    }
    else{
        sleep(1);   
        int fd1 = open("mypipe", O_RDONLY);
        int n = read(fd1, buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("child received:%s\n", buffer);

        int fd2 = open("mypipe", O_WRONLY);
        write(fd2, "I'm child", 10);
        close(fd1);
        close(fd2);
    }
}
