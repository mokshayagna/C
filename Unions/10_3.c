#include<stdio.h>

union node{
    int a;
    int c1;
};

int main(){
    union node a;

    printf("size of union is : %lu\n", sizeof(union node));
    printf("Base address : %p\n", &a);
    printf("Address of a : %p\n", &a.a);
    printf("Address of c1 : %p\n", &a.c1);
    return 0;
}

