#include "../includes/bistromatic.h"

void prepend_link(linked_list **list, char *str)
{
    linked_list *old;
	linked_list *new;

    old = (*list);
	new = create_link(str);
	new->next = old;
	*list = new;
}
