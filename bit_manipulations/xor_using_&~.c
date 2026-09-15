#include<stdio.h>

void bitXOR(int a, int b){
    printf("%d\n",~(~(a&(~b))&(~((~a)&b))));    
}
int main(){
    int a = 10;
    int b = 9;
    bitXOR(a,b);
    return 0;
}