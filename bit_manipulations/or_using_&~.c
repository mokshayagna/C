#include <stdio.h>
void bitNor(int x, int y)
{
    printf("%d\n",(~((~x)&(~y))));
} 

int main(){
    int x = 10;
    int y = 8;
    bitNor(x,y);
    return 0;
}