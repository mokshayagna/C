#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

struct msg_queue{
    long flag;
    char msg[100];
};

int main(){
    int tid;
    int msgid;
    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    struct msg_queue msg;
    tid = fork();
    if(tid>0){
        msg.flag = 1;
        strcpy(msg.msg, "Hello I am parent");
        msgsnd(msgid, &msg, sizeof(msg.msg), 1);
        wait(NULL);
        msgrcv(msgid, &msg, sizeof(msg.msg), 1, 0);
        printf("message received %s\n", msg.msg);
    }
    else{
        msgrcv(msgid, &msg, sizeof(msg.msg), 1, 0);
        printf("message received %s\n", msg.msg);
        //msg.flag = 2;
        strcpy(msg.msg, "Hello I am child");
        msgsnd(msgid, &msg, sizeof(msg.msg), 1);
    }
    return 0;
}