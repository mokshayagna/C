/*
 Declare a structure with different data types.  Define object for the same and  initialize/assign 
 values and print 
*/

#include <stdio.h>
#include <string.h>
struct student{
    char name[20];
    int age;
    float marks;
};
int main(){
    struct student s1;
    
    strcpy(s1.name, "Moksha");
    s1.age = 23;
    s1.marks = 100;

    printf("%s\n",s1.name);
    printf("%d\n",s1.age);
    printf("%f\n",s1.marks);

    struct student s2 = {"yagna",22,76};
    printf("%s\n",s2.name);
    printf("%d\n",s2.age);
    printf("%f\n",s2.marks);
    return 0;
}