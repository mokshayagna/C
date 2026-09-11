/*
int a = 0x12131415
i.e. after swapping value of ‘a’ is 0x151141312 
*/

#include <stdio.h>
int main(){
    int a = 0x12131415;
    int len = sizeof(a)/2; 
    int *p = &a;
    char temp;
    for (int i = 0; i < len; i++) {
        temp = *((char*)p + i);
        *((char*)p + i) = *((char*)p + (len - 1 - i));
        *((char*)p + (len - 1 - i)) = temp;
    }   
    printf("The value of a after swapping is: 0x%x\n", *p);
    return 0;
}