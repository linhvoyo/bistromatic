/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:08:19 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:47:17 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VAR char *total;char *tmp;int big=ft_strlen(s1);int sign=1;
#define VARS_2 int carry = 0; int loop;
#define SWAP tmp=s1; s1=s2; s2=tmp;

void	loop(int i, char *s1, char *s2, char *total)
{
	VARS_2;
	while (i >= 0)
	{
		loop = 0;
		if (((s1[i] - '0') - (s2[i] - '0') < 0) && (loop = 1))
		{
			total[i] = ((s1[i] - '0') + 10) - (s2[i] - '0') + carry + '0';
			carry = -1;
		}
		else if ((carry == -1 && (s1[i] - '0') - (s2[i] - '0') == 0)
				&& (loop = 1))
		{
			total[i] = 10 + carry + '0';
			carry = -1;
		}
		else
		{
			total[i] = (s1[i] - '0') - (s2[i] - '0') + carry + '0';
			carry = 0;
			loop = 1;
		}
		if (!loop)
			total[i] = '0';
		i--;
	}
}

char	*subtract(char *s1, char *s2)
{
	VAR;
	if (is_negative(s2))
		return (add(s1, multiply(s2, "-1")));
	if (is_negative(s1))
		return (multiply(add(multiply(s1, "-1"), s2), "-1"));
	if (is_str1_smaller(s1, s2) && (big = ft_strlen(s2) + sign))
	{
		total = (char *)malloc(sizeof(char) * (big + 1 + sign));
		SWAP;
		sign = -1;
	}
	else
		total = (char *)malloc(sizeof(char) * (big + 1));
	if (!total)
		return (NULL);
	s1 = pad_left(s1, big);
	s2 = pad_left(s2, big);
	total[big--] = '\0';
	loop(big, s1, s2, total);
	if (sign == -1)
		total[0] = '-';
	if (number_cmp("0", total) == 0)
		return ("0");
	truncate_zeros(&total);
	return (total);
}
