/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:00:28 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:01:16 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int	get_index(char *array, char c)
{
	int i;

	i = 0;
	while (*array)
	{
		if (*array == c)
			return (i);
		i++;
		array++;
	}
	return (-1);
}
