/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:05:33 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:06:59 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*initialize_characters(int length, char c)
{
	int		i;
	char	*str;

	str = ft_strnew(length);
	i = 0;
	while (i < length)
		str[i++] = c;
	return (str);
}
