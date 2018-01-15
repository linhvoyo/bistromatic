#include "../includes/bistromatic.h"

char *get_closest_base(linked_list *list, char *value, int *index)
{
	(*index) = 0;
	while (number_cmp(list->data, value) > 0)
	{
		(*index)++;
		list = list->next;
	}
	return (list->data);
}
