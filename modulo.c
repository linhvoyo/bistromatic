#include "bistromatic.h"

char *modulo(char *dividend, char *divisor)
{
	char *result;
	char *multiplier;
	char *negative_flag;

	if (zeroed(divisor))
		return ("Error: Division by 0.");
	negative_flag = "";
	if (number_cmp(dividend, "0") < 0)
		dividend++;
	if (number_cmp(divisor, "0") < 0 && (negative_flag = "-"))
		divisor++;
	if (number_cmp(dividend, divisor) < 0)
		return (divisor);
	multiplier = ft_strdup("0");
	while (number_cmp(dividend, multiply(multiplier, divisor)) > 0)
		multiplier = add(multiplier, "1");
	if (number_cmp(dividend, multiply(multiplier, divisor)) < 0)
		result = multiply(subtract(multiplier, "1"), divisor);
	else
		result = multiply(multiplier, divisor);
	if (number_cmp(result, dividend) == 0)
		return ("0");
	return (ft_strjoin(negative_flag, subtract(dividend, result)));
}
