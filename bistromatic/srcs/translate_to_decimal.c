/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_to_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 23:46:40 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/15 09:12:08 by lilam            ###   ########.fr       */
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

char *translate_to_decimal(char *charset, char *expression)
{
	char *chunk;
	char *charset_duplicate;
	char *expression_duplicate;
	
	charset_duplicate = ft_strdup(charset);
	expression_duplicate = ft_strdup(expression);
	chunk = get_chunk(charset, expression);
	while (ft_strlen(chunk) > 0)
	{
		expression = replace(expression, chunk, get_decimal(charset, chunk), 0);
		chunk = get_chunk(charset, expression);
	}
	return (expression);
}
