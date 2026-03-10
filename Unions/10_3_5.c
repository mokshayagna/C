#include<stdio.h>

union node{
    int a;
    char c;
    int i;
    char c1;
};

int main(){
    union node a;

    printf("size of union is : %lu\n", sizeof(union node));
    printf("Base address : %p\n", &a);
    printf("Address of C : %p\n", &a.a);
    printf("Address of C : %p\n", &a.c);
    printf("Address of I : %p\n", &a.i);
    printf("Address of C1 : %p\n", &a.c1);

    return 0;
}