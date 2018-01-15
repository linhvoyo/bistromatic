#include "../includes/bistromatic.h"

char *initialize_characters(int length, char c)
{
    int i;
	char *str;

	str = ft_strnew(length);
    i = 0;
    while (i < length)
        str[i++] = c;
	return (str);
}
