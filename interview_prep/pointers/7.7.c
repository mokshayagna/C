#include <stdio.h>
int main(){

    char dstr[15][5] = {
        "AURA NETWORKS",
        "Bangalore",
        "INDIA"
    };
    printf("%d\n",sizeof(dstr));
    char *p = dstr;
    printf("%c\n",*p);  
    printf("dstr:%p\n",dstr); 
    char *q = &dstr;
    printf("%c\n",*q);
    printf("dstr[0]:%s\n",dstr[0]);
    printf("%p\n",&dstr);
    return 0;
}
