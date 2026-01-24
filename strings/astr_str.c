#include "astr.h"

char *astr_str(const char *str1, const char *str2)
{
    if (*str2 == '\0')
        return (char *)str1;

    while (*str1 != '\0')
    {
        const char *s1 = str1;
        const char *s2 = str2;

        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
        {
            s1++;
            s2++;
            
        }

        if (*s2 == '\0')
            return (char *)str1;

        str1++;
    }
    
}
