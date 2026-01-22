#include <stdio.h>
#include "astr.h"
#include "astr_test.h"

void test_astrchr(void)
{
    const char *str = "Hello, World!";
    int ch = 'W';
    char *result = astrchr(str, ch);
    if (result != NULL) {
        printf("Character '%c' found at position\n", ch);
    } else {
        printf("Character '%c' not found in the string.\n", ch);
    }
}
