#include <stdio.h>
#include <unistd.h>

int s;
int a = 10;
int i;
int tpid;

void nodes(void);
void child(void);
void parent(void);

void nodes() {
    s = getpid();
    printf("child:%d\n", a);

    tpid = fork();

    if (tpid == 0) {
        child();
    } else {
        parent();
    }
}

void child() {
    for (;;) {   
        printf("child:%d\n", a);
        i++;
        sleep(1);
    }
}

void parent() {
    for (;;) {  
        a = a + 5;
        printf("parent:%d\n", a);
        sleep(1);
    }
}

int main() {
    nodes();
    return 0;
}
