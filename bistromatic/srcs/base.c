/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 23:32:46 by lilam             #+#    #+#             */
/*   Updated: 2018/01/14 23:38:23 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

static char		*base_positive(char *charset, char *decimal)
{
	char		*strings[3];
	int			ints[3];
	linked_list	*powers;

	if ((ints[1] = 0) || zeroed(decimal))
		return (stringerize(charset[0]));
	strings[2] = ft_itoa(ft_strlen(charset));
	powers = create_link("1");
	strings[1] = "1";
	while (number_cmp(strings[1], decimal) < 0 &&
			(strings[1] = multiply(strings[1], strings[2])))
		if (number_cmp(strings[1], decimal) <= 0)
			prepend_link(&powers, strings[1]);
	strings[0] = initialize_characters(size(powers), charset[0]);
	while (strings[0][ints[1]++])
		if (!zeroed(decimal) && (ints[2] = ints[1]))
		{
			strings[1] = get_closest_base(powers, decimal, &ints[2]);
			ft_putstr("");
			ints[0] = ft_atoi(divide(decimal, strings[1]));
			decimal = subtract(decimal,
					multiply(divide(decimal, strings[1]), strings[1]));
			strings[0][ints[2]] = charset[ints[0]];
		}
	return (strings[0]);
}

char			*base(char *charset, char *decimal)
{
	char *sign;

	sign = "";
	if (*decimal == '-')
	{
		sign = "-";
		decimal++;
	}
	return (ft_strjoin(sign, base_positive(charset, decimal)));
}
