/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:55:39 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 07:57:31 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

linked_list	*create_link(char *str)
{
	linked_list *new;

	new = (linked_list *)malloc(sizeof(linked_list));
	new->data = str;
	new->next = 0;
	return (new);
}
