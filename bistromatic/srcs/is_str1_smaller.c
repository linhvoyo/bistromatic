/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str1_smaller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:51:27 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:53:21 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int	is_str1_smaller(char *str1, char *str2)
{
	int n1;
	int n2;
	int i;

	n1 = ft_strlen(str1);
	n2 = ft_strlen(str2);
	if (n1 < n2)
		return (1);
	if (n2 < n1)
		return (0);
	i = 0;
	while (i < n1)
	{
		if (str1[i] < str2[i])
			return (1);
		else if (str1[i] > str2[i])
			return (0);
		i++;
	}
	return (0);
}
