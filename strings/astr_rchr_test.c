#include <stdio.h>
#include "astr.h"
#include "astr_test.h"

    void test_astrrchr(void)
{
    const char *str = "Hello, World!";
    char ch = 'o';

    char *p = astrrchr(str, ch);

    if (p) {
        printf("Last occurrence of '%c' in \"%s\" found at position: %ld\n",ch, str, p - str);
    } else {
        printf("Character '%c' not found in \"%s\"\n", ch, str);
    }
}
