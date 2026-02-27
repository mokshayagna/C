#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char buffer[20];
    int x = read(3, buffer, sizeof(buffer));
    if(x < 0){
        printf("No data\n");
        return 1;
    }
    return 0;
}