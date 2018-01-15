/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:09:17 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/15 09:09:18 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char		*substring(char *str, int i, int j)
{
	char	*new;
	char	*iter;

	new = ft_strdup(str);
	iter = new;
	if (i > (int)ft_strlen(new))
		return ("");
	if (i < 0)
		i = 0;
	if (j < 0)
		return ("");
	if (j > (int)ft_strlen(new))
		j = ft_strlen(new);
	while (i--)
		new++;
	while (j--)
		iter++;
	*(++iter) = '\0';
	return (new);
}
