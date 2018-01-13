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
