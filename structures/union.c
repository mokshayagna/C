#include <stdio.h>
/*
int main(){
    int a = 300;
    int *p = &a;

    char *c = (char *)p;
    short int *s = (short int *)p;
    printf("%d\n", *c);
    printf("%d\n", *(c +1));
    printf("%d\n", *s);
    return 0;
}
*/
/*
int main(){
    int a = 300;
    int mask = 0x000000ff;
    for(int i = 0; i < 4; i++)
    {
        int b = (a>>(i*8))& mask;
        printf("%d\n", b);
    }
    return 0;
}
*/

union U
{
    int i;
    char c[4];
};

int main()
{
    union U u;

    u.i = 300;

    printf("1st byte = %d\n", u.c[0]);
    printf("2nd byte = %d\n", u.c[1]);
    printf("3rd byte = %d\n", u.c[2]);
    printf("4th byte = %d\n", u.c[3]);
    return 0;
}
