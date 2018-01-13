#include "bistromatic.h"

char *initialize_zero(int length)
{
    int i;
	char *str;

	str = ft_strnew(length);
    i = 0;
    while (i < length)
        str[i++] = '0';
	return (str);
}
