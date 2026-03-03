#include <stdio.h>

void myFunction() {
    printf("Inside normal function\n");
}

int main() {
    printf("Before function call\n");
    myFunction();
    printf("After function call\n");
    return 0;
}