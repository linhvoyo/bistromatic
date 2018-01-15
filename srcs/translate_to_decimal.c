/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_to_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 23:46:40 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/14 23:47:00 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

static char	*get_chunk(char *charset, char *expression)
{
	int		i;
	int		j;

	i = 0;
	while (get_index(charset, expression[i]) < 0)
		i++;
	if (!expression[i])
		return ("");
	j = i;
	while (get_index(charset, expression[j]) > 0)
		j++;
	j--;
	return (substring(expression, i, j));
}

char		*translate_to_decimal(char *charset, char *expression)
{
	char	*chunk;
	char	*decimal;
	int		i;
	int		j;

	i = 0;
	while (expression[i] && (chunk = get_chunk(charset, &expression[i])))
	{
		decimal = get_decimal(charset, chunk);
		while (get_index(charset, expression[i]) < 0)
			if (i++ >= ft_strlen(expression))
				break ;
		if (i >= ft_strlen(expression))
			break ;
		j = ft_strlen(decimal);
		expression = ft_strjoin(
				ft_strjoin(substring(expression, 0, i - 1), decimal),
				substring(expression, ft_strlen(decimal) + i,
					ft_strlen(expression)));
		while (j--)
			i++;
		i++;
	}
	return (expression);
}
