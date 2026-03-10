#include<stdio.h>

struct node{
    int a;
    int c1;
};

int main(){
    struct node a;

    printf("size of structure is : %lu\n", sizeof(struct node));
    printf("Base address : %p\n", &a);
    printf("Address of a : %p\n", &a.a);
    printf("Address of c1 : %p\n", &a.c1);
    return 0;
}

