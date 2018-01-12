#include "bistromatic.h"

linked_list *create_link(char *str)
{
    linked_list *new;

    new = (linked_list *)malloc(sizeof(linked_list));
    new->data = str;
    new->next = 0;
    return (new);
}

void add_link(linked_list **list, char *str)
{
    linked_list *iter;

    iter = (*list);
    while (iter->next)
        iter = iter->next;
    iter->next = create_link(str);
}

char    *summate_linked_list(linked_list *list)
{
    char *sum;

    if (list && !list->next)
        return (list->data);
    else if (!list)
        return ("0");
    sum = 0;
    while (list)
    {
        if (!sum)
            sum = add("0", list->data);
        else
            sum = add(sum, list->data);
        list = list->next;
    }
    return (sum);
}

void	print_linked_list(linked_list *list)
{
	while (list)
	{
		ft_putstr(list->data);
		ft_putstr("\n");
		list = list->next;
	}
}
