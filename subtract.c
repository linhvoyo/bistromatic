#include "bistromatic.h"

char *subtract(char *s1, char *s2)
{
	char *total;
	char *tmp;

	int carry;
	int big;
	int i;
	int sign;

	carry = 0;
	sign = 1;

	if (is_negative(s2))
		return (add(s1, multiply(s2,"-1")));
	if (is_negative(s1))
		return (multiply(add(multiply(s1, "-1"), s2), "-1"));
	big = ft_strlen(s1);
	if (is_str1_smaller(s1, s2)  && (big = ft_strlen(s2) + sign))
	{
		total = (char *)malloc(sizeof(char) * (big + 1 + sign));
		tmp = s1;
		s1 = s2;
		s2 = tmp;
		sign = -1;
	}
	else
		total = (char *)malloc(sizeof(char) * (big + 1));
	if (!total)
			return (NULL);
	s1 = pad_left(s1, big);
	s2 = pad_left(s2, big);
	i = big;
	int loop = 0;
	total[i--] = '\0';
	while (i >= 0)
	{
		loop = 0;
		int value1 = s1[i] - '0';
		int value2 = s2[i] - '0';
	//	printf("value 1: %d, value 2: %d\n", value1, value2);
		if ((value1) - (value2) < 0)
		{
			total[i] = (value1 + 10) - (value2) + carry + '0';
			carry = -1;
			loop = 1;
		}
		else if (carry == -1 && value1 - value2 == 0)
		{
	//		puts("here");
	//		printf("value 1: %d, value 2: %d\n", value1, value2);
			total[i] = 10 + carry + '0';
	//		printf("total[i] %c\n", total[i]);
			carry = -1;
			loop = 1;
		}
		else
		{
			total[i] = (value1) - (value2) + carry + '0';
			carry = 0;
			loop = 1;
		}
	//	printf("%c total[%d] \n", total[i], i );
		if (!loop)
			total[i] = '0';
		i--;
	}
	if (sign == -1)
		total[0] = '-';
	if (number_cmp("0", total) == 0)
		return ("0");
	truncate_zeros(&total);
	return (total);	
}

