#include "../includes/bistromatic.h"

int pop_digit(char *str)
{
    int value;

    value = get_rightmost_digit(str);
    shift_right(&str);
    return (value);
}
