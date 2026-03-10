#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_queue{
    long type;
    char msg[100];
};

int main(){
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_queue msg;
    while(1){
        msgrcv(msgid, &msg, sizeof(msg.msg), 1, 0);
        printf("the received message from client one is : %s\n", msg.msg);

        msg.type = 3;
        strcpy(msg.msg, "this is to client 1");
        msgsnd(msgid, &msg, sizeof(msg.msg), 0);

        msgrcv(msgid, &msg, sizeof(msg.msg), 2, 0);
        printf("The message recieved from client 2 : %s", msg.msg);

        msg.type = 4;
        strcpy(msg.msg, "this is to client 2");
        msgsnd(msgid, &msg, sizeof(msg.msg),0);
    }
    return 0;
}