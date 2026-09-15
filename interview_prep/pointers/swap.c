//swap using pointers
#include <stdio.h>

int swap_two(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    return 0;
}
int main(){
    int a = 10; 
    int b = 20;
    printf("Before swapping a = %d, b = %d\n",a,b);
    swap_two(&a,&b);
    printf("After swapping a = %d, b = %d\n",a,b);
    return 0;
}