#include<stdio.h>

struct node{
    char a;
    short c;
    int i;
};

int main(){
    struct node a;

    printf("size of structure is : %lu\n", sizeof(struct node));
    printf("Base address : %p\n", &a);
    printf("Address of C : %p\n", &a.a);
    printf("Address of C : %p\n", &a.c);
    printf("Address of I : %p\n", &a.i);

    return 0;
}