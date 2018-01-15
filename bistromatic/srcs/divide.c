/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 23:39:02 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:48:31 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VARS char *total; char *minuend; char *tmp; char div[2]; char **res;
#define VARS_2 char *sign = multiply("1","1"); int start_len; int i; int j = 0;
#define INIT i=start_len;minuend=ft_strdup(dividend);minuend[start_len]='\0';

char		**closest_whole_num(char *divisor, char *minuend)
{
	char	**res;
	char	*total;
	char	counter[2];
	int		i;
	int		len;

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
	return (res);
}

int				div_handle_negs(char **dividend, char **divisor, char **sign)
{
	if (zeroed(*divisor))
		return (0);
	if (is_negative(*dividend))
	{
		*sign = multiply(*sign, "-1");
		*dividend = multiply(*dividend, "-1");
	}
	if (is_negative(*divisor))
	{
		*sign = multiply(*sign, "-1");
		*divisor = multiply(*divisor, "-1");
	}
	return (1);
}

char			*divide(char *dividend, char *divisor)
{
	VARS;
	VARS_2;
	if (div_handle_negs(&dividend, &divisor, &sign) == 0)
		return ("Error: Division by zero.");
	if (number_cmp(dividend, divisor) < 0)
		return ("0");
	start_len = ft_strlen(divisor);
	if (ft_strncmp(dividend, divisor, start_len) < 0)
		start_len = start_len + 1;
	total = malloc(sizeof(char) * (ft_strlen(dividend) - start_len + 1 + 1));
	if (!total)
		return (NULL);
	INIT;
	dividend = (pad_right(dividend, 1));
	while (dividend[i] && (res = closest_whole_num(divisor, minuend)))
	{
		tmp = minuend;
		div[0] = dividend[i++];
		minuend = ft_strjoin(subtract(minuend, res[1]), div);
		total[j++] = res[0][0];
		free(res);
		free(tmp);
	}
	total[j] = '\0';
	return (multiply(sign, total));
}
