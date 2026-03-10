
#include<stdio.h>

union node{
    char a;
    char c;
};

int main(){
    union node a;

    printf("size of union is : %lu\n", sizeof(union node));
    printf("Base address : %p\n", &a);
    printf("Address of C : %p\n", &a.a);
    printf("Address of C : %p\n", &a.c);

    return 0;
}