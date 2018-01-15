/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 06:56:52 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:00:05 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

static char		*get_decimal_positive(char *charset, char *string)
{
	char		*strings[2];
	int			ints[2];
	linked_list	*summands;
	char		*sign;

	if (zeroed_character(string, charset[0]))
		return ("0");
	sign = "";
	if (*string == '-' && (sign = "-"))
		string++;
	ints[0] = ft_strlen(string) - 1;
	strings[1] = ft_itoa(ft_strlen(charset));
	strings[0] = "0";
	summands = create_link("0");
	while (*string)
	{
		ints[1] = get_index(charset, *string);
		strings[0] = multiply(ft_itoa(ints[1]), power(strings[1],
					ft_itoa(ints[0])));
		prepend_link(&summands, strings[0]);
		ints[0]--;
		string++;
	}
	return (summate_linked_list(summands));
}

char			*get_decimal(char *charset, char *string)
{
	char *sign;

	sign = "";
	if (*string == '-')
	{
		sign = "-";
		string++;
	}
	return (ft_strjoin(sign, get_decimal_positive(charset, string)));
}
