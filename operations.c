#include "bistromatic.h"

char *pad_left(char *s1, int n)
{
	char *str;
	int len;
	int i;
	int j;

	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(char)*(n + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (i < (n - len))
		str[i++] = '0';
	while (i < n)
		str[i++] = s1[j++];
	str[n] = '\0';
	return (str);
}

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

char	**closest_whole_num(char *divisor, char *minuend)
{
	char **res;
	char *total;
	char *tmp;
	char counter[2];
	int i;
	int len;

	res = (char **)malloc(sizeof(char*) * 2);
	i = 0;
	total = divisor;
	if (ft_strlen(divisor) > ft_strlen(minuend))
		len = ft_strlen(divisor);
	else 
		len = ft_strlen(minuend);
	total = pad_left(total, len);
	while (number_cmp(total, minuend) <= 0)
	{
		total = add(total, divisor);
		i++;
	}
	counter[0] = '0' + i;
	res[0] = ft_strdup(counter);
	res[1] = subtract(total, divisor);
	if (counter[0] == '0')
		res[1] = ft_strdup(&counter[0]);
	return(res);
}

char *divide(char *dividend, char *divisor)
{
	char *total;
	char *minuend;
	char *tmp;
	char div[2];
	char **res;
	char *sign;

	int start_len;
	int i;
	int j;

	sign = multiply("1","1");
	if (zeroed(divisor))
		return ("Error: Division by zero.");
	if (is_negative(dividend))
	{
		sign = multiply(sign, "-1");
		dividend = multiply(dividend, "-1");
	}
	if (is_negative(divisor))
	{
		sign = multiply(sign, "-1");
		divisor = multiply(divisor, "-1");
	}	
	if (number_cmp(dividend, divisor) < 0)
		return ("0");;
	start_len = ft_strlen(divisor);
	if (ft_strncmp(dividend, divisor, start_len) < 0 )
		start_len = start_len + 1;
	total = (char *)malloc(sizeof(char) * (ft_strlen(dividend) - start_len + 1 + 1));
	if (!total)
		return (NULL);
	i = start_len;
	j = 0;
	minuend = ft_strdup(dividend);
	minuend[start_len] = '\0';
	dividend = (pad_right(dividend, 1));
	while (dividend[i])
	{
		res = closest_whole_num(divisor, minuend);
		tmp = minuend;
		div[0] = dividend[i++];
//		printf("dividend %c | minuend %s | res %s | divisor %s \n", dividend[i], minuend, res[1], divisor);
		minuend = ft_strjoin(subtract(minuend, res[1]), div);
		total[j++] = res[0][0];
		free(res);
		free(tmp);
//		printf("total[%d] %c\n", j, total[j]);
	}
	total[j] = '\0';
	return (multiply(sign,total));
}
