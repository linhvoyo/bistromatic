/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:13:13 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:48:03 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define V1 linked_list *list;char *negative_flag;char *new;int count;
#define V char *multiplicand=ft_strdup(str1);char *multiplier=ft_strdup(str2);
#define INIT V1; V; count = 0; list = 0;

static char	*multiply_helper(char *str1, char *str2)
{
	char	*row;
	int		i;
	int		value;
	int		carry;
	int		singles_digit;

	i = ft_strlen(str1);
	row = initialize_zero(i + ft_strlen(str2));
	while (i > 0)
	{
		value = (str1[i - 1] - '0') * (*str2 - '0');
		carry = value / 10;
		singles_digit = value % 10 + row[i] - '0';
		if (singles_digit > 9)
		{
			carry = carry + singles_digit / 10;
			singles_digit = singles_digit % 10;
		}
		row[i] = singles_digit + '0';
		row[i - 1] = carry + row[i - 1];
		i--;
	}
	return (row);
}

char		*multiply(char *str1, char *str2)
{
	INIT;
	if (zeroed(str1) || zeroed(str2))
		return ("0");
	negative_flag = "";
	if ((str1[0] == '-' && str2[0] != '-') ||
			(str1[0] != '-' && str2[0] == '-'))
		negative_flag = "-";
	if (str1[0] == '-')
		multiplicand++;
	if (str2[0] == '-')
		multiplier++;
	while (!zeroed(multiplier))
	{
		if (!list)
			list = create_link(multiply_helper(multiplicand,
						ft_itoa(pop_digit(multiplier))));
		else
			add_link(&list, pad_right(multiply_helper(multiplicand,
							ft_itoa(pop_digit(multiplier))), count));
		count++;
	}
	new = ft_strjoin(negative_flag, summate_linked_list(list));
	truncate_zeros(&new);
	return (new);
}
