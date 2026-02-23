#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct msg_queue{
    long flag;
    char msg[100];
};

int main(){
    int msgid;

    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if(msgid < 0){
        perror("msgget failed");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", msgid);

    struct msg_queue msg;
    int tpid = fork();

    if(tpid > 0){   // Parent
        msg.flag = 1;
        strcpy(msg.msg, "Hello from parent process!");

        msgsnd(msgid, &msg, sizeof(msg.msg), 0);
        printf("Parent sent: %s\n", msg.msg);
       // msgctl(msgid, IPC_RMID, NULL);

    }
    else{           // Child
        msgrcv(msgid, &msg, sizeof(msg.msg), 1, 0);
        printf("Child received: %s\n", msg.msg);
    }

    return 0;
}
