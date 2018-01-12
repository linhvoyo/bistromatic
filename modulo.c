/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 22:05:38 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/11 22:10:29 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char *modulo(char *dividend, char *divisor)
{
	if (number_cmp(dividend, divisor) < 0)
		return (divisor);
	return (dividend);
}
