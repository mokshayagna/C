#include "astr.h"
#include <stdlib.h>

int length(const char *s)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}
char *astr_dup(const char *s)
{
    int len = length(s);
    char *dup = (char *)malloc(len + 1);
    for(int i = 0; i < len; i++)
    {
        dup[i] = s[i];
    }
    dup[len] = '\0';
    return dup;
}
