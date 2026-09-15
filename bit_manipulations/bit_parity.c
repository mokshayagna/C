#include <stdio.h>

int bitParity(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count % 2;
}

int main(){
    int n = 10;
    printf("%d\n",bitParity(n));
    return 0;
}