#include <stdio.h>
int get_bit_count(int n){
    int count = 0;
    while(n){
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main(){
    int n = 10;
    printf("The number of set bits in %d is %d\n", n, get_bit_count(n));
    return 0;
}