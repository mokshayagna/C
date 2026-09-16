#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int main(){
    char p[20];
    strcpy(p,"aura networks");

    printf("%s\n",p);
    return 0;
}
*/

int main(){
    char arr[20];
    char *p;
    p = arr; // arr = char*
    strcpy(p,"aura networks");

    printf("%s\n",p);
    printf("%p\n",&p);
    printf("%c\n",*p);
    return 0;
}
    
/*
int main(){
    char *p = malloc(20);
    strcpy(p,"aura networks");

    printf("%s\n",p);
    return 0;
}   
*/
/*
int main(){
    char *p;
    strcpy(p,"aura networks");

    printf("%s\n",p);
    return 0;
}
*/