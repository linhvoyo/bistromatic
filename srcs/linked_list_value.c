#include "../includes/bistromatic.h"

char *value(linked_list *list, int n)
{
	linked_list *iter;

	iter = list;
	while (n-- && iter->next)
		iter = iter->next;
	return (iter->data);
}
