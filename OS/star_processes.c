#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int tpid;
     tpid = fork();
    for(int i=0;i<5;i++){
        if (tpid > 0){
            tpid = fork();
            printf("current:%d\n parent:%d\n",getpid(),getppid());
            exit(0);
        }
    }
    return 0;
}
