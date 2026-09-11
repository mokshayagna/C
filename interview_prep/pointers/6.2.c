/*
int a = 0x12131415
i.e. ch1 contains 0x12
 ch2 contains 0x13
 ch3 contains 0x14
 ch4 contains 0x15 
*/

#include <stdio.h>

int main(){
    int a = 0x12131415;
    
    char *ch1 = (char*)&a;
    char *ch2 = (char*)&a + 1;
    char *ch3 = (char*)&a + 2;
    char *ch4 = (char*)&a + 3;

    printf("The value of a is: 0x%x\n", a);
    printf("The individual byte values of a are: 0x%x 0x%x 0x%x 0x%x\n", *ch1, *ch2, *ch3, *ch4);
    return 0;
}
