#include "bistromatic.h"

char *get_closest_base(linked_list *list, char *value)
{
	while (number_cmp(list->data, value) > 0)
		list = list->next;
	return (list->data);
}
