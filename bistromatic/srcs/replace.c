/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:55:55 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:57:23 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

/*
** "-(" --> "-1*("
** "--" --> "+"
*/

char	*replace(char *input, char *replaced, char *replacer, int repeat)
{
	char	*new;
	char	*replaced_location;
	int		i;
	int		j;

	if (!ft_strstr(input, replaced))
		return (input);
	new = ft_strdup(input);
	while ((replaced_location = ft_strstr(new, replaced)))
	{
		i = 0;
		j = ft_strlen(replaced);
		while (&new[i] != replaced_location)
			i++;
		new = ft_strjoin(
				ft_strjoin(substring(new, 0, i - 1), replacer),
				substring(new, i + j, ft_strlen(new)));
		if (!repeat)
			break ;
	}
	return (new);
}
