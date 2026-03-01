#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int tid;
    char buffer[50];

    mkfifo("My pipe", 0666);
    tid = fork();
    if(tid > 0){
        int fd = open("My pipe", O_WRONLY);
        write(fd, "Hello there", 11);
        close(fd);
    }
    else{
        int fd = open("My pipe", O_RDONLY);
        int n = read(fd, buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("The message is received : %s\n", buffer);
        close(fd);
    }
    return 0;
}