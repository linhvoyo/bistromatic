/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:54:50 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:55:43 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*power(char *number, char *exponent)
{
	char *result;

	result = "1";
	if (number_cmp("0", exponent) == 0)
		return (result);
	while (number_cmp("0", exponent) < 0)
	{
		result = multiply(result, number);
		exponent = subtract(exponent, "1");
	}
	return (result);
}
