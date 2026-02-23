#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int p2c[2];
    int c2p[2];
    char buffer[20];
    int tpid;

    pipe(p2c); // Parent to Child
    pipe(c2p); // Child to Parent
    tpid = fork();


    if (tpid > 0) {   // Parent
        // Parent writes first
        write(p2c[1], "P: Hello", strlen("P: Hello"));

        int n = read(c2p[0], buffer, sizeof(buffer)-1);
        buffer[n] = '\0';

        printf("Parent received: %s\n", buffer);

        close(p2c[1]);  // Done writing
        wait(NULL);
    }
    else {            // Child
        sleep(1);   

        int n = read(p2c[0], buffer, sizeof(buffer)-1);
        buffer[n] = '\0';

        printf("Child received: %s\n", buffer);

        write(c2p[1], "C: Hello", strlen("C: Hello"));

        close(c2p[0]);
        close(p2c[1]);
    }

    return 0;
}
