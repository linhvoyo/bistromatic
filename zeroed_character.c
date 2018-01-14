#include "bistromatic.h"

int zeroed_character(char *str, char c)
{
    while (*str)
    {
        if (*str != c)
            return (0);
        str++;
    }
    return (1);
}
