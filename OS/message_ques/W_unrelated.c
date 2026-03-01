#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct msg_queue{
    long flag;
    char msg[100];
};

int main(){
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, IPC_CREAT | 0666);
    struct msg_queue msg;
    msg.flag = 1;
    strcpy(msg.msg, "Hello from parent process!");
    msgsnd(msgid, &msg, sizeof(msg.msg), 0);
    printf("Sent: %s\n", msg.msg);
    return 0;
}