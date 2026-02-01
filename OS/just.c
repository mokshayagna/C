#include <stdio.h>
#include <unistd.h>
int s;
int main(){
    printf("parent ID:%d\n",getppid());
    s = fork();
    for(int i=0;i<5;i++){
        if(s==0){
            printf("%d\n",getpid());
            fork();
        }
    }
    sleep(50);
    return 0;
}
