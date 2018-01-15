/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rightmost_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:01:27 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:05:21 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int	get_rightmost_digit(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	if (!str[i + 1])
		return (str[i] - '0');
	while (str[i + 1])
		i++;
	return (str[i] - '0');
}
