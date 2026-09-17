#include <stdio.h>

struct S
{
    int i;
};

int main()
{
    struct S s;

    s.i = 300;

    char *c = (char *)&s.i;

    printf("%d\n", *(c+1));  

    return 0;
}

