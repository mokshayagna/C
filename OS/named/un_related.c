#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("mypipe", O_RDONLY);
    char buffer[20];
    read(fd, buffer, 11);
    buffer[11] = '\0';
    printf("child received:%s\n", buffer);
    close(fd);
}