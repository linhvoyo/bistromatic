/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:53:48 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:55:29 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void	add_link(linked_list **list, char *str)
{
	linked_list *iter;

	iter = (*list);
	while (iter->next)
		iter = iter->next;
	iter->next = create_link(str);
}
