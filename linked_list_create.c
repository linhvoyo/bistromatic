#include "bistromatic.h"

linked_list *create_link(char *str)
{
    linked_list *new;

    new = (linked_list *)malloc(sizeof(linked_list));
    new->data = str;
    new->next = 0;
    return (new);
}

