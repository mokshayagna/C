#include "astr.h"

char *astrrchr(const char *s, char c)
{
    const char *last = 0;

    while (*s) {
        if (*s == c)
            last = s;
        s++;
    }

    /* handle search for '\0' */
    if (c == '\0')
        return (char *)s;

    return (char *)last;
}
