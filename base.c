#include "bistromatic.h"

char *base(char *charset, char *decimal)
{
	char *new;
	char *result;
	char *base_system;
	linked_list *powers;
	int i;
	int index;

	if (zeroed(decimal))
		return ("0");
	if (number_cmp("1", decimal) == 0)
		return ("1");
	base_system = ft_itoa(ft_strlen(charset));
	powers = create_link("1");
	result = "1";
	while (number_cmp(result, decimal) < 0)
	{
		result = multiply(result, base_system);
		if (number_cmp(result, decimal) < 0)
			prepend_link(&powers, result);
	}
	new = initialize_zero(size(powers));
	index = 0;
	while (new[index])
	{
		result = get_closest_base(powers, decimal);
		divide = subtract(decimal, multiply(divide(decimal, result));
		i = ft_atoi(divide(decimal, result));
		new[index] = charset[i];
		index++;
		printf("CHARACTER: %c\n", charset[i]);
	}

	print_linked_list(powers);
	return ("test");
}
