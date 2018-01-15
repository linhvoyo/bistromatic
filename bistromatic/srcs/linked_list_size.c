/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:01:36 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:02:32 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int	size(linked_list *list)
{
	linked_list	*iter;
	int			i;

	iter = list;
	i = 0;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
