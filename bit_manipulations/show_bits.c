#include <stdio.h>

void show_bits(int n){
    for(int i=31;i>=0;i--){
        printf("%d",(n >> i) & 1);
    }
    printf("\n");
}
int main(){
    int n = 10;
    show_bits(n);
    return 0;
}