#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int i;
    int tpid = fork();
    printf("parent:%d\n child:%d\n",getppid(),getpid());
    for(i=0;i<=5;i++){
        if(tpid == 0){
            printf("tpid:%d\n",tpid);
            tpid = fork();
            printf("pid:%d\nppid:%d\n",getpid(),getppid());
        }
    }
    sleep(50);
    return 0;
}
