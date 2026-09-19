#include <stdio.h>

char pname[10];
char pname2[20] = "Aura Networks";

char *p = pname2;
int main(){
    printf("pname = %p\n", pname);
    printf("pname = %d\n", pname[1]);
    printf("&pname = %p\n",&pname);
    printf("pname2 = %p\n", pname2);
    printf("pname2 = %d\n",pname2[19]);
    printf("pname2 val = %p\n", &pname2[0]);
    printf("p = %p\n",p);
    printf("&pname2 = %p\n",pname2 + 1);

    return 0;
}
