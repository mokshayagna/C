//How to find the number of bit swaps required converting integer A to integer B? 

#include <stdio.h>

int no_of_swap_count(int a, int b){
    int n = a^b;
    int count = 0;
    while(n){
        n = n & (n-1);
        count ++;
    }
    return count;
}

int main(){
    int a = 10;
    int b = 9;
    printf("No of bits required to swap %d to %d is: %d\n",a,b,no_of_swap_count(a,b));

    return 0;
}