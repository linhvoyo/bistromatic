/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_get_closest_base.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:57:45 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:58:56 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*get_closest_base(linked_list *list, char *value, int *index)
{
	(*index) = 0;
	while (number_cmp(list->data, value) > 0)
	{
		(*index)++;
		list = list->next;
	}
	return (list->data);
}
