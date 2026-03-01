#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char buffer[50];
    int fd = open("mypipe", O_RDONLY);
    printf("above to read\n");
    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    close(fd);
    printf("message received : %s", buffer);
    return 0;
}