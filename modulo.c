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
	return subtract(dividend, result);
}
