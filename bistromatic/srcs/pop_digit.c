/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:28:06 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:54:02 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int	pop_digit(char *str)
{
	int value;

	value = get_rightmost_digit(str);
	shift_right(&str);
	return (value);
}
