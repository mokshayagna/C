#include <stdio.h>
#include <unistd.h>
int s;
int main(){
    printf("parent ID:%d\n",getppid());
    s = fork();
    if (s==0){
        printf("child ID:%d\n",getpid());
    }
    else{
        printf("I'm parent:%d\n",getpid());
    }
    return 0;
}
