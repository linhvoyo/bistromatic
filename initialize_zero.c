#include "bistromatic.h"

void initialize_zero(char *str, int length)
{
    int i;

    i = 0;
    while (i < length)
        str[i++] = '0';
    str[i] = '\0';
}
