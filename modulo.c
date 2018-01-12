#include "bistromatic.h"

char *modulo(char *dividend, char *divisor)
{
	char *result;

	if (number_cmp(dividend, divisor) < 0)
		return (divisor);
	printf("dividend: %s, divisor: %s\n", dividend, divisor);
	result = divide(divisor, divisor);
	if (number_cmp(multiply(result, divisor), dividend) == 0)
		return ("0");
	else
	{
		printf("result: %s, divisor: %s, %s\n", result, divisor, multiply(result, divisor));
		return (subtract(dividend, multiply(result, divisor)));
	}
}
