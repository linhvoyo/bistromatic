/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:58:23 by lilam             #+#    #+#             */
/*   Updated: 2018/01/10 15:49:21 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


void truncate_zeros(char **str)
{
	int i;
	int sign;

	char *temp;

	i = 0;
	if (*str[i++] == '-')
		sign = -1;
	while ((*str)[i] && (*str)[i] == '0')
		i++;
	temp = *str;
	if (sign == -1)
		*str = ft_strjoin("-", *str + i);
	else
		*str = ft_strdup(*str + i);
	free(temp);
}




char *add(char *s1, char *s2)
{
	char *total;

	int len1;
	int len2;
	int carry;
	int i;

	carry = 0;
	if ((len1 = ft_strlen(s1) + 1) > (len2 = ft_strlen(s2) + 1))
	{
		s2 = pad_left(s2,len1 - 1);
		total = (char *)malloc(sizeof(char) * (len1 + 1));
		i = len1;
	}
	else
	{
		total = (char *)malloc(sizeof(char) * (len2 + 1));
		s1 = pad_left(s1, len2 - 1);
		i = len2;
	}
	if (!total)
		return (NULL);

	total[i--] = '\0';
	while (i > 0)
	{
		int value1 = s1[i - 1] - '0';
		int value2 = s2[i - 1] - '0';
		if ((value1) + (value2) > 9)
		{
			total[i] = ((value1) + (value2)) % 10 + carry + '0';
			carry = 1;
			if (i == 1)
				total[0] = '1';
		}
		else
		{
			total[i] = (value1) + (value2) + carry + '0';
			carry = 0;
			if (i == 1)
				total[0] = '0';
		}
		i--;
	}
	truncate_zeros(&total);
	return (total);	
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
	big = ft_strlen(s1);
	if (is_str1_smaller(s1, s2) && (big = ft_strlen(s2) + sign))
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
	while (i > 0)
	{
		loop = 0;
		int value1 = s1[i] - '0';
		int value2 = s2[i] - '0';
//		printf("value 1: %d, value 2: %d\n", value1, value2);
		if ((value1) - (value2) < 0)
		{
			total[i] = (value1 + 10) - (value2) + carry + '0';
			carry = -1;
			loop = 1;
		}
		else if (carry == -1 && value1 - value2 == 0)
		{
			total[i] = 10 - value1 - value2 + carry + '0';
			carry = -1;
			loop = 1;
		}
		else
		{
			total[i] = (value1) - (value2) + carry + '0';
			carry = 0;
			loop = 1;
		}
//		printf("%c total[%d] \n", total[i], i );
		if (!loop)
			total[i] = '0';
		i--;
	}
	(sign == -1) ? (total[0] = '-') : (total[0] = '0');
	truncate_zeros(&total);
	return (total);	
}

/*
int main()
{
	printf("%s\n", subtract("5", "10"));
	printf("%s\n", subtract("10", "5"));
	printf("%s\n", subtract("644", "1000090"));
	printf("%s\n", subtract("1000090", "644"));
	printf("%s\n", add("15", "80"));
	printf("%s\n", subtract("3000546090", "3000546089"));
	printf("%s\n", subtract("20001230090", "600450344"));
//	printf("%s\n", multiplication("15", "80"));
	printf("%s\n", add("5654654", "32132564154"));
	return (0);
}

*/
