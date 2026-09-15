//How do you find out if an unsigned integer is a power of 2?

#include <stdio.h>
int is_power_of_two(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count ++;
    }
    return count;
}

int main(){
    int n = 6;
    int x = is_power_of_two(n);
    if (x == 1){
        printf("the give number is power of 2\n");
    }
    else{
        printf("the give number is not power of 2\n");
    }
    return 0;
}