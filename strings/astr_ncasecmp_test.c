#include <stdio.h>
#include "astr.h"
#include "astr_test.h"

void test_astrncasecmp(void)
{
    const char *s1 = "HelloWorld";
    const char *s2 = "HeLLoWorld";

    int result = astrncasecmp(s1, s2, 5);

    if (result == 0)
        printf("PASS: astrncasecmp\n");
    else
        printf("FAIL: astrncasecmp (%d)\n", result);
}
