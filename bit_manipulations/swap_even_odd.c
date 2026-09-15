//Swap Odd and Even Bits in an Integer 

#include <stdio.h>
int swapEvenOddBits(int x) 
{
    int odd = x & 0xAA;
    int even = x & 0x55;

    even = even << 1;
    odd = odd >> 1;

    x = even | odd;

    return x;
}
void show_bits(int n){
    for(int i=31;i>=0;i--){
        printf("%d",(n>>i)&1);
    }
    printf("\n");
}
int main(){
    int x = 10;
    show_bits(x);
    int y = swapEvenOddBits(x);
    show_bits(y);
    return 0;
}