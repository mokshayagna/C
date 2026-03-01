#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   

struct msg_queue {
    long flag;
    char msg[100];
};

int main() {
    key_t key = ftok("progfile", 65);  
    int msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid < 0) {
        perror("msgget failed");
        exit(1);
    }

    struct msg_queue msg;

    msg.flag = 1;
    strcpy(msg.msg, "Hello");
    msgsnd(msgid, &msg, sizeof(msg.msg), 0);
    printf("Sent: %s\n", msg.msg);

    sleep(1);   

    msg.flag = 1;
    strcpy(msg.msg, "World");
    msgsnd(msgid, &msg, sizeof(msg.msg), 0);
    printf("Sent: %s\n", msg.msg);

    struct msg_queue rcv_msg;

    msgrcv(msgid, &rcv_msg, sizeof(rcv_msg.msg), 0, 0);
    printf("Received: %s\n", rcv_msg.msg);

    msgrcv(msgid, &rcv_msg, sizeof(rcv_msg.msg), 0, 0);
    printf("Received: %s\n", rcv_msg.msg);

    return 0;
}