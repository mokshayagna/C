#include<stdio.h>

void show_bits(int n){
    for(int i=31;i>=0;i--){
        printf("%d",(n >> i) & 1);
    }
    printf("\n");
}
void bit_flip(int m, int nth){
    int x = 1 << nth;
    m = m ^ x;
    show_bits(m);
}
int main(){
    int m = 10;
    int nth = 2;
    show_bits(m);
    bit_flip(m,nth);
    return 0;
}