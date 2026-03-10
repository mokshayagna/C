    #include<stdio.h>
    #include<stdlib.h>

    union node{
        int a;
        char c1;
    };


    int main(){
        union node a;
        char *p;
        a.a = 300;
        p = &a.c1;
        printf("Byte 1: %d\n", *p);
        p++;
        printf("Byte 1: %d\n", *p);
        p++;
        printf("Byte 1: %d\n", *p);
        p++;
        printf("Byte 1: %d\n", *p);
        return 0;
    }