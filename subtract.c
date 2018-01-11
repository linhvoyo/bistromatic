/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:25:23 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/11 10:31:37 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int is_str1_smaller(char *str1, char *str2);
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
	while (i >= 0)
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
			total[i] = 10 + carry + '0';
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
	if (sign == -1)
		total[0] = '-';
	truncate_zeros(&total);
	return (total);	
}
