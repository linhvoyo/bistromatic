/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:11:57 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:13:00 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*modulo(char *dividend, char *divisor)
{
	char *result;
	char *multiplier;
	char *sign;

	if (zeroed(dividend))
		return ("0");
	if (zeroed(divisor))
		return ("Error: Division by 0.");
	sign = "";
	if (is_negative(dividend) && dividend++)
		sign = "-";
	if (number_cmp(dividend, divisor) < 0)
		return (divisor);
	multiplier = divide(dividend, divisor);
	result = multiply(multiplier, divisor);
	if (number_cmp(result, dividend) == 0)
		return ("0");
	return (ft_strjoin(sign, subtract(dividend, result)));
}
