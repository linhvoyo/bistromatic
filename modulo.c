#include "bistromatic.h"

char *modulo(char *dividend, char *divisor)
{
	char *result;
	char *multiplier;

	if (zeroed(dividend))
		return ("0");
	if (zeroed(divisor))
		return ("Error: Division by 0.");
	multiplier = divide(dividend, divisor);
	result = multiply(multiplier, divisor);
	printf("%s %s %s %s\n", dividend, divisor, multiplier, result);
	if (number_cmp(result, dividend) == 0)
		return ("0");
	return (subtract(dividend, result));
}
