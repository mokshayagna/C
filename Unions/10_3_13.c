
#include<stdio.h>

union node{
    short a;
    char c;
    char i;
};

int main(){
    union node a;

    printf("size of union is : %lu\n", sizeof(union node));
    printf("Base address : %p\n", &a);
    printf("Address of C : %p\n", &a.a);
    printf("Address of C : %p\n", &a.c);
    printf("Address of I : %p\n", &a.i);

    return 0;
}