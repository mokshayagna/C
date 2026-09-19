// string compare excluding case sensitivity

#include <stdio.h>

static char to_lower(int c){
    if(c >= 'A' && c <= 'Z'){
        return c + 32;
    }
    return c;
}

int case_cmp(char *str1, char *str2){
    int i = 0;
    while(str1[i] && str2[i]){
        char ch1 = to_lower(str1[i]);
        char ch2 = to_lower(str2[i]);
    
        if (ch1 != ch2){
            return 0;
        }
        i ++;
    }
    return 1;
}

int main(){
    char *str1 = "MOKSHA";
    char *str2 = "sweety";
    int a = case_cmp(str1,str2);

    if(a == 1){
        printf("The strings are equal\n");
    }else{
        printf("The strings are not equal\n");
    return 0;
    }
}