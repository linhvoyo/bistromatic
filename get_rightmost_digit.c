#include "bistromatic.h"

int get_rightmost_digit(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        return (0);
    if (!str[i + 1])
        return (str[i] - '0');
    while (str[i + 1])
        i++;
    return (str[i] - '0');
}
