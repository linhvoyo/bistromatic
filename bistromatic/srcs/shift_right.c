/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:57:32 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 09:01:21 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VARS int alternate=0;int i=0;char temp=0;char temp2=0;char *str;

void	shift_right(char **string_pointer)
{
	VARS;
	str = *string_pointer;
	while (str[i] && str[i] == '0')
		i++;
	if (!str[i])
		return ;
	while (str[i])
	{
		if (!temp2)
		{
			temp = str[i];
			temp2 = str[i + 1];
			str[i] = '0';
		}
		else
		{
			if (!alternate)
			{
				str[i] = temp;
				temp = str[i + 1];
				alternate = 1;
			}
			else if (alternate)
			{
				str[i] = temp2;
				temp2 = str[i + 1];
				alternate = 0;
			}
		}
		i++;
	}
}
