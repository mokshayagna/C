#include <stdio.h>
/*
int main(){

    char a[10] = "Moksha yagna";
    a[1] = 'O';

    printf("%ld\n",sizeof(a));
    printf("%s\n",a);
    return 0;
}
*/


int main(){
    char *p = "Moksha";

    printf("addressof p :%p\n",&p);
    printf("value stored in p :%p\n",p);
    printf("value located at address %p is : %s\n",p,*&p);

    p = "Yagna";
    printf("value located at address %p is : %s\n",p,*&p);
    printf("value stored in p :%p\n",p);

    p[1] = 'O';
    printf("%s\n",*&p);
    return 0;
}