#include <stdio.h>
#include "astr.h"
#include "astr_test.h"
#include <stdlib.h>

void test_astr_dup(void)
{
    const char *original = "Hello, World!";
    char *duplicate = astr_dup(original);

    if (duplicate == NULL)
    {
        printf("Failed to allocate memory for duplicate string.\n");
    }
    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);
    
    free(duplicate);
}