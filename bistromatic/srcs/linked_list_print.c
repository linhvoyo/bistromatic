/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:00:42 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:01:28 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void	print_linked_list(linked_list *list)
{
	while (list)
	{
		ft_putstr(list->data);
		ft_putstr("\n");
		list = list->next;
	}
}
