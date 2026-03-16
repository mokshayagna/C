    #include<stdio.h>
    #include<stdlib.h>

    union node{
        int a;
        char c[4];
    };


    int main(){
        union node a;
        a.a = 300;
        printf("Byte 1: %d\n", a.c[0]);
        printf("Byte 2: %d\n", a.c[1]);
        printf("Byte 3: %d\n", a.c[2]);
        printf("Byte 4: %d\n", a.c[3]);
        return 0;
    }