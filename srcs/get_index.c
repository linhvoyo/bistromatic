#include "../includes/bistromatic.h"

int get_index(char *array, char c)
{
	int i;

	i = 0;
	while (*array)
	{
		if (*array == c)
			return (i);
		i++;
		array++;
	}
	return (-1);
}
