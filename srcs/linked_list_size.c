#include "../includes/bistromatic.h"

int size(linked_list *list)
{
	linked_list *iter;
	int i;

	iter = list;
	i = 0;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
