#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    printf("Read FD = %d, Write FD = %d\n", fd[0], fd[1]);
    write(fd[1], "Hello", strlen("Hello"));
    printf("Data written into unnamed pipe\n");
    sleep(15);  
    return 0;
}