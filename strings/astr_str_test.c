#include <stdio.h>
#include "astr.h"
#include "astr_test.h"

void test_astr_str(void)
{
    const char *str1 = "Hello, welcome to the world of C programming.";
    const char *str2 = "world";
    char *result = astr_str(str1, str2);
    
    if (result != NULL)
        printf("Substring found: %s\n", result);
    else
        printf("Substring not found.\n");
   
}