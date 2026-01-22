#include "astr.h"

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int astrcasecmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] && str2[i]) {
        char c1 = to_lower(str1[i]);
        char c2 = to_lower(str2[i]);

        if (c1 != c2)
            return c1 - c2;
        i++;
    }
    return to_lower(str1[i]) - to_lower(str2[i]);
}
