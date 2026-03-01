#include<stdio.h>

int a = 0;
void child(){
    for(;;){
        a = a+5;
        printf("child_a = %d\n", a);
    }

}

void parent(){
    for(;;){
        a = a+10;
        printf("parent_a = %d\n", a);
    }
}

int main(){
    int pid = fork();
    if(pid == 0){
        child();
    }
    else{
        parent();
    }
    return 0;
}