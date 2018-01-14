#include "bistromatic.h"

char *stringerize(char c)
{
	char *new;

	new = ft_strnew(1);
	new[0] = c;
	return (new);
}
