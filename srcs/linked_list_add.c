#include "../includes/bistromatic.h"

void add_link(linked_list **list, char *str)
{
    linked_list *iter;

    iter = (*list);
    while (iter->next)
        iter = iter->next;
    iter->next = create_link(str);
}

