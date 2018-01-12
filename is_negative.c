#include "bistromatic.h"

int is_negative(char *str1)
{
	if (number_cmp("0", str1) > 0)
		return (1);
	return (0);
}
