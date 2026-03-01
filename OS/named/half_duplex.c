#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char buffer[50];
    int tid;
    mkfifo("pipe", 0666);
    tid = fork();
    if(tid > 0){
        int fd = open("pipe", O_WRONLY);
        write(fd, "I am parent\n", 11);
        printf("\n\nwritten on parent successfully\n");
        close(fd);
        int fd1 = open("pipe", O_RDONLY);
        int n = read(fd1, buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("message received in parent : %s\n", buffer);
        close(fd1);
    }
    else{
        sleep(1);
        int fd = open("pipe", O_RDONLY);
        int n = read(fd, buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("I am in child message: %s\n", buffer);
        close(fd);
        int fd1 = open("pipe", O_WRONLY);
        write(fd1, "I am child\n", 10);
        printf("message written by child\n");
        close(fd1);
    }
    return 0;
}