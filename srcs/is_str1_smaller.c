#include "../includes/bistromatic.h"

int is_str1_smaller(char *str1, char *str2)
{
	int n1;
	int n2;
	int i;

	if ((n1 = ft_strlen(str1)) < (n2 = ft_strlen(str2)))
		return (1);
	if (n2 < n1)
		return (0);
	i = 0;
	while (i < n1)
	{
		if (str1[i] < str2[i])
			return (1);
		else if (str1[i] > str2[i])
			return (0);
		i++;
	}
	return (0);
}

