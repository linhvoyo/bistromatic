#include "bistromatic.h"

char *modulo(char *dividend, char *divisor)
{
	char *result;
	char *multiplier;
	char *negative_flag;

	if (zeroed(dividend))
		return ("0");
	if (zeroed(divisor))
		return ("Error: Division by 0.");
	negative_flag = "";
	if (is_negative(dividend))
		dividend++;
	if (is_negative(divisor) && number_cmp(dividend, divisor) < 0)
		return (divisor);
	if (is_negative(divisor))
	{
		negative_flag = "-";
		divisor++;
	}
	multiplier = divide(dividend, divisor);
	result = multiply(multiplier, divisor);
	if (number_cmp(result, dividend) == 0)
		return ("0");
	if (number_cmp(result, dividend) < 0)
		return (subtract(dividend, result));
	return (ft_strjoin(negative_flag, subtract(dividend, result)));
}
