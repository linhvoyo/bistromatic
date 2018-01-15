/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_summate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:02:46 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:03:51 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*summate_linked_list(linked_list *list)
{
	char *sum;

	if (list && !list->next)
		return (list->data);
	else if (!list)
		return ("0");
	sum = 0;
	while (list)
	{
		if (!sum)
			sum = add("0", list->data);
		else
			sum = add(sum, list->data);
		list = list->next;
	}
	return (sum);
}
