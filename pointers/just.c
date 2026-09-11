#include <stdio.h>

int main()
{
    char str[] = "Hello";
    char *p = str;

    *p = 'Y';

    printf("%s\n", str);

    return 0;
}