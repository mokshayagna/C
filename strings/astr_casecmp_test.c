#include <stdio.h>
#include "astr.h"
#include "astr_test.h"

void test_astrcasecmp(void)
{
    const char *s1 = "HelloWorld";
    const char *s2 = "HeLLoWorld";

    if (astrcasecmp(s1, s2) != 0)
        printf("FAIL: astrcasecmp\n");
    else
        printf("PASSED\n");
}
