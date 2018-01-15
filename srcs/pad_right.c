#include "../includes/bistromatic.h"

char    *pad_right(char *str, int number_of_zeros)
{
    char *new;
    int length;

    if (!number_of_zeros)
        return (str);
    length = ft_strlen(str);
    new = ft_strnew(length + number_of_zeros);
    ft_strcpy(new, str);
    while (number_of_zeros)
        new[(length - 1) + number_of_zeros--] = '0';
    return (new);
}
