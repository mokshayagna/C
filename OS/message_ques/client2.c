#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_queue{
    long type;
    char msg[100];
};

int main(){

    key_t key = ftok("progfile",65);
    int msgid = msgget(key,0666);

    struct msg_queue msg;

    while(1){

        msg.type=2;
        printf("Client2 message: ");
        fgets(msg.msg,100,stdin);

        msgsnd(msgid,&msg,sizeof(msg.msg),0);

        msgrcv(msgid,&msg,sizeof(msg.msg),4,0);
        printf("Server replied: %s\n",msg.msg);
    }

    return 0;
}