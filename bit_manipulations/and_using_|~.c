#include<stdio.h>

void bitAnd(int a, int b){
    printf("a&b is : %d\n",~((~a)|(~b)));

}

int main(){
    int a = 10;
    int b = 9;
    bitAnd(a,b);
    return 0;
}