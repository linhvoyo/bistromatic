/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:57:23 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/11 20:07:33 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int number_cmp(char *str1, char *str2)
{
	char *cmp1;
	char *cmp2;

	cmp1 = ft_strdup(str1);
	truncate_zeros(&cmp1);
	cmp2 = ft_strdup(str2);
	truncate_zeros(&cmp2);
	if (cmp1[0] == '-' && (zeroed(cmp2) || ft_strcmp(cmp2, "0") > 0))
		return (-1);
	else if (cmp2[0] == '-' && (zeroed(cmp1) || ft_strcmp(cmp1, "0") > 0))
		return (1);
	if (cmp1[0] == '-' && cmp2[0] == '-')
	{
		if (ft_strlen(cmp2) > ft_strlen(cmp1))
			return (1);
		else if (ft_strlen(cmp1) > ft_strlen(cmp2))
			return (-1);
		return (-ft_strcmp(cmp1, cmp2));
	}
	if (ft_strcmp(cmp1, cmp2) > 0 && ft_strlen(cmp2) > ft_strlen(cmp1))
		return (-1);
	if (ft_strcmp(cmp1, cmp2) < 0 && ft_strlen(cmp2) < ft_strlen(cmp1))
		return (1);
	return (ft_strcmp(cmp1, cmp2));
}
