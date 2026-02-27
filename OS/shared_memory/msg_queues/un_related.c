#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

struct msg_queue {
    long flag;
    char msg[100];
};

int main() {
    key_t key = ftok("progfile", 65);  
    int msgid = msgget(key, 0666);

    if (msgid < 0) {
        perror("msgget failed");
        exit(1);
    }
    struct msg_queue msg;
    msgrcv(msgid, &msg, sizeof(msg.msg), 1, 0);
    printf("Received: %s\n", msg.msg);
    return 0;
}