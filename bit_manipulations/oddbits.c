#include <stdio.h>

void show_bits(int n)
{
    for (int i=31;i>=0;i--)
    {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}
int oddBits(void)
{
    int x = 0;
    for(int i=31;i>0;i=i-2)
    {
        x = x | (1 << i);
    }
    show_bits(x);
    return 0;
}
int main()
{
    oddBits();
    return 0;
}