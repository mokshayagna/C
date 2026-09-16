#include <stdio.h>

int main(){
    char *dstr[5]={
        "aura networks",
        "bangalore",
        "india",
        "moksha",
        "xyzdgdk",
        "qwrrtyyu"
    };
    printf("dstr:%p\n",dstr);
    printf("dstr:%s\n",*dstr);
    printf("dstr:%s\n",dstr[0]);
    printf("dstr:%ld\n",sizeof(dstr));
    char *dstr2[5]={};
    printf("dstr2:%ld\n",sizeof(dstr2));
    return 0;
}