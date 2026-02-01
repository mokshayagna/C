#include <stdio.h>
#include <unistd.h>
int s;
int main(){
    s = getpid();
    fork();
    fork();
    fork();
    printf("parent%d\n child:%d\n",getppid(),getpid());
    return 0;
}
