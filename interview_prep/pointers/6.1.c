/*
int a = 0x12131415;
Print the value of ‘a’ as '0x12131415'
Print each individual byte's value of ‘a’ '0x12 0x13 0x14 0x15'
Print both short int values of ‘a’ as '0x1213 0x1415'
Print each individual byte's value of ‘a’ in reverse order '0x15 0x14 0x13 0x12
*/

#include <stdio.h>

int main(){
    int a = 0x12131415;
    int *p = &a;
    printf("The value of a is: 0x%x\n",*p);
    char *p = (char*)&a;
    printf("The individual byte values of a are: 0x%x 0x%x 0x%x 0x%x\n",*p,*(p+1),*(p+2),*(p+3));
    short int *q = (short int*)&a;
    printf("The short int values of a are: 0x%x 0x%x\n",*q,*(q+1));
    printf("The individual byte values of a in reverse order are: 0x%x 0x%x 0x%x 0x%x\n",*(p+3),*(p+2),*(p+1),*p);
    return 0;
}