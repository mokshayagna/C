#include "astr.h"

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int astrncasecmp(const char *str1, const char *str2, int n)
{
    int i = 0;

    while (i < n && str1[i] != '\0' && str2[i] != '\0') {
        char c1 = to_lower(str1[i]);
        char c2 = to_lower(str2[i]);

        if (c1 != c2)
            return c1 - c2;
        i++;
    }

    if (i == n)
        return 0;

    return to_lower(str1[i]) - to_lower(str2[i]);
}
