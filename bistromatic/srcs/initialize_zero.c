/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:47:45 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:50:04 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*initialize_zero(int length)
{
	int		i;
	char	*str;

	str = ft_strnew(length);
	i = 0;
	while (i < length)
		str[i++] = '0';
	return (str);
}
