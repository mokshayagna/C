#include <unistd.h>
#include <stdio.h>

int main() {

    write(1, "Before system call\n", 19);

    write(1, "Inside system call\n", 19);

    write(1, "After system call\n", 18);

    return 0;
}