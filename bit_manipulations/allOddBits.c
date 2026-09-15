#include <stdio.h>

int allOddBits(int n)
{
    return (n & 0xAA) == 0xAA;
}

int main()
{
    int n = 170;

    printf("%d\n", allOddBits(n));

    return 0;
}