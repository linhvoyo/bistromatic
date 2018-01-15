#include "bistromatic.h"

int zeroed(char *str)
{
    while (*str)
    {
        if (*str != '0')
            return (0);
        str++;
    }
    return (1);
}
