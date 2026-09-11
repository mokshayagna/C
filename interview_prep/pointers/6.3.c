/*
Int a = 0x12131415
i.e. sh1 contains 0x1213
 sh1 contains 0x1415
*/

#include <stdio.h>
int main(){
    int a = 0x12131415;
    
    short int *sh1 = (short int*)&a;
    short int *sh2 = (short int*)&a + 1;

    printf("The value of a is: 0x%x\n", a);
    printf("The short int values of a are: 0x%x 0x%x\n", *sh1, *sh2);
    return 0;
}