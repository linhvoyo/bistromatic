/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_prepend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:59:11 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:00:29 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void	prepend_link(linked_list **list, char *str)
{
	linked_list *old;
	linked_list *new;

	old = (*list);
	new = create_link(str);
	new->next = old;
	*list = new;
}
