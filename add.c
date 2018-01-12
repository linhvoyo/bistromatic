#include "bistromatic.h"

char *add(char *str1, char *str2)
{
	char *num1;
	char *num2;
	int i;
	int value;

	num1 = ft_strdup(str1);
	num2 = ft_strdup(str2);
	if (number_cmp(str1, str2) < 0)
		swap(&num1, &num2);
	if (zeroed(num1) || zeroed(num2))
		return (num1);
	if (is_negative(num1) && is_negative(num2))
		return ft_strjoin("-", add(++num1, ++num2));
	if (!is_negative(num1) && is_negative(num2))
		return (subtract(num1, ++num2));
	num1 = pad_left(num1, ft_strlen(num1) + 1);
	i = ft_strlen(num1) - 1;
	while (i > 0)
	{
		value = (num1[i] - '0') + pop_digit(num2);
		num1[i - 1] = value / 10 + num1[i - 1];
		num1[i--] = value % 10 + '0';
	}
	truncate_zeros(&num1);
	return (num1);
}
