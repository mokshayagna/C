#include<stdio.h>

int endianess(int n){
    int*p = &n;
    unsigned char *q = (unsigned char *)&n;
    if(*p == 0x78)
        return 0; //little
    else
        return 1; //big
}
int main(){
    int n = 0x12345678;
    printf("%d\n", endianess(n));
    return 0;
}