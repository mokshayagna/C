#include <stdio.h>

struct A
{
    //char a;
    char b;
    int c;
};

int main()
{
    struct A s1;

    printf("Size of structure = %zu\n", sizeof(s1));

    //printf("Base address = %p\n", &s1);
    //printf("Address of a = %p\n", &s1.a);
    printf("Address of b = %p\n", &s1.b);
    printf("Address of c = %p\n", &s1.c);

    return 0;
}