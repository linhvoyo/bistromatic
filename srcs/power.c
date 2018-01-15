#include "../includes/bistromatic.h"

char *power(char *number, char *exponent)
{
	char *result;

	result = "1";
	if (number_cmp("0", exponent) == 0)
		return (result);
	while (number_cmp("0", exponent) < 0)
	{
		result = multiply(result, number);
		exponent = subtract(exponent, "1");
	}
	return (result);
}
