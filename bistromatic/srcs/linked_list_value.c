/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:04:01 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:04:40 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*value(linked_list *list, int n)
{
	linked_list *iter;

	iter = list;
	while (n-- && iter->next)
		iter = iter->next;
	return (iter->data);
}
